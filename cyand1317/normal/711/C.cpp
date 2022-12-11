#include <cstdio>
typedef long long int64;
static const int64 INF64 = (1LL << 62);
static const int MAXN = 105;
static const int MAXM = 105;
template <typename T> inline void tension(T &var, const T val) { if (var > val) var = val; }

int n, m, k;
int c[MAXN];
int p[MAXN][MAXM];
int64 f[MAXN][MAXN][MAXM];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]); --c[i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &p[i][j]);

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k < MAXM; ++k) f[i][j][k] = INF64;
    f[0][0][m] = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= m; ++k) {
                if (c[i] != -1) {
                    tension(f[i + 1][j + (c[i] != k)][c[i]], f[i][j][k]);
                } else {
                    for (int w = 0; w < m; ++w)
                        tension(f[i + 1][j + (w != k)][w], f[i][j][k] + p[i][w]);
                }
            }

    int64 ans = INF64;
    for (int i = 0; i < m; ++i) tension(ans, f[n][k][i]);
    printf("%I64d\n", ans == INF64 ? -1 : ans);

    return 0;
}