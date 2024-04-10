// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, fa[10005], ga[10005], dis[105][105], lst[105];
bool d[105][105][105], vis[105];
char c;
std::vector<int> to[105];
std::vector<std::pair<int, int>> ans;
int id(int x, int y) { return x * n + y; }
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
int gind(int now) { return now == ga[now] ? now : ga[now] = gind(ga[now]); }
bool build(int now, int fa)
{
    for (int i = 0; i != n; ++i)
        if (d[fa][i][now])
        {
            if (vis[i])
                return false;
            vis[i] = true;
            if (!build(i, now))
                return false;
            ans.push_back({now, i});
        }
    return true;
}
bool check()
{
    if (int(ans.size()) != n - 1)
        return false;
    for (int i = 0; i != n; ++i)
        to[i].clear();
    for (auto i : ans)
        to[i.first].push_back(i.second), to[i.second].push_back(i.first);
    for (int i = 0; i != n; ++i)
    {
        std::fill(dis[i], dis[i] + n, -1);
        std::queue<int> que;
        que.push(i);
        dis[i][i] = 0;
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (auto j : to[now])
                if (!~dis[i][j])
                    dis[i][j] = dis[i][now] + 1, que.push(j);
        }
    }
    std::iota(ga, ga + n * n, 0);
    for (int i = 0; i != n; ++i)
    {
        std::fill(lst, lst + n, -1);
        for (int j = 0, t; j != n; lst[dis[i][j]] = j, ++j)
            if (~(t = lst[dis[i][j]]))
            {
                int min = std::min({gind(id(i, j)), gind(id(i, t)), gind(id(j, i)), gind(id(t, i))});
                ga[gind(id(i, j))] = ga[gind(id(i, t))] = ga[gind(id(j, i))] = ga[gind(id(t, i))] = min;
            }
    }
    for (int i = 0; i != n * n; ++i)
        if (find(i) != gind(i))
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::iota(fa, fa + n * n, 0);
        for (int i = 0; i != n; ++i)
            for (int j = i; ++j != n;)
                for (int k = 0; k != n; ++k)
                {
                    std::cin >> c;
                    if ((d[i][j][k] = d[j][i][k] = c == '1'))
                    {
                        int min = std::min({find(id(i, k)), find(id(j, k)), find(id(k, i)), find(id(k, j))});
                        fa[find(id(i, k))] = fa[find(id(j, k))] = fa[find(id(k, i))] = fa[find(id(k, j))] = min;
                    }
                }
        for (int i = 0; i != n; ++i)
            for (int j = i; ++j != n;)
                for (int k = 0; k != n; ++k)
                    if ((find(id(i, k)) == find(id(j, k))) ^ d[i][j][k])
                    {
                        std::cout << "No" << std::endl;
                        goto next;
                    }
        for (int i = 1; i != n; ++i)
        {
            ans = {{0, i}};
            std::fill(vis, vis + n, false);
            vis[i] = vis[0] = true;
            if (build(0, i) && build(i, 0) && check())
            {
                std::cout << "Yes" << std::endl;
                for (auto j : ans)
                    std::cout << j.first + 1 << ' ' << j.second + 1 << std::endl;
                goto next;
            }
        }
        std::cout << "No" << std::endl;
    next:;
    }
    return 0;
}