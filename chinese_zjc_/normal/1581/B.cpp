// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, k, T;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> k;
        k -= 2;
        if (n == 1 && m == 0 && k >= 0)
            std::cout << "YES" << std::endl;
        else if (m == n * (n - 1ll) / 2 && k >= 1)
            std::cout << "YES" << std::endl;
        else
            std::cout << ((m >= n - 1 && m <= n * (n - 1ll) / 2 && k >= 2) ? "YES" : "NO") << std::endl;
    }
    return 0;
}