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
int l[10][10];
double dp[10][10];
double dfs(int x, int y)
{
    if (x < 0)
        return 0;
    if (x == 0 && y == 0)
        return 0;
    if (dp[x][y] > 0)
        return dp[x][y];
    int tx = x, ty = y, tmp = 0;
    for (int i = 1; i <= 6; ++i)
    {
        if (tx & 1)
        {
            if (ty == 9)
                --tx;
            else
                ++ty;
        }
        else
        {
            if (ty == 0)
                --tx;
            else
                --ty;
        }
        if (tx < 0)
            ++tmp;
        else
            dp[x][y] += std::min(dfs(tx, ty), dfs(tx - l[tx][ty], ty));
    }
    dp[x][y] = (dp[x][y] + 6) / (6 - tmp);
    return dp[x][y];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i != 10; ++i)
        for (int j = 0; j != 10; ++j)
            std::cin >> l[i][j];
    std::cout << std::fixed << std::setprecision(10) << dfs(9, 0) << std::endl;
    return 0;
}