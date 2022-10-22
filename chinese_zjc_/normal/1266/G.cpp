// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
int n, dp[2000005], fact[2000005], ifact[2000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    fact[0] = 1;
    for (long long i = 1; i <= 2 * n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[2 * n] = power(fact[2 * n], MOD - 2);
    for (long long i = 2 * n; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    dp[0] = n;
    for (int i = 1; i < n; ++i)
        dp[i] = 1ll * fact[n] * ifact[n - i + 1] % MOD * ((1ll * (n - i) * (n - i) + 1) % MOD) % MOD;
    for (int i = n; i != 2 * n; ++i)
        dp[i] = (fact[n] - dp[i - n] + MOD) % MOD;
    long long ans = (1ll * fact[n] * n + 1) % MOD * n % MOD * fact[n] % MOD * ifact[2] % MOD;
    for (long long i = 1; i < 2 * n; ++i)
        ans = (ans - dp[i] * i % MOD + MOD) % MOD;
    std::cout << ans << std::endl;
    return 0;
}