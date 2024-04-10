// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, dis[205][205], x[2005], y[2005], ans1 = 0, ans2 = INT_MIN;
bool z[2005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = i == j ? 0 : INT_MAX / 2;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> x[i] >> y[i] >> z[i];
        z[i] ^= true;
        dis[x[i]][y[i]] = 1;
        if (z[i])
            dis[y[i]][x[i]] = +1;
        else
            dis[y[i]][x[i]] = -1;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= n; ++i)
    {
        bool flag = true;
        for (int j = 1; j <= m; ++j)
        {
            int d = dis[i][y[j]] - dis[i][x[j]];
            if ((z[j] ? std::abs(d) : d) != 1)
                flag = false;
        }
        int res = *std::max_element(dis[i] + 1, dis[i] + 1 + n);
        if (flag && res > ans2)
        {
            ans1 = i;
            ans2 = std::max(ans2, res);
        }
    }
    if (!ans1)
        return std::cout << "NO" << std::endl, 0;
    std::cout << "YES" << std::endl
              << ans2 << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << dis[ans1][i] << " \n"[i == n];
    return 0;
}