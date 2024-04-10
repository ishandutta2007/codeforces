// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, dp[1 << 20], tim[20][20], t[20][1 << 20];
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> s;
    for (int i = 1; i != n; ++i)
    {
        ++tim[s[i - 1] - 'a'][s[i] - 'a'];
        ++tim[s[i] - 'a'][s[i - 1] - 'a'];
    }
    for (int i = 0; i != m; ++i)
        tim[i][i] = 0;
    std::fill(dp + 1, dp + (1 << m), INT_MAX / 2);
    for (int i = 0; i != m; ++i)
    {
        for (int j = 0; j != m; ++j)
            t[i][1 << j] = tim[i][j];
        for (int j = 1; j != 1 << m; ++j)
            t[i][j] = t[i][j & -j] + t[i][j & (j - 1)];
    }
    for (int i = 0; i != 1 << m; ++i)
        for (int j = 0; j != m; ++j)
            if (i >> j & 1)
                dp[i] = std::min(dp[i], dp[i ^ 1 << j] + __builtin_popcount(i) * (t[j][i] - t[j][(1 << m) - 1 - i]));
    std::cout << dp[(1 << m) - 1] << std::endl;
    return 0;
}