// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long MOD;
int n, k, pow2[6405], C[85][85], bad[85][85], tot[85][85], f[85][85], ans;
int P(int n, int m)
{
    int res = 1;
    while (m--)
        res = 1ll * res * (n - m) % MOD;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> MOD;
    pow2[0] = 1;
    for (int i = 1; i <= 6400; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    for (int i = 0; i <= 80; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
        {
            tot[i][j] = pow2[i * j];
            for (int l = 0; l < j; ++l)
                tot[i][j] = (tot[i][j] + (MOD - C[j][l]) * tot[i][l]) % MOD;
        }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
        {
            f[i][j] = P(pow2[j] - 1, i);
            for (int l = 0; l < j; ++l)
                f[i][j] = (f[i][j] + (MOD - C[j][l]) * f[i][l]) % MOD;
        }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            for (int a = 0; a < i; ++a)
                for (int b = 0; b < j; ++b)
                    if (!((n & 1) && i == n && a == n - 1))
                        bad[i][j] = (bad[i][j] + (tot[a][b] - bad[a][b] + MOD) *
                                                     C[i][a] % MOD *
                                                     C[j][b] % MOD *
                                                     f[i - a][j - b] % MOD *
                                                     pow2[(i - a) * b]) %
                                    MOD;
    for (int i = 0; i <= k; ++i)
        ans = (ans + C[k][i] * (tot[n][i] - bad[n][i] + MOD)) % MOD;
    std::cout << ans << std::endl;
    return 0;
}