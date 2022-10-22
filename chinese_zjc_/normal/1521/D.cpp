//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, n, fa[100005], dp[3][100005], back;
std::vector<int> son[100005];
struct ANS
{
    int a, b, lca;
};
std::vector<ANS> ans;
void init(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        init(son[now][i]);
    }
}
int dfs(int now)
{
    std::vector<std::pair<int, int>> g;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        int back = dfs(son[now][i]);
        if (back)
            g.push_back(std::make_pair(back, son[now][i]));
    }
    if (g.empty())
        return now;
    if (g.size() == 1)
        return g[0].first;
    for (int i = 2; i != (int)g.size(); ++i)
        ans.push_back({g[i].first, g[i].second, g[i].second});
    ans.push_back({g[0].first, g[1].first, now});
    return 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            son[i].clear();
        back = 0;
        ans.clear();
        for (int i = 1; i < n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            son[x].push_back(y);
            son[y].push_back(x);
        }
        init(1);
        int back = dfs(1);
        if (back)
            ans.push_back({back, 1, 1});
        std::cout << ans.size() - 1 << std::endl;
        for (int i = 1; i != (int)ans.size(); ++i)
        {
            std::cout << ans[i - 1].lca << ' ' << fa[ans[i - 1].lca] << ' ' << ans[i - 1].b << ' ' << ans[i].a << std::endl;
        }
    }
    return 0;
}