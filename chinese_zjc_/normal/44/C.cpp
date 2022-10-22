// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int t[105], n, m;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1, a, b; i <= m; ++i)
    {
        std::cin >> a >> b;
        for (int j = a; j <= b; ++j)
            ++t[j];
    }
    for (int i = 1; i <= n; ++i)
        if (t[i] != 1)
            return std::cout << i << ' ' << t[i] << std::endl, 0;
    std::cout << "OK" << std::endl;
    return 0;
}