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
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
int n, f[50], x[200005], y[200005], siz[30][200005];
std::vector<int> to[200005], sta;
bool vis[200005];
bool find(int x) { return std::binary_search(f, f + 30, x); }
void init(int tim, int now, int fa = 0)
{
    siz[tim][now] = 1;
    for (auto i : to[now])
    {
        if (fa == i || vis[i])
            continue;
        int nxt = x[i] ^ y[i] ^ now;
        init(tim, nxt, i);
        siz[tim][now] += siz[tim][nxt];
    }
}
bool check(int tim, int now);
int dfs(int tim, int now, int tot, int fa = 0)
{
    for (auto i : to[now])
    {
        if (fa == i || vis[i])
            continue;
        int nxt = x[i] ^ y[i] ^ now;
        if (find(siz[tim][nxt]) && find(tot - siz[tim][nxt]))
        {
            vis[i] = true;
            sta.push_back(i);
            if (check(tim + 1, nxt) && check(tim + 1, now))
                return 1;
            while (sta.back() != i)
                vis[sta.back()] = false, sta.pop_back();
            vis[i] = false;
            sta.pop_back();
            return 0;
        }
        int back = dfs(tim, nxt, tot, i);
        if (~back)
            return back;
    }
    return -1;
}
bool check(int tim, int now)
{
    init(tim, now);
    return siz[tim][now] == 1 || dfs(tim, now, siz[tim][now]) == 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i != 30; ++i)
        f[i] = f[i - 1] + f[i - 2];
    for (int i = 1; i != n; ++i)
    {
        std::cin >> x[i] >> y[i];
        to[x[i]].push_back(i);
        to[y[i]].push_back(i);
    }
    std::cout << (find(n) && check(0, 1) ? "YES" : "NO") << std::endl;
    return 0;
}