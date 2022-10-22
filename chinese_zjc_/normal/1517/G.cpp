// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, S, T, head[2005], cnt, dis[2005], cur[2005];
std::map<std::pair<int, int>, int> map;
struct edge
{
    int n, t;
    long long v;
} e[10005];
void add_edge(int A, int B, long long C)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].v = C;
    head[A] = cnt++;
}
void add_flow(int A, int B, long long C)
{
    // std::cout << A << ' ' << B << ' ' << C << std::endl;
    add_edge(A, B, C);
    add_edge(B, A, 0);
}
bool bfs()
{
    std::queue<int> que;
    std::fill(dis, dis + n + n + 2, -1);
    dis[S] = 0;
    que.push(S);
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
                else
                    que.push(e[i].t);
            }
    }
    return false;
}
long long dfs(int now = S, long long flow = LLONG_MAX)
{
    if (now == T || !flow)
        return flow;
    long long res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (dis[e[i].t] == dis[now] + 1 && e[i].v)
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
long long Dinic()
{
    long long res = 0;
    while (bfs())
    {
        std::copy(head, head + n + n + 2, cur);
        res += dfs();
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n;
    S = n << 1;
    T = n << 1 | 1;
    long long ans = 0;
    for (int i = 0, x, y, w; i != n; ++i)
    {
        std::cin >> x >> y >> w;
        ans += w;
        add_flow(i << 1, i << 1 | 1, w);
        map[{x, y}] = i;
    }
    for (auto i : map)
    {
        static std::map<std::pair<int, int>, int>::iterator iter;
        int g = ((i.first.first & 1) << 1) | (i.first.second & 1);
        switch (g)
        {
        case 0:
            iter = map.find({i.first.first, i.first.second + 1});
            if (iter != map.end())
                add_flow(i.second << 1 | 1, iter->second << 1, LLONG_MAX);
            iter = map.find({i.first.first, i.first.second - 1});
            if (iter != map.end())
                add_flow(i.second << 1 | 1, iter->second << 1, LLONG_MAX);
            break;
        case 2:
            add_flow(S, i.second << 1, LLONG_MAX);
        case 1:
            iter = map.find({i.first.first + 1, i.first.second});
            if (iter != map.end())
                add_flow(i.second << 1 | 1, iter->second << 1, LLONG_MAX);
            iter = map.find({i.first.first - 1, i.first.second});
            if (iter != map.end())
                add_flow(i.second << 1 | 1, iter->second << 1, LLONG_MAX);
            break;
        case 3:
            add_flow(i.second << 1 | 1, T, LLONG_MAX);
            break;
        }
    }
    std::cout << ans - Dinic() << std::endl;
    return 0;
}