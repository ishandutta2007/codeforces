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
const int MOD = 998244353;
int n, a[5005], dp[5005], c[5005], ans, inv[5005];
// dp[i] means the percent to choose one when we have already chosen i numbers.
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], ++c[a[i]];
    dp[0] = inv[n];
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] >= 2)
        {
            for (int j = n - 2; j >= 0; --j)
                ans = (ans + c[i] * (c[i] - 1) * dp[j] % MOD * inv[n - j - 1] % MOD) % MOD;
        }
        for (int j = n; j >= 1; --j)
            dp[j] = (dp[j] + c[i] * dp[j - 1] % MOD * inv[n - j] % MOD) % MOD;
        // for (int j = 0; j <= n; ++j)
        //     std::cout << dp[j] << " \n"[j == n];
    }
    std::cout << ans << std::endl;
    return 0;
}