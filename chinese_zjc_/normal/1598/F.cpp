// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int dp[2][1 << 20], n, cnt[20][800005], sum[1 << 20], min[20];
std::string a[20];
void cmax(int &A, int B) { A = std::max(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    for (int i = 0; i != n; ++i)
        sum[1 << i] = std::count(a[i].begin(), a[i].end(), '(') - std::count(a[i].begin(), a[i].end(), ')');
    for (int i = 0; i != 1 << n; ++i)
        sum[i] = sum[i & (i - 1)] + sum[i & -i];
    for (int i = 0; i != 1 << n; ++i)
        sum[i] += 400000;
    for (int i = 0; i != n; ++i)
    {
        int now = 400000;
        min[i] = 400000;
        for (const auto &j : a[i])
        {
            now += j == '(' ? +1 : -1;
            min[i] = std::min(now, min[i]);
            if (now == min[i])
                ++cnt[i][800000 - now];
        }
    }
    memset(dp, 0xf0, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;
    for (int i = 0; i != 1 << n; ++i)
        for (int j = 0; j != n; ++j)
            if (~i & 1 << j)
            {
                cmax(dp[sum[i] + min[j] >= 800000][i | 1 << j], dp[1][i] + cnt[j][sum[i]]);
                cmax(dp[0][i | 1 << j], dp[0][i]);
            }
    std::cout << std::max(dp[1][(1 << n) - 1], dp[0][(1 << n) - 1]) << std::endl;
    return 0;
}