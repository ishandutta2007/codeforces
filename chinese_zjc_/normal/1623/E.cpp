// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, fa[20][200005], l[200005], r[200005], tim, dfn[200005], idfn[200005], depth[200005], turn[200005], end[200005];
char c[200005];
bool vis[200005];
void init(int now)
{
    if (!now)
        return;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    depth[l[now]] = depth[r[now]] = depth[now] + 1;
    turn[r[now]] = (turn[l[now]] = turn[now]) + 1;
    init(l[now]);
    idfn[dfn[now] = ++tim] = now;
    init(r[now]);
    end[now] = tim;
}
int need(int now)
{
    for (int i = 20; i--;)
        if (!vis[fa[i][now]])
            now = fa[i][now];
    return now;
}
void fill(int now)
{
    if (!vis[now])
    {
        vis[now] = true;
        --k;
        fill(fa[0][now]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    vis[0] = true;
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> l[i] >> r[i], fa[0][l[i]] = fa[0][r[i]] = i;
    fa[0][0] = 0;
    init(1);
    turn[0] = 0;
    for (int i = 1, j = 1; i <= n; i = j)
    {
        while (c[idfn[i]] == c[idfn[j]])
            ++j;
        if (c[idfn[i]] > c[idfn[j]])
            continue;
        do
        {
            int root = idfn[i];
            while (i <= dfn[fa[0][root]] && dfn[fa[0][root]] < j)
                root = fa[0][root];
            if (turn[root] - turn[need(root)] == 0)
                for (; i <= end[root] && i < j; ++i)
                    if (depth[idfn[i]] - depth[need(idfn[i])] < k)
                        fill(idfn[i]);
            i = end[root] + 1;
        } while (i < j);
    }
    for (int i = 1; i <= n; ++i)
    {
        std::cout << c[idfn[i]];
        if (vis[idfn[i]])
            std::cout << c[idfn[i]];
    }
    std::cout << std::endl;
    return 0;
}