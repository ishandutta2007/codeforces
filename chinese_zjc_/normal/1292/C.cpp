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
int n, dp[3005][3005], siz[3005][3005], dis[3005][3005], ans;
std::vector<int> to[3005];
std::queue<std::pair<int, int>> que;
int dfs(int now, int fa)
{
    if (siz[now][fa])
        return siz[now][fa];
    siz[now][fa] = 1;
    for (int i = 0; i != (int)to[now].size(); ++i)
        if (fa != to[now][i])
            siz[now][fa] += dfs(to[now][i], now);
    return siz[now][fa];
}
void init(int now, int from)
{
    for (int i = 0; i != (int)to[now].size(); ++i)
        if (!~dis[from][to[now][i]])
            dis[from][to[now][i]] = dis[from][now] + 1, init(to[now][i], from);
}
int DP(int A, int B)
{
    if (A == B)
        return 0;
    if (dp[A][B])
        return dp[A][B];
    int AF = -1, BF = -1;
    for (int i = 0; i != (int)to[A].size(); ++i)
        if (dis[to[A][i]][B] < dis[A][B])
            AF = to[A][i];
    for (int i = 0; i != (int)to[B].size(); ++i)
        if (dis[A][to[B][i]] < dis[A][B])
            BF = to[B][i];
    return dp[A][B] = std::max(DP(AF, B), DP(A, BF)) + siz[A][AF] * siz[B][BF];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j != (int)to[i].size(); ++j)
            siz[i][to[i][j]] = dfs(i, to[i][j]);
    memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= n; ++i)
        que.push({i, i}), dis[i][i] = 0, init(i, i);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans = std::max(ans, DP(i, j));
    std::cout << ans << std::endl;
    return 0;
}