//This C ode was made by Chinese_zjc_.
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
int n, k, fa[200005], heavy[200005], siz[200005];
bool has[200005];
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
        siz[now] += siz[son[now][i]];
        if (siz[son[now][i]] > siz[heavy[now]])
            heavy[now] = son[now][i];
    }
}
void find(int now, std::vector<int> &pull, int no)
{
    if (now == no)
        return;
    if (has[now])
        pull.push_back(now);
    for (auto i : son[now])
        find(i, pull, no);
}
void work(int now)
{
    std::cout << 1 << std::endl
              << now << std::endl;
    std::vector<std::vector<int>> ans;
    for (auto i : son[now])
    {
        std::vector<int> s;
        find(i, s, now);
        ans.push_back(s);
    }
    std::vector<int> s;
    find(1, s, now);
    ans.push_back(s);
    if (has[now])
    {
        s.assign(1, now);
        ans.push_back(s);
    }
    std::priority_queue<std::pair<int, int>> que;
    for (int i = 0; i != (int)ans.size(); ++i)
        if (!ans[i].empty())
            que.push({ans[i].size(), i});
    while (!que.empty())
    {
        int A = que.top().second;
        que.pop();
        int B = que.top().second;
        que.pop();
        std::cout << ans[A].back() << ' ' << ans[B].back() << ' ' << now << std::endl;
        ans[A].pop_back();
        if (!ans[A].empty())
            que.push({ans[A].size(), A});
        ans[B].pop_back();
        if (!ans[B].empty())
            que.push({ans[B].size(), B});
    }
}
void dfs(int now)
{
    if (siz[heavy[now]] <= k)
        return work(now);
    dfs(heavy[now]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    for (int i = 1; i <= k + k; ++i)
    {
        static int x;
        std::cin >> x;
        siz[x] = has[x] = true;
    }
    init(1);
    dfs(1);
    return 0;
}