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
int n, m, a[200005], w[200005], f[3005][3005], d[3005][3005], W[2], ans, min, Inv[10005];
bool now = true, lst = false;
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
void initinv()
{
    min = W[0] + W[1] - 5000;
    for (int i = 0; i <= 10000; ++i)
        Inv[i] = power(min + i, MOD - 2);
}
int inv(int x)
{
    return Inv[x - min];
}
void add(int &A, const int &B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> w[i], W[a[i]] += w[i];
    initinv();
    for (int j = m; j >= 0; --j)
        for (int k = m; k >= 0; --k)
            if (j + k == m)
                f[j][k] = 1;
            else
                f[j][k] = (inv(W[0] + W[1] - j + k) * 2 % MOD * f[j][k + 1] +
                           (W[0] - j + MOD) * inv(W[0] + W[1] - j + k) % MOD * f[j + 1][k] +
                           (W[1] + k - 1 + MOD) * inv(W[0] + W[1] - j + k) % MOD * f[j][k + 1]) %
                          MOD;
    for (int j = m; j >= 0; --j)
        for (int k = m; k >= 0; --k)
            if (j + k == m)
                d[j][k] = 1;
            else
                d[j][k] = ((W[0] - j - 1 + MOD) * inv(W[0] + W[1] - j + k) % MOD * d[j + 1][k] +
                           (W[1] + k + MOD) * inv(W[0] + W[1] - j + k) % MOD * d[j][k + 1]) %
                          MOD;
    for (int i = 1; i <= n; ++i)
        std::cout << (a[i] ? f[0][0] : d[0][0]) * w[i] % MOD << std::endl;
    return 0;
}