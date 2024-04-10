#include <cstdio>
#include <vector>
static const int MAXN = 42;

int n, m, q;
bool g[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN] = {{{{ 0 }}}};

int main()
{
    scanf("%d%d%d", &n, &m, &q); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) g[i][j] = (getchar() == '1');

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) f[i][j][i][j] = (g[i][j] ? 0 : 1);
    // Single-row
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < m; ++j) if (!g[i][j]) {
            for (int k = 0; k < j; ++k) f[i][k][i][j] = f[i][k][i][j - 1] + 1;
        }
    // Single-column
    for (int j = 0; j < m; ++j)
        for (int i = 1; i < n; ++i) if (!g[i][j]) {
            for (int k = 0; k < i; ++k) f[k][j][i][j] = f[k][j][i - 1][j] + 1;
        }
    // Multi-row & Multi-column
    for (int r = 1; r < n; ++r)
        for (int c = 1; c < m; ++c) {
            for (int i = 0; i < n - r; ++i)
                for (int j = 0; j < m - c; ++j) if (!g[i + r][j + c]) {
                    int ver_nearest = i - 1, hor_nearest = j - 1;
                    for (int k = i; k < i + r; ++k) if (g[k][j + c]) ver_nearest = k;
                    for (int k = j; k < j + c; ++k) if (g[i + r][k]) hor_nearest = k;
                    f[i][j][i + r][j + c] =
                        f[ver_nearest + 1][hor_nearest + 1][i + r - 1][j + c - 1] +
                        (i + r - ver_nearest) + (j + c - hor_nearest) - 1;
                }
        }

    int a, b, c, d;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d); --a, --b, --c, --d;
        int ans = 0;
        for (int i = a; i <= c; ++i)
            for (int j = b; j <= d; ++j) ans += f[a][b][i][j];//, printf("%d %d - %d %d: %d\n", a + 1, b + 1, i + 1, j + 1, f[a][b][i][j]);
        printf("%d\n", ans);
    }

    return 0;
}