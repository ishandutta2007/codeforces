// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const int MOD = 998244353;
int n, p[1000005], q[1000005], ans;
std::vector<int> a[1000005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        static int m, x;
        std::cin >> m;
        for (int j = 0; j != m; ++j)
            std::cin >> x, a[i].push_back(x);
    }
    for (int i = 0, P = power(n, MOD - 2); i != n; ++i)
        for (int j = 0, PP = P * power(a[i].size(), MOD - 2) % MOD; j != (int)a[i].size(); ++j)
            p[a[i][j]] += PP, q[a[i][j]] += P;
    for (int i = 1; i <= 1000000; ++i)
        p[i] %= MOD, q[i] %= MOD, ans += p[i] * q[i] % MOD;
    std::cout << ans % MOD << std::endl;
    return 0;
}