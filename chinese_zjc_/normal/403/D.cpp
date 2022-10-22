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
int T, n, k, C[1005][1005], dp[1005][1005], fact[1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i <= 1000; ++i)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= 1000; ++i)
        for (int j = 50; j; --j)
            for (int k = i; k <= 1000; ++k)
                dp[j][k] = (dp[j][k] + dp[j - 1][k - i]) % MOD;
    fact[0] = 1;
    for (int i = 1; i <= 1000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    // for (int i = 0; i <= 20; ++i)
    //     for (int j = 0; j <= 20; ++j)
    //         std::cout << dp[i][j] << " \n"[j == 20];
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        if (k > 50)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        int res = 0;
        for (int i = k; i <= n; ++i)
            res = (res + C[i][k] * dp[k][n - i]) % MOD;
        std::cout << res * fact[k] % MOD << std::endl;
    }
    return 0;
}