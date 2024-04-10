// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, dp[65];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = 4llu * dp[i - 1] * 4llu * dp[i - 1] % MOD;
    std::cout << dp[n] * 6llu % MOD << std::endl;
    return 0;
}