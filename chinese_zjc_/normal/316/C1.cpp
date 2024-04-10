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
int n, m, a[85][85], ecnt, ncnt, S, T, id[85][85], head[6405], cur[6405], flow, cost, dis[6405];
bool vis[6405];
struct edge
{
    int t, n, f, c;
} e[40005];
void add_edge(int A, int B, int F, int C)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].f = F;
    e[ecnt].c = C;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int F, int C)
{
    add_edge(A, B, F, +C);
    add_edge(B, A, 0, -C);
}
bool spfa()
{
    std::fill(dis, dis + ncnt, INF);
    dis[S] = 0;
    std::queue<int> que;
    que.push(S);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].f && dis[e[i].t] > dis[now] + e[i].c)
            {
                dis[e[i].t] = dis[now] + e[i].c;
                que.push(e[i].t);
            }
    }
    return dis[T] != INF;
}
int dfs(int now = S, int flow = INF)
{
    if (now == T || !flow)
        return flow;
    vis[now] = true;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (!vis[e[i].t] && e[i].f && dis[e[i].t] == dis[now] + e[i].c)
        {
            int tmp = dfs(e[i].t, std::min(flow, e[i].f));
            res += tmp;
            flow -= tmp;
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            cost += tmp * e[i].c;
            if (!flow)
                break;
        }
    vis[now] = false;
    return res;
}
int Dinic()
{
    int res = 0;
    while (spfa())
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
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> a[i][j], id[i][j] = ncnt++;
    S = ncnt++;
    T = ncnt++;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if ((i + j) & 1)
                add_flow(id[i][j], T, 1, 0);
            else
            {
                add_flow(S, id[i][j], 1, 0);
                if (i < n)
                    add_flow(id[i][j], id[i + 1][j], 1, a[i][j] != a[i + 1][j]);
                if (j < m)
                    add_flow(id[i][j], id[i][j + 1], 1, a[i][j] != a[i][j + 1]);
                if (i > 1)
                    add_flow(id[i][j], id[i - 1][j], 1, a[i][j] != a[i - 1][j]);
                if (j > 1)
                    add_flow(id[i][j], id[i][j - 1], 1, a[i][j] != a[i][j - 1]);
            }
        }
    Dinic();
    std::cout << cost << std::endl;
    return 0;
}