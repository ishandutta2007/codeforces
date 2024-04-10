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
int MOD, x, y, dx, dy, t;
struct matrix
{
    int v[6][6];
    matrix(int x)
    {
        for (int i = 0; i != 6; ++i)
            for (int j = 0; j != 6; ++j)
                if (i == j)
                    v[i][j] = x;
                else
                    v[i][j] = 0;
    }
    int &operator()(const int &A, const int &B) { return v[A][B]; }
    const int &operator()(const int &A, const int &B) const { return v[A][B]; }
    friend matrix operator*(const matrix &A, const matrix &B)
    {
        matrix res(0);
        for (int i = 0; i != 6; ++i)
            for (int j = 0; j != 6; ++j)
                for (int k = 0; k != 6; ++k)
                    res(i, j) = (res(i, j) + A(i, k) * B(k, j)) % MOD;
        return res;
    }
};
matrix power(matrix A, int B)
{
    matrix res(1);
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
    std::cin >> MOD >> x >> y >> dx >> dy >> t;
    matrix sta(0), cha(0);
    sta(0, 0) = x - 1;
    sta(0, 1) = y - 1;
    sta(0, 2) = (dx % MOD + MOD) % MOD;
    sta(0, 3) = (dy % MOD + MOD) % MOD;
    sta(0, 4) = 0;
    sta(0, 5) = 1;
    cha(0, 0) = 2, cha(0, 1) = 1, cha(0, 2) = 1, cha(0, 3) = 1, cha(0, 4) = 0, cha(0, 5) = 0;
    cha(1, 0) = 1, cha(1, 1) = 2, cha(1, 2) = 1, cha(1, 3) = 1, cha(1, 4) = 0, cha(1, 5) = 0;
    cha(2, 0) = 1, cha(2, 1) = 0, cha(2, 2) = 1, cha(2, 3) = 0, cha(2, 4) = 0, cha(2, 5) = 0;
    cha(3, 0) = 0, cha(3, 1) = 1, cha(3, 2) = 0, cha(3, 3) = 1, cha(3, 4) = 0, cha(3, 5) = 0;
    cha(4, 0) = 1, cha(4, 1) = 1, cha(4, 2) = 1, cha(4, 3) = 1, cha(4, 4) = 1, cha(4, 5) = 0;
    cha(5, 0) = 2, cha(5, 1) = 2, cha(5, 2) = 2, cha(5, 3) = 2, cha(5, 4) = 1, cha(5, 5) = 1;
    matrix ans = sta * power(cha, t);
    std::cout << ans(0, 0) + 1 << ' ' << ans(0, 1) + 1 << std::endl;
    return 0;
}