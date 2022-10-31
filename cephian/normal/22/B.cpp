#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
string grid[25];

int rect[25][25];

int rc(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    return rect[a][b];
}

int rctsum(int a, int b, int c, int d) {
    return rc(c, d) - rc(c, b - 1) - rc(a - 1, d) + rc(a - 1, b - 1);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        cin >> grid[i];

    for (int i = 0; i < R; ++i) {
        rect[i][0] = grid[i][0] == '1';
        for (int j = 1; j < C; ++j)
            rect[i][j] = rect[i][j - 1] + (grid[i][j] == '1');

    }
    for (int j = 0; j < C; ++j)
        for (int i = 1; i < R; ++i)
            rect[i][j] += rect[i - 1][j];
    int ans = 0;

    for (int a = 0; a < R; ++a)
        for (int b = a; b < R; ++b)
            for (int c = 0; c < C; ++c)
                for (int d = c; d < C; ++d)
                    if (rctsum(a, c, b, d) == 0)
                        ans = max(ans, 2 * (2 + b - a + d - c));

    cout << ans << "\n";

    return 0;
}