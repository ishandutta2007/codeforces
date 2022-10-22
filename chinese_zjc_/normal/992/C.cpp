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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
// const int _2 = 500000004;
const int MOD = 1000000007;
// struct matrix
// {
//     vector<vector<int>> val;
//     int n() const
//     {
//         return val.size();
//     }
//     int m() const
//     {
//         if (val.empty())
//         {
//             return 0;
//         }
//         return val.front().size();
//     }
//     void assign(int n, int m)
//     {
//         val.assign(n, vector<int>(m));
//     }
//     matrix operator*(const matrix &__Val) const
//     {
//         matrix res;
//         for (int k = 0; k < m(); ++k)
//         {
//             for (int i = 0; i < res.n(); ++i)
//             {
//                 for (int j = 0; j < res.m(); ++j)
//                 {
//                     res.val[i][j] += val[i][k] * __Val.val[k][j] % MOD;
//                 }
//             }
//         }
//         for (int i = 0; i < res.n(); ++i)
//         {
//             for (int j = 0; j < res.m(); ++j)
//             {
//                 res.val[i][j] %= MOD;
//             }
//         }
//     }
// };
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
int x, k;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> x >> k;
    if (x == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    x %= MOD;
    cout << (x * power(2, k + 1) - power(2, k) + 1 + MOD) % MOD << endl;
    return 0;
}