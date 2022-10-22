// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, dp[5005][1 << 9], sum[5005], a[5005], b[5005];
void cmax(int &A, int B) { A = std::max(A, B); }
int calc(int i, int j, int l)
{
    int res = sum[b[i - l]];
    for (int o = 0; o != k; ++o)
        if (j >> o & 1 && b[i - o] <= b[i - l])
            --res;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    ++k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], b[a[i]] = i;
    std::memset(dp, 0xf0, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = i ? b[i] : n + 1; j <= n; ++j)
            ++sum[j];
        for (int j = 1 << k; j--;)
            if (dp[i][j] >= 0)
            {
                for (int l = 0; l != k; ++l)
                    if (j >> l & 1)
                        cmax(dp[i][j ^ 1 << l], dp[i][j] + calc(i, j, l));
                if (j < 1 << k >> 1)
                    cmax(dp[i + 1][j << 1 | 1], dp[i][j]);
            }
    }
    std::cout << n * (n - 1) / 2 - dp[n][0] << std::endl;
    return 0;
}