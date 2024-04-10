//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int sum[100005], s[100005], depth[100005], fa[20][100005], siz[100005], n, m;
std::vector<int> to[100005];
void init1(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    sum[now] = depth[now];
    siz[now] = 1;
    for (auto i : to[now])
    {
        if (i == fa[0][now])
            continue;
        depth[i] = depth[now] + 1;
        fa[0][i] = now;
        init1(i);
        sum[now] += sum[i];
        siz[now] += siz[i];
    }
}
void init2(int now)
{
    s[now] = s[fa[0][now]] +
             (sum[fa[0][now]] - sum[now]) -
             (siz[fa[0][now]] - siz[now]) * depth[fa[0][now]] +
             (n - siz[now]);
    for (auto i : to[now])
    {
        if (fa[0][now] == i)
            continue;
        init2(i);
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
int run(int A, int B)
{
    for (int i = 19; i >= 0; --i)
        if (depth[B] - depth[A] > 1 << i)
            B = fa[i][B];
    return B;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(9);
    std::cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    init1(1);
    for (auto i : to[1])
        init2(i);
    for (int i = 1; i <= m; ++i)
    {
        static int a, b, lca;
        std::cin >> a >> b;
        if (depth[a] > depth[b])
            std::swap(a, b);
        lca = LCA(a, b);
        if (lca == a)
        {
            int tmp = run(a, b);
            std::cout << s[tmp] * 1.0l / (n - siz[tmp]) + sum[b] * 1.0l / siz[b] - depth[tmp] + 1 << std::endl;
        }
        else
        {
            std::cout << sum[a] * 1.0l / siz[a] + sum[b] * 1.0l / siz[b] - 2 * depth[lca] + 1 << std::endl;
        }
    }
    return 0;
}