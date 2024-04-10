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
const int base = 114514;
const int MOD = 19260817;
int n, m, hash[26][200005];
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
int get(int l, int r, int p)
{
    return (hash[p][r] - hash[p][l - 1] * power(base, r - l + 1) % MOD + MOD) % MOD;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static char c;
        std::cin >> c;
        for (int j = 0; j != 26; ++j)
            hash[j][i] = (hash[j][i - 1] * base + (c == 'a' + j ? 1 : 0)) % MOD;
    }
    for (int i = 1; i <= m; ++i)
    {
        static int a, b, l;
        std::cin >> a >> b >> l;
        int A = 0, B = 0;
        for (int j = 0; j != 26; ++j)
        {
            A ^= get(a, a + l - 1, j) % MOD;
            B ^= get(b, b + l - 1, j) % MOD;
        }
        for (int j = 0; j != 26; ++j)
        {
            A = A * std::max(1ll, get(a, a + l - 1, j)) % MOD;
            B = B * std::max(1ll, get(b, b + l - 1, j)) % MOD;
        }
        // std::cout << A << ' ' << B << std::endl;
        if (A == B)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}