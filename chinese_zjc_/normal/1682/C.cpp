// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::map<int, int> map;
        for (int i = 1, x; i <= n; ++i)
            std::cin >> x, ++map[x];
        int a = 0, b = 0;
        for (auto i : map)
            if (i.second == 1)
                ++a;
            else
                ++b;
        if (a)
            std::cout << (a - 1) / 2 + 1 + b << std::endl;
        else
            std::cout << b << std::endl;
    }
    return 0;
}