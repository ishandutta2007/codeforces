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
int n, m, a[400005], b[400005], dfn[400005], low[400005], tim, fa[400005], cnt, siz[400005];
bool bridge[400005], vis[400005];
std::vector<int> to[400005], TO[400005];
void Tarjan(int now, int from)
{
    // std::cout << now << std::endl;
    dfn[now] = low[now] = ++tim;
    for (auto i : to[now])
    {
        if (i == from)
            continue;
        int to = a[i] ^ b[i] ^ now;
        if (!dfn[to])
        {
            Tarjan(to, i);
            low[now] = std::min(low[now], low[to]);
            if (low[to] > dfn[now])
                bridge[i] = true;
        }
        else
            low[now] = std::min(low[now], dfn[to]);
    }
}
void paint(int now, int from)
{
    // std::cout << now << std::endl;
    ++siz[fa[now] = cnt];
    for (auto i : to[now])
    {
        if (bridge[i] || vis[i])
            continue;
        if (a[i] != now)
            std::swap(a[i], b[i]);
        vis[i] = true;
        if (!fa[b[i]])
            paint(b[i], i);
    }
}
void dfs(int now, int from)
{
    for (auto i : TO[now])
    {
        if (i == from)
            continue;
        if (fa[a[i]] != now)
            std::swap(a[i], b[i]);
        vis[i] = true;
        dfs(fa[b[i]], i);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            Tarjan(i, 0);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << dfn[i] << " " << low[i] << std::endl;
    for (int i = 1; i <= n; ++i)
        if (!fa[i])
        {
            ++cnt;
            paint(i, 0);
            // std::cout << std::endl;
        }
    for (int i = 1; i <= m; ++i)
        if (bridge[i])
        {
            // std::cout << "YES " << i << std::endl;
            TO[fa[a[i]]].push_back(i);
            TO[fa[b[i]]].push_back(i);
        }
    int root = std::max_element(siz + 1, siz + 1 + cnt) - siz;
    std::cout << siz[root] << std::endl;
    dfs(root, 0);
    for (int i = 1; i <= m; ++i)
        std::cout << b[i] << ' ' << a[i] << std::endl;
    return 0;
}