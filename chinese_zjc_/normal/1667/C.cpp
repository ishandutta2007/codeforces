// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
std::vector<std::pair<int, int>> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    int l = (n + 2) / 3;
    switch (n % 3)
    {
    case 0:
        std::cout << l * 2 << std::endl;
        for (int i = 0; i != l; ++i)
            std::cout << i + 1 << ' ' << l - i << std::endl;
        for (int i = 1; i != l; ++i)
            std::cout << n - i << ' ' << n - l + i << std::endl;
        std::cout << n << ' ' << n << std::endl;
        break;
    case 1:
    case 2:
        std::cout << l * 2 - 1 << std::endl;
        for (int i = 0; i != l; ++i)
            std::cout << i + 1 << ' ' << l - i << std::endl;
        for (int i = 1; i != l; ++i)
            std::cout << n - i + 1 << ' ' << n - l + i + 1 << std::endl;
        break;
    }
    return 0;
}