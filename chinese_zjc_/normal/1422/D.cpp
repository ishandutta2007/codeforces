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
struct point
{
    int x, y, p;
} T, a[100005];
std::vector<std::pair<int, int>> to[100005];
std::priority_queue<std::pair<int, int>> que;
int n, m, dis[100005], ans = INF;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    std::cin >> a[0].x >> a[0].y >> T.x >> T.y;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i].x >> a[i].y;
        a[i].p = i;
    }
    std::sort(a, a + m + 1, [&](const point &A, const point &B)
              { return A.x < B.x; });
    for (int i = 0; i != m; ++i)
    {
        to[a[i].p].push_back(std::make_pair(a[i + 1].p, a[i + 1].x - a[i].x));
        to[a[i + 1].p].push_back(std::make_pair(a[i].p, a[i + 1].x - a[i].x));
    }
    std::sort(a, a + m + 1, [&](const point &A, const point &B)
              { return A.y < B.y; });
    for (int i = 0; i != m; ++i)
    {
        to[a[i].p].push_back(std::make_pair(a[i + 1].p, a[i + 1].y - a[i].y));
        to[a[i + 1].p].push_back(std::make_pair(a[i].p, a[i + 1].y - a[i].y));
    }
    std::sort(a, a + m + 1, [&](const point &A, const point &B)
              { return A.p < B.p; });
    std::fill(dis + 1, dis + 1 + m, INF);
    que.push(std::make_pair(0, 0));
    while (!que.empty())
    {
        if (que.top().first + dis[que.top().second])
        {
            que.pop();
            continue;
        }
        int now = que.top().second;
        que.pop();
        for (int i = 0; i != (int)to[now].size(); ++i)
        {
            if (dis[to[now][i].first] > dis[now] + to[now][i].second)
            {
                dis[to[now][i].first] = dis[now] + to[now][i].second;
                que.push(std::make_pair(-dis[to[now][i].first], to[now][i].first));
            }
        }
    }
    for (int i = 0; i <= m; ++i)
        ans = std::min(ans, llabs(T.x - a[i].x) + llabs(T.y - a[i].y) + dis[i]);
    std::cout << ans << std::endl;
    return 0;
}