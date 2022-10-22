//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[100005], b[100005], w[100005], FA[100005], fa[20][100005], max[20][100005], rk[100005], depth[100005],
    fe[100005];
std::vector<int> to[100005];
std::string ans[100005];
int find(int now) { return FA[now] == now ? now : FA[now] = find(FA[now]); }
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]], max[i][now] = std::max(max[i - 1][now], max[i - 1][fa[i - 1][now]]);
    for (auto i : to[now])
    {
        int nxt = a[i] ^ b[i] ^ now;
        if (fa[0][now] == nxt)
            continue;
        fa[0][nxt] = now;
        max[0][nxt] = w[i];
        fe[nxt] = i;
        depth[nxt] = depth[now] + 1;
        init(nxt);
    }
}
int dis(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    int res = 0;
    for (int i = 19; ~i; --i)
        if (depth[A] - depth[B] >= 1 << i)
            res = std::max(res, max[i][A]), A = fa[i][A];
    if (A == B)
        return res;
    for (int i = 19; ~i; --i)
        if (fa[i][A] != fa[i][B])
            res = std::max(res, std::max(max[i][A], max[i][B])), A = fa[i][A], B = fa[i][B];
    return res = std::max(res, std::max(max[0][A], max[0][B]));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i] >> w[i], rk[i] = i;
    std::sort(rk + 1, rk + 1 + m, [&](const int &A, const int &B)
              { return w[A] < w[B]; });
    for (int i = 1; i <= n; ++i)
        FA[i] = i;
    for (int i = 1; i <= m; ++i)
        if (find(a[rk[i]]) != find(b[rk[i]]))
            FA[find(a[rk[i]])] = find(b[rk[i]]), to[a[rk[i]]].push_back(rk[i]), to[b[rk[i]]].push_back(rk[i]);
    init(1);
    for (int i = 1; i <= n; ++i)
        FA[i] = i;
    for (int j = 1; j <= m; ++j)
    {
        int i = rk[j];
        if (dis(a[i], b[i]) < w[i])
            ans[i] = "none";
        else if (fe[a[i]] == i || fe[b[i]] == i)
            ans[i] = "any";
        else
        {
            ans[i] = "at least one";
            int A = find(a[i]), B = find(b[i]);
            while (A != B)
            {
                if (depth[A] < depth[B])
                {
                    // std::cout << fe[B] << ' ' << i << std::endl;
                    if (w[fe[B]] == w[i])
                        ans[fe[B]] = ans[i];
                    B = FA[B] = find(fa[0][B]);
                }
                else
                {
                    if (w[fe[A]] == w[i])
                        ans[fe[A]] = ans[i];
                    A = FA[A] = find(fa[0][A]);
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}