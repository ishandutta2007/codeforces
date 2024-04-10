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
int T, n, fa[20][200005], siz[200005], ans[200005], depth[200005], A, B;
std::vector<int> son[200005];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    siz[now] = 1;
    for (auto i : son[now])
    {
        if (i == fa[0][now])
            continue;
        fa[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
        siz[now] += siz[i];
    }
}
int findfa(int now, int dep)
{
    for (int i = 19; ~i; --i)
        if (depth[now] - dep >= 1 << i)
            now = fa[i][now];
    return now;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::fill(fa[0], fa[0] + n, -1);
        std::fill(ans, ans + n + 1, 0);
        for (int i = 0; i != n; ++i)
            son[i].clear();
        for (int i = 1; i != n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            son[x].push_back(y);
            son[y].push_back(x);
        }
        init(0);
        for (auto i : son[0])
            ans[0] += siz[i] * (siz[i] - 1) / 2;
        ans[1] = n * (n - 1) / 2 - ans[0];
        A = B = 0;
        for (int i = 1; i != n; ++i)
        {
            if (findfa(A, depth[i]) == i || findfa(B, depth[i]) == i)
            {
            }
            else if (A == 0 && B == 0)
            {
                A = i;
            }
            else if (B == 0)
            {
                if (findfa(i, depth[A]) == A)
                    A = i;
                else
                {
                    B = i;
                    if (findfa(A, 1) == findfa(B, 1))
                        break;
                }
            }
            else
            {
                if (findfa(i, depth[A]) == A)
                    A = i;
                else if (findfa(i, depth[B]) == B)
                    B = i;
                else
                    break;
            }
            if (B == 0)
                ans[i + 1] = (n - siz[findfa(A, 1)]) * siz[A];
            else
                ans[i + 1] = siz[A] * siz[B];
        }
        for (int i = 2; i <= n; ++i)
            ans[i - 1] -= ans[i];
        for (int i = 0; i <= n; ++i)
            std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}