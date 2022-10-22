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
int sa[200005], rk[200005], n, m, k;
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
int fact(int N) { return N ? fact(N - 1) * N % MOD : 1; }
int C(int M, int N) { return M < N ? 0 : fact(M) * power(fact(N) * fact(M - N) % MOD, MOD - 2) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    memset(rk, -1, sizeof(rk));
    for (int i = 0; i != n; ++i)
        std::cin >> sa[i], rk[sa[i]] = i;
    for (int i = 0; i + 1 != n; ++i)
        if (rk[sa[i] + 1] < rk[sa[i + 1] + 1])
            ++m;
    std::cout << C(m + k, n) << std::endl;
    return 0;
}