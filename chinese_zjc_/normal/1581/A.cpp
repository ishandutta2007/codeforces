// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int T, n;
int fact(int x) { return x <= 2 ? 1 : 1ll * x * fact(x - 1) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::cout << fact(2 * n) << std::endl;
    }
    return 0;
}