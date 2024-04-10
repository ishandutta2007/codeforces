// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, l, cnt[1000005], ans;
long long dp[1000005];
bool a[1000005];
void work(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + a[i];
        cnt[i] = cnt[i - 1];
        if (dp[i] > dp[std::max(i - l, 0)] + x)
            dp[i] = dp[std::max(i - l, 0)] + x, cnt[i] = cnt[std::max(i - l, 0)] + 1;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> l;
    for (int i = 1; i <= n; ++i)
    {
        static char c;
        std::cin >> c;
        a[i] = isupper(c);
    }
    int L = 0, R = l;
    while (L < R)
    {
        int mid = (L + R) / 2;
        work(mid);
        if (cnt[n] > k)
            L = mid + 1;
        else
            R = mid;
    }
    work(L);
    ans = dp[n] - k * L;
    for (int i = 1; i <= n; ++i)
        a[i] ^= true;
    L = 0, R = l;
    while (L < R)
    {
        int mid = (L + R) / 2;
        work(mid);
        if (cnt[n] > k)
            L = mid + 1;
        else
            R = mid;
    }
    work(L);
    ans = std::min(ans, int(dp[n] - k * L));
    std::cout << ans << std::endl;
    return 0;
}