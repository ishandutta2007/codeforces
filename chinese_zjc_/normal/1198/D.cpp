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
int n, dp[55][55][55][55], sum[55][55];
char c[55][55];
int query(int sx, int tx, int sy, int ty)
{
    return sum[tx][ty] - sum[sx - 1][ty] - sum[tx][sy - 1] + sum[sx - 1][sy - 1];
}
int dfs(int sx, int tx, int sy, int ty)
{
    if (sx > tx || sy > ty)
        return 0;
    if (~dp[sx][tx][sy][ty])
        return dp[sx][tx][sy][ty];
    dp[sx][tx][sy][ty] = std::max(tx - sx + 1, ty - sy + 1);
    for (int i = sx; i <= tx; ++i)
        if (!query(i, i, sy, ty))
            dp[sx][tx][sy][ty] = std::min(dp[sx][tx][sy][ty], dfs(sx, i - 1, sy, ty) + dfs(i + 1, tx, sy, ty));
    for (int i = sy; i <= ty; ++i)
        if (!query(sx, tx, i, i))
            dp[sx][tx][sy][ty] = std::min(dp[sx][tx][sy][ty], dfs(sx, tx, sy, i - 1) + dfs(sx, tx, i + 1, ty));
    // std::cout << sx << ' ' << tx << ' ' << sy << ' ' << ty << ' ' << dp[sx][tx][sy][ty] << std::endl;
    return dp[sx][tx][sy][ty];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> c[i][j], sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (c[i][j] == '#');
    std::cout << dfs(1, n, 1, n) << std::endl;
    return 0;
}