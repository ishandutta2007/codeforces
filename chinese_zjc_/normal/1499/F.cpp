//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
const int MOD = 998244353;
short n, k, fa[5005];
int ans;
std::vector<short> to[5005];
long long power(long long A, long long B)
{
    long long res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
long long inv(int x) { return x ? power(x, MOD - 2) : 1; }
std::array<int, 5005> dfs(short now)
{
    for (short i = 0; i != (short)to[now].size(); ++i)
    {
        if (to[now][i] == fa[now])
        {
            to[now].erase(to[now].begin() + i--);
            continue;
        }
        fa[to[now][i]] = now;
    }
    std::vector<std::array<int, 5005>> dp(to[now].size());
    std::array<int, 5005> res;
    res.fill(0);
    for (short i = 0; i != (short)to[now].size(); ++i)
        dp[i] = dfs(to[now][i]);
    int pre[k + 1], suf[to[now].size() + 1][k + 1];
    std::fill(pre, pre + k + 1, 1);
    std::fill(suf[to[now].size()], suf[to[now].size()] + k + 1, 1);
    for (short i = to[now].size(); i--;)
    {
        long long val = 0;
        for (short j = 0; j <= k; ++j)
            val = (val + dp[i][j]) % MOD;
        for (short j = 0; j <= k; ++j)
            suf[i][j] = suf[i + 1][j] * val % MOD, val = (val + dp[i][j]) % MOD;
    }
    res[0] = suf[0][0];
    for (short i = 0; i != (short)to[now].size(); ++i)
    {
        for (short j = 1; j <= k; ++j)
        {
            short l = std::min(j - 0, k - j);
            res[j] = (res[j] + 1ll * dp[i][j - 1] * pre[std::min(j - 1, k - j)] % MOD * suf[i + 1][l]) % MOD;
        }
        long long val = 0;
        val = 0;
        for (short j = 0; j <= k; ++j)
            val = (val + dp[i][j]) % MOD;
        for (short j = 0; j <= k; ++j)
            pre[j] = pre[j] * val % MOD, val = (val + dp[i][j]) % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (short i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    std::array<int, 5005> dp = dfs(1);
    for (int i = 0; i <= k; ++i)
        ans = (ans + dp[i]) % MOD;
    // std::array<int, 5005> T[5005];
    // for (int i = 1; i <= n; ++i)
    //     T[i] = dfs(i);
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 0; j <= k; ++j)
    //         std::cout << T[i][j] << " \n"[j == k];
    std::cout << ans << std::endl;
    return 0;
}