// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
std::string s, c[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> s;
        c[0].clear();
        c[1].clear();
        for (auto i : s)
            c[i & 1].push_back(i);
        std::merge(c[0].begin(), c[0].end(), c[1].begin(), c[1].end(), s.begin());
        std::cout << s << std::endl;
    }
    return 0;
}