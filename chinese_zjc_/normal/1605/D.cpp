// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, ans[200005], fa[200005], cnt;
bool depth[200005], used[200005];
std::vector<int> to[200005], L;
void init(int now)
{
    if (depth[now])
        L.push_back(now);
    for (auto i : to[now])
    {
        if (i == fa[now])
            continue;
        depth[i] = !depth[fa[i] = now];
        init(i);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::fill(ans + 1, ans + 1 + n, 0);
        std::fill(fa + 1, fa + 1 + n, 0);
        std::fill(depth + 1, depth + 1 + n, false);
        std::fill(used + 1, used + 1 + n, false);
        std::for_each(to + 1, to + 1 + n, [](std::vector<int> &x)
                      { x.clear(); });
        L.clear();
        cnt = 0;
        for (int i = 1, a, b; i < n; ++i)
        {
            std::cin >> a >> b;
            to[a].push_back(b);
            to[b].push_back(a);
        }
        init(1);
        for (int i = 20; i--;)
            if (int(L.size()) >= 1 << i)
                for (int j = 1 << i; j <= n && j != 1 << i << 1; ++j)
                    used[ans[L.back()] = j] = true, L.pop_back();
        for (int i = 1; i <= n; ++i)
            if (!ans[i])
            {
                while (used[++cnt])
                    ;
                ans[i] = cnt;
            }
        for (int i = 1; i <= n; ++i)
            std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}