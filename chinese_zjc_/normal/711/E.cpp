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
const int MOD = 1000003;
const int phiMOD = MOD - 1;
int n, k, pow2, res, A = 1;
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
int work(int x) { return x ? x / 2 + work(x / 2) : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    // std::cout << n << std::endl;
    if (n <= 60 && 1ll << n < k)
        return std::cout << 1 << ' ' << 1 << std::endl, 0;
    pow2 = (n % phiMOD) * ((k - 1) % phiMOD) % phiMOD;
    // std::cout << (n % phiMOD) << ' ' << (k - 1) % phiMOD << std::endl;
    // for (int i = 1; i < k; ++i)
    //     res += log2(i & -i);
    // res = work(k - 1) % phiMOD;
    for (int i = 2; i <= k - 1; i <<= 1)
        res = (res + (k - 1) / i) % phiMOD;
    // std::cout << pow2 << ' ' << res << std::endl;
    if (k > MOD)
        std::cout << power(2, pow2 - res + phiMOD) << ' ' << power(2, pow2 - res + phiMOD) << std::endl;
    else
    {
        for (int i = 1; i <= k - 1; ++i)
            A = A * (power(2, n % phiMOD) - i + MOD) % MOD;
        std::cout << (power(2, pow2) - A + MOD) * power(2, phiMOD - res) % MOD << ' '
                  << power(2, pow2 - res + phiMOD) << std::endl;
    }
    return 0;
}