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
int n, m, a[300005], b[300005], dfn[300005], low[300005], tim, s, t, fa[300005], has[300005];
bool bridge[300005], v[300005];
std::vector<int> to[300005], TO[300005];
void Tarjan(int now, int from)
{
    dfn[now] = low[now] = ++tim;
    for (auto i : to[now])
    {
        if (i == from)
            continue;
        int nxt = a[i] ^ b[i] ^ now;
        if (!dfn[nxt])
        {
            Tarjan(nxt, i);
            low[now] = std::min(low[now], low[nxt]);
            if (low[nxt] > dfn[now])
                bridge[i] = true;
        }
        else
            low[now] = std::min(low[now], dfn[nxt]);
    }
}
void paint(int now)
{
    fa[now] = tim;
    for (auto i : to[now])
    {
        if (bridge[i])
            continue;
        int nxt = a[i] ^ b[i] ^ now;
        if (v[i])
            has[tim] = true;
        if (!fa[nxt])
            paint(nxt);
    }
}
void dfs(int now, int from, bool vis)
{
    vis |= has[now];
    if (vis && now == fa[t])
        std::cout << "YES" << std::endl, exit(0);
    for (auto i : TO[now])
    {
        if (i == from)
            continue;
        dfs(fa[a[i]] ^ fa[b[i]] ^ now, i, vis | v[i]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i] >> v[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            Tarjan(i, 0);
    tim = 0;
    for (int i = 1; i <= n; ++i)
        if (!fa[i])
            ++tim, paint(i);
    for (int i = 1; i <= m; ++i)
        if (bridge[i])
            TO[fa[a[i]]].push_back(i), TO[fa[b[i]]].push_back(i);
    std::cin >> s >> t;
    if (has[fa[s]] && fa[s] == fa[t])
        return std::cout << "YES" << std::endl, 0;
    dfs(fa[s], 0, false);
    std::cout << "NO" << std::endl;
    return 0;
}