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
struct matrix
{
    int n, m, v[55][55];
    int &operator()(const int &A, const int &B) { return v[A][B]; }
    const int &operator()(const int &A, const int &B) const { return v[A][B]; }
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix res;
        memset(res.v, 0, sizeof(res.v));
        res.n = A.n;
        res.m = B.m;
        for (int i = 0; i != res.n; ++i)
            for (int j = 0; j != res.m; ++j)
                for (int k = 0; k != A.m; ++k)
                    res(i, j) = (res(i, j) + A(i, k) * B(k, j)) % MOD;
        return res;
    }
} dp, cha;
int n, k, a[105], c[2], r;
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
matrix power(matrix A, int B)
{
    matrix res = A;
    --B;
    while (B)
    {
        if (B & 1)
            res = res * A;
        B >>= 1;
        A = A * A;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], ++c[a[i]];
    for (int i = 1; i <= c[0]; ++i)
        r += a[i];
    int max = std::min(c[0], c[1]);
    dp.n = 1, dp.m = max + 1;
    for (int i = 0; i <= max; ++i)
        dp(0, i) = i == r;
    cha.n = cha.m = max + 1;
    for (int i = 0, d = power(n * (n - 1) / 2, MOD - 2); i <= max; ++i)
    {
        if (i > 0)
            cha(i, i - 1) = i * i * d % MOD;
        if (i < max)
            cha(i, i + 1) = (c[0] - i) * (c[1] - i) * d % MOD;
        cha(i, i) = (1 + (i * i + (c[0] - i) * (c[1] - i)) * (MOD - d)) % MOD;
    }
    dp = dp * power(cha, k);
    std::cout << dp(0, 0) << std::endl;
    return 0;
}