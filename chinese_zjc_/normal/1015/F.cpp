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
int n, m, dp[205][205][205], kmp[205];
char s[205];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> (s + 1);
    n <<= 1;
    m = strlen(s + 1);
    for (int i = 2, j = 0; i <= m; ++i)
    {
        while (j && s[j + 1] != s[i])
            j = kmp[j];
        if (s[i] == s[j + 1])
            ++j;
        kmp[i] = j;
        while (kmp[i] && s[kmp[i] + 1] == s[i + 1])
            kmp[i] = kmp[kmp[i]];
    }
    // for (int i = 1; i <= m; ++i)
    //     std::cout << kmp[i] << " \n"[i == m];
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                int to = k;
                while (to && s[to + 1] != '(')
                    to = kmp[to];
                bool add = s[to + 1] == '(';
                dp[i + 1][j + 1][to + add] = (dp[i + 1][j + 1][to + add] + dp[i][j][k]) % MOD;
                if (j)
                {
                    to = k;
                    while (to && s[to + 1] != ')')
                        to = kmp[to];
                    // std::cout << k << ' ' << to << std::endl;
                    add = s[to + 1] == ')';
                    dp[i + 1][j - 1][to + add] = (dp[i + 1][j - 1][to + add] + dp[i][j][k]) % MOD;
                }
            }
            dp[i + 1][j + 1][m] = (dp[i + 1][j + 1][m] + dp[i][j][m]) % MOD;
            if (j)
                dp[i + 1][j - 1][m] = (dp[i + 1][j - 1][m] + dp[i][j][m]) % MOD;
        }
    }
    std::cout << dp[n][0][m] << std::endl;
    return 0;
}