// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long u, v;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> u >> v;
        std::cout << -u * u << ' ' << v * v << std::endl;
    }
    return 0;
}