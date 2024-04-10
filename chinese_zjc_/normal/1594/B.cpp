// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int T, n, k;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        int res = 0, v = 1;
        while (k)
        {
            if (k & 1)
                res = (res + v) % MOD;
            v = 1ll * v * n % MOD;
            k >>= 1;
        }
        std::cout << res << std::endl;
    }
    return 0;
}