// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, s[10005], a[10005], d[10005], u[10005], v[10005], w[10005], ecnt, head[10005], S, T, SS, TT,
    dis[10005], cur[10005];
struct edge
{
    int t, n, v;
} e[200005];
int add_edge(int A, int B, int C)
{
    e[ecnt].t = B;
    e[ecnt].n = head[A];
    e[ecnt].v = C;
    return head[A] = ecnt++;
}
int add_flow(int A, int B, int C)
{
    add_edge(A, B, C);
    return add_edge(B, A, 0);
}
void add_bound(int A, int B, int C)
{
    if (C)
    {
        d[A] -= C;
        d[B] += C;
    }
}
bool bfs(int S, int T)
{
    std::queue<int> que({S});
    std::memset(dis, -1, sizeof(dis));
    dis[S] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now, int T, int flow = INT_MAX)
{
    if (!flow || now == T)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
    {
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, T, std::min(e[i].v, flow));
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
            if (!flow)
                break;
            if (e[i].v)
                dis[e[i].t] = -1;
        }
    }
    return res;
}
int Dinic(int S, int T)
{
    int res = 0;
    while (bfs(S, T))
    {
        std::copy(head, head + n + 4, cur);
        res += dfs(S, T);
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::memset(head, -1, sizeof(head));
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> u[i] >> v[i];
        w[i] = add_flow(u[i], v[i], 1);
        ++a[u[i]];
        --a[v[i]];
    }
    S = 0;
    T = n + 1;
    // for (int i = 1; i <= n; ++i)
    //     std::cout << a[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i)
        if (s[i])
        {
            if (a[i] & 1)
                return std::cout << "NO" << std::endl, 0;
            if (a[i] < 0)
                add_bound(i, T, -a[i] >> 1);
            else
                add_bound(S, i, +a[i] >> 1);
        }
        else
        {
            add_flow(S, i, m);
            add_flow(i, T, m);
        }
    SS = n + 2;
    TT = n + 3;
    int tot = 0;
    for (int i = 0; i <= n + 1; ++i)
    {
        if (d[i] > 0)
            add_flow(SS, i, +d[i]), tot += d[i];
        else
            add_flow(i, TT, -d[i]);
    }
    add_flow(T, S, m);
    // std::cout << tot << std::endl;
    // for (int i = 0; i != n + 4; ++i)
    //     for (int j = head[i]; ~j; j = e[j].n)
    //         if (e[j].v)
    //             std::cout << i << ' ' << e[j].t << ' ' << e[j].v << std::endl;
    if (tot == Dinic(SS, TT))
    {
        std::cout << "YES" << std::endl;
        for (int i = 1; i <= m; ++i)
            if (e[w[i]].v)
                std::cout << v[i] << ' ' << u[i] << std::endl;
            else
                std::cout << u[i] << ' ' << v[i] << std::endl;
        return 0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}