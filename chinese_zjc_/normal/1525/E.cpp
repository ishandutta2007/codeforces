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
int n, m, dis[50005][20], ans;
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
int fact(int n)
{
    return n ? fact(n - 1) * n % MOD : 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            std::cin >> dis[j][i];
    int f = fact(n);
    for (int i = 0; i != m; ++i)
    {
        std::sort(dis[i], dis[i] + n);
        int s = 1;
        for (int j = 0; j != n; ++j)
        {
            s = s * (dis[i][j] - 1 - j) % MOD;
        }
        ans = (ans + (f - s + MOD)) % MOD;
    }
    ans = ans * power(f, MOD - 2) % MOD;
    std::cout << ans << std::endl;
    return 0;
}