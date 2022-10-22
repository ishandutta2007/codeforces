// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long ans, pre[1000005], cnt[1000005];
char c[1000005];
long long sum(int l, int r) { return (r - l + 1ll) * (l + r) / 2; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> c[i];
            pre[i] = pre[i - 1];
            cnt[i] = cnt[i - 1];
            if (c[i] == '*')
                pre[i] += i, ++cnt[i];
        }
        ans = pre[n] - sum(1, cnt[n]);
        for (int i = 1; i <= n; ++i)
            ans = std::min(ans,
                           (sum(i - cnt[i] + 1, i) - pre[i]) + ((pre[n] - pre[i]) - sum(i + 1, i + (cnt[n] - cnt[i]))));
        std::cout << ans << std::endl;
    }
    return 0;
}