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
int n, fa[400005], root, depth[400005], siz[400005], heavy[400005], dp[400005], max[400005], lim;
std::vector<int> son[400005];
void init(int now)
{
    siz[now] = 1;
    heavy[now] = 0;
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        depth[i] = depth[now] + 1;
        fa[i] = now;
        init(i);
        siz[now] += siz[i];
        if (siz[heavy[now]] < siz[i])
            heavy[now] = i;
    }
}
void dfs1(int now)
{
    dp[now] = siz[now] <= lim ? siz[now] : 0;
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        dfs1(i);
        dp[now] = std::max(dp[now], dp[i]);
    }
}
void dfs2(int now, int maxsiz)
{
    max[now] = n - siz[now] > lim ? maxsiz : dp[heavy[now]];
    // std::cout << now << ' ' << max[now] << ' ' << siz[now] << std::endl;
    std::multiset<int> s;
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        s.insert(dp[i]);
    }
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        s.erase(s.find(dp[i]));
        s.insert(n - siz[i]);
        if (*s.begin() > lim)
            dfs2(i, maxsiz);
        else
            dfs2(i, std::max(maxsiz, *--s.upper_bound(lim)));
        s.erase(s.find(n - siz[i]));
        s.insert(dp[i]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    lim = n / 2;
    for (int i = 1; i != n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    fa[1] = 0;
    init(1);
    for (int i = 1; i <= n; ++i)
        if (std::max(siz[heavy[i]], n - siz[i]) <= lim)
            root = i;
    fa[root] = 0;
    init(root);
    dfs1(root);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << dp[i] << " \n"[i == n];
    dfs2(root, 0);
    // std::cout << root << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << (std::max(n - siz[i], siz[heavy[i]]) - max[i] <= lim) << " \n"[i == n];
    return 0;
}