// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            static char c;
            std::cin >> c;
            switch (c)
            {
            case 'B':
            case 'W':
            case 'G':
                break;
            default:
                std::cout << "#Color" << std::endl;
                return 0;
            }
        }
    std::cout << "#Black&White" << std::endl;
    return 0;
}