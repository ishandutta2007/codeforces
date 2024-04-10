// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, s, t, S, T, d[105], a[1005], b[1005], head[105], cnt, ans, dis[105], cur[105];
bool c[1005], vis[105];
struct edge
{
    int n, t, v;
} e[5005];
void add_edge(int A, int B, int C)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].v = C;
    head[A] = cnt++;
}
void add_flow(int A, int B, int C)
{
    add_edge(A, B, C);
    add_edge(B, A, 0);
}
void add_bound(int A, int B, int L, int R)
{
    d[A] -= L;
    d[B] += L;
    add_flow(A, B, R - L);
}
bool bfs(int x, int y)
{
    std::fill(dis + 1, dis + 1 + n, -1);
    std::queue<int> que;
    que.push(x);
    dis[x] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == y)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now, int end, int flow = INT_MAX)
{
    if (now == end || !flow)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (dis[e[i].t] == dis[now] + 1 && e[i].v)
        {
            int tmp = dfs(e[i].t, end, std::min(e[i].v, flow));
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
            if (!flow)
                break;
            if (e[i].v)
                dis[e[i].t] = -1;
        }
    return res;
}
int Dinic(int x, int y)
{
    int res = 0;
    while (bfs(x, y))
    {
        std::copy(head + 1, head + 1 + n, cur + 1);
        res += dfs(x, y);
    }
    return res;
}
void visit(int now)
{
    vis[now] = true;
    for (int i = head[now]; ~i; i = e[i].n)
        if (!vis[e[i].t] && e[i].v)
            visit(e[i].t);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s >> t;
    S = ++n;
    T = ++n;
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i] >> c[i];
    cnt = 0;
    std::fill(head + 1, head + 1 + n, -1);
    for (int i = 1; i <= m; ++i)
        if (c[i])
        {
            add_edge(a[i], b[i], 1);
            add_edge(b[i], a[i], m * 2);
        }
        else
            add_flow(a[i], b[i], m * 2);
    ans = Dinic(s, t);
    if (ans > m)
        return -1;
    visit(s);
    cnt = 0;
    std::fill(head + 1, head + 1 + n, -1);
    for (int i = 1; i <= m; ++i)
        if (c[i])
        {
            if (vis[a[i]] && !vis[b[i]])
                add_flow(a[i], b[i], m);
            else
                add_bound(a[i], b[i], 1, 99999999);
        }
    for (int i = 1; i <= n; ++i)
        if (d[i] > 0)
            add_flow(S, i, +d[i]);
        else
            add_flow(i, T, -d[i]);
    add_flow(t, s, m * 2);
    Dinic(S, T);
    Dinic(s, t);
    std::cout << ans << std::endl;
    for (int i = 1; i <= m; ++i)
        if (c[i])
        {
            int v = -1;
            for (int j = head[a[i]]; ~j; j = e[j].n)
                if (e[j].t == b[i])
                    v = e[j ^ 1].v;
            if (vis[a[i]] && !vis[b[i]])
                std::cout << v << ' ' << v << std::endl;
            else
                std::cout << v + 1 << ' ' << 1000000000 << std::endl;
        }
        else
            std::cout << 0 << ' ' << 1000000000 << std::endl;
    return 0;
}