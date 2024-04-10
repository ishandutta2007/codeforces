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
int n, ans, fa[100005], len[100005], siz[100005];
std::vector<std::pair<int, int>> son[100005];
void dfs(int now)
{
    len[now] = 0;
    siz[now] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (son[now][i].first == fa[now])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i].first] = now;
        dfs(son[now][i].first);
        len[now] += len[son[now][i].first] + son[now][i].second;
        siz[now] += siz[son[now][i].first];
    }
    std::sort(son[now].begin(), son[now].end(), [&](const std::pair<int, int> &A, const std::pair<int, int> &B)
              { return (len[A.first] + A.second) * siz[B.first] < (len[B.first] + B.second) * siz[A.first]; });
    for (int i = 0, pre = 0; i != (int)son[now].size(); ++i)
    {
        ans += (pre + son[now][i].second) * siz[son[now][i].first];
        pre += 2 * (len[son[now][i].first] + son[now][i].second);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i != n; ++i)
    {
        static int a, b, c;
        std::cin >> a >> b >> c;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
    }
    dfs(1);
    std::cout << std::fixed << std::setprecision(15) << ans / (n - 1.0) << std::endl;
    return 0;
}