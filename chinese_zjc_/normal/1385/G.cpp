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
int T, n, x[200005], y[200005], cnt;
bool visn[200005], vise[200005];
std::vector<int> ans;
std::vector<std::pair<int, int>> xx[200005], yy[200005];
std::vector<int> xxx, yyy;
void dfs(int s, int lst = -1)
{
    visn[s] = true;
    for (auto i : xx[s])
    {
        if (!vise[i.second])
            vise[i.second] = true, dfs(i.first, s), xxx.push_back(i.second);
    }
    for (auto i : yy[s])
    {
        if (!vise[i.second])
            vise[i.second] = true, dfs(i.first, s), yyy.push_back(i.second);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::fill(visn + 1, visn + 1 + n, false);
        std::fill(vise + 1, vise + 1 + n, false);
        for (int i = 1; i <= n; ++i)
            std::cin >> x[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> y[i];
        for (int i = 1; i <= n; ++i)
            xx[i].clear(), yy[i].clear();
        for (int i = 1; i <= n; ++i)
        {
            xx[x[i]].push_back(std::make_pair(y[i], i));
            yy[y[i]].push_back(std::make_pair(x[i], i));
        }
        for (int i = 1; i <= n; ++i)
            if ((int)(xx[i].size() + yy[i].size()) != 2)
            {
                std::cout << -1 << std::endl;
                goto nextcase;
            }
        for (int i = 1; i <= n; ++i)
            if (!visn[i])
            {
                // std::cout << i << std::endl;
                dfs(i, i);
                if (xxx.size() < yyy.size())
                    ans.insert(ans.end(), xxx.begin(), xxx.end());
                else
                    ans.insert(ans.end(), yyy.begin(), yyy.end());
                // for (auto i : xxx)
                //     std::cout << i << ' ';
                // std::cout << std::endl;
                // for (auto i : yyy)
                //     std::cout << i << ' ';
                // std::cout << std::endl;
                xxx.clear();
                yyy.clear();
            }
        std::cout << ans.size() << std::endl;
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
        ans.clear();
    nextcase:;
    }
    return 0;
}