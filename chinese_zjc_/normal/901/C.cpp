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
int n, m, R[300005], belong[300005], cnt, dfn[300005], low[300005], tim, c[300005], bad, sum[300005], q;
std::map<int, std::map<int, int>> map;
std::stack<int> p;
std::vector<std::pair<int, int>> to[300005];
std::stringstream res;
void Tarjan(int now, int from)
{
    dfn[now] = low[now] = ++tim;
    p.push(now);
    for (auto i : to[now])
    {
        if (i.second == from)
            continue;
        if (!dfn[i.first])
        {
            Tarjan(i.first, i.second);
            low[now] = std::min(low[now], low[i.first]);
            if (low[i.first] >= dfn[now])
            {
                ++cnt;
                std::vector<int> que;
                while (p.top() != i.first)
                {
                    que.push_back(p.top());
                    p.pop();
                }
                que.push_back(i.first);
                p.pop();
                que.push_back(now);
                for (int i = 0; i != (int)que.size(); ++i)
                    belong[map[que[i]][que[(i + 1) % que.size()]]] = cnt; // std::cout << que[i] << ' ' << -cnt << std::endl;
                c[cnt] = que.size() == 2 ? INF : que.size();
            }
        }
        else
        {
            low[now] = std::min(low[now], dfn[i.first]);
        }
    }
}
int calc(int x) { return x * (x + 1) / 2; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    bool flag = 8467 == n && m == 8469;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(std::make_pair(b, i));
        to[b].push_back(std::make_pair(a, i));
        map[a][b] = map[b][a] = i;
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            Tarjan(i, 0);
    // for (int i = 1; i <= n; ++i)
    //     std::cout << low[i] << " \n"[i == n];
    // for (int i = 1; i <= m; ++i)
    //     std::cout << belong[i] << " \n"[i == m];
    for (int i = 1, j = 1, l = 1; i <= n; ++i)
    {
        while (j <= n && !bad)
        {
            for (auto k : to[j++])
                if (i <= k.first && k.first < j && !--c[belong[k.second]])
                    ++bad;
            if (!bad)
                l = j;
        }
        if (!bad)
            l = j;
        sum[i] = sum[i - 1] + (R[i] = l - 1);
        for (auto k : to[i])
            if (i <= k.first && k.first < j && !c[belong[k.second]]++)
                --bad;
        if (!bad)
            l = j;
        // for (int i = 1; i <= cnt; ++i)
        //     std::cout << c[i] << " \n"[i == cnt];
        // std::cout << bad << std::endl;
    }
    // if (flag)
    //     for (int i = 1; i <= n; ++i)
    //         std::cout << R[i] << " \n"[i == n];
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        // if (flag && i == 4234)
        //     std::cout << r << std::endl;
        int lim = std::upper_bound(R + l, R + 1 + r, r) - R - 1;
        res << (sum[lim] - sum[l - 1] + (r - lim) * r) - (calc(r - 1) - calc(l - 2)) << std::endl;
    }
    std::cout << res.str();
    return 0;
}