#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
            return false;
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer &&
                 board[i][1] == currentPlayer &&
                 board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer &&
                 board[1][i] == currentPlayer &&
                 board[2][i] == currentPlayer))
                return true;
        }
        // Diagonals
        if ((board[0][0] == currentPlayer &&
             board[1][1] == currentPlayer &&
             board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer &&
             board[1][1] == currentPlayer &&
             board[2][0] == currentPlayer))
            return true;
        return false;
    }

    bool checkDraw() {
        for (const auto& row : board)
            for (char cell : row)
                if (cell == ' ')
                    return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;
        while (true) {
            printBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3 1-3): ";
            cin >> row >> col;
            row--; col--;
            if (!makeMove(row, col)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }
            if (checkWin()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkDraw()) {
                printBoard();
                cout << "It's a draw!\n";
                break;
            }
            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}