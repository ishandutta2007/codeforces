// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    n %= 4;
    switch (n)
    {
    case 0:
        std::cout << 0 << std::endl;
        break;
    case 1:
        std::cout << 1 << std::endl;
        break;
    case 2:
        std::cout << 1 << std::endl;
        break;
    case 3:
        std::cout << 0 << std::endl;
        break;
    }
    return 0;
}