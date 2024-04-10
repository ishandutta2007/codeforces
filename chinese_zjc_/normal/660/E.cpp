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
int fact[1000005], ifact[1000005];
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
int C(int m, int n)
{
    if (0 <= n && n <= m)
        return fact[m] * ifact[n] % MOD * ifact[m - n] % MOD;
    return 0;
}
int calc(int n, int m)
{
    int res = 0;
    for (int p = 0; p < n; ++p)
        res = (res + power(m, n - p) * power(m + m - 1, p)) % MOD;
    return (res + power(m, n)) % MOD;
}
signed main()
{
    fact[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[1000000] = power(fact[1000000], MOD - 2);
    for (int i = 1000000; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::cout << calc(n, m) << std::endl;
    return 0;
}