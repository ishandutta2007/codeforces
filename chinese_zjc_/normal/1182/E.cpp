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
const int pMOD = 1000000006;
int f[100005], n, f1, f2, f3, c, ans = 1;
struct matrix
{
    int n, m;
    int v[10][10];
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix res;
        memset(res.v, 0, sizeof(res.v));
        res.n = A.n;
        res.m = B.m;
        for (int i = 1; i <= res.n; ++i)
            for (int j = 1; j <= res.m; ++j)
                for (int k = 1; k <= A.m; ++k)
                    res.v[i][j] = (res.v[i][j] + A.v[i][k] * B.v[k][j]) % pMOD;
        return res;
    }
    int &operator()(const int &A, const int &B) { return v[A][B]; }
    const int &operator()(const int &A, const int &B) const { return v[A][B]; }
};
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
    std::cin >> n >> f1 >> f2 >> f3 >> c;
    matrix sta, cha;
    cha.n = cha.m = 5;
    cha(1, 1) = 0, cha(1, 2) = 0, cha(1, 3) = 1, cha(1, 4) = 0, cha(1, 5) = 0;
    cha(2, 1) = 1, cha(2, 2) = 0, cha(2, 3) = 1, cha(2, 4) = 0, cha(2, 5) = 0;
    cha(3, 1) = 0, cha(3, 2) = 1, cha(3, 3) = 1, cha(3, 4) = 0, cha(3, 5) = 0;
    cha(4, 1) = 0, cha(4, 2) = 0, cha(4, 3) = 1, cha(4, 4) = 1, cha(4, 5) = 0;
    cha(5, 1) = 0, cha(5, 2) = 0, cha(5, 3) = 0, cha(5, 4) = 2, cha(5, 5) = 1;
    sta.n = 1, sta.m = 5;
    sta(1, 1) = 1, sta(1, 2) = 0, sta(1, 3) = 0, sta(1, 4) = 0, sta(1, 5) = 0;
    ans = (ans * power(f1, (sta * power(cha, n - 3))(1, 3))) % MOD;
    // std::cout << (sta * power(cha, n - 3))(1, 3) << std::endl;
    sta(1, 1) = 0, sta(1, 2) = 1, sta(1, 3) = 0, sta(1, 4) = 0, sta(1, 5) = 0;
    ans = (ans * power(f2, (sta * power(cha, n - 3))(1, 3))) % MOD;
    // std::cout << (sta * power(cha, n - 3))(1, 3) << std::endl;
    sta(1, 1) = 0, sta(1, 2) = 0, sta(1, 3) = 1, sta(1, 4) = 0, sta(1, 5) = 0;
    ans = (ans * power(f3, (sta * power(cha, n - 3))(1, 3))) % MOD;
    // std::cout << (sta * power(cha, n - 3))(1, 3) << std::endl;
    sta(1, 1) = 0, sta(1, 2) = 0, sta(1, 3) = 0, sta(1, 4) = 2, sta(1, 5) = 1;
    ans = (ans * power(c, (sta * power(cha, n - 3))(1, 3))) % MOD;
    // std::cout << (sta * power(cha, n - 3))(1, 3) << std::endl;
    std::cout << ans << std::endl;
    return 0;
}