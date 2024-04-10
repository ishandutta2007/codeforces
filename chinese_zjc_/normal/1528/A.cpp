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
int n, T, dp[100005][2], l[100005], r[100005], fa[100005];
std::vector<int> son[100005];
void dfs(int now)
{
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
            continue;
        fa[son[now][i]] = now;
        dfs(son[now][i]);
        dp[now][0] += std::max(dp[son[now][i]][0] + llabs(l[son[now][i]] - l[now]),
                               dp[son[now][i]][1] + llabs(r[son[now][i]] - l[now]));
        dp[now][1] += std::max(dp[son[now][i]][0] + llabs(l[son[now][i]] - r[now]),
                               dp[son[now][i]][1] + llabs(r[son[now][i]] - r[now]));
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = dp[i][1] = 0;
            son[i].clear();
            std::cin >> l[i] >> r[i];
        }
        for (int i = 1; i < n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            son[x].push_back(y);
            son[y].push_back(x);
        }
        dfs(1);
        std::cout << std::max(dp[1][0], dp[1][1]) << std::endl;
    }
    return 0;
}