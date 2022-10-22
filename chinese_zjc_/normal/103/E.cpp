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
const int inf = 0x3fffffff;
int n, ncnt, ecnt, S, T, head[605], v[305], id1[305], id2[305], cur[605], dis[605];
std::vector<int> to[305];
struct edge
{
    int n, t, v;
} e[200005];
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
    std::queue<int> que;
    que.push(S);
    std::fill(dis, dis + ncnt, -1);
    dis[S] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == T)
                    return true;
                que.push(e[i].t);
            }
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
    {
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow));
            if (!tmp)
                dis[e[i].t] = -1;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
            if (!flow)
                break;
        }
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
    std::cin >> n;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; ++i)
    {
        static int t;
        std::cin >> t;
        to[i].resize(t);
        for (int j = 0; j != t; ++j)
            std::cin >> to[i][j];
        id1[i] = ncnt++;
        id2[i] = ncnt++;
    }
    S = ncnt++;
    T = ncnt++;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        add_flow(S, id1[i], inf - v[i]);
        add_flow(id2[i], T, inf);
        sum += inf - v[i];
        for (int j = 0; j != (int)to[i].size(); ++j)
            add_flow(id1[i], id2[to[i][j]], INF);
    }
#ifdef debug
    for (int i = 0; i != ncnt; ++i)
        for (int j = head[i]; ~j; j = e[j].n)
            std::cout << i << ' ' << e[j].t << ' ' << e[j].v << std::endl;
#endif
    std::cout << Dinic() - sum << std::endl;
    return 0;
}