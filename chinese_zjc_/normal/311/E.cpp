//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, g, v[10005], w[10005], k[10005], ans, idd[10005], idm[10005],
    dis[20005], S, T, ncnt, ecnt, head[20005], cur[20005];
bool a[10005], b[10005], p[10005];
struct edge
{
    int n, t, v;
} e[300005];
void add_edge(int A, int B, int V)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].v = V;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int V)
{
    add_edge(A, B, V);
    add_edge(B, A, 0);
}
bool bfs()
{
    std::fill(dis, dis + ncnt, -1);
    dis[S] = 0;
    std::queue<int> que;
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
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now = S, int flow = INF)
{
    if (now == T || !flow)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow));
            res += tmp;
            flow -= tmp;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            if (!tmp)
                dis[e[i].t] = -1;
            if (!flow)
                break;
        }
    return res;
}
int Dinic()
{
    int res = 0;
    while (bfs())
    {
        std::copy(head, head + ncnt, cur);
        res += dfs();
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> m >> g;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];
    S = ncnt++;
    T = ncnt++;
    for (int i = 1; i <= n; ++i)
        idd[i] = ncnt++;
    for (int i = 1; i <= n; ++i)
        if (a[i])
            add_flow(idd[i], T, v[i]);
        else
            add_flow(S, idd[i], v[i]);
    for (int i = 1; i <= m; ++i)
    {
        idm[i] = ncnt++;
        std::cin >> b[i] >> w[i] >> k[i];
        ans += w[i];
        for (int j = 1; j <= k[i]; ++j)
        {
            static int x;
            std::cin >> x;
            if (b[i])
                add_flow(idd[x], idm[i], INF);
            else
                add_flow(idm[i], idd[x], INF);
        }
        std::cin >> p[i];
        if (p[i])
            w[i] += g;
        if (b[i])
            add_flow(idm[i], T, w[i]);
        else
            add_flow(S, idm[i], w[i]);
    }
    std::cout << ans - Dinic() << std::endl;
    return 0;
}