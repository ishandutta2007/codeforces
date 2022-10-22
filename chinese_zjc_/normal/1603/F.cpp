// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const long long MOD = 998244353;
int T, n, k, x, pow2[10000005], pw[10000005], ans;
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
signed main()
{
    std::ios::sync_with_stdio(false);
    pow2[0] = pw[0] = 1;
    for (int i = 1; i <= 10000000; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k >> x;
        if (x == 0)
        {
            ans = 1;
            if (n > k)
                ans = 0;
            else
                for (int i = 0; i != n; ++i)
                    ans = ans * (pow2[k] - pow2[i] + MOD) % MOD;
            std::cout << ans << std::endl;
        }
        else
        {
            ans = 0;
            pw[1] = power(2, n);
            for (int i = 1; i <= k; ++i)
                pw[i] = 1ll * pw[i - 1] * pw[1] % MOD;
            for (int i = 1, sum = 1; i <= k; ++i)
            {
                ans = (ans + (i & 1 ? 1 : MOD - 1) * pw[k - i] % MOD * sum % MOD * pow2[k - i]) % MOD;
                sum = sum * (pow2[k - i] - 1ll) % MOD;
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}