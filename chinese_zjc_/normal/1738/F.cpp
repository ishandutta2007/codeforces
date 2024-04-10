// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, d[1005], fa[1005], rk[1005];
bool vis[1005];
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> d[i];
        std::iota(fa, fa + n, 0);
        std::iota(rk, rk + n, 0);
        std::sort(rk, rk + n, [&](const int &A, const int &B)
                  { return d[A] > d[B]; });
        std::fill(vis, vis + n, false);
        for (int i = 0; i != n; ++i)
        {
            int t = rk[i];
            if (fa[t] == t)
                for (int j = 0, x; j != d[t]; ++j)
                {
                    std::cout << "? " << t + 1 << std::endl;
                    std::cin >> x;
                    --x;
                    int old = find(x);
                    fa[old] = find(t);
                    vis[find(t)] = true;
                    if (vis[old])
                        break;
                }
        }
        std::cout << '!';
        for (int i = 0; i != n; ++i)
            std::cout << ' ' << find(i) + 1;
        std::cout << std::endl;
    }
    return 0;
}