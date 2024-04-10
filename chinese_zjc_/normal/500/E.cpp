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
int n, m, p[200005], l[200005], fa[20][200005], dis[20][200005], depth[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i] >> l[i], l[i] += p[i];
    for (int i = n - 1; i >= 1; --i)
    {
        fa[0][i] = i + 1;
        while (fa[0][i] && l[i] > l[fa[0][i]])
            fa[0][i] = fa[0][fa[0][i]];
        depth[i] = depth[fa[0][i]] + 1;
        dis[0][i] = std::max(0ll, p[fa[0][i]] - l[i]);
        for (int j = 1; 1 << j <= depth[i]; ++j)
            fa[j][i] = fa[j - 1][fa[j - 1][i]], dis[j][i] = dis[j - 1][i] + dis[j - 1][fa[j - 1][i]];
    }
    std::cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        static int l, r, now, ans;
        std::cin >> l >> r;
        now = l;
        ans = 0;
        for (int i = 19; i >= 0; --i)
            if (fa[i][now] != 0 && fa[i][now] <= r)
            {
                ans += dis[i][now];
                now = fa[i][now];
            }
        std::cout << ans << std::endl;
    }
    return 0;
}