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
int n, p, k, dp[2][1 << 7], a[100005], rk[100005], v[100005][7], popcount[1 << 7];
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], rk[i] = i;
    std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
              { return a[A] > a[B]; });
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j != p; ++j)
            std::cin >> v[i][j];
    for (int i = 1; i != 1 << p; ++i)
        popcount[i] = popcount[i & (i - 1)] + 1;
    memset(dp[now], 0xf0, sizeof(dp[now]));
    dp[now][0] = 0;
    for (int I = 1; I <= n; ++I)
    {
        int i = rk[I];
        std::swap(now, lst);
        memset(dp[now], 0xf0, sizeof(dp[now]));
        for (int j = 0; j != 1 << p; ++j)
        {
            dp[now][j] = dp[lst][j] + (I - popcount[j] <= k ? a[i] : 0);
            for (int l = 0; l != p; ++l)
                if (j & 1 << l)
                    dp[now][j] = std::max(dp[now][j], dp[lst][j ^ 1 << l] + v[i][l]);
            // std::cout << dp[now][j] << " \n"[j + 1 == 1 << p];
        }
    }
    std::cout << dp[now][(1 << p) - 1] << std::endl;
    return 0;
}