// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, app[1000005][2], ans, cnt;
struct edge
{
    int u, v, fa;
    bool w, ans;
} e[6000005];
void add(int x)
{
    if (e[x].u == e[x].v)
        return;
    if (app[e[x].u][e[x].w])
    {
        int y = app[e[x].u][e[x].w];
        // std::cout << e[x].u << ' ' << e[x].v << ' ' << e[x].w << ' ' << e[y].u << ' ' << e[y].v << ' ' << e[y].w << std::endl;
        app[e[y].u][e[y].w] = 0;
        app[e[y].v][e[y].w] = 0;
        ++cnt;
        e[cnt].u = e[x].v;
        e[x].ans = true;
        e[cnt].v = e[y].u ^ e[y].v ^ e[x].u;
        e[y].ans = e[y].v != e[cnt].v;
        e[cnt].w = e[x].w;
        e[x].fa = e[y].fa = cnt;
        add(cnt);
    }
    else if (app[e[x].v][e[x].w])
    {
        int y = app[e[x].v][e[x].w];
        // std::cout << e[x].u << ' ' << e[x].v << ' ' << e[x].w << ' ' << e[y].u << ' ' << e[y].v << ' ' << e[y].w << std::endl;
        app[e[y].u][e[y].w] = 0;
        app[e[y].v][e[y].w] = 0;
        ++cnt;
        e[cnt].u = e[x].u;
        e[x].ans = false;
        e[cnt].v = e[y].u ^ e[y].v ^ e[x].v;
        e[y].ans = e[y].v != e[cnt].v;
        e[cnt].w = e[x].w;
        e[x].fa = e[y].fa = cnt;
        add(cnt);
    }
    else
        app[e[x].u][e[x].w] = app[e[x].v][e[x].w] = x;
}
void work(int now)
{
    // std::cout << now << std::endl;
    if (app[now][0])
    {
        int t = app[now][0];
        e[t].ans = now == e[t].v;
        app[e[t].u][e[t].w] = app[e[t].v][e[t].w] = 0;
        work(now ^ e[t].u ^ e[t].v);
    }
    else if (app[now][1])
    {
        int t = app[now][1];
        e[t].ans = now == e[t].v;
        app[e[t].u][e[t].w] = app[e[t].v][e[t].w] = 0;
        work(now ^ e[t].u ^ e[t].v);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    cnt = m;
    for (int i = 1, tmp; i <= m; ++i)
    {
        std::cin >> e[i].u >> e[i].v >> tmp;
        e[i].w = --tmp;
        add(i);
    }
    // for (int i = 1; i <= cnt; ++i)
    //     if (!e[i].fa)
    //         std::cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << std::endl;
    for (int i = 1; i <= n; ++i)
        ans += bool(app[i][0]);
    for (int i = 1; i <= n; ++i)
        if (bool(app[i][0]) ^ bool(app[i][1]))
            work(i);
    for (int i = 1; i <= n; ++i)
        work(i);
    std::cout << ans << std::endl;
    for (int i = cnt; i; --i)
        e[i].ans ^= e[e[i].fa].ans;
    for (int i = 1; i <= m; ++i)
        std::cout << 1 + e[i].ans;
    std::cout << std::endl;
    return 0;
}