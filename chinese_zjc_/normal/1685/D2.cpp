// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, p[205], fa[205], tot, tim[205];
bool vis[205];
std::vector<int> ans;
struct edge
{
    int a, b, v;
    friend bool operator<(const edge &A, const edge &B) { return A.v < B.v; }
};
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
bool check()
{
    if (int(ans.size()) == n)
        return true;
    std::vector<int> g;
    std::iota(fa + 1, fa + 1 + n, 1);
    std::fill(vis, vis + 1 + n, false);
    std::fill(tim, tim + 1 + n, 0);
    std::vector<edge> gg;
    for (auto i : ans)
        vis[i] = true;
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            fa[find(i)] = find(p[i]);
    for (std::size_t i = 1; i != ans.size(); ++i)
    {
        fa[find(ans[i - 1])] = find(ans[i]);
        if (ans[i - 1] < p[ans[i]])
            for (int l = ans[i - 1], r = p[ans[i]]; l < r; ++l)
                ++tim[l];
        else if (ans[i - 1] > p[ans[i]])
            for (int l = p[ans[i]], r = ans[i - 1]; l < r; ++l)
                ++tim[l];
    }
    for (int i = 1; i < n; ++i)
        if (tim[i] > 2)
            return false;
    for (int i = 1; i < n; ++i)
        if (tim[i] == 1)
            fa[find(i)] = find(i + 1);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            g.push_back(i), g.push_back(p[i]);
    g.push_back(p[ans.front()]);
    g.push_back(ans.back());
    std::sort(g.begin(), g.end());
    g.erase(std::unique(g.begin(), g.end()), g.end());
    for (std::size_t i = 1; i != g.size(); ++i)
        gg.push_back({g[i - 1], g[i], std::abs(g[i] - g[i - 1])});
    std::sort(gg.begin(), gg.end());
    int res = n - std::count(tim + 1, tim + 1 + n, 0);
    for (auto i : gg)
        if (find(i.a) != find(i.b))
            res += i.v, fa[find(i.a)] = find(i.b);
    // std::cout << res << std::endl;
    // for (auto i : g)
    //     std::cout << i << std::endl;
    return res == tot - 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> p[i];
        // for (int i = 1; i <= n; ++i)
        //     std::cout << p[i] << ' ' << i << std::endl;
        // if (p[1] == 44 && p[2] == 24 && p[3] == 40)
        //     for (int i = 1; i <= n; ++i)
        //         std::cout << p[i] << " \n"[i == n];
        tot = 0;
        std::fill(vis, vis + 1 + n, false);
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
            {
                int j = i;
                do
                    vis[j] = true, j = p[j];
                while (j != i);
                ++tot;
            }
        ans.clear();
        for (int i = 1; i <= n; ++i)
        {
            ans.emplace_back();
            for (int j = 1; j <= n; ++j)
                if (!std::count(ans.begin(), ans.end(), j) && (ans.back() = j) && check())
                    break;
        }
        // if ((p[1] == 28 && p[2] == 14 && p[3] == 23) ||
        //     (p[1] == 27 && p[2] == 23 && p[3] == 26) ||
        //     (p[1] == 48 && p[2] == 20 && p[3] == 44))
        //     continue;
        // std::cout << std::endl;
        // for (auto i : ans)
        //     std::cout << p[i] << ' ' << i << '\n';
        for (auto i : ans)
            std::cout << i << " \n"[i == ans.back()];
    }
    return 0;
}