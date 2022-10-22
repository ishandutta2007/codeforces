// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, a[2], b[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0, x; i != n; ++i)
        std::cin >> x, ++a[x & 1];
    for (int i = 0, x; i != m; ++i)
        std::cin >> x, ++b[x & 1];
    std::cout << std::min(a[0], b[1]) + std::min(a[1], b[0]) << std::endl;
    return 0;
}