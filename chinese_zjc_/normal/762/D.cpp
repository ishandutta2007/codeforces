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
int dp[6][64], n, a[3][100005];
const bool to[6][6] = {
    {0, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0}};
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int j = 0; j != 3; ++j)
        for (int i = 1; i <= n; ++i)
            std::cin >> a[j][i];
    if (n == 1)
        return std::cout << a[0][1] + a[1][1] + a[2][1] << std::endl, 0;
    for (int i = 0; i != 6; ++i)
        for (int j = 0; j != 64; ++j)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 1; i != n; ++i)
    {
        for (int j = 0; j != 64; ++j)
            for (int k = 0; k != 6; ++k)
                for (int l = 0; l != 6; ++l)
                    if (~j >> l & 1 && to[k][l])
                        dp[l][j | 1 << k] = std::max(dp[l][j | 1 << k], dp[k][j] + a[k % 3][i + k / 3]);
        for (int j = 0; j != 3; ++j)
            for (int k = 0; k != 64; ++k)
                dp[j][k] = -INF;
        for (int j = 3; j != 6; ++j)
            for (int k = 0; k != 64; ++k)
                dp[j - 3][k >> 3] = std::max(dp[j - 3][k >> 3], dp[j][k]);
        for (int j = 3; j != 6; ++j)
            for (int k = 0; k != 64; ++k)
                dp[j][k] = -INF;
    }
    std::cout << *std::max_element(dp[2], dp[2] + 64) + a[2][n] << std::endl;
    return 0;
}