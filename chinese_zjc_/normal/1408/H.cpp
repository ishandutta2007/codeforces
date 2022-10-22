// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[500005], lim, ans;
std::vector<int> app[500005];
std::vector<std::pair<int, int>> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        std::cin >> n;
        app[0].clear();
        for (int i = 1; i <= n; ++i)
            app[i].clear(), app[i].push_back(0);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], app[a[i]].push_back(i);
        for (int i = 1; i <= n; ++i)
            app[i].push_back(n + 1);
        if (app[0].empty())
        {
            std::cout << ans << std::endl;
            continue;
        }
        lim = app[0][app[0].size() / 2];
        g.clear();
        for (int i = 1; i <= n; ++i)
        {
            int l = *--std::upper_bound(app[i].begin(), app[i].end(), lim),
                r = *std::upper_bound(app[i].begin(), app[i].end(), lim);
            g.push_back({std::lower_bound(app[0].begin(), app[0].end(), l) - app[0].begin(),
                         app[0].end() - std::lower_bound(app[0].begin(), app[0].end(), r)});
        }
        std::sort(g.begin(), g.end());
        std::reverse(g.begin(), g.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> que;
        std::vector<std::pair<int, int>>::iterator j = g.begin();
        for (int i = app[0].size() / 2; i; --i)
        {
            while (j != g.end() && j->first == i)
                que.push(j++->second);
            if (!que.empty())
                que.pop(), ++ans;
        }
        while (j != g.end())
            que.push(j++->second);
        for (int i = 1; i <= int(app[0].size() / 2); ++i)
        {
            while (!que.empty() && que.top() < i)
                que.pop();
            if (!que.empty())
                que.pop(), ++ans;
        }
        std::cout << std::min(int(app[0].size() / 2), ans) << std::endl;
    }
    return 0;
}