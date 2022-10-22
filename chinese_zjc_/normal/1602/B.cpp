// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, q, n, a[2005], c[2005], ans[100005];
std::vector<std::pair<int, int>> query[50005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::cin >> q;
        for (int i = 0; i <= 50000; ++i)
            query[i].clear();
        for (int i = 1, x, y; i <= q; ++i)
            std::cin >> x >> y, query[std::min(50000, y)].emplace_back(x, i);
        for (auto i : query[0])
            ans[i.second] = a[i.first];
        for (int i = 1; i <= 50000; ++i)
        {
            std::fill(c + 1, c + 1 + n, 0);
            for (int j = 1; j <= n; ++j)
                ++c[a[j]];
            for (int j = 1; j <= n; ++j)
                a[j] = c[a[j]];
            for (auto j : query[i])
                ans[j.second] = a[j.first];
        }
        for (int i = 1; i <= q; ++i)
            std::cout << ans[i] << std::endl;
    }
    return 0;
}