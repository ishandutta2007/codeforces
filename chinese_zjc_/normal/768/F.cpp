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
int f, w, h, fact[200005], ifact[200005], res, tot;
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
    if (n == m)
        return 1;
    if (0 <= n && n <= m)
        return fact[m] * ifact[n] % MOD * ifact[m - n] % MOD;
    return 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i <= 200001; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[200001] = power(fact[200001], MOD - 2);
    for (int i = 200001; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    std::cin >> f >> w >> h;
    for (int i = 0; i <= w / (h + 1); ++i)
    {
        int lw = w - i * (h + 1);
        res = (res + C(i - 1, lw + i - 1) * (C(i - 2, f - 1) + 2 * C(i - 1, f - 1) + C(i, f - 1)) % MOD) % MOD;
    }
    for (int i = 0; i <= w; ++i)
        tot = (tot + C(i - 1, w - 1) * (C(i - 2, f - 1) + 2 * C(i - 1, f - 1) + C(i, f - 1)) % MOD) % MOD;
    std::cout << res * power(tot, MOD - 2) % MOD << std::endl;
    return 0;
}