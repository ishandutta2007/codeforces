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
int n, k, a[300005], in[300005], out[300005], belong[300005], cnt;
std::vector<int> to[300005];
std::vector<std::vector<int>> seg;
std::stringstream res;
std::queue<int> que;
void work(int now)
{
    belong[now] = seg.size() - 1;
    seg.back().push_back(now);
    if (!to[now].empty())
        work(to[now].back());
}
void print(const std::vector<int> &now)
{
    for (auto i : now)
        res << i << " \n"[++cnt == n];
}
bool app[300005];
void check(const std::vector<int> &now)
{
    for (auto i : now)
        app[i] = false;
    for (auto i : now)
        if (!app[a[i]])
            std::cout << 0 << std::endl, exit(0);
        else
            app[i] = true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(app, true, sizeof(app));
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= k; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        ++out[x];
        ++in[y];
        to[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
        if ((in[i] | out[i]) > 1)
            return std::cout << 0 << std::endl, 0;
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            seg.push_back(std::vector<int>()), work(i), check(seg.back());
    for (int i = 1; i <= n; ++i)
        in[i] = out[i] = 0, to[i].clear();
    for (int i = 1; i <= n; ++i)
        if (a[i] && belong[a[i]] != belong[i])
            to[belong[a[i]]].push_back(belong[i]), ++in[belong[i]];
    for (int i = 0; i != (int)seg.size(); ++i)
        if (!in[i])
            que.push(i);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        print(seg[now]);
        for (auto i : to[now])
            if (!--in[i])
                que.push(i);
    }
    if (cnt == n)
        std::cout << res.str();
    else
        std::cout << 0 << std::endl;
    return 0;
}