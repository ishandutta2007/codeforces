// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> p;
int T, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 1; p.size() < std::size_t(1000); ++i)
    {
        if (i % 3 == 0 || i % 10 == 3)
            continue;
        p.push_back(i);
    }
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::cout << p[n - 1] << std::endl;
    }
    return 0;
}