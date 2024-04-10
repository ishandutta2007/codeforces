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
int n, m, k, ans, fact[1000005], ifact[1000005];
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
int sqr(int x) { return x * x % MOD; }
int C(int n, int m) { return 0 <= n && n <= m ? fact[m] * ifact[n] % MOD * ifact[m - n] % MOD : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    if (m == 1)
        return std::cout << power(k, n) << std::endl, 0;
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= std::max(n, k); ++i)
        ifact[i] = power(fact[i] = fact[i - 1] * i % MOD, MOD - 2);
    for (int i = 1; i <= std::min(k, n); ++i)
    {
        int way = 0;
        for (int j = 0; j <= i; ++j)
            way = (way + (j & 1 ? MOD - 1 : 1) * C(j, i) % MOD * power(i - j, n)) % MOD;
        way = sqr(way);
        for (int j = 0; j <= i; ++j)
            ans = (ans + C(j, k) * C(i - j, k - j) % MOD * C(i - j, k - i) % MOD *
                             power(j, (m - 2) * n) % MOD * way) %
                  MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}