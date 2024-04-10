// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, q, fa[20][100005], depth[100005];
struct node
{
    int min[20];
    node() { std::fill(min, min + 10, INT_MAX); }
    friend node operator+(const node &A, const node &B)
    {
        node res;
        std::merge(A.min, A.min + 10, B.min, B.min + 10, res.min);
        return res;
    }
} fe[20][100005];
std::vector<int> to[100005];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]], fe[i][now] = fe[i - 1][now] + fe[i - 1][fa[i - 1][now]];
    for (auto i : to[now])
    {
        if (i == fa[0][now])
            continue;
        fa[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
node query(int A, int B)
{
    node res;
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 20; i--;)
        if (depth[A] - depth[B] >= 1 << i)
            res = res + fe[i][A], A = fa[i][A];
    if (A == B)
        return res + fe[0][A];
    for (int i = 20; i--;)
        if (fa[i][A] != fa[i][B])
            res = res + fe[i][A] + fe[i][B], A = fa[i][A], B = fa[i][B];
    res = res + fe[0][A] + fe[0][B], A = fa[0][A], B = fa[0][B];
    return res + fe[0][A];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 1, x, y; i != n; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1, c; i <= m; ++i)
        std::cin >> c, *std::lower_bound(fe[0][c].min, fe[0][c].min + 10, INT_MAX) = i;
    init(1);
    while (q--)
    {
        int x, y, a;
        std::cin >> x >> y >> a;
        node res = query(x, y);
        int *end = std::find(res.min, res.min + a, INT_MAX);
        std::cout << end - res.min;
        for (int *i = res.min; i != end; ++i)
            std::cout << ' ' << *i;
        std::cout << std::endl;
    }
    return 0;
}