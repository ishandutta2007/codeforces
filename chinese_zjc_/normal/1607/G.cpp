// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, a[200005], b[200005], x[200005], y[200005];
long long dis;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        dis = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i] >> b[i], x[i] = std::min(m, a[i]), y[i] = m - x[i], dis += (b[i] - y[i]) - (a[i] - x[i]);
        if (dis < 0)
        {
            std::cout << -dis << std::endl;
            for (int i = 1; i <= n; ++i)
                std::cout << x[i] << ' ' << y[i] << std::endl;
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            int cnt = std::min(std::min(x[i], b[i] - y[i]) + 0ll, dis / 2);
            x[i] -= cnt;
            y[i] += cnt;
            dis -= cnt * 2;
        }
        std::cout << dis << std::endl;
        for (int i = 1; i <= n; ++i)
            std::cout << x[i] << ' ' << y[i] << std::endl;
    }
    return 0;
}