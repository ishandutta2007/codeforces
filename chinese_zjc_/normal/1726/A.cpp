// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, a[2005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        if (n == 1)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = std::max(ans, a[i] - a[i % n + 1]);
        ans = std::max(ans, a[n] - *std::min_element(a + 1, a + n));
        ans = std::max(ans, *std::max_element(a + 2, a + 1 + n) - a[1]);
        std::cout << ans << std::endl;
    }
    return 0;
}