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
int n, dp[505][505], a[505];
int dfs(int l, int r)
{
    if (l == r)
        return 1;
    if (~dp[l][r])
        return dp[l][r];
    dp[l][r] = dfs(l + 1, r);
    for (int i = l; i < r; ++i)
        if (a[l] < a[i + 1])
            dp[l][r] = (dp[l][r] + (i == l ? 1 : dfs(l + 1, i)) * dfs(i + 1, r)) % MOD;
    return dp[l][r];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    if (a[1] != 1)
        std::cout << 0 << std::endl;
    else if (n == 1)
        std::cout << 1 << std::endl;
    else
        std::cout << dfs(2, n) << std::endl;
    return 0;
}