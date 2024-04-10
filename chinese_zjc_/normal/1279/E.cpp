// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, rk[55], fa[55];
unsigned long long k, f[55], g[55];
bool app[55];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    f[1] = f[2] = f[3] = 1;
    for (int i = 4; i <= 50; ++i)
        f[i] = f[i - 1] * (i - 2);
    g[0] = 1;
    for (int i = 1; i <= 50; ++i)
        for (int j = i; j; --j)
            g[i] += g[i - j] * f[j];
    while (T--)
    {
        std::cin >> n >> k;
        memset(app, false, sizeof(app));
        --k;
        for (int i = 1; i <= n; ++i)
            fa[i] = i, rk[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
                if (k / g[n - j] < f[j - i + 1])
                {
                    app[fa[i] = rk[i] = j] = true;
                    for (int l = i + 1; l < j; ++l)
                        for (int o = i; o <= j; ++o)
                            if (!app[o] && find(l) != find(o))
                            {
                                if (k / g[n - j] < f[j - l + 1])
                                {
                                    app[fa[l] = rk[l] = o] = true;
                                    break;
                                }
                                else
                                    k -= f[j - l + 1] * g[n - j];
                            }
                    for (int l = i; l <= j; ++l)
                        if (!app[l])
                        {
                            app[fa[j] = rk[j] = l] = true;
                            break;
                        }
                    i = j;
                    break;
                }
                else
                    k -= f[j - i + 1] * g[n - j];
            if (!rk[i])
            {
                k = -1;
                break;
            }
        }
        if (k)
            std::cout << -1 << std::endl;
        else
            for (int i = 1; i <= n; ++i)
                std::cout << rk[i] << " \n"[i == n];
    }
    return 0;
}