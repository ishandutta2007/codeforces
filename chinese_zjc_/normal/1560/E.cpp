// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, app[26];
std::size_t lst[26];
std::string t, s, g;
bool check()
{
    bool del[26];
    memset(del, false, sizeof(del));
    std::string tt;
    for (auto i : g)
    {
        for (auto j : s)
            if (!del[j - 'a'])
                tt.push_back(j);
        del[i - 'a'] = true;
    }
    return tt == t;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> t;
        memset(app, 0, sizeof(app));
        memset(lst, -1, sizeof(lst));
        for (std::size_t i = 0; i != t.size(); ++i)
            ++app[t[i] - 'a'], lst[t[i] - 'a'] = i;
        g.resize(26);
        std::iota(g.begin(), g.end(), 'a');
        std::sort(g.begin(), g.end(), [&](const char &A, const char &B)
                  { return lst[A - 'a'] < lst[B - 'a']; });
        while (!~lst[g.back() - 'a'])
            g.pop_back();
        for (std::size_t i = 0; i != g.size(); ++i)
            app[g[i] - 'a'] /= i + 1;
        s = t.substr(0, std::accumulate(app, app + 26, 0));
        if (check())
            std::cout << s << ' ' << g << std::endl;
        else
            std::cout << -1 << std::endl;
    }
    return 0;
}