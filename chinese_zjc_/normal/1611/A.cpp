// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string n;
int T;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        if (n.back() % 2 == 0)
            std::cout << 0 << std::endl;
        else if (n.front() % 2 == 0)
            std::cout << 1 << std::endl;
        else if (std::count_if(n.begin(), n.end(), [&](const char &x)
                               { return x % 2 == 0; }))
            std::cout << 2 << std::endl;
        else
            std::cout << -1 << std::endl;
    }
    return 0;
}