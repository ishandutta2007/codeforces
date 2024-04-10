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
std::map<int, std::vector<int>> map;
int n, a[100005], b[100005], F[100005], S[100005], fa[100005], siz[100005], root, ans1;
std::vector<int> ans2;
std::vector<int> son[100005];
int find(int now) { return F[now] == now ? now : F[now] = find(F[now]); }
void init(int now)
{
    siz[now] = S[now];
    for (auto i : son[now])
    {
        int to = find(a[i]) ^ find(b[i]) ^ now;
        if (fa[now] == to)
            continue;
        fa[to] = now;
        init(to);
        siz[now] += siz[to];
    }
}
void update(int pos, int val)
{
    if (val > ans1)
        ans1 = val, ans2.clear();
    if (val == ans1)
        ans2.push_back(pos);
}
void dfs(int now, int tot)
{
    for (auto i : son[now])
    {
        int to = find(a[i]) ^ find(b[i]) ^ now;
        if (to == fa[now])
            continue;
        update(i, (tot - siz[to]) * siz[to] * 2);
        dfs(to, tot);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        F[i] = i, S[i] = 1;
    for (int i = 1; i != n; ++i)
    {
        static int v;
        std::cin >> a[i] >> b[i] >> v;
        map[v].push_back(i);
    }
    for (auto i : map)
    {
        std::vector<int> node;
        for (auto j : i.second)
        {
            node.push_back(find(a[j]));
            node.push_back(find(b[j]));
        }
        std::sort(node.begin(), node.end());
        node.erase(std::unique(node.begin(), node.end()), node.end());
        for (auto j : node)
            son[j].clear(), fa[j] = 0, siz[j] = 0;
        for (auto j : i.second)
        {
            son[find(a[j])].push_back(j);
            son[find(b[j])].push_back(j);
        }
        for (auto j : node)
            if (!fa[j])
                init(j), dfs(j, siz[j]);
        for (auto j : i.second)
        {
            S[find(a[j])] += S[find(b[j])];
            F[find(b[j])] = find(a[j]);
        }
    }
    std::cout << ans1 << ' ' << ans2.size() << std::endl;
    std::sort(ans2.begin(), ans2.end());
    for (auto i : ans2)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}