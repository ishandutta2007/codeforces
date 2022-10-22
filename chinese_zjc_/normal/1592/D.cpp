// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, fa[1005], dfn[1005], tim;
std::vector<int> son[1005];
void init(int now)
{
    dfn[++tim] = now;
    for (auto i : son[now])
    {
        if (i == fa[now])
            continue;
        fa[i] = now;
        init(i);
    }
}
int query(int x)
{
    std::cout << "? " << x;
    for (int i = 1; i <= x; ++i)
        std::cout << ' ' << dfn[i];
    std::cout << std::endl;
    std::cin >> x;
    return x;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a, b; i != n; ++i)
    {
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(1);
    int ans = query(n);
    int l = 2, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (query(mid) == ans)
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << "! " << dfn[l] << ' ' << fa[dfn[l]] << std::endl;
    return 0;
}