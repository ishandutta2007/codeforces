// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[1000005], from[1000005];
long long ans;
char b[1000005];
std::vector<int> p;
std::vector<std::pair<int, int>> app[1000005], sta, w[1000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    for (int i = 2; i <= 1000000; ++i)
    {
        if (!from[i])
        {
            from[i] = i;
            p.push_back(i);
        }
        for (auto j : p)
        {
            if (i * j > 1000000)
                break;
            from[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
    for (int i = 1; i <= n; ++i)
        while (a[i] > 1)
        {
            int v = from[a[i]], tim = 0;
            while (a[i] % v == 0)
                a[i] /= v, ++tim;
            if (app[v].empty())
                app[v].emplace_back(0, 0);
            app[v].push_back({(b[i] == '/' ? -1 : +1) * tim, i});
        }
    for (int i = 1; i <= 1000000; ++i)
    {
        if (app[i].empty())
            continue;
        for (int j = 1; j != (int)app[i].size(); ++j)
            app[i][j].first += app[i][j - 1].first;
        app[i].push_back({INT_MIN, n + 1});
        sta.clear();
        sta.emplace_back(INT_MIN, n + 1);
        for (int j = app[i].size() - 1; j--;)
        {
            while (sta.back().first >= app[i][j].first)
                sta.pop_back();
            w[app[i][j + 1].second].emplace_back(sta.back().second, app[i][j].second);
            sta.emplace_back(app[i][j]);
        }
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
    que.push({n + 1, 0});
    for (int i = n; i; --i)
    {
        for (auto j : w[i])
            que.push(j);
        while (que.top().second >= i)
            que.pop();
        ans += que.top().first - i;
        // std::cout << que.top().first << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}