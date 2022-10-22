// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, d[200005], h[200005];
std::vector<int> to[200005];
std::vector<std::pair<int, int>> ans;
void del(int now)
{
    if (h[now])
    {
        --d[now];
        --d[h[now]];
        ans.push_back({now, h[now]});
        del(h[now]);
    }
}
void dfs(int now, int fa = 0)
{
    std::vector<int> s[2];
    for (auto i : to[now])
    {
        if (i == fa)
            continue;
        dfs(i, now);
        s[d[i] & 1].push_back(i);
    }
    while (!s[d[now] & 1].empty())
    {
        h[now] = s[d[now] & 1].back();
        s[d[now] & 1].pop_back();
        --d[now];
        --d[h[now]];
        ans.push_back({now, h[now]});
        del(h[now]);
        h[now] = 0;
    }
    if (s[~d[now] & 1].size() == 1)
        h[now] = s[~d[now] & 1].back();
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans.clear();
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            to[i].clear();
        for (int i = 1, x, y; i != n; ++i)
        {
            std::cin >> x >> y;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        for (int i = 1; i <= n; ++i)
            d[i] = to[i].size(), h[i] = 0;
        dfs(1);
        if (int(ans.size()) == n - 1)
        {
            std::cout << "YES" << std::endl;
            for (auto i : ans)
                std::cout << i.first << ' ' << i.second << std::endl;
        }
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}