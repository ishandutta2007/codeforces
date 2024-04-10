// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, m, ans, cnt[2005], fa[4005], f;
bool vis[4005], sum[4005], v[4005];
char c[2005][2005];
std::vector<int> to[4005];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
void dfs(int now, int fa, bool goal)
{
    v[now] = sum[now];
    for (auto i : to[now])
    {
        if (i == fa)
            continue;
        dfs(i, now, goal);
        if (v[i] != goal)
            v[i] ^= true, v[now] ^= true;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    switch ((n & 1) << 1 | (m & 1))
    {
    case 0:
        ans = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '?')
                    ans = ans * 2 % MOD;
        break;
    case 1:
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '?')
                    ++cnt[i];
                else
                    sum[i] ^= c[i][j] ^ '0';
        for (int k = 0; k != 2; ++k)
        {
            int res = 1;
            for (int i = 1; i <= n; ++i)
                if (cnt[i])
                    res = 1ll * res * power(2, cnt[i] - 1) % MOD;
                else if (sum[i] != k)
                    res = 0;
            ans = (ans + res) % MOD;
        }
        break;
    case 2:
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '?')
                    ++cnt[j];
                else
                    sum[j] ^= c[i][j] ^ '0';
        for (int k = 0; k != 2; ++k)
        {
            int res = 1;
            for (int i = 1; i <= m; ++i)
                if (cnt[i])
                    res = 1ll * res * power(2, cnt[i] - 1) % MOD;
                else if (sum[i] != k)
                    res = 0;
            ans = (ans + res) % MOD;
        }
        break;
    case 3:
        std::iota(fa + 1, fa + 1 + n + m, 1);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (c[i][j] == '?')
                    if (find(i) != find(n + j))
                        to[i].push_back(n + j), to[n + j].push_back(i), fa[find(i)] = find(n + j);
                    else
                        ++f;
                else
                    sum[i] ^= c[i][j] ^ '0', sum[n + j] ^= c[i][j] ^ '0';
        for (int k = 0; k != 2; ++k)
        {
            std::fill(vis + 1, vis + 1 + n + m, false);
            bool able = true;
            for (int i = 1; i <= n + m; ++i)
            {
                if (!vis[i])
                    dfs(i, 0, k);
                able &= v[i] == k;
            }
            if (able)
                ans = (ans + power(2, f)) % MOD;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}