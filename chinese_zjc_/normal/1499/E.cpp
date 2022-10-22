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
const int MOD = 998244353;
int n, m, dp[1005][1005][2][4], ans;
char a[1005], b[1005];
void add(int &A, int B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            dp[i + 1][j][0][1] = dp[i][j + 1][1][2] = 1;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 1; k != 4; ++k)
            {
                if (i)
                {
                    if (i != n && a[i - 1] != a[i])
                        add(dp[i + 1][j][0][k | 1], dp[i][j][0][k]);
                    if (j != m && a[i - 1] != b[j])
                        add(dp[i][j + 1][1][k | 2], dp[i][j][0][k]);
                }
                if (j)
                {
                    if (i != n && b[j - 1] != a[i])
                        add(dp[i + 1][j][0][k | 1], dp[i][j][1][k]);
                    if (j != m && b[j - 1] != b[j])
                        add(dp[i][j + 1][1][k | 2], dp[i][j][1][k]);
                }
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k != 2; ++k)
                ans = (ans + dp[i][j][k][3]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}