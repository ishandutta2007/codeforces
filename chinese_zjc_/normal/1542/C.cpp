// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int T;
unsigned long long n, p[50], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    for (unsigned long long i = 1, j = 1; i <= 43; ++i)
        p[i] = j = i / std::__gcd(i, j) * j;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        ans = n;
        for (int i = 1; i < 43; ++i)
            ans = (ans + n / p[i]) % MOD;
        std::cout << ans << std::endl;
    }
    return 0;
}