// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long n;
bool dp[2000005][7];
signed main()
{
    std::ios::sync_with_stdio(false);
    dp[0][0] = true;
    for (int i = 0; i <= 1000000; ++i)
        for (int j = 0; j <= 6; ++j)
            for (int k = 1; k <= 6; ++k)
                dp[i + 21 - j - (7 - k)][k] |= dp[i][j];
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        while (n >= 1000000)
            n -= (n - 10000) / 14 * 14;
        std::cout << (std::count(dp[n], dp[n] + 7, true) ? "YES" : "NO") << std::endl;
    }
    return 0;
}