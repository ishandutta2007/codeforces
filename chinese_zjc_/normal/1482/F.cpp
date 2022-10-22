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
int n, m, dis[200005][2][2], x[200005], y[200005], v[200005];
std::vector<int> to[200005];
struct node
{
    int x, y, z, v;
    friend bool operator<(const node &A, const node &B) { return A.v > B.v; }
};
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> x[i] >> y[i] >> v[i];
        to[x[i]].push_back(i);
        to[y[i]].push_back(i);
    }
    memset(dis, 0x3f, sizeof(dis));
    std::priority_queue<node> que;
    que.push({1, 0, 0, dis[1][0][0] = 0});
    while (!que.empty())
    {
        node now = que.top();
        que.pop();
        if (dis[now.x][now.y][now.z] != now.v)
            continue;
        for (auto i : to[now.x])
        {
            int nxt = x[i] ^ y[i] ^ now.x;
            if (dis[nxt][now.y][now.z] > dis[now.x][now.y][now.z] + v[i])
                que.push({nxt, now.y, now.z, dis[nxt][now.y][now.z] = dis[now.x][now.y][now.z] + v[i]});
            if (!now.y && dis[nxt][1][now.z] > dis[now.x][0][now.z] + v[i] * 2)
                que.push({nxt, 1, now.z, dis[nxt][1][now.z] = dis[now.x][0][now.z] + v[i] * 2});
            if (!now.z && dis[nxt][now.y][1] > dis[now.x][now.y][0])
                que.push({nxt, now.y, 1, dis[nxt][now.y][1] = dis[now.x][now.y][0]});
            if (!now.y && !now.z && dis[nxt][1][1] > dis[now.x][0][0] + v[i])
                que.push({nxt, 1, 1, dis[nxt][1][1] = dis[now.x][0][0] + v[i]});
        }
    }
    for (int i = 2; i <= n; ++i)
        std::cout << dis[i][1][1] << " \n"[i == n];
    return 0;
}