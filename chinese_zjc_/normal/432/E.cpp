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
int n, m;
char ans[105][105];
int get(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m ? ans[x][y] : -1;
}
bool check(int x, int y, int len, char c)
{
    for (int i = x; i != x + len; ++i)
        for (int j = y; j != y + len; ++j)
            if (get(i, j) != c && get(i, j))
                return false;
    return true;
}
void fill(int x, int y, int len, char c)
{
    for (int i = x; i != x + len; ++i)
        for (int j = y; j != y + len; ++j)
            ans[i][j] = c;
}
void paint(int x, int y)
{
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        if (get(x - 1, y) == i || get(x, y + 1) == i)
            continue;
        int j = y;
        while (get(x, j - 1) == i)
            --j;
        if (check(x, j, y - j + 1, i))
        {
            fill(x, j, y - j + 1, i);
            break;
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            if (!ans[i][j])
                paint(i, j);
    for (int i = 0; i != n; ++i, std::cout << std::endl)
        for (int j = 0; j != m; ++j)
            std::cout << ans[i][j];
    return 0;
}