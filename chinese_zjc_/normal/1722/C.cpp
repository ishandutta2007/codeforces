// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, c[3];
std::set<std::string> a[3];
std::map<std::string, int> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::fill(c, c + 3, 0);
        a[0].clear();
        a[1].clear();
        a[2].clear();
        g.clear();
        for (int k = 0; k != 3; ++k)
            for (int i = 0; i != n; ++i)
            {
                static std::string s;
                std::cin >> s;
                a[k].insert(s);
                ++g[s];
            }
        for (auto i : g)
        {
            int v = i.second == 3 ? 0 : (i.second == 2 ? 1 : 3);
            for (int j = 0; j != 3; ++j)
                if (a[j].count(i.first))
                    c[j] += v;
        }
        std::cout << c[0] << ' ' << c[1] << ' ' << c[2] << std::endl;
    }
    return 0;
}