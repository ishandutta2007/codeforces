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
int dfn[100005], low[100005], n, m, q, fa[20][200005], depth[200005], tim, cnt;
std::vector<int> to[100005], son[200005];
std::stack<int, std::vector<int>> sta;
void Tarjan(int now, int fa)
{
    // std::cout << now << " " << fa << std::endl;
    dfn[now] = low[now] = ++tim;
    sta.push(now);
    for (auto i : to[now])
    {
        if (!dfn[i])
        {
            Tarjan(i, now);
            if (low[i] >= dfn[now])
            {
                ++cnt;
                while (sta.top() != i)
                {
                    son[cnt].push_back(sta.top());
                    son[sta.top()].push_back(cnt);
                    sta.pop();
                }
                son[cnt].push_back(sta.top());
                son[sta.top()].push_back(cnt);
                sta.pop();
                son[cnt].push_back(now);
                son[now].push_back(cnt);
            }
            low[now] = std::min(low[now], low[i]);
        }
        else if (fa != i)
        {
            low[now] = std::min(low[now], dfn[i]);
        }
        // std::cout << now << ' ' << low[now] << std::endl;
    }
}
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[0][now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[0][son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
    }
}
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 19; i >= 0; --i)
        if (depth[A] - depth[B] >= 1 << i)
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 19; i >= 0; --i)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    cnt = n;
    Tarjan(1, 0);
    init(1);
    for (int i = 1; i <= q; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        std::cout << (depth[a] + depth[b] - depth[LCA(a, b)] * 2) / 2 << std::endl;
    }
    return 0;
}