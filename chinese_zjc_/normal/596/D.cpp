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
#define left false
#define right true
int n, h, x[2005];
double p, dp[2005][2005][2][2];
double d(double x) { return x < 0 ? 0 : x; }
double dfs(int l, int r, int lstl, int lstr)
{
    if (dp[l][r][lstl][lstr] >= 0)
        return dp[l][r][lstl][lstr];
    double &now = dp[l][r][lstl][lstr] = 0;
    if (l > r)
        return now;
    if (lstl == right && x[l - 1] + h > x[l])
        return now = dfs(l + 1, r, lstl, lstr) + d(std::min(x[r + 1] - (lstr == left) * h, x[l] + h) - (x[l - 1] + h));
    if (lstr == left && x[r + 1] - h < x[r])
        return now = dfs(l, r - 1, lstl, lstr) + d((x[r + 1] - h) - std::max(x[l - 1] + (lstl == right) * h, x[r] - h));
    now = 0.5 * p * (dfs(l, r - 1, lstl, left) + d(x[r] - std::max(x[l - 1] + (lstl == right) * h, x[r] - h))) +
          0.5 * (1 - p) * (dfs(l, r - 1, lstl, right) + d(std::min(x[r + 1] - (lstr == left) * h, x[r] + h) - x[r])) +
          0.5 * p * (dfs(l + 1, r, left, lstr) + d(x[l] - std::max(x[l - 1] + (lstl == right) * h, x[l] - h))) +
          0.5 * (1 - p) * (dfs(l + 1, r, right, lstr) + d(std::min(x[r + 1] - (lstr == left) * h, x[l] + h) - x[l]));
    return now;
}
signed main()
{
    std::cout << std::fixed << std::setprecision(20);
    for (int i = 0; i != 2005; ++i)
        for (int j = 0; j != 2005; ++j)
            for (int k = 0; k != 2; ++k)
                for (int l = 0; l != 2; ++l)
                    dp[i][j][k][l] = -1;
    std::ios::sync_with_stdio(false);
    std::cin >> n >> h >> p;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i];
    std::sort(x + 1, x + 1 + n);
    x[0] = -INF;
    x[n + 1] = INF;
    std::cout << dfs(1, n, left, right) << std::endl;
    return 0;
}