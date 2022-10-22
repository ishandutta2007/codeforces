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
int n, a[5005], ans, dp[5005][5005], nxt[5005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = n, j = n + 1; i >= 0; --i)
    {
        nxt[i] = j;
        if (a[i] == 0)
            j = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            std::fill(dp[i], dp[i] + 1 + n, INF);
            for (int j = 0; j <= n; ++j)
            {
                dp[i][nxt[j]] = std::min(dp[i][nxt[j]], dp[i - 1][j] + llabs(i - nxt[j]));
            }
            for (int j = 1; j <= n; ++j)
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1]);
        }
        else
        {
            std::copy(dp[i - 1], dp[i - 1] + 1 + n, dp[i]);
        }
    }
    std::cout << *std::min_element(dp[n], dp[n] + 1 + n) << std::endl;
    return 0;
}