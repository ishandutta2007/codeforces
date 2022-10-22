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
int n, fa[1000005], depth[1000005], siz[1000005], ans[1000005], heavy[1000005], app[1000005], max;
std::vector<int> son[1000005];
void init(int now)
{
    siz[now] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
        siz[now] += siz[son[now][i]];
        if (siz[son[now][i]] > siz[heavy[now]])
            heavy[now] = son[now][i];
    }
}
void clear(int now)
{
    --app[depth[now]];
    for (auto i : son[now])
        clear(i);
}
void add(int now)
{
    ++app[depth[now]];
    if (app[max] < app[depth[now]] || (app[max] == app[depth[now]] && max > depth[now]))
        max = depth[now];
    for (auto i : son[now])
        add(i);
}
void dfs(int now)
{
    for (auto i : son[now])
    {
        if (i == heavy[now])
            continue;
        dfs(i);
        clear(i);
    }
    if (heavy[now])
        dfs(heavy[now]);
    for (auto i : son[now])
    {
        if (i == heavy[now])
            continue;
        add(i);
    }
    ++app[depth[now]];
    if (app[max] < app[depth[now]] || (app[max] == app[depth[now]] && max > depth[now]))
        max = depth[now];
    ans[now] = max - depth[now];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(1);
    dfs(1);
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << '\n';
    return 0;
}