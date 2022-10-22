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
int n, a[205], id[205], ncnt, ecnt, head[205], S, T, dis[205], cur[205], tot;
bool is[20005];
std::stringstream str;
struct edge
{
    int n, t, v;
} e[50005];
std::vector<int> to[205], ans;
void add_edge(int A, int B, int C)
{
    e[ecnt].n = head[A];
    e[ecnt].t = B;
    e[ecnt].v = C;
    head[A] = ecnt++;
}
void add_flow(int A, int B, int C)
{
    add_edge(A, B, C);
    add_edge(B, A, 0);
}
bool bfs()
{
    std::queue<int> que;
    std::fill(dis, dis + ncnt, -1);
    dis[S] = 0;
    que.push(S);
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
            res += tmp;
            flow -= tmp;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
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
void work(int now)
{
    is[now] = true;
    ans.push_back(now);
    for (auto i : to[now])
        if (!is[i])
            work(i);
}
void print()
{
    ++tot;
    str << ans.size();
    for (auto i : ans)
        str << ' ' << i;
    str << std::endl;
    ans.clear();
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    memset(is, true, sizeof(is));
    is[1] = false;
    for (int i = 2; i <= 20000; ++i)
        for (int j = i + i; j <= 20000; j += i)
            is[j] = false;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        id[i] = ncnt++;
    }
    S = ncnt++;
    T = ncnt++;
    for (int i = 1; i <= n; ++i)
        if (a[i] & 1)
        {
            add_flow(S, id[i], 2);
            for (int j = 1; j <= n; ++j)
                if (is[a[i] + a[j]])
                    add_flow(id[i], id[j], 1);
        }
        else
            add_flow(id[i], T, 2);
    // for (int i = 0; i != ncnt; ++i)
    //     for (int j = head[i]; ~j; j = e[j].n)
    //         std::cout << i << ' ' << e[j].t << " " << e[j].v << std::endl;
    if (Dinic() != n)
        return std::cout << "Impossible" << std::endl, 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] & 1)
            for (int j = head[id[i]]; ~j; j = e[j].n)
                if (e[j].v == 0)
                {
                    int nxt = std::find(id + 1, id + 1 + n, e[j].t) - id;
                    if (nxt <= n)
                    {
                        to[i].push_back(nxt);
                        to[nxt].push_back(i);
                    }
                }
    memset(is, false, sizeof(is));
    for (int i = 1; i <= n; ++i)
        if (!is[i])
            work(i), print();
    std::cout << tot << std::endl
              << str.str();
    return 0;
}