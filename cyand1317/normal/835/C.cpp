#include <cstdio>
static const int MAXN = 1e5 + 3;
static const int MAXX = 102;
static const int MAXC = 12;

int n, q, c;
int x[MAXN], y[MAXN], s[MAXN];
int f[MAXX][MAXX][MAXC] = {{{ 0 }}};

int main()
{
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &s[i]);
        ++f[x[i]][y[i]][s[i]];
    }

    for (int u = 0; u <= c; ++u) {
        for (int i = 1; i < MAXX; ++i)
            for (int j = 1; j < MAXX; ++j)
                f[i][j][u] += f[i - 1][j][u] + f[i][j - 1][u] - f[i - 1][j - 1][u];
    }

    for (int i = 0, t, x1, y1, x2, y2; i < q; ++i) {
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int ans = 0;
        for (int u = 0; u <= c; ++u) {
            int ct = f[x2][y2][u] - f[x1 - 1][y2][u] - f[x2][y1 - 1][u] + f[x1 - 1][y1 - 1][u];
            ans += ct * ((u + t) % (c + 1));
        }
        printf("%d\n", ans);
    }

    return 0;
}