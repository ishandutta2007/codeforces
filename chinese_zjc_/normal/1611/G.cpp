// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, ans;
char c;
std::vector<int> d[2][1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> c, c == '1' ? d[(i + j) & 1][i - j + m].push_back(i + j) : void();
        for (std::vector<int> *e = d[0]; e; e == d[0] ? e = d[1] : e = nullptr)
        {
            std::multiset<int> s;
            for (int i = n + m; i--;)
            {
                for (std::vector<int>::reverse_iterator j = e[i].rbegin(); j != e[i].rend(); ++j)
                {
                    std::multiset<int>::iterator iter = s.lower_bound(*j);
                    if (iter != s.end())
                        s.erase(iter);
                    s.insert(*j);
                }
                e[i].clear();
            }
            ans += s.size();
        }
        std::cout << ans << std::endl;
        ans = 0;
    }
    return 0;
}