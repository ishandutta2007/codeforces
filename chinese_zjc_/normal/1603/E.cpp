// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, MOD, fact[205], ifact[205], dp[205][205][205], ans;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        A = 1ll * A * A % MOD;
        B >>= 1;
    }
    return res;
}
void ps(int &A, int B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> MOD;
    fact[0] = 1;
    for (long long i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = power(fact[n], MOD - 2);
    for (long long i = n; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    for (int a1 = n + 1; a1 >= n - 2 * std::sqrt(n); --a1)
    {
        for (int i = 1; i <= std::min(n, a1); ++i)
            dp[i][0][std::max(i + 2, a1 + 1)] = ifact[i];
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= a1; ++j)
                for (int k = a1 + 1; k <= n + 1; ++k)
                    for (int l = 0; dp[i][j][k] && k >= i + l + 1 && j + l * (k - a1) <= a1; ++l)
                        ps(dp[i + l][j + l * (k - a1)][std::max(i + l + 2, k + 1)], 1ll * dp[i][j][k] * ifact[l] % MOD);
        for (int i = 0; i <= a1; ++i)
            ps(ans, 1ll * dp[n][i][n + 2] * fact[n] % MOD);
        memset(dp, 0, sizeof(dp));
    }
    std::cout << ans << std::endl;
    return 0;
}