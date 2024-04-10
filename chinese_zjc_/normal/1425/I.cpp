// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, a[50005], b[50005], c[50005], fa[50005], dfn[50005], tim, end[50005], v[50005];
std::vector<int> son[50005];
void init(int now)
{
    dfn[now] = ++tim;
    c[dfn[now]] = c[dfn[fa[now]]] + 1;
    for (auto i : son[now])
        init(i);
    end[now] = tim;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[i], son[fa[i]].push_back(i);
    init(1);
    for (int i = 1; i <= n; ++i)
        b[dfn[i]] = a[i];
    for (register int i = 1, x, sum, cnt; i <= q; ++i)
    {
        std::cin >> x;
        sum = cnt = 0;
        for (register int j = dfn[x], ed = end[x]; j <= ed; ++j)
            if (v[j] <= i)
                v[j] = i + b[j], sum += c[j], ++cnt;
        std::cout << sum - cnt * c[dfn[x]] << ' ' << cnt << std::endl;
    }
    return 0;
}