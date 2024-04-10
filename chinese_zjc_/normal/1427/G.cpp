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
const int xx[] = {0, 1}, yy[] = {1, 0};
int n, m, a[205][205], id[205][205], ecnt, ncnt, s, t, head[100005], ans, dis[100005], cur[100005], FLOW;
std::vector<int> val;
bool wa[100005];
struct edge
{
    int n, t, flow;
} e[500005];
void add_edge(int A, int B, int FLOW)
{
    e[ecnt] = {head[A], B, FLOW};
    head[A] = ecnt++;
}
void add_flow(int A, int B, int FLOW)
{
    add_edge(A, B, FLOW);
    add_edge(B, A, 0);
}
bool bfs(bool f)
{
    std::fill(dis, dis + ncnt, -1);
    dis[s] = 0;
    std::queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if ((!f || now != s || wa[e[i].t]) && e[i ^ f].flow && !~dis[e[i].t])
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == t)
                    return true;
                que.push(e[i].t);
            }
        }
    }
    return false;
}
int dfs(bool f, int now, int flow = INF)
{
    if (now == t)
        return flow;
    int res = 0, &i = cur[now];
    while (~i)
    {
        if (e[i ^ f].flow && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(f, e[i].t, std::min(flow, e[i ^ f].flow));
            e[i ^ f].flow -= tmp;
            e[i ^ f ^ 1].flow += tmp;
            res += tmp;
            flow -= tmp;
            if (!flow)
                return res;
        }
        i = e[i].n;
    }
    return res;
}
int dinic(bool f)
{
    int res = 0;
    while (bfs(f))
    {
        std::copy(head, head + ncnt, cur);
        res += dfs(f, s);
    }
    return res;
}
bool check(int now)
{
    for (int i = head[now]; ~i; i = e[i].n)
        if (i % 2 && e[i].flow)
            return true;
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    m = n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[i][j];
            if (a[i][j] > 0)
                val.push_back(a[i][j]);
        }
    std::sort(val.begin(), val.end());
    val.erase(std::unique(val.begin(), val.end()), val.end());
    s = ncnt++;
    t = ncnt++;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (~a[i][j])
                id[i][j] = ncnt++;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (id[i][j])
                for (int k = 0; k < 2; ++k)
                    if (id[i + xx[k]][j + yy[k]])
                    {
                        add_edge(id[i][j], id[i + xx[k]][j + yy[k]], 1);
                        add_edge(id[i + xx[k]][j + yy[k]], id[i][j], 1);
                    }
    for (int i = 1; i <= n; ++i)
    {
        add_flow(s, id[i][1], INF);
        add_flow(s, id[i][m], INF);
    }
    for (int i = 2; i < m; ++i)
    {
        add_flow(s, id[1][i], INF);
        add_flow(s, id[n][i], INF);
    }
    for (int i = 1; i < val.size(); ++i)
    {
        memset(wa, false, sizeof(wa));
        for (int j = 1; j <= n; ++j)
        {
            if (a[j][1] == val[i - 1])
                wa[id[j][1]] = true;
            if (a[j][m] == val[i - 1])
                wa[id[j][m]] = true;
        }
        for (int j = 2; j < m; ++j)
        {
            if (a[1][j] == val[i - 1])
                wa[id[1][j]] = true;
            if (a[n][j] == val[i - 1])
                wa[id[n][j]] = true;
        }
        FLOW -= dinic(true);
        for (int j = 0; j < ncnt; ++j)
            if (wa[j])
            {
                for (int k = head[j]; ~k; k = e[k].n)
                    if (e[k].t == s)
                        e[k ^ 1].flow = 0;
                add_flow(j, t, INF);
            }
#ifdef debug
        for (int j = 0; j < ncnt; ++j)
            for (int k = head[j]; ~k; k = e[k].n)
                if (k % 2 == 0)
                    std::cout << j << ' ' << e[k].t << ' ' << e[k].flow << std::endl;
        std::cout << ans << std::endl;
#endif
        FLOW += dinic(false);
        ans += FLOW * (val[i] - val[i - 1]);
    }
#ifdef debug
    std::cout << id[2][2] << std::endl;
#endif
    std::cout << ans << std::endl;
    return 0;
}