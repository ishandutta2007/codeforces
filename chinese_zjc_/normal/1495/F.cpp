// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, p[200005], a[200005], b[200005], fa[20][200005], D[200005];
long long f[200005], g[200005], depth[200005], ans;
std::vector<int> son[200005], sta;
std::set<int> set;
void init(int now)
{
    for (int i = 1; 1 << i <= D[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : son[now])
    {
        D[i] = D[now] + 1;
        init(i);
        g[now] += f[i];
    }
    f[now] = std::min(now == 0 ? LLONG_MAX : b[now], a[now] + g[now]);
}
void init_(int now)
{
    depth[now] += a[now] + g[now];
    for (auto i : son[now])
    {
        depth[i] = depth[now] - f[i];
        init_(i);
    }
}
int LCA(int A, int B)
{
    if (D[A] < D[B])
        std::swap(A, B);
    for (int i = 20; i--;)
        if (D[fa[i][A]] >= D[B])
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 20; i--;)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
long long dis(int A, int B)
{
    A = fa[0][A];
    B = fa[0][B];
    return depth[A] + depth[B] - 2 * depth[LCA(A, B)];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i];
    p[0] = n + 2;
    p[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    sta.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        while (p[sta.back()] < p[i])
            sta.pop_back();
        son[fa[0][i] = sta.back()].push_back(i);
        sta.push_back(i);
    }
    init(0);
    init_(0);
    set.insert(0);
    set.insert(n + 1);
    ans += g[0] * 2;
    for (int i = 0, x; i != m; ++i)
    {
        std::cin >> x;
        std::set<int>::iterator iter = set.find(x);
        if (iter == set.end())
        {
            iter = set.upper_bound(x);
            ans -= dis(*std::prev(iter), *iter);
            ans += dis(*std::prev(iter), x);
            ans += dis(x, *iter);
            set.insert(x);
        }
        else
        {
            set.erase(iter++);
            ans -= dis(*std::prev(iter), x);
            ans -= dis(x, *iter);
            ans += dis(*std::prev(iter), *iter);
        }
        std::cout << (ans / 2) << std::endl;
    }
    return 0;
}