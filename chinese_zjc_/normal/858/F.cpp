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
std::vector<int> to[200005];
int n, m, fa[200005], ans, depth[200005];
std::stringstream res;
void print(int A, int B, int C)
{
    res << A << ' ' << B << ' ' << C << std::endl;
    ++ans;
}
bool dfs(int now)
{
    int lst = 0;
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
                if (lst)
                {
                    print(i, now, lst);
                    lst = 0;
                }
                else
                {
                    lst = i;
                }
            }
        }
        else if (depth[i] < depth[now])
        {
            if (lst)
            {
                print(i, now, lst);
                lst = 0;
            }
            else
            {
                lst = i;
            }
        }
    }
    if (lst && ~fa[now])
    {
        print(fa[now], now, lst);
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
    for (int i = 1; i <= m; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!fa[i])
            fa[i] = -1, dfs(i);
    std::cout << ans << std::endl
              << res.str();
    return 0;
}