// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, p[205], fa[205];
std::vector<int> to[205], ans;
struct edge
{
    int a, b, v;
    friend bool operator<(const edge &A, const edge &B) { return A.v < B.v; }
};
std::vector<edge> e;
std::vector<std::pair<int, int>> g;
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
void dfs(int now)
{
    while (!to[now].empty())
    {
        int i = to[now].back();
        to[now].pop_back();
        dfs(i);
        if (now == p[i])
            ans.push_back(i);
        g.push_back({now, i});
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::iota(fa + 1, fa + 1 + n, 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> p[i];
            to[p[i]].push_back(i);
            fa[find(i)] = find(p[i]);
        }
        e.clear();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                e.push_back({i, j, std::abs(i - j)});
        std::sort(e.begin(), e.end());
        for (auto i : e)
            if (find(i.a) != find(i.b))
            {
                fa[find(i.a)] = find(i.b);
                to[i.a].push_back(i.b);
                to[i.b].push_back(i.a);
            }
        dfs(1);
        for (int i = 1; i <= n; ++i)
            to[i].clear();
        std::reverse(ans.begin(), ans.end());
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
        ans.clear();
        // std::reverse(g.begin(), g.end());
        // for (auto i : g)
        //     std::cout << i.first << ' ' << i.second << std::endl;
        // g.clear();
    }
    return 0;
}