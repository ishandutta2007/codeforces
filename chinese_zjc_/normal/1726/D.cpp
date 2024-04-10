// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
std::mt19937 Rand(std::chrono::system_clock::now().time_since_epoch().count());
int T, n, m, x[200005], y[200005], fa1[200005], fa2[200005];
bool ans[200005];
int find1(int now) { return fa1[now] == now ? now : fa1[now] = find1(fa1[now]); }
int find2(int now) { return fa2[now] == now ? now : fa2[now] = find2(fa2[now]); }
bool work()
{
    std::iota(fa1 + 1, fa1 + 1 + n, 1);
    std::iota(fa2 + 1, fa2 + 1 + n, 1);
    for (int i = 1; i <= m; ++i)
    {
        bool A = find1(x[i]) != find1(y[i]), B = find2(x[i]) != find2(y[i]);
        if (A && B)
            ans[i] = Rand() & 1;
        else
            ans[i] = B;
        if (!A && !B)
            return false;
        if (ans[i])
            fa2[find2(x[i])] = find2(y[i]);
        else
            fa1[find1(x[i])] = find1(y[i]);
    }
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= m; ++i)
            std::cin >> x[i] >> y[i];
        while (!work())
            ;
        for (int i = 1; i <= m; ++i)
            std::cout << ans[i];
        std::cout << std::endl;
    }
    return 0;
}