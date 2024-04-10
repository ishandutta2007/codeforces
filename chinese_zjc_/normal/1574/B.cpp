// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, a[3], m;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        for (int i = 0; i != 3; ++i)
            std::cin >> a[i];
        std::cin >> m;
        std::sort(a, a + 3);
        if (a[0] + a[1] + a[2] - 3 < m)
            std::cout << "NO" << std::endl;
        else if (a[0] + a[1] >= a[2] - 1 - m)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}