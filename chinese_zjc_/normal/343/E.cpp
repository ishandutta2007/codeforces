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
#include <vector>
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
int n, m, cnt, head[205], dis[205], cur[205], ans, CNT, fa[205];
std::vector<int> way[205];
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
struct EDGE
{
    int a, b, v;
    friend bool operator<(const EDGE &A, const EDGE &B) { return A.v < B.v; }
} E[205];
struct edge
{
    int n, t, v;
} e[2005];
void add_edge(int A, int B, int V)
{
    e[cnt].n = head[A];
    e[cnt].t = B;
    e[cnt].v = V;
    head[A] = cnt++;
}
void add_flow(int A, int B, int V)
{
    add_edge(A, B, V);
    add_edge(B, A, V);
}
bool bfs(int S, int T)
{
    std::queue<int> que;
    que.push(S);
    std::fill(dis + 1, dis + 1 + n, -1);
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
int dfs(const int &now, int flow, const int &T)
{
    if (now == T || !flow)
        return flow;
    int res = 0;
    for (int &i = cur[now]; ~i; i = e[i].n)
        if (e[i].v && dis[e[i].t] == dis[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow), T);
            if (!tmp)
                dis[e[i].t] = -1;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
            flow -= tmp;
            res += tmp;
            if (!flow)
                break;
        }
    return res;
}
int Dinic(int S, int T)
{
    for (int i = 0; i != cnt; ++i, ++i)
        e[i].v = e[i ^ 1].v = (e[i].v + e[i ^ 1].v) >> 1;
    int res = 0;
    while (bfs(S, T))
    {
        std::copy(head + 1, head + 1 + n, cur + 1);
        res += dfs(S, INF, T);
    }
    return res;
}
void DFS(int now, std::bitset<205> &S)
{
    S[now] = true;
    for (int i = head[now]; ~i; i = e[i].n)
        if (e[i].v && !S[e[i].t])
            DFS(e[i].t, S);
}
const std::vector<int> operator+(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> res;
    for (std::vector<int>::const_iterator i = A.begin(); i != A.end(); ++i)
        res.push_back(*i);
    for (std::vector<int>::const_iterator i = B.begin(); i != B.end(); ++i)
        res.push_back(*i);
    return res;
}
void init(std::bitset<205> now)
{
    int S = -1, T = -1;
    for (int i = 1; i <= n; ++i)
        if (now[i])
        {
            if (~S)
                T = i;
            else
                S = i;
        }
    if (!~T)
        return;
    static int tmp;
    ans += tmp = Dinic(S, T);
    E[CNT].a = S;
    E[CNT].b = T;
    E[CNT].v = tmp;
    ++CNT;
    std::bitset<205> s;
    DFS(S, s);
    init(now & s);
    init(now & ~s);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y, z;
        std::cin >> x >> y >> z;
        add_flow(x, y, z);
    }
    init(~std::bitset<205>());
    std::sort(E, E + CNT);
    std::cout << ans << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        way[i].push_back(i);
    }
    for (int i = CNT; i--;)
    {
        way[find(E[i].a)].insert(way[find(E[i].a)].end(), way[find(E[i].b)].begin(), way[find(E[i].b)].end());
        fa[find(E[i].b)] = find(E[i].a);
    }
    for (int i = 0; i != n; ++i)
        std::cout << way[find(1)][i] << ' ';
    std::cout << std::endl;
    return 0;
}