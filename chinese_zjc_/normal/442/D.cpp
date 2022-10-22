// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, fa[1000005], cnt[1000005];
std::pair<int, int> dp[1000005], ol[1000005];
bool update(int now)
{
    int newv = std::max(dp[now].first, dp[now].second + 1),
        oldv = std::max(ol[now].first, ol[now].second + 1);
    if (newv == oldv)
        return false;
    ol[fa[now]] = dp[fa[now]];
    if (dp[fa[now]].first == oldv)
        dp[fa[now]].first = newv;
    else if (dp[fa[now]].second == oldv)
        dp[fa[now]].second = newv;
    else
        return false;
    return true;
}
signed main()
{
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    ++n;
    for (int i = 2; i <= n; ++i)
    {
        std::cin >> fa[i];
        ol[fa[i]] = dp[fa[i]];
        if (!dp[fa[i]].first)
            dp[fa[i]].first = 1;
        else if (!dp[fa[i]].second)
            dp[fa[i]].second = 1;
        for (int j = fa[i]; j > 1 && update(j); j = fa[j])
            ;
        std::cout << dp[1].first << " \n"[i == n];
    }
    return 0;
}