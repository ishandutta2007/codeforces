// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int MOD, n, k, dp[1005][100], pow10k[1005], pow10m[1005], ans;
void add(int &A, int B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> MOD;
    pow10k[0] = pow10m[0] = 1;
    for (int i = 1; i <= 1000; ++i)
        pow10k[i] = pow10k[i - 1] * 10 % k,
        pow10m[i] = pow10m[i - 1] * 10ll % MOD;
    for (int o = 0; o != n; ++o)
        for (int i = 1; i != 10; ++i)
            add(dp[o + 1][i * pow10k[o] % k], 1);
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j != k; ++j)
            for (int l = 0; l != 10; ++l)
                add(dp[i][(j + l * pow10k[i - 1]) % k], dp[i - 1][j]);
    for (int i = 1; i != n; ++i)
        add(ans, dp[i][0] * 9ll % MOD * pow10m[n - i - 1] % MOD);
    add(ans, dp[n][0]);
    std::cout << ans << std::endl;
    return 0;
}