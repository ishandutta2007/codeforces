// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, m, dp[65];
std::map<long long, int> bad;
const char color[] = {'w', 'o', 'b', 'y', 'r', 'g'};
struct node
{
    int v[6];
    node() : v() {}
    node(int x) : v{x, x, x, x, x, x} {}
};
#define lson (now << 1)
#define rson (lson | 1)
node dfs(long long now, int depth)
{
    int pos = bad[now];
    node res;
    if (~pos)
    {
        if (!bad.count(lson) && !bad.count(rson))
        {
            res.v[pos] = dp[depth];
            return res;
        }
        node l = bad.count(lson) ? dfs(lson, depth - 1) : dp[depth - 1],
             r = bad.count(rson) ? dfs(rson, depth - 1) : dp[depth - 1];
        unsigned L = 0, R = 0;
        for (int i = 0; i != 6; ++i)
            if (i % 3)
                L += l.v[(pos + i) % 6], R += r.v[(pos + i) % 6];
        res.v[pos] = 1llu * L * R % MOD;
        return res;
    }
    node l = bad.count(lson) ? dfs(lson, depth - 1) : dp[depth - 1],
         r = bad.count(rson) ? dfs(rson, depth - 1) : dp[depth - 1];
    for (int i = 0; i != 6; ++i)
        for (int j = 0; j != 6; ++j)
            for (int k = 0; k != 6; ++k)
                if ((i - k) % 3 && (j - k) % 3)
                    res.v[k] = (res.v[k] + 1ll * l.v[i] * r.v[j]) % MOD;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = 4llu * dp[i - 1] * 4llu * dp[i - 1] % MOD;
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static long long x;
        static std::string y;
        std::cin >> x >> y;
        bad[x] = std::find(color, color + 6, y.front()) - color;
        for (x >>= 1; x; x >>= 1)
            bad.insert({x, -1});
    }
    node res = dfs(1, n);
    std::cout << std::accumulate(res.v, res.v + 6, 0ll) % MOD << std::endl;
    return 0;
}