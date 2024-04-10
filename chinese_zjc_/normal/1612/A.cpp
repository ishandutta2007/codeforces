// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, x, y;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> x >> y;
        if ((x + y) & 1)
        {
            std::cout << -1 << ' ' << -1 << std::endl;
            continue;
        }
        int mid = (x + y) / 2;
        bool flag = false;
        for (int i = 0; i <= x; ++i)
            if (mid - i <= y)
            {
                std::cout << i << ' ' << mid - i << std::endl;
                flag = true;
                break;
            }
        if (!flag)
            std::cout << -1 << ' ' << -1 << std::endl;
    }
    return 0;
}