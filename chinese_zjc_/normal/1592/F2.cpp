// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, ans, match[505], vis[505], cnt;
bool a[505][505], t[505][505];
bool dfs(int now, int tag)
{
    if (tag == vis[now])
        return false;
    vis[now] = tag;
    for (int i = 1; i < m; ++i)
        if (a[n][i] && a[now][i] && (!match[i] || dfs(match[i], tag)))
        {
            match[i] = now;
            return true;
        }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            static char c;
            std::cin >> c;
            a[i][j] = c == 'B';
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans += a[i][j] ^= a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1];
    for (int i = 1; i < n; ++i)
        if (a[i][m] && dfs(i, i))
            ++cnt;
    ans -= cnt;
    ans -= a[n][m];
    ans += a[n][m] ^ (cnt & 1);
    std::cout << ans << std::endl;
    return 0;
}