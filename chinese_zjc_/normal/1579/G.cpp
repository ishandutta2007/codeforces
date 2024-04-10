// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, dp[2][2005], a[10005];
bool now = true, lst = false;
void cmin(int &A, int B) { A = std::min(A, B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        memset(dp[now], 0x3f, sizeof(dp[now]));
        for (int i = 0; i <= 1000; ++i)
            dp[now][i] = i;
        for (int i = 1; i <= n; ++i)
        {
            std::swap(now, lst);
            memset(dp[now], 0x3f, sizeof(dp[now]));
            for (int j = 0; j <= 2000; ++j)
            {
                if (j - a[i] >= 0)
                    cmin(dp[now][j], std::max(dp[lst][j - a[i]], j));
                if (j + a[i] <= 2000)
                    cmin(dp[now][j], dp[lst][j + a[i]]);
            }
        }
        std::cout << *std::min_element(dp[now], dp[now] + 2005) << std::endl;
    }
    return 0;
}