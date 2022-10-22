// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long x, y;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> x >> y;
        std::cout << (x - y == 1 ? "NO" : "YES") << std::endl;
    }
    return 0;
}