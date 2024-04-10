// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[105], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], ans = std::max(ans, a[i] - i);
        std::cout << ans << std::endl;
    }
    return 0;
}