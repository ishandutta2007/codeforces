#include <cstdio>
#include <vector>
#define MAXN 55
// Checks whether _n is in [_l, _u).
#define inrange(_n, _l, _u) ((_n) >= (_l) && (_n) < (_u))

struct point {
    int row, col;
    point(int _row, int _col) : row(_row), col(_col) {}
};

int main()
{
    int n;
    char b[MAXN][MAXN];
    char move[MAXN * 2][MAXN * 2];
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j) b[i][j] = getchar();

    for (int i = 0; i < n + n - 1; ++i)
        for (int j = 0; j < n + n - 1; ++j) move[i][j] = 'x';
    move[n - 1][n - 1] = 'o';
    std::vector<point> pieces, blanks;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (b[i][j] == 'o') {
            pieces.push_back(point(i, j));
        } else if (b[i][j] == '.') {
            blanks.push_back(point(i, j));
        }

    for (std::vector<point>::iterator i = blanks.begin(); i != blanks.end(); ++i) {
        for (std::vector<point>::iterator j = pieces.begin(); j != pieces.end(); ++j) {
            move[n - 1 + i->row - j->row][n - 1 + i->col - j->col] = '.';
        }
    }

    // Validity check
    char bb[MAXN][MAXN];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) bb[i][j] = '.';
    for (std::vector<point>::iterator i = pieces.begin(); i != pieces.end(); ++i) {
        bb[i->row][i->col] = 'o';
        for (int drow = 1 - n; drow <= n - 1; ++drow)
            for (int dcol = 1 - n; dcol <= n - 1; ++dcol) if (move[drow + n - 1][dcol + n - 1] == 'x')
                if (inrange(i->row + drow, 0, n) && inrange(i->col + dcol, 0, n)
                        && bb[i->row + drow][i->col + dcol] == '.') {
                    bb[i->row + drow][i->col + dcol] = 'x';
                }
    }
    bool valid = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (b[i][j] != bb[i][j]) { valid = false; break; }
        if (!valid) break;
    }

    if (valid) {
        puts("YES");
        for (int i = 0; i < n + n - 1; ++i) {
            for (int j = 0; j < n + n - 1; ++j) putchar(move[i][j]);
            putchar('\n');
        }
    } else puts("NO");
    return 0;
}