// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const long long INF = LLONG_MAX >> 1;
const int MOD = 1000000007;
int n, k, dp[100005][205], fa[100005], siz[100005], S[205][205], fact[205], sum[205], ans;
std::vector<int> son[100005];
void add(int &A, const int &B) { A = (A + B) % MOD; }
void dfs(int now)
{
    dp[now][0] = 1;
    siz[now] = 1;
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        fa[i] = now;
        dfs(i);
        std::vector<int> f(dp[now], dp[now] + std::min(k, siz[now]) + 1);
        for (int j = 0; j <= std::min(k, siz[i]); ++j)
        {
            add(dp[now][j], dp[i][j]);
            add(dp[now][j + 1], dp[i][j]);
        }
        for (int j = 0; j != (int)f.size(); ++j)
            for (int l = 0; l <= std::min(k - j, siz[i]); ++l)
            {
                int val = f[j] * dp[i][l] % MOD;
                add(dp[now][j + l], val);
                add(sum[j + l], val);
                add(dp[now][j + l + 1], val);
                add(sum[j + l + 1], val);
            }
        siz[now] += siz[i];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfs(1);
    fact[0] = 1;
    for (int i = 1; i <= k; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    S[0][0] = 1;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= i; ++j)
            S[i][j] = (S[i - 1][j] * j + S[i - 1][j - 1]) % MOD;
    for (int i = 0; i <= k; ++i)
        ans = (ans + fact[i] * S[k][i] % MOD * sum[i]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}