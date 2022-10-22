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
int n, m, f[55][55], g[55][55], inv[55];
// f -> edge
// g -> vertex
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
    int res = 1;
    for (int i = m; i != m - n; --i)
        res = res * i % MOD;
    for (int i = 1; i <= n; ++i)
        res = res * power(i, MOD - 2) % MOD;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    f[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
            for (int k = 0; k <= n + 1; ++k)
                for (int l = 0; l <= n + 1; ++l)
                    g[i][std::min(k, l)] = (g[i][std::min(k, l)] + f[j][k] * f[i - j - 1][l]) % MOD;
        for (int j = 0; j <= i; ++j)
            for (int k = n; k >= i; --k)
                for (int l = j; l <= n + 2; ++l)
                    for (int o = 1, s = g[i][j] + o - 1; o * i <= k && o * j <= l; ++o, s = s * inv[o] % MOD * (g[i][j] + o - 1) % MOD)
                        f[k][l] = (f[k][l] + f[k - o * i][l - o * j] * s) % MOD;
    }
    std::cout << f[n][m] << std::endl;
    return 0;
}