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
int n, k, fact[200005], ans;
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
    return fact[n] * power(fact[n - m] * fact[m] % MOD, MOD - 2) % MOD;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    if (k == 0)
        return std::cout << fact[n] << std::endl, 0;
    int c = n - k;
    if (c < 0)
        return std::cout << 0 << std::endl, 0;
    for (int i = c, p = 1; i >= 0; --i, p = p * (MOD - 1) % MOD % MOD)
    {
        ans = (ans + p * C(c, i) % MOD * power(i, n) % MOD) % MOD;
    }
    std::cout << ans * C(n, c) % MOD * 2 % MOD << std::endl;
    return 0;
}