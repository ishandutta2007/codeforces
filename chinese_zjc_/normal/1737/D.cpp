// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, m, dis[505][505];
long long e[505][505];
template <class T>
void cmin(T &A, T B) { A = std::min(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                e[i][j] = 1e15, dis[i][j] = i == j ? 0 : INT_MAX / 2;
        for (int i = 1; i <= m; ++i)
        {
            static int u, v;
            static long long w;
            std::cin >> u >> v >> w;
            cmin(e[u][v], w);
            cmin(e[v][u], w);
            dis[u][v] = dis[v][u] = 1;
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    cmin(dis[i][j], dis[i][k] + dis[k][j]);
        long long ans = LLONG_MAX;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                cmin(ans, (dis[1][i] + dis[n][j] + 1) * e[i][j]);
                for (int k = 1; k <= n; ++k)
                    cmin(ans, (dis[k][1] + dis[k][n] + dis[k][i] + 2) * e[i][j]);
            }
        std::cout << ans << std::endl;
    }
    return 0;
}