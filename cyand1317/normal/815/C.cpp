#include <cstdio>
#include <vector>
typedef long long int64;
static const int MAXN = 5004;
static const int64 INF = 1LL << 61;

int n, b;
int c[MAXN], d[MAXN], p[MAXN];
std::vector<int> e[MAXN];

int sts[MAXN], pfc[MAXN];
int64 f[MAXN][MAXN], g[MAXN][MAXN];

void dfs_sts(int u)
{
    sts[u] = 1;
    pfc[u] = -1;
    for (int v : e[u]) {
        dfs_sts(v);
        sts[u] += sts[v];
        if (pfc[u] == -1 || sts[pfc[u]] < sts[v])
            pfc[u] = v;
    }
}

void dfs_dp(int u)
{
    f[u][0] = 0;
    g[u][0] = 0;
    for (int i = 1; i <= n; ++i) f[u][i] = g[u][i] = INF;
    if (e[u].empty()) {
        f[u][1] = c[u];
        g[u][1] = c[u] - d[u];
        return;
    }

    for (int v : e[u]) dfs_dp(v);
    for (int i = 0; i <= n; ++i) {
        f[u][i] = std::min(f[u][i], f[pfc[u]][i]);
        g[u][i] = std::min(g[u][i], std::min(f[pfc[u]][i], g[pfc[u]][i]));
    }
    int cur_sz = sts[pfc[u]] + 1;
    for (int v : e[u]) if (v != pfc[u]) {
        for (int i = cur_sz; i >= 0; --i)
            for (int j = 0; j <= sts[v]; ++j) {
                int64 ff = f[u][i];
                f[u][i + j] = std::min(f[u][i + j], f[u][i] + f[v][j]);
                g[u][i + j] = std::min(g[u][i + j], std::min(ff, g[u][i]) + std::min(f[v][j], g[v][j]));
            }
        cur_sz += sts[v];
    }

    for (int i = sts[u]; i >= 1; --i) g[u][i] = g[u][i - 1] + (c[u] - d[u]);
    g[u][0] = INF;
    for (int i = sts[u]; i >= 1; --i) f[u][i] = std::min(f[u][i], f[u][i - 1] + c[u]);
    f[u][0] = 0;
}

int main()
{
    scanf("%d%d%d%d", &n, &b, &c[0], &d[0]);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &c[i], &d[i], &p[i]); --p[i];
        e[p[i]].push_back(i);
    }

    dfs_sts(0);
    dfs_dp(0);
    int ans = 0;
    for (; ans <= n && (f[0][ans] <= b || g[0][ans] <= b); ++ans) ;
    printf("%d\n", ans - 1);

    return 0;
}