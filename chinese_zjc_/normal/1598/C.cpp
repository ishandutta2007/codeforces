// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005];
long long x, ans;
std::map<int, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        x = std::accumulate(a, a + n, 0ll);
        x *= 2;
        if (x % n)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        x /= n;
        map.clear();
        for (int i = 0; i != n; ++i)
        {
            ans += map[x - a[i]];
            ++map[a[i]];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}