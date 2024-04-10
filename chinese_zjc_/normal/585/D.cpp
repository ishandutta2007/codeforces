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
std::map<std::pair<int, int>, std::pair<int, std::string>> map;
int n, v[25][3], mid;
std::pair<int, std::string> ans = {-INF, "Impossible"};
template <class T>
void cmax(T &A, const T &B) { A = std::max(A, B); }
template <class T>
void dfs(int now, int lim, std::array<int, 3> x, std::string y, T fun)
{
    if (now == lim)
    {
        // std::cout << y << std::endl;
        fun(x, y);
        return;
    }
    dfs(now + 1, lim, {x[0] + v[now][0], x[1] + v[now][1], x[2]}, y + "LM\n", fun);
    dfs(now + 1, lim, {x[0] + v[now][0], x[1], x[2] + v[now][2]}, y + "LW\n", fun);
    dfs(now + 1, lim, {x[0], x[1] + v[now][1], x[2] + v[now][2]}, y + "MW\n", fun);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> v[i][0] >> v[i][1] >> v[i][2];
    mid = n >> 1;
    dfs(0, mid, std::array<int, 3>(), std::string(), [&](const std::array<int, 3> &x, const std::string &y)
        {
            auto iter = map.insert({{x[0] - x[1], x[1] - x[2]}, {x[2], y}});
            if (!iter.second)
                cmax(iter.first->second, {x[2], y});
        });
    dfs(mid, n, std::array<int, 3>(), std::string(), [&](const std::array<int, 3> &x, const std::string y)
        {
            auto iter = map.find({-(x[0] - x[1]), -(x[1] - x[2])});
            if (iter != map.end())
                cmax(ans, {iter->second.first + x[2], iter->second.second + y});
        });
    std::cout << ans.second;
    return 0;
}