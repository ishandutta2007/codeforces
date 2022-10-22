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
double dp[105][100005], sum[100005];
int n, m, v[105], S;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (m == 1)
        return std::cout << 1 << std::endl, 0;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i], S += v[i];
    sum[0] = dp[0][0] = m - 1;
    for (int i = 1; i <= n * m; ++i)
        sum[i] = sum[i - 1] + dp[0][i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n * m; ++j)
        {
            // for (int k = 1; k <= j && k <= m; ++k)
            // {
            //     if (v[i] == k)
            //         continue;
            //     dp[i][j] += dp[i - 1][j - k] / (m - 1);
            // }
            dp[i][j] = (sum[j - 1] - (j - m - 1 < 0 ? 0 : sum[j - m - 1]) -
                        (j >= v[i] ? dp[i - 1][j - v[i]] : 0)) /
                       (m - 1);
        }
        sum[0] = dp[i][0];
        for (int j = 1; j <= n * m; ++j)
            sum[j] = sum[j - 1] + dp[i][j];
        // for (int j = 0; j <= n * m; ++j)
        //     std::cout << dp[i][j] << " \n"[j == n * m];
        // std::cout << sum[n * m] << std::endl;
    }
    // for (int i = 0; i <= n * m; ++i)
    //     std::cout << dp[n][i] << " \n"[i == n * m];
    std::cout << std::fixed << std::setprecision(20) << sum[S - 1] + 1 << std::endl;
    return 0;
}