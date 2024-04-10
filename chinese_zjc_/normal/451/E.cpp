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
int n, lim, a[20], sum[1 << 20], pop[1 << 20], ans, ifact[25];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
int lucas(int N, int M) // N choose M
{
    if (N < MOD && M < MOD)
    {
        if (0 <= M && M <= N)
        {
            M = std::min(M, N - M);
            int res = 1;
            for (int i = 0; i != M; ++i)
                res = res * (N - i) % MOD;
            res = res * ifact[M] % MOD;
            return res;
        }
        else
            return 0;
    }
    return lucas(N % MOD, M % MOD) * lucas(N / MOD, M / MOD) % MOD;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> lim;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i], sum[1 << i] = ++a[i];
    ifact[0] = 1;
    for (int i = 1; i <= n; ++i)
        ifact[i] = ifact[i - 1] * power(i, MOD - 2) % MOD;
    for (int i = 0; i != 1 << n; ++i)
    {
        sum[i] = sum[i & (i - 1)] + sum[i & -i];
        pop[i] = pop[i & (i - 1)] + bool(i & -i);
        // std::cout << lucas(n - 1 + (lim - sum[i]), n - 1) << std::endl;
        ans = (ans + lucas(n - 1 + (lim - sum[i]), n - 1) * (pop[i] & 1 ? MOD - 1 : 1)) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}