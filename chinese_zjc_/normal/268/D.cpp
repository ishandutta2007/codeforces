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
const int MOD = 1000000009;
int dp[2][2][35][35][35], n, h;
bool now = true, lst = false;
void add(int &A, const int &B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> h;
    dp[now][1][h][h][h] = 1;
    for (int i = 1; i <= n; ++i)
    {
        std::swap(now, lst);
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 0; j != 2; ++j)
            for (int k = 0; k <= h; ++k)
                for (int l = k; l <= h; ++l)
                    for (int p = l; p <= h; ++p)
                    {
                        add(dp[now][!!j][k ? k - 1 : 0][l ? l - 1 : 0][p ? p - 1 : 0], dp[lst][j][k][l][p]);
                        if (j)
                        {
                            add(dp[now][!!k][l ? l - 1 : 0][p ? p - 1 : 0][h - 1], dp[lst][j][k][l][p]);
                            add(dp[now][!!l][k ? k - 1 : 0][p ? p - 1 : 0][h - 1], dp[lst][j][k][l][p]);
                            add(dp[now][!!p][k ? k - 1 : 0][l ? l - 1 : 0][h - 1], dp[lst][j][k][l][p]);
                        }
                        else
                        {
                            add(dp[now][!!k][0][l ? l - 1 : 0][p ? p - 1 : 0], dp[lst][j][k][l][p]);
                            add(dp[now][!!l][0][k ? k - 1 : 0][p ? p - 1 : 0], dp[lst][j][k][l][p]);
                            add(dp[now][!!p][0][k ? k - 1 : 0][l ? l - 1 : 0], dp[lst][j][k][l][p]);
                        }
                    }
    }
    int ans = 0;
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j <= h; ++j)
            for (int k = 0; k <= h; ++k)
                for (int l = 0; l <= h; ++l)
                    if (i || j || k || l)
                        add(ans, dp[now][i][j][k][l]);
    std::cout << ans << std::endl;
    return 0;
}