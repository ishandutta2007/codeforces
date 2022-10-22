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
std::vector<int> son[200005];
int n, fa[200005], top[200005], button[200005], heavy[200005], size[200005], depth[200005], d, ans;
void init1(int now)
{
    size[now] = 1;
    for (int i = 0; i != son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init1(son[now][i]);
        size[now] += size[son[now][i]];
        heavy[now] = size[heavy[now]] < size[son[now][i]] ? son[now][i] : heavy[now];
    }
}
void init2(int now)
{
    for (int i = 0; i != son[now].size(); ++i)
    {
        if (son[now][i] == heavy[now])
            continue;
        top[son[now][i]] = son[now][i];
        init2(son[now][i]);
    }
    if (heavy[now])
    {
        top[heavy[now]] = top[now];
        init2(heavy[now]);
        button[now] = button[heavy[now]];
    }
    else
        button[now] = now;
}
int query(char c, int u)
{
    static int res;
    std::cout << c << ' ' << u << std::endl;
    std::cin >> res;
    return res;
}
void solve(int now)
{
    int nxt_depth = (depth[button[now]] + d - query('d', button[now])) / 2;
    while (depth[now] != nxt_depth)
        now = heavy[now];
    if (depth[now] == d)
        ans = now;
    else
        solve(query('s', now));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
    {
        static int u, v;
        std::cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    init1(1);
    top[1] = 1;
    init2(1);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << heavy[i] << ' ' << top[i] << ' ' << button[i] << std::endl;
    d = query('d', 1);
    solve(1);
    std::cout << '!' << ' ' << ans << std::endl;
    return 0;
}