// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, x[400005], p, n, ans;
std::map<int, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        map.clear();
        std::cin >> p >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> x[i], ++map[p - x[i]];
        --p;
        for (auto i : map)
        {
            int cnt = std::min({i.second, p / i.first});
            if (cnt <= 0)
                break;
            ans += cnt;
            p -= cnt * i.first;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}