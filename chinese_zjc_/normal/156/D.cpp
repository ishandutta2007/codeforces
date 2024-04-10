// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int fa[100005], siz[100005], n, m, MOD;
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
int mul(int A, int B) { return A && B ? 1ll * A * B % MOD : A ^ B; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> MOD;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1, x, y; i <= m; ++i)
    {
        std::cin >> x >> y;
        fa[find(x)] = find(y);
    }
    for (int i = 1; i <= n; ++i)
        ++siz[find(i)];
    if (n - std::count(siz + 1, siz + 1 + n, 0) == 1)
        return std::cout << 1 % MOD << std::endl, 0;
    std::cout << power(n, n - std::count(siz + 1, siz + 1 + n, 0) - 2) *
                     std::accumulate(siz + 1, siz + 1 + n, 1ll, mul) % MOD
              << std::endl;
    return 0;
}