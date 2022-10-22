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
int n, m, r, b, S, T, s, t, ncnt, ecnt, cost, head[500005], dis[500005], cur[500005], need[500005];
char add;
struct point
{
    int x, y, p;
} p[100005];
struct line
{
    bool X;
    int l, d, inid, outid, on;
} l[100005];
struct edge
{
    int n, t, flow;
} e[1000005];
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
void add_bound(int A, int B, int DOWN, int UP)
{
    if (DOWN > UP)
        std::cout << -1 << std::endl, exit(0);
    need[A] += DOWN;
    need[B] -= DOWN;
    add_flow(A, B, UP - DOWN);
}
int ceildiv(int A, int B)
{
    return (A + B - 1) / B;
}
bool bfs(int beg, int end)
{
    std::queue<int> que;
    std::fill(dis, dis + ncnt, -1);
    dis[beg] = 0;
    que.push(beg);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
            if (e[i].flow && dis[e[i].t] == -1)
            {
                dis[e[i].t] = dis[now] + 1;
                if (e[i].t == end)
                    return true;
                que.push(e[i].t);
            }
    }
    return false;
}
int dfs(int now, int end, int Flow = INF)
{
    if (now == end)
        return Flow;
    int res = 0;
    while (~cur[now] && Flow)
    {
        if (e[cur[now]].flow && dis[e[cur[now]].t] == dis[now] + 1)
        {
            int tmp = dfs(e[cur[now]].t, end, std::min(Flow, e[cur[now]].flow));
            e[cur[now]].flow -= tmp;
            e[cur[now] ^ 1].flow += tmp;
            res += tmp;
            Flow -= tmp;
            if (!Flow)
                break;
        }
        cur[now] = e[cur[now]].n;
    }
    return res;
}
int dinic(int beg, int end)
{
    int res = 0;
    while (bfs(beg, end))
    {
        std::copy(head, head + ncnt, cur);
        res += dfs(beg, end);
#ifdef debug
        std::cout << res << std::endl;
#endif
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> m >> r >> b;
    if (r < b)
    {
        std::swap(r, b);
        add = 'r' ^ 'b';
    }
    S = ncnt++;
    T = ncnt++;
    s = ncnt++;
    t = ncnt++;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> p[i].x >> p[i].y;
    }
    std::map<std::pair<bool, int>, int> L;
    for (int i = 1; i <= m; ++i)
    {
        static int X, l, d;
        std::cin >> X >> l >> d;
        std::pair<std::map<std::pair<bool, int>, int>::iterator, bool> tmp =
            L.insert(std::make_pair(std::make_pair(bool(X & 1), l), d));
        if (!tmp.second)
            tmp.first->second = std::min(d, tmp.first->second);
    }
    m = 0;
    for (std::map<std::pair<bool, int>, int>::iterator i = L.begin(); i != L.end(); ++i)
    {
        ++m;
        l[m].X = i->first.first;
        l[m].l = i->first.second;
        l[m].d = i->second;
        i->second = m;
        l[m].inid = l[m].outid = ncnt++;
    }
    l[0].inid = t;
    l[0].outid = s;
    for (int i = 1; i <= n; ++i)
    {
        int X = L[std::make_pair(true, p[i].x)], Y = L[std::make_pair(false, p[i].y)];
        ++l[X].on;
        ++l[Y].on;
        p[i].p = ecnt;
        add_flow(l[X].outid, l[Y].inid, 1);
    }
    for (int i = 1; i <= m; ++i)
        if (l[i].X)
            add_bound(s, l[i].inid, std::max(0ll, ceildiv(l[i].on - l[i].d, 2)), (l[i].on + l[i].d) / 2);
        else
            add_bound(l[i].outid, t, std::max(0ll, ceildiv(l[i].on - l[i].d, 2)), (l[i].on + l[i].d) / 2);
    add_flow(t, s, n);
    for (int i = 0; i < ncnt; ++i)
    {
        if (need[i] < 0)
            add_flow(S, i, -need[i]);
        if (need[i] > 0)
            add_flow(i, T, need[i]);
    }
#ifdef debug
    if (n == 100000)
        std::cout << ncnt << ' ' << ecnt << std::endl, exit(0);
    for (int i = 0; i < ncnt; ++i)
    {
        for (int j = head[i]; ~j; j = e[j].n)
        {
            if (j % 2 == 0)
                std::cout << i << ' ' << e[j].t << ' ' << e[j].flow << std::endl;
        }
    }
#endif
    dinic(S, T);
    for (int i = head[S]; ~i; i = e[i].n)
        if (e[i].flow)
            return std::cout << -1 << std::endl, 0;
    std::cout << r * n - (r - b) * dinic(s, t) << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        char ans = e[p[i].p].flow ? 'r' : 'b';
        std::cout << char(ans ^ add);
    }
    return 0;
}