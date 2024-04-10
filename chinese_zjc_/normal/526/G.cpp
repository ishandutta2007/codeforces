// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m;
std::vector<int> to[100005], V[100005];
typedef std::greater<std::pair<int, int>> cmp;
int find_root(int st)
{
    bool vis[100005];
    memset(vis, false, sizeof(vis));
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> que;
    std::pair<int, int> now;
    que.push({0, st});
    while (!que.empty())
    {
        now = que.top();
        que.pop();
        for (std::size_t i = 0; i != to[now.second].size(); ++i)
        {
            if (vis[to[now.second][i]])
                continue;
            vis[to[now.second][i]] = true;
            que.push({now.first + V[now.second][i], to[now.second][i]});
        }
    }
    return now.second;
}
struct TREE
{
    int fa[20][100005], dis[100005], maxdis[100005], heavy[100005], rk[100005], root;
    std::vector<std::pair<int, int>> s;
    std::vector<int> pre;
    void dfs1(int now)
    {
        for (int i = 1; i != 20; ++i)
            fa[i][now] = fa[i - 1][fa[i - 1][now]];
        maxdis[now] = dis[now];
        for (std::size_t i = 0; i != to[now].size(); ++i)
        {
            if (to[now][i] == fa[0][now])
                continue;
            fa[0][to[now][i]] = now;
            dis[to[now][i]] = dis[now] + V[now][i];
            dfs1(to[now][i]);
            maxdis[now] = std::max(maxdis[now], maxdis[to[now][i]]);
            if (maxdis[heavy[now]] < maxdis[to[now][i]])
                heavy[now] = to[now][i];
        }
        for (auto i : to[now])
        {
            if (i == fa[0][now] || i == heavy[now])
                continue;
            s.push_back({maxdis[i] - dis[now], i});
        }
    }
    void dfs2(int now)
    {
        if (heavy[now])
            rk[heavy[now]] = rk[now], dfs2(heavy[now]);
        for (auto i : to[now])
        {
            if (i == fa[0][now] || i == heavy[now])
                continue;
            rk[i] = std::lower_bound(s.begin(), s.end(), std::make_pair(maxdis[i] - dis[now], i), cmp()) - s.begin();
            dfs2(i);
        }
    }
    void init()
    {
        dfs1(root);
        s.push_back({maxdis[root], root});
        std::sort(s.begin(), s.end(), cmp());
        dfs2(root);
        pre.push_back(0);
        for (auto i : s)
            pre.push_back(pre.back() + i.first);
    }
    int query(int x, int y)
    {
        y = std::min(int(s.size()), 2 * y - 1);
        if (rk[x] < y)
            return pre[y];
        else
        {
            int z = x;
            for (int i = 20; i--;)
                if (rk[fa[i][z]] >= y)
                    z = fa[i][z];
            z = fa[0][z];
            return std::max(pre[y] + maxdis[x] - maxdis[z], pre[y - 1] + maxdis[x] - dis[z]);
        }
    }
} T[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1, x, y, z; i != n; ++i)
        std::cin >> x >> y >> z, to[x].push_back(y), to[y].push_back(x), V[x].push_back(z), V[y].push_back(z);
    T[0].root = find_root(1);
    T[1].root = find_root(T[0].root);
    T[0].init();
    T[1].init();
    for (int i = 1, x, y, ans = 0; i <= m; ++i)
    {
        std::cin >> x >> y;
        x = (x + ans - 1) % n + 1;
        y = (y + ans - 1) % n + 1;
        std::cout << (ans = std::max(T[0].query(x, y), T[1].query(x, y))) << std::endl;
    }
    return 0;
}