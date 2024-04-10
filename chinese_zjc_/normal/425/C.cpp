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
int n, m, s, e, tim, a[100005], b[100005], dp[2][305], ans;
std::vector<int> app[100005];
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s >> e;
    tim = s / e;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
        std::cin >> b[i];
    for (int i = 1; i <= m; ++i)
        app[b[i]].push_back(i);
    for (int i = 1; i <= 100000; ++i)
        app[i].push_back(INF + 1);
    std::fill(dp[now] + 1, dp[now] + 1 + tim, INF);
    for (int i = 1; i <= n; ++i)
    {
        std::swap(now, lst);
        dp[now][0] = 0;
        for (int j = 1; j <= tim; ++j)
        {
            dp[now][j] = std::min(dp[lst][j], *std::upper_bound(app[a[i]].begin(), app[a[i]].end(), dp[lst][j - 1]));
            if (dp[now][j] + i + j * e <= s)
                ans = std::max(ans, j);
            else
                dp[now][j] = INF;
        }
        // for (int j = 0; j <= tim; ++j)
        //     std::cout << dp[now][j] << " \n"[j == tim];
    }
    std::cout << ans << std::endl;
    return 0;
}