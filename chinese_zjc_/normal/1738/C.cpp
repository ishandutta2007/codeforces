// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, t[2];
int dp[105][105][2];
bool dfs(int A, int B, bool cur)
{
    if (~dp[A][B][cur])
        return dp[A][B][cur];
    if (A == 0 && B == 0)
        return (dp[A][B][cur] = cur == 0);
    return (dp[A][B][cur] = (A && !dfs(A - 1, B, cur ^ !(B & 1))) || (B && !dfs(A, B - 1, cur ^ !(B & 1))));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    std::memset(dp, -1, sizeof(dp));
    while (T--)
    {
        std::cin >> n;
        t[0] = t[1] = 0;
        for (int i = 1, x; i <= n; ++i)
            std::cin >> x, ++t[x & 1];
        std::cout << (dfs(t[0], t[1], 0) ? "Alice" : "Bob") << std::endl;
    }
    return 0;
}