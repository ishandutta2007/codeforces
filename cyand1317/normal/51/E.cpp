#include <cstdio>
typedef long long int64;
static const int MAXN = 704;

int n, m;
int deg[MAXN] = { 0 };
bool g[MAXN][MAXN] = {{ false }};
int ways2[MAXN][MAXN] = {{ 0 }};

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        ++deg[u], ++deg[v];
        g[u][v] = g[v][u] = true;
    }

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = 0; k < n; ++k) if (g[i][k] && g[j][k])
                ++ways2[i][j], ++ways2[j][i];
    int64 ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) if (g[i][j])
            for (int k = 0; k < n; ++k) if (k != i && k != j)
                ans += (int64)(ways2[i][k] - g[j][k]) * (ways2[j][k] - g[i][k]);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) if (g[i][j])
            for (int k = 0; k < n; ++k) if (g[i][k] && g[j][k])
                ans -= (deg[k] - 2);

    printf("%I64d\n", ans / 5);

    return 0;
}