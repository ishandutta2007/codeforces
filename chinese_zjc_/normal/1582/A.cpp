// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, a, b, c;
std::bitset<10001> dp;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> a >> b >> c;
        dp.reset();
        dp.set(5000);
        a = a - std::max(a - 100, 0) / 2 * 2;
        b = b - std::max(b - 100, 0) / 2 * 2;
        c = c - std::max(c - 100, 0) / 2 * 2;
        for (int i = 1; i <= a; ++i)
            dp = dp << 1 | dp >> 1;
        for (int i = 1; i <= b; ++i)
            dp = dp << 2 | dp >> 2;
        for (int i = 1; i <= c; ++i)
            dp = dp << 3 | dp >> 3;
        for (int i = 0; i <= a + b * 2 + c * 3; ++i)
            if (dp[i + 5000])
            {
                std::cout << i << std::endl;
                break;
            }
    }
    return 0;
}