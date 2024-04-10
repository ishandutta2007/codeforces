// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> to[200005], g;
bool vis[200005];
int n, m, a[200005], x[200005], y[200005], fa[200005], fe[200005], dfn[200005], end[200005], tim;
std::map<int, int> h[200005];
struct cmp
{
    bool operator()(const int &A, const int &B) { return end[A] < end[B]; }
};
std::set<int, cmp> son[200005];
bool in(int u, int v, int w)
{
    if (fa[v] == u)
        return dfn[v] <= dfn[w] && dfn[w] <= end[v];
    else
        return !(dfn[u] <= dfn[w] && dfn[w] <= end[u]);
}
bool check(int id) { return in(x[id], y[id], a[x[id]]) && in(y[id], x[id], a[y[id]]); }
void work(int id);
void update(int pos)
{
    if (a[pos] == pos)
        return;
    if (in(pos, fa[pos], a[pos]))
        work(h[pos][fa[pos]]);
    else
        work(h[pos][*son[pos].lower_bound(a[pos])]);
}
void work(int id)
{
    if (check(id))
    {
        std::swap(a[x[id]], a[y[id]]);
        g.push_back(id);
        vis[id] = true;
        update(x[id]);
        update(y[id]);
    }
}
// void massert(bool C)
// {
//     if (!C)
//     {
//         std::cout << "Bad" << std::endl;
//         exit(0);
//     }
// }
// void dfs(int pos, std::function<bool(int)> func)
// {
//     std::cout << pos << std::endl;
//     for (int i = 1; i <= n; ++i)
//         std::cout << func(i) << " \n"[i == n];
//     for (int i = 1; i <= n; ++i)
//         std::cout << a[i] << " \n"[i == n];
//     std::cout << std::flush;
//     for (auto i : g)
//         std::cout << i << ' ';
//     std::cout << std::endl;
//     static int timm = 0;
//     ++timm;
//     massert(timm <= 10000000);
//     while (!func(a[pos]))
//     {
//         while (vis[to[pos].back()])
//             to[pos].pop_back(), massert(!to[pos].empty());
//         int cur = to[pos].back(), v = x[cur] ^ y[cur] ^ pos;
//         vis[cur] = true;
//         to[pos].pop_back();
//         // std::cout << pos << ' ' << cur << std::endl;
//         dfs(pos, [&](const int &x)
//             { return in(pos, v, x); });
//         dfs(v, [&](const int &x)
//             { return in(v, pos, x); });
//         std::swap(a[pos], a[v]);
//         g.push_back(cur);
//     }
// }
void init(int now)
{
    vis[now] = true;
    dfn[now] = ++tim;
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        init(i);
        son[now].insert(i);
    }
    end[now] = tim;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> x[i] >> y[i];
        to[x[i]].push_back(y[i]);
        to[y[i]].push_back(x[i]);
        h[x[i]][y[i]] = i;
        h[y[i]][x[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            init(i);
    std::fill(vis + 1, vis + 1 + m, false);
    for (int i = 1; i <= n; ++i)
        update(i);
    for (auto i : g)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}