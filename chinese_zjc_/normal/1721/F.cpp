// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n1, n2, m, q, p, a[200005], b[200005], c[200005], d[400005],
    head[400005], dis[400005], cur[400005], S, T, ecnt;
long long tot;
bool vis[400005];
std::vector<int> g;
struct edge
{
    int t, n, v;
} e[1200005];
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
bool bfs()
{
    std::queue<int> que;
    que.push(S);
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
int dfs(int now = S, int flow = INT_MAX)
{
    if (!flow || now == T)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow));
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            res += tmp;
            flow -= tmp;
            if (!flow)
                break;
            if (e[i].v)
                dis[e[i].t] = -1;
        }
    return res;
}
int Dinic()
{
    int res = 0;
    while (bfs())
    {
        std::copy(head, head + n1 + n2 + 2, cur);
        res += dfs();
    }
    return res;
}
void build(int now)
{
    vis[now] = true;
    for (int i = head[now]; ~i; i = e[i].n)
        if (e[i].v && !vis[e[i].t])
            build(e[i].t);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n1 >> n2 >> m >> q;
    std::memset(head, -1, sizeof(head));
    S = 0;
    T = n1 + n2 + 1;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i];
        c[i] = add_flow(a[i], b[i] + n1, 2);
    }
    for (int i = 1; i <= n1; ++i)
        add_flow(S, i, 1);
    for (int i = 1; i <= n2; ++i)
        add_flow(i + n1, T, 1);
    p = Dinic();
    build(S);
    for (int i = 1; i <= n1; ++i)
        if (!vis[i])
            g.push_back(i);
    for (int i = 1; i <= n2; ++i)
        if (vis[n1 + i])
            g.push_back(n1 + i);
    for (int i = 1; i <= m; ++i)
        if (e[c[i]].v)
            tot += d[a[i]] = d[n1 + b[i]] = i;
    // for (auto i : g)
    //     std::cout << i << ' ';
    // std::cout << std::endl;
    for (int i = 0, opt; i != q; ++i)
    {
        std::cin >> opt;
        if (opt == 1)
        {
            std::cout << 1 << std::endl
                      << (g.back() > n1 ? -g.back() + n1 : g.back()) << std::endl
                      << (tot -= d[g.back()]) << std::endl;
            d[g.back()] = 0;
            g.pop_back();
        }
        else
        {
            std::cout << g.size() << std::endl;
            if (g.empty())
                std::cout << std::endl;
            else
                for (int i = 1, cnt = 0; i <= m; ++i)
                    if (d[a[i]] == i && d[n1 + b[i]] == i)
                        std::cout << i << " \n"[++cnt == int(g.size())];
            // std::cout << "-----" << std::endl;
        }
    }
    return 0;
}