// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, x[100005];
long long ans;
std::vector<int> t[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        ans = 0;
        t[0].clear();
        t[1].clear();
        for (int i = 1; i <= n; ++i)
            std::cin >> x[i];
        for (int i = 1, y; i <= n; ++i)
            std::cin >> y, t[x[i]].push_back(y), ans += y;
        std::sort(t[0].begin(), t[0].end(), std::greater<int>());
        std::sort(t[1].begin(), t[1].end(), std::greater<int>());
        if (t[0].size() != t[1].size())
            for (std::size_t i = 0; i != t[0].size() && i != t[1].size(); ++i)
                ans += t[0][i] + t[1][i];
        else
            ans = ans * 2 - std::min(t[0].back(), t[1].back());
        std::cout << ans << std::endl;
    }
    return 0;
}