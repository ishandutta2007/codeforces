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
struct edge
{
    int n, t, v, x;
} e[500005];
int n, m, L, x[100005], d[100005], t[100005], p[100005], head[300005], dis[300005];
std::pair<int, int> from[300005];
std::vector<int> pos, ans;
void add_edge(int A, int B, int C, int D)
{
    e[m].n = head[A];
    e[m].t = B;
    e[m].v = C;
    e[m].x = D;
    head[A] = m++;
}
void work(int x)
{
    if (x == 0)
        return;
    work(from[x].first);
    if (from[x].second)
        ans.push_back(from[x].second);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> L;
    pos.push_back(0);
    pos.push_back(L);
    for (int i = 1; i <= n; ++i)
    {
        static int b, e;
        std::cin >> x[i] >> d[i] >> t[i] >> p[i];
        b = x[i] - p[i];
        e = x[i] + d[i];
        if (b >= 0)
        {
            pos.push_back(b);
            pos.push_back(e);
        }
    }
    std::sort(pos.begin(), pos.end());
    pos.erase(std::unique(pos.begin(), pos.end()), pos.end());
    for (int i = 1; i <= n; ++i)
    {
        static int b, e;
        b = x[i] - p[i];
        e = x[i] + d[i];
        if (b >= 0)
            add_edge(std::lower_bound(pos.begin(), pos.end(), b) - pos.begin(),
                     std::lower_bound(pos.begin(), pos.end(), e) - pos.begin(), x[i] - b + t[i], i);
    }
    for (int i = 1; i != (int)pos.size(); ++i)
        add_edge(i - 1, i, pos[i] - pos[i - 1], 0), add_edge(i, i - 1, pos[i] - pos[i - 1], 0);
    std::priority_queue<std::pair<int, int>> que;
    que.push({0, 0});
    std::fill(dis + 1, dis + pos.size(), INF);
    while (!que.empty())
    {
        if (que.top().first + dis[que.top().second])
        {
            que.pop();
            continue;
        }
        int now = que.top().second;
        que.pop();
        for (int j = head[now]; ~j; j = e[j].n)
        {
            // std::cout << now << ' ' << e[j].t << ' ' << e[j].v << std::endl;
            if (dis[e[j].t] > dis[now] + e[j].v)
                que.push({-(dis[e[j].t] = dis[now] + e[j].v), e[j].t}), from[e[j].t] = {now, e[j].x};
        }
    }
    std::cout << dis[pos.size() - 1] << std::endl;
    work(pos.size() - 1);
    std::cout << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}