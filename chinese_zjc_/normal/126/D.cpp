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
int T, f[90], dp[90][3][3];
signed main()
{
    std::ios::sync_with_stdio(false);
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i != 90; ++i)
        f[i] = f[i - 1] + f[i - 2];
    std::cin >> T;
    while (T--)
    {
        static int x;
        std::cin >> x;
        memset(dp, 0, sizeof(dp));
        dp[88][0][0] = 1;
        for (int i = 88; i; --i)
        {
            static bool has;
            x -= f[i - 1] * (has = x >= f[i - 1]);
            for (int j = 0; j != 3; ++j)
                for (int k = 0; k != 3; ++k)
                {
                    if (j <= 1)
                        dp[i - 1][k][has] += dp[i][j][k];
                    if (j >= 1 && k != 2)
                        dp[i - 1][k + 1][has + 1] += dp[i][j][k];
                }
        }
#ifdef debug
        for (int i = 5; i >= 0; --i)
            std::cout << dp[i][0][0] << ' ' << dp[i][0][1] << ' ' << dp[i][1][0] << ' ' << dp[i][1][1] << std::endl;
#endif
        std::cout << dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1] << std::endl;
    }
    return 0;
}