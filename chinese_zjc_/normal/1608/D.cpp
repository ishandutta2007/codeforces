// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, fact[100005], ifact[100005], pow2[100005], ans;
std::string s[100005];
int cnt[3][3], l[3], r[3], t[128];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * A * res % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
int C(int n, int m) { return 0 <= m && m <= n ? 1ll * fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i];
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    fact[0] = 1;
    for (long long i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = power(fact[n], MOD - 2);
    for (long long i = n; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    t['?'] = 0;
    t['W'] = 1;
    t['B'] = 2;
    for (int i = 1; i <= n; ++i)
        ++cnt[t[int(s[i][0])]][t[int(s[i][1])]], ++l[t[int(s[i][0])]], ++r[t[int(s[i][1])]];
    for (int i = 0; i <= n; ++i)
        ans = (ans + 1ll * C(l[0], i - l[1]) * C(r[0], i - r[2])) % MOD;
    if (!cnt[1][1] && !cnt[2][2])
    {
        ans = (ans + MOD - pow2[cnt[0][0]]) % MOD;
        if (!l[1] && !r[2])
            ++ans;
        if (!l[2] && !r[1])
            ++ans;
    }
    std::cout << ans % MOD << std::endl;
    return 0;
}