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
int n, m, s, min[205], rk[205], res[205];
int k, dp[2][205];
int check()
{
    for (int i = 1; i <= s; ++i)
        dp[0][i] = 0;
    dp[0][0] = 1;
    for (int i = 0; i != s; ++i)
    {
        for (int j = 0; j <= s; ++j)
            dp[~i & 1][j] = 0;
        for (int j = 0; j <= i; ++j)
        {
            if (j && res[i] != 1)
                dp[~i & 1][j - 1] = std::min(INF, dp[~i & 1][j - 1] + dp[i & 1][j]);
            if (res[i] != -1)
                dp[~i & 1][j + 1] = std::min(INF, dp[~i & 1][j + 1] + dp[i & 1][j]);
        }
    }
    return dp[s & 1][0];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    s = n + m - 1;
    for (int i = 0; i != s; ++i)
        min[i] = INF;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
        {
            static int x;
            std::cin >> x;
            min[i + j] = std::min(min[i + j], x);
        }
    for (int i = 0; i != s; ++i)
        rk[i] = i;
    std::sort(rk, rk + s, [&](const int &A, const int &B)
              { return min[A] < min[B]; });
    for (int i = 0; i != s; ++i)
    {
        res[rk[i]] = 1;
        int tmp = check();
        if (tmp < k)
        {
            res[rk[i]] = -1;
            k -= tmp;
        }
    }
#ifdef debug
    for (int i = 0; i != s; ++i)
        std::cout << (res[i] == 1 ? '(' : ')');
    std::cout << std::endl;
#else
    for (int i = 0; i != n; ++i, std::cout << std::endl)
        for (int j = 0; j != m; ++j)
            std::cout << (res[i + j] == 1 ? '(' : ')');
#endif
    return 0;
}