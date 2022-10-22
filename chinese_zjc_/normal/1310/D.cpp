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
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int n, k, v[85][85], dp[2][85], c[85], ans = INF;
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cin >> v[i][j];
    while (clock() < 2500)
    {
        std::for_each(c + 1, c + 1 + n, [&](int &x)
                      { x = Rand() & 1; });
        std::fill(dp[now] + 1, dp[now] + 1 + n, INF);
        dp[now][1] = 0;
        for (int i = 1; i <= k; ++i)
        {
            std::swap(now, lst);
            std::fill(dp[now] + 1, dp[now] + 1 + n, INF);
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    if (c[j] != c[k])
                    {
                        dp[now][k] = std::min(dp[now][k], dp[lst][j] + v[j][k]);
                    }
                }
            }
        }
        ans = std::min(ans, dp[now][1]);
    }
    std::cout << ans << std::endl;
    return 0;
}