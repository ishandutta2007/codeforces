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
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        std::sort(a + 1, a + 1 + n);
        ans = 0;
        for (int i = 2; i <= n; ++i)
            ans = std::__gcd(ans, a[i] - a[1]);
        std::cout << (a[n] == a[1] ? -1 : ans) << std::endl;
    }
    return 0;
}