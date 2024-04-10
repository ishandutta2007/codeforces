// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005];
char b[200005];
std::vector<int> s[200005];
std::multiset<int> t;
bool ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        ans = true;
        for (int i = 1; i <= n; ++i)
            s[i].clear();
        for (int i = 1; i <= n; ++i)
            if (b[i] == 'R')
            {
                if (a[i] <= n)
                    s[std::max(1, a[i])].push_back(n);
                else
                    ans = false;
            }
            else
            {
                if (1 <= a[i])
                    s[1].push_back(std::min(a[i], n));
                else
                    ans = false;
            }
        t.clear();
        if (ans)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (auto j : s[i])
                    t.insert(j);
                if (t.empty() || *t.begin() < i)
                {
                    ans = false;
                    break;
                }
                t.erase(t.begin());
            }
        }
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}