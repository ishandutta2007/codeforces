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
int n, k, s, a[155], dp[155][155 * 155];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> s;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        for (int j = k; j; --j)
            for (int l = i - j; l <= std::min(n * k, s); ++l)
                dp[j][l] = std::min(dp[j][l], dp[j - 1][l - (i - j)] + a[i]);
    }
    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j <= n * k; ++j)
    //         std::cout << dp[i][j] << " \n"[j == n * k];
    std::cout << *std::min_element(dp[k], dp[k] + std::min(n * k, s) + 1) << std::endl;
    return 0;
}