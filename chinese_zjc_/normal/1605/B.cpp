// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
char c[1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> c;
        int cnt0 = std::count(c, c + n, '0');
        std::vector<int> a;
        for (int i = 0; i != cnt0; ++i)
            if (c[i] == '1')
                a.push_back(i);
        for (int i = cnt0; i != n; ++i)
            if (c[i] == '0')
                a.push_back(i);
        if (a.empty())
            std::cout << 0 << std::endl;
        else
        {
            std::cout << 1 << std::endl
                      << a.size();
            for (auto i : a)
                std::cout << ' ' << i + 1;
            std::cout << std::endl;
        }
    }
    return 0;
}