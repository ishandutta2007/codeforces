// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
bool f[100005];
std::vector<int> p;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    for (int i = 2; i <= 100000; ++i)
    {
        if (!f[i])
            p.push_back(i);
        for (int j : p)
        {
            if (i * j > 100000)
                break;
            f[i * j] = true;
            if (i % j == 0)
                break;
        }
    }
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cout << p[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}