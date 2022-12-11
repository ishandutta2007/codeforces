#include <cstdio>
#include <cstring>
static const int MAXN = 204;

int n, m;
int g[MAXN][MAXN];
int deg[MAXN];

void find_eulerian_path(int u)
{
    static int q[MAXN * MAXN], top;
    int v = u;
    top = 0;
    q[top++] = v;
    do {
        for (int i = 0; i <= n; ++i) if (g[v][i] == 1) {
            g[v][i] = g[i][v] = 0; --deg[v], --deg[i];
            v = i; q[top++] = v; break;
        }
    } while (u != v);
    for (int i = 0; i < top - 1; ++i) g[q[i]][q[i + 1]] = 2;
}

void work()
{
    memset(g, 0, sizeof g);
    memset(deg, 0, sizeof deg);
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        g[u][v] = g[v][u] = 1;
        ++deg[u], ++deg[v];
    }
    int ct = 0;
    for (int i = 0; i < n; ++i) if (deg[i] % 2 == 0) ++ct;
    printf("%d\n", ct);
    for (int i = 0; i < n; ++i) if (deg[i] % 2 == 1) {
        g[n][i] = g[i][n] = 1;
        ++deg[i]; ++deg[n];
    }
    for (int i = 0; i <= n; ++i) if (deg[i] > 0) find_eulerian_path(i);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j] == 2) printf("%d %d\n", i + 1, j + 1);
}

int main()
{
    int T; scanf("%d", &T);
    do work(); while (--T);
    return 0;
}