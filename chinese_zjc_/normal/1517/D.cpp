//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, k, l[505][505], c[505][505], dp[11][505][505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    if (k & 1)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cout << -1 << " \n"[j == m];
        return 0;
    }
    k >>= 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < m; ++j)
            std::cin >> l[i][j];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    for (int t = 1; t <= k; ++t)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                dp[t][i][j] = INF;
                if (i > 1)
                    dp[t][i][j] = std::min(dp[t - 1][i - 1][j] + c[i - 1][j], dp[t][i][j]);
                if (i < n)
                    dp[t][i][j] = std::min(dp[t - 1][i + 1][j] + c[i][j], dp[t][i][j]);
                if (j > 1)
                    dp[t][i][j] = std::min(dp[t - 1][i][j - 1] + l[i][j - 1], dp[t][i][j]);
                if (j < m)
                    dp[t][i][j] = std::min(dp[t - 1][i][j + 1] + l[i][j], dp[t][i][j]);
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cout << dp[k][i][j] * 2 << " \n"[j == m];
    return 0;
}