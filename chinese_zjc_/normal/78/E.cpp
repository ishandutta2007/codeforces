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
const int xx[] = {0, +1, 0, -1, 0},
          yy[] = {+1, 0, -1, 0, 0};
int n, t, S, T, id[15][15][65], dis[15][15], ncnt, ecnt, head[20005], cur[20005], DIS[20005];
char a[15][15], b[15][15];
std::queue<std::pair<int, int>> que;
struct edge
{
    int n, t, v;
} e[200005];
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
    que.push(S);
    std::fill(DIS, DIS + ncnt, -1);
    DIS[S] = 0;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].v && !~DIS[e[i].t])
            {
                DIS[e[i].t] = DIS[now] + 1;
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
        if (e[i].v && DIS[e[i].t] == DIS[now] + 1)
        {
            int tmp = dfs(e[i].t, std::min(e[i].v, flow));
            if (!tmp)
                DIS[e[i].t] = -1;
            // else
            //     std::cout << "VIS" << e[i].t << std::endl;
            res += tmp;
            flow -= tmp;
            e[i].v -= tmp;
            e[i ^ 1].v += tmp;
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
        // std::cout << res << std::endl;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> b[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            switch (a[i][j])
            {
            case 'Z':
                que.push({i, j});
            case 'Y':
                dis[i][j] = 0;
                break;
            default:
                dis[i][j] = t;
            }
    while (!que.empty())
    {
        std::pair<int, int> now = que.front();
        que.pop();
        for (int i = 0; i != 4; ++i)
        {
            std::pair<int, int> nxt = {now.first + xx[i], now.second + yy[i]};
            if (dis[nxt.first][nxt.second] > dis[now.first][now.second] + 1)
            {
                dis[nxt.first][nxt.second] = dis[now.first][now.second] + 1;
                que.push(nxt);
            }
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= n; ++j)
    //         std::cout << dis[i][j] << " \n"[j == n];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 0; k <= dis[i][j]; ++k)
                id[i][j][k] = ncnt++;
    S = ncnt++;
    T = ncnt++;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 0; k != dis[i][j]; ++k)
                for (int l = 0; l != 5; ++l)
                    if (k + 1 <= dis[i + xx[l]][j + yy[l]])
                        add_flow(id[i][j][k], id[i + xx[l]][j + yy[l]][k + 1], INF);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (dis[i][j])
                add_flow(S, id[i][j][0], a[i][j] - '0'), add_flow(id[i][j][dis[i][j]], T, b[i][j] - '0');
    // for (int i = 0; i != ncnt; ++i)
    //     for (int j = head[i]; ~j; j = e[j].n)
    //         if (~j & 1)
    //             std::cout << i << ' ' << e[j].t << ' ' << (e[j].v >= INF ? "" : std::to_string(e[j].v)) << std::endl;
    std::cout << Dinic() << std::endl;
    return 0;
}