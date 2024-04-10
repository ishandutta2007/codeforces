// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[2005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = -1;
        std::memset(a, 0, sizeof(a));
        std::cin >> n;
        for (int i = 1, x; i <= n; ++i)
            std::cin >> x, a[x] = i;
        for (int i = 1; i <= 1000; ++i)
            for (int j = 1; j <= 1000; ++j)
                if (std::__gcd(i, j) == 1 && a[i] && a[j])
                    ans = std::max(ans, a[i] + a[j]);
        std::cout << ans << std::endl;
    }
    return 0;
}