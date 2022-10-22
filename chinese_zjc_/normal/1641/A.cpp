// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
signed main()
{
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--)
    {
        int n, x, ans = 0;
        std::cin >> n >> x;
        std::map<long long, int> g;
        for (int i = 1, y; i <= n; ++i)
        {
            std::cin >> y;
            ++g[y];
        }
        while (!g.empty())
        {
            if (g.begin()->second <= 0)
                ans += -g.begin()->second;
            else
                g[g.begin()->first * x] -= g.begin()->second;
            g.erase(g.begin());
        }
        std::cout << ans << std::endl;
    }
    return 0;
}