// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a, b;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> a >> b;
        std::vector<int> l, r;
        l.push_back(a);
        r.push_back(b);
        for (int i = n; i > a && l.size() < n / 2; --i)
            if (i != b)
                l.push_back(i);
        for (int i = 1; i < b && r.size() < n / 2; ++i)
            if (i != a)
                r.push_back(i);
        if (l.size() != n / 2 || r.size() != n / 2)
            std::cout << -1 << std::endl;
        else
        {
            for (auto i : l)
                std::cout << i << ' ';
            for (auto i : r)
                std::cout << i << ' ';
            std::cout << std::endl;
        }
    }
    return 0;
}