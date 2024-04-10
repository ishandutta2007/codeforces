// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, ans1, ans2 = 1, b[2000005];
long long fact[500005];
int C1(int x) { return x * (x - 1ll) / 2 % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    fact[0] = 1;
    for (int i = 1, a; i <= n; ++i)
        std::cin >> a, ++b[1000000 - a], --b[1000000 + a], fact[i] = fact[i - 1] * i % MOD;
    int tot = 0;
    for (int i = 0; i <= 2000000; ++i)
    {
        b[i] += i >= 2 ? b[i - 2] : 0;
        ans1 = (ans1 + (i + 1 - 1000000ll + MOD) * (C1(tot + b[i]) - C1(tot) + MOD)) % MOD;
        ans2 = ans2 * fact[b[i]] % MOD;
        tot = (tot + b[i]) % MOD;
    }
    std::cout << ans1 << ' ' << ans2 << std::endl;
    return 0;
}