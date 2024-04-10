// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, MOD, dp[4000005], cha[4000005];
void add(int &A, int B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> MOD;
    cha[1] = 1;
    cha[2] = MOD - 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = cha[i];
        cha[i + 1] = (0ll + cha[i + 1] + dp[i] + cha[i]) % MOD;
        for (int j = 2; i * j <= n; ++j)
        {
            add(cha[i * j], dp[i]);
            add(cha[std::min(n + 1, i * j + j)], MOD - dp[i]);
        }
    }
    std::cout << dp[n] << std::endl;
    return 0;
}