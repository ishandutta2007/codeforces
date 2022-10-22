// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int INF = INT_MAX >> 1;
int n, m, ans[100005], a[100005], b[100005], fa[20][100005], depth[100005], s[100005];
std::vector<int> to[100005];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : to[now])
    {
        int v = a[i] ^ b[i] ^ now;
        if (v == fa[0][now])
            continue;
        fa[0][v] = now;
        depth[v] = depth[now] + 1;
        init(v);
    }
}
int LCA(int A, int B)
{
    if (depth[A] > depth[B])
        std::swap(A, B);
    for (int i = 19; i >= 0; --i)
        if (depth[B] - depth[A] >= 1 << i)
            B = fa[i][B];
    if (A == B)
        return A;
    for (int i = 19; i >= 0; --i)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
void work(int now)
{
    for (auto i : to[now])
    {
        int v = a[i] ^ b[i] ^ now;
        if (v == fa[0][now])
            continue;
        work(v);
        s[now] += s[v];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i != n; ++i)
        std::cin >> a[i] >> b[i], to[a[i]].push_back(i), to[b[i]].push_back(i);
    init(1);
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        ++s[x];
        ++s[y];
        s[LCA(x, y)] -= 2;
    }
    work(1);
    for (int i = 1; i != n; ++i)
        std::cout << (depth[a[i]] < depth[b[i]] ? s[b[i]] : s[a[i]]) << " \n"[i == n - 1];
    return 0;
}