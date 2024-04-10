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
const int MOD = 1000000007;
int dp[2][505][505], n, m, ans, tim;
char c[505][505];
bool now = true, lst = false;
char g1(int x, int y)
{
    return 1 + x >= 1 && 1 + y >= 1 && 1 + x <= n && 1 + y <= m ? c[1 + x][1 + y] : '0';
}
char g2(int x, int y)
{
    return n - x >= 1 && m - y >= 1 && n - x <= n && m - y <= m ? c[n - x][m - y] : '1';
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    dp[now][0][0] = (c[1][1] == c[n][m]);
    tim = (n + m - 2) / 2;
    for (int i = 1; i <= tim; ++i)
    {
        std::swap(now, lst);
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= n; ++k)
            {
                if (g1(j, i - j) == g2(k, i - k))
                    dp[now][j][k] = (dp[now][j][k] + dp[lst][j][k]) % MOD;
                if (g1(j, i - j) == g2(k + 1, i - k - 1))
                    dp[now][j][k + 1] = (dp[now][j][k + 1] + dp[lst][j][k]) % MOD;
                if (g1(j + 1, i - j - 1) == g2(k, i - k))
                    dp[now][j + 1][k] = (dp[now][j + 1][k] + dp[lst][j][k]) % MOD;
                if (g1(j + 1, i - j - 1) == g2(k + 1, i - k - 1))
                    dp[now][j + 1][k + 1] = (dp[now][j + 1][k + 1] + dp[lst][j][k]) % MOD;
            }
        }
        // for (int j = 0; j != n; ++j, std::cout << std::endl)
        //     for (int k = 0; k != n; ++k)
        //         std::cout << dp[now][j][k] << " ";
        // std::cout << std::endl;
    }
    if ((n + m) & 1)
    {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                if (1 + i + 1 == n - j || 1 + i == n - j)
                    ans = (ans + dp[now][i][j]) % MOD;
    }
    else
    {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                if (1 + i == n - j)
                    ans = (ans + dp[now][i][j]) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}