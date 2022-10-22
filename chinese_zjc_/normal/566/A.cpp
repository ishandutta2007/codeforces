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
int n, root, son[800005][26], fa[800005], cnt, depth[800005], ans;
std::string s[100005], t[100005];
std::vector<int> app1[800005], app2[800005];
std::stringstream res;
template <class T>
void add(int now, int pos, const std::string &x, T fun)
{
    if (pos == (int)x.size())
        return fun(now);
    if (!son[now][x[pos] - 'a'])
        ++cnt, depth[son[now][x[pos] - 'a'] = cnt] = depth[fa[cnt] = now] + 1;
    add(son[now][x[pos] - 'a'], pos + 1, x, fun);
}
void merge(std::vector<int> &A, std::vector<int> &B)
{
    if (A.size() < B.size())
        A.swap(B);
    A.insert(A.end(), B.begin(), B.end());
    B.clear();
    B.shrink_to_fit();
}
void dfs(int now)
{
    for (int i = 0; i != 26; ++i)
        if (son[now][i])
            dfs(son[now][i]), merge(app1[now], app1[son[now][i]]), merge(app2[now], app2[son[now][i]]);
    while (!app1[now].empty() && !app2[now].empty())
    {
        ans += depth[now];
        res << app1[now].back() << ' ' << app2[now].back() << std::endl;
        app1[now].pop_back();
        app2[now].pop_back();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    root = ++cnt;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i], add(root, 0, s[i], [&](const int &x)
                              { app1[x].push_back(i); });
    for (int i = 1; i <= n; ++i)
        std::cin >> t[i], add(root, 0, t[i], [&](const int &x)
                              { app2[x].push_back(i); });
    dfs(root);
    std::cout << ans << std::endl
              << res.str();
    return 0;
}