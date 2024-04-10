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
int n, m, fa[100005], depth[100005];
std::vector<int> to[100005];
std::stringstream res;
bool dfs(int now)
{
    int lef = 0;
    for (auto i : to[now])
    {
        if (fa[now] == i)
            continue;
        if (!fa[i])
        {
            fa[i] = now;
            depth[i] = depth[now] + 1;
            if (dfs(i))
            {
                if (lef)
                {
                    res << lef << ' ' << now << ' ' << i << std::endl;
                    lef = 0;
                }
                else
                {
                    lef = i;
                }
            }
        }
        else if (depth[i] < depth[now])
        {
            if (lef)
            {
                res << lef << ' ' << now << ' ' << i << std::endl;
                lef = 0;
            }
            else
            {
                lef = i;
            }
        }
    }
    if (lef)
    {
        res << lef << ' ' << now << ' ' << fa[now] << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (m & 1)
        return std::cout << "No solution" << std::endl, 0;
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    fa[1] = -1;
    dfs(1);
    std::cout << res.str();
    return 0;
}