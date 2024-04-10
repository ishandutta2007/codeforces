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
int x[2505], y[2505], n;
double dp[2505][2505][2], ans;
int sqr(int x) { return x * x; }
double dis(int A, int B) { return sqrt(sqr(x[A] - x[B]) + sqr(y[A] - y[B])); }
double dfs(int L, int R, bool side)
{
    if ((R - L + n) % n == 1)
        return 0;
    if (dp[L][R][side] >= 0)
        return dp[L][R][side];
    return dp[L][R][side] = std::max(dfs((L + 1) % n, R, false) + dis(side ? R : L, (L + 1) % n),
                                     dfs(L, (R + n - 1) % n, true) + dis(side ? R : L, (R + n - 1) % n));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> x[i] >> y[i];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k != 2; ++k)
                dp[i][j][k] = -1;
    for (int i = 0; i != n; ++i)
        ans = std::max(ans, dfs(i, i, false));
    std::cout << std::fixed << std::setprecision(100) << ans << std::endl;
    return 0;
}