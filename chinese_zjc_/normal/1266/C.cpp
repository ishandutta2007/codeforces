// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (n == 1 && m == 1)
        return std::cout << 0 << std::endl, 0;
    if (m == 1)
        for (int i = 1; i <= n; ++i)
            std::cout << i + m << std::endl;
    else
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cout << (j + n) * i << " \n"[j == m];
    return 0;
}