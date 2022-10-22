// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, m, x, y, fa[105], dp[105][105][105], siz[105], ans[105], C[105][105];
std::vector<int> to[105];
void add(int &A, const int &B) { A = A + B >= MOD ? A + B - MOD : A + B; }
void sub(int &A, const int &B) { add(A, MOD - B); }
void mul(int &A, const int &B) { A = 1ll * A * B % MOD; }
void dfs(int now)
{
    siz[now] = 1;
    dp[now][0][0] = 1;
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        dfs(i);
        for (int j = siz[now]; j >= 0; --j)
            for (int l = siz[now]; l >= 0; --l)
            {
                int tmp = dp[now][j][l];
                dp[now][j][l] = 0;
                for (int k = 0; k <= siz[i]; ++k)
                    for (int o = 0; o <= siz[i]; ++o)
                        add(dp[now][j + k][l + o], 1ll * tmp * dp[i][k][o] % MOD);
            }
        siz[now] += siz[i];
    }
    for (int i = 0; i <= siz[now]; ++i)
        for (int j = 0; j < siz[now]; ++j)
            add(dp[now][siz[now]][j + 1], 1ll * dp[now][i][j] * (siz[now] - i) % MOD);
}
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        A = 1ll * A * A % MOD;
        B >>= 1;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (int i = 1; i != n; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
            add(ans[n - i], dp[1][n][j]);
        ans[n - i] = 1ll * dp[1][n][i] * power(n, MOD + i - 3) % MOD;
    }
    for (int i = n; i--;)
        for (int j = i + 1; j != n; ++j)
            sub(ans[i], 1ll * ans[j] * C[j][i] % MOD);
    for (int i = 0; i != n; ++i)
        std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}