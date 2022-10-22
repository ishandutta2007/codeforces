// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, k, fact[1000005], ifact[1000005], dp[1000005], sum[1000005], ans;
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
void add(int &A, int B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    fact[0] = 1;
    for (long long i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = power(fact[n], MOD - 2);
    for (long long i = n; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    dp[0] = 1;
    ans = 1ll * fact[k] * ifact[k + 1] % MOD * fact[n - 1] % MOD * (n - k - 1) % MOD;
    sum[0] = 1;
    for (int i = 1; i + k + 1 < n; ++i)
    {
        // for (int j = i - 1; j >= i - k && j >= 0; --j)
        //     add(dp[i], 1ll * dp[j] * ifact[j] % MOD * fact[i - 1] % MOD);
        dp[i] = (sum[i - 1] - (i - k - 1 < 0 ? 0ll : sum[i - k - 1]) + MOD) * fact[i - 1] % MOD;
        sum[i] = (sum[i - 1] + 1ll * dp[i] * ifact[i]) % MOD;
        int br = 1ll * dp[i] * ifact[i] % MOD * fact[i + k] % MOD;
        add(ans, 1ll * br * ifact[i + k + 1] % MOD * fact[n - 1] % MOD * (n - i - k - 1) % MOD);
    }
    std::cout << ans << std::endl;
    return 0;
}