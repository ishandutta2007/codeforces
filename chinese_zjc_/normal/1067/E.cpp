// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int n, dp[500005][2][2];
std::vector<int> to[500005];
void add(int &A, int B) { A = (A + B) % MOD; }
void mul(int &A, int B) { A = 1ll * A * B % MOD; }
void dfs(int now, int fa = 0)
{
    dp[now][0][0] = 1;
    for (auto s : to[now])
    {
        if (s == fa)
            continue;
        dfs(s, now);
        int tmp[2][2];
        std::memcpy(tmp, dp[now], sizeof(tmp));
        std::memset(dp[now], 0, sizeof(dp[now]));
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
            {
                add(dp[now][i][0], 1ll * tmp[i][0] * dp[s][j][0] % MOD);
                add(dp[now][i][1], (1ll * tmp[i][0] * dp[s][j][1] + 1ll * tmp[i][1] * dp[s][j][0]) % MOD);
                if (i == 0 && j == 0)
                {
                    add(dp[now][1][0], 1ll * tmp[i][0] * dp[s][j][0] % MOD);
                    add(dp[now][1][1], (1ll * tmp[i][0] * dp[s][j][1] + 1ll * tmp[i][1] * dp[s][j][0] +
                                        2ll * tmp[i][0] * dp[s][j][0]) %
                                           MOD);
                }
                else
                {
                    add(dp[now][i][0], 1ll * tmp[i][0] * dp[s][j][0] % MOD);
                    add(dp[now][i][1], (1ll * tmp[i][0] * dp[s][j][1] + 1ll * tmp[i][1] * dp[s][j][0]) % MOD);
                }
            }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs(1);
    std::cout << (dp[1][0][1] + dp[1][1][1]) % MOD << std::endl;
    return 0;
}