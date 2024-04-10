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
int dp[2][100005], kmp[100005], n, m;
char s[100005], t[100005];
bool now = true, lst = false;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    std::fill(dp[now], dp[now] + m + 1, -INF);
    dp[now][0] = 0;
    for (int i = 2, j = 0; i <= m; ++i)
    {
        while (j && t[j + 1] != t[i])
            j = kmp[j];
        if (t[j + 1] == t[i])
            ++j;
        kmp[i] = j;
    }
    for (int i = 1; i <= n; ++i)
    {
        std::swap(now, lst);
        std::fill(dp[now], dp[now] + m + 1, -INF);
        for (int j = 1; j <= m; ++j)
            if (s[i] == t[j] || s[i] == '?')
                dp[now][j] = std::max(dp[now][j], dp[lst][j - 1]);
        ++dp[now][m];
        for (int j = 0; j != m; ++j)
            dp[now][0] = std::max(dp[now][0], dp[lst][j]);
        for (int j = m; j; --j)
            dp[now][kmp[j]] = std::max(dp[now][kmp[j]], dp[now][j]);
    }
    std::cout << dp[now][0] << std::endl;
    return 0;
}