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
const int INF = 0x3fffffffffffff;
int n, k, ans, ecnt, head[55], dis[55], from[55], flow[55];
struct edge
{
    int n, t, f, c;
} e[10005];
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
    std::queue<int> que;
    std::fill(dis + 1, dis + 1 + n, INF);
    dis[1] = 0;
    flow[1] = INF;
    que.push(1);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].f && dis[e[i].t] > dis[now] + e[i].c)
            {
                dis[e[i].t] = dis[now] + e[i].c;
                flow[e[i].t] = std::min(flow[now], e[i].f);
                from[e[i].t] = i;
                que.push(e[i].t);
            }
    }
    return dis[n] != INF;
}
void work()
{
    int now = n;
    while (now != 1)
    {
        e[from[now]].f -= flow[n];
        e[from[now] ^ 1].f += flow[n];
        now = e[from[now] ^ 1].t;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            static int v;
            std::cin >> v;
            if (v)
            {
                add_flow(i, j, v, 0);
                add_flow(i, j, INF, 1);
            }
        }
    }
    while (spfa())
    {
        // std::cout << k << ' ' << flow[n] << ' ' << dis[n] << std::endl;
        if (k < flow[n] * dis[n])
        {
            ans += k / dis[n];
            break;
        }
        else
        {
            k -= flow[n] * dis[n];
            ans += flow[n];
        }
        work();
    }
    std::cout << ans << std::endl;
    return 0;
}