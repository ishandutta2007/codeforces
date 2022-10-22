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
int fact[1005], ifact[1005], n, x[105], y[105], dp[105][1005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int C(int n, int m)
{
    return 0 <= n && n <= m ? fact[m] * ifact[n] % MOD * ifact[m - n] % MOD : 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> y[i];
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= 1000; ++i)
        ifact[i] = power(fact[i] = fact[i - 1] * i % MOD, MOD - 2);
    for (int i = 1; i <= n; ++i)
        dp[0][0] += x[i];
    dp[0][0] = fact[dp[0][0]];
    for (int i = 1; i <= n; ++i)
        dp[0][0] = dp[0][0] * ifact[x[i]] % MOD;
    for (int i = 1, s = 0; i <= n; ++i)
    {
        for (int j = 0; j <= s; ++j)
        {
            int h = j + x[i];
            for (int k = 0; k <= std::min(h, y[i]); ++k)
                dp[i][h - k] = (dp[i][h - k] + dp[i - 1][j] * C(k, h)) % MOD;
        }
        s += x[i];
    }
    std::cout << dp[n][0] << std::endl;
    return 0;
}