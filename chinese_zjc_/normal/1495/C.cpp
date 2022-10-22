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
const int xx[] = {-1, 0, 1, 0}, yy[] = {0, -1, 0, 1};
char c[505][505];
int T, n, m;
bool check(int X, int Y)
{
    if (c[X][Y] != 'X')
        return false;
    for (int i = 0; i < 3; ++i)
    {
        int x = X + xx[i], y = Y + yy[i];
        if (c[x][y] == 'X')
            return false;
    }
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                std::cin >> c[i][j];
            }
        }
        if (n <= 3)
        {
            for (int i = 1; i <= m; ++i)
            {
                c[std::min(n, 2ll)][i] = 'X';
            }
        }
        else
        {
            for (int i = 1; i + 2 <= n; i += 3)
            {
                for (int j = 1; j <= m; ++j)
                {
                    c[i][j] = 'X';
                }
                bool noline = false;
                for (int j = 1; j <= m; ++j)
                {
                    if (c[i + 1][j] == 'X' || c[i + 2][j] == 'X')
                    {
                        c[i + 1][j] = c[i + 2][j] = 'X';
                        noline = true;
                        break;
                    }
                }
                if (!noline)
                    c[i + 1][1] = c[i + 2][1] = 'X';
            }
            if (n % 3 == 0)
            {
                for (int i = 1; i <= m; ++i)
                {
                    if (c[n][i] == 'X')
                        c[n - 1][i] = 'X';
                }
            }
            else
            {
                for (int i = 1; i <= m; ++i)
                {
                    c[n - (n % 3 == 2)][i] = 'X';
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                std::cout << c[i][j];
            }
            std::cout << std::endl;
        }
    }
    return 0;
}