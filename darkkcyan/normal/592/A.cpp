#include <iostream>

using namespace std;

const int MAX_ROW = 8;
const int MAX_COL = 8;

const int EMPTY = 0;
const int WHITE_PAWN = 1;
const int BLACK_PAWN = 2;

const char EMPTY_SYMBOL = '.';
const char WHITE_PAWN_SYMBOL = 'W';
const char BLACK_PAWN_SYMBOL = 'B';

const char WHITE_PAWN_PLAYER = 'A';
const char BLACK_PAWN_PLAYER = 'B';

// input
int board[MAX_ROW][MAX_COL];

// output
char winner;

// functions
void readInput(istream& is) {
    char ch;
    for (int r = 0; r < MAX_ROW; ++r) {
        is >> std::ws;

        for (int c = 0; c < MAX_COL; ++c) {
            is >> ch;
            switch (ch) {
                case EMPTY_SYMBOL: board[r][c] = EMPTY; break;
                case WHITE_PAWN_SYMBOL: board[r][c] = WHITE_PAWN; break;
                case BLACK_PAWN_SYMBOL: board[r][c] = BLACK_PAWN; break;
            }
        }
    }
}

void process() {
    int nearestWhitePawnRow = MAX_ROW;
    int nearestBlackPawnRow = -1;

    int col, row;

    for (col = 0; col < MAX_COL; ++col) {
        for (row = 0; row < MAX_ROW; ++row) {
            if (board[row][col] == BLACK_PAWN) break;
            if (board[row][col] == EMPTY) continue;
            if (row < nearestWhitePawnRow) {
                nearestWhitePawnRow = row;
                break;
            }
        }

        for (row = MAX_ROW - 1; row >= 0; --row) {
            if (board[row][col] == WHITE_PAWN) break;
            if (board[row][col] == EMPTY) continue;
            if (row > nearestBlackPawnRow) {
                nearestBlackPawnRow = row;
                break;
            }
        }
    }

    winner = (nearestWhitePawnRow <= (MAX_ROW - nearestBlackPawnRow - 1))
        ? WHITE_PAWN_PLAYER
        : BLACK_PAWN_PLAYER
    ;
}

void writeOutput(ostream& os) {
    os << winner << endl;
}

int main(void) {
    readInput(cin);
    process();
    writeOutput(cout);

    return 0;
}