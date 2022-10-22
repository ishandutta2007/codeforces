// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int dp[505][505], n, k, power[505][505], C[505][505], ans;
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        power[i][0] = 1;
        for (int j = 1; j <= n; ++j)
            power[i][j] = 1ll * power[i][j - 1] * i % MOD;
    }
    for (int i = 0; i <= n; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (j < i)
                dp[i][j] = (power[j][i] - power[j - 1][i] + MOD) % MOD;
            if (j >= i)
                for (int l = 0; l <= i; ++l)
                    dp[i][j] = (dp[i][j] + 1ll * dp[i - l][j - i + 1] * C[i][l] % MOD * power[i - 1][l]) % MOD;
        }
    }
    ans = 0;
    for (int i = 1; i <= k; ++i)
        ans = (ans + dp[n][i]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}