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
int n, m, s, t, ds, dt, a[400005], b[400005], fa[200005];
std::stringstream res;
std::vector<int> tos, tot;
bool hass[200005], hast[200005];
bool st;
int find(int now) { return now == fa[now] ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> a[i] >> b[i];
    std::cin >> s >> t >> ds >> dt;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        bool S = a[i] == s || b[i] == s, T = a[i] == t || b[i] == t;
        if (S && T)
            st = true;
        else if (S)
            tos.push_back(a[i] == s ? b[i] : a[i]);
        else if (T)
            tot.push_back(a[i] == t ? b[i] : a[i]);
        else if (find(a[i]) != find(b[i]))
            res << a[i] << ' ' << b[i] << std::endl, fa[find(a[i])] = find(b[i]);
    }
    for (auto i : tos)
        hass[find(i)] = true;
    for (auto i : tot)
        hast[find(i)] = true;
    for (auto i : tos)
        if (find(s) != find(i) && ds && !hast[find(i)])
            --ds, fa[find(s)] = find(i), res << s << ' ' << i << std::endl;
    for (auto i : tot)
        if (find(t) != find(i) && dt && !hass[find(i)])
            --dt, fa[find(t)] = find(i), res << t << ' ' << i << std::endl;
    for (auto i : tos)
        if (find(s) != find(i) && ds)
            --ds, fa[find(s)] = find(i), res << s << ' ' << i << std::endl;
    for (auto i : tot)
        if (find(t) != find(i) && dt)
            --dt, fa[find(t)] = find(i), res << t << ' ' << i << std::endl;
    if (st && ds && dt && find(s) != find(t))
        fa[find(s)] = find(t), --ds, --dt, res << s << ' ' << t << std::endl;
    for (int i = 1; i != n; ++i)
        if (find(i) != find(i + 1))
            return std::cout << "No" << std::endl, 0;
    std::cout << "Yes" << std::endl
              << res.str();
    return 0;
}