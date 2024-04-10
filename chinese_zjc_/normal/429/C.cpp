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
int n, m, a[24], pop[1 << 11], high[1 << 11];
bool dp[11][1 << 11];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m;
    for (int i = 0; i != m; ++i)
    {
        std::cin >> a[i];
        if (a[i] == 1)
        {
            --m;
            --i;
            ++n;
        }
    }
    if (n == 1 && m == 0)
        return std::cout << "YES" << std::endl, 0;
    std::sort(a, a + m);
    if (a[0] == 2 || a[m - 1] != n + m || m > 11)
        return std::cout << "NO" << std::endl, 0;
    high[0] = -1;
    for (int i = 1; i != 1 << m; ++i)
        pop[i] = pop[i & (i - 1)] + 1, high[i] = high[i >> 1] + 1;
    // for (int i = 0; i != m; ++i)
    //     std::cout << a[i] << ' ';
    // std::cout << std::endl;
    for (int i = 0; i != m; ++i)
    {
        bool DP[n + 1][1 << i];
        memset(DP, false, sizeof(DP));
        DP[0][0] = true;
        for (int j = 0; j <= n; ++j /*, std::cout << std::endl*/)
            for (int k = 0; k != 1 << i; ++k)
            {
                for (int l = k; (l &= k); --l)
                    if (a[high[l]] + 1 < a[i] && j >= a[high[l]] - pop[l] && a[high[l]] - pop[l] >= 0)
                        // std::cout << i << ' ' << j << ' ' << k << ' ' << l << std::endl,
                        DP[j][k] |= DP[j - (a[high[l]] - pop[l])][k ^ l] && dp[high[l]][l];
                // std::cout << DP[j][k];
                dp[i][k | 1 << i] |= DP[j][k] && j <= a[i] - pop[k | 1 << i] && a[i] - pop[k | 1 << i] <= n;
            }
    }
    // for (int i = 0; i != m; ++i, std::cout << std::endl)
    //     for (int j = 0; j != 1 << i << 1; ++j)
    //         std::cout << dp[i][j];
    std::cout << (dp[m - 1][(1 << m) - 1] ? "YES" : "NO") << std::endl;
    return 0;
}