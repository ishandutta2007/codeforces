// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, a[1005], b[1005], from[1005];
bool vis[1005];
std::vector<int> to[1005];
bool check(long long now)
{
    std::fill(vis + 1, vis + 1 + n, false);
    vis[1] = true;
    std::vector<int> g;
    g.push_back(1);
    auto add = [&](int x, std::vector<int> &res)
    {
        for (; ~x; x = from[x])
            res.push_back(x);
    };
    auto work = [&](const std::vector<int> &x)
    {
        for (auto i : x)
            if (!vis[i])
                vis[i] = true, g.push_back(i), now += b[i];
    };
    while (!g.empty())
    {
        std::fill(from + 1, from + 1 + n, -1);
        std::vector<std::pair<int, long long>> s;
        for (int k = 1; k <= n; ++k)
            if (vis[k])
                for (auto i : to[k])
                    if (!vis[i] && now > a[i])
                        from[i] = k, s.push_back({i, now + b[i]});
        g.pop_back();
        while (!s.empty())
        {
            std::pair<int, long long> now = s.back();
            s.pop_back();
            for (auto i : to[now.first])
            {
                if (from[now.first] == i)
                    continue;
                if (vis[i])
                {
                    std::vector<int> res;
                    add(now.first, res);
                    work(res);
                    goto nextcase;
                }
                if (~from[i])
                {
                    std::vector<int> res;
                    add(now.first, res);
                    add(i, res);
                    work(res);
                    goto nextcase;
                }
                if (now.second > a[i])
                {
                    from[i] = now.first;
                    s.push_back({i, now.second + b[i]});
                }
            }
        }
    nextcase:;
    }
    return std::count(vis + 1, vis + 1 + n, true) == n;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            to[i].clear();
        for (int i = 2; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 2; i <= n; ++i)
            std::cin >> b[i];
        for (int i = 1, x, y; i <= m; ++i)
            std::cin >> x >> y, to[x].push_back(y), to[y].push_back(x);
        int l = 2, r = 1000000001;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}