#include <cstdio>
#include <cstdlib>
#include <cstring>
static const int MAXN = 33;
static const int MAXT = 6;
static const int MAXL = MAXN * MAXT * 2;
static const int OFFSET = MAXN * MAXT;

int n, t[MAXN];
bool a[MAXL][MAXL][8] = {{{ false }}}, b[MAXL][MAXL][8];
bool v[MAXL][MAXL] = {{ false }};
static const int mov[8][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {+1, +1}, {+1, -1}, {-1, -1}, {-1, +1}};
static const int turn[8][2] = {{4, 5}, {6, 7}, {4, 7}, {5, 6}, {0, 2}, {0, 3}, {1, 3}, {1, 2}};

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);

    a[OFFSET - 1][OFFSET][0] = true;
    for (int T = 0; T < n; ++T) {
        memset(b, false, sizeof b);
        for (int i = 0; i < MAXL; ++i)
            for (int j = 0; j < MAXL; ++j)
                for (int k = 0; k < 8; ++k) if (a[i][j][k]) {
                    for (int m = 1; m <= t[T]; ++m) v[i + mov[k][0] * m][j + mov[k][1] * m] = true;
                    b[i + mov[k][0] * t[T]][j + mov[k][1] * t[T]][turn[k][0]] = true;
                    b[i + mov[k][0] * t[T]][j + mov[k][1] * t[T]][turn[k][1]] = true;
                }
        memcpy(a, b, sizeof b);
    }

    int ans = 0;
    for (int i = 0; i < MAXL; ++i)
        for (int j = 0; j < MAXL; ++j)
            if (v[i][j]) ans++;//, printf("%d %d\n", i - OFFSET, j - OFFSET);
    printf("%d\n", ans);

    return 0;
}