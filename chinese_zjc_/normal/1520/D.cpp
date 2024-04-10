// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long ans;
std::map<int, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        ans = 0;
        map.clear();
        for (int i = 1, x; i <= n; ++i)
        {
            std::cin >> x;
            ans += map[x - i];
            ++map[x - i];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}