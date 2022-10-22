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
short n, m, L[5005][5005], R[5005][5005], U[5005][5005], D[5005][5005], ans1, ans2;
char c[5005][5005];
void erase(int x, int y)
{
    L[x][R[x][y]] = L[x][y];
    R[x][L[x][y]] = R[x][y];
    U[D[x][y]][y] = U[x][y];
    D[U[x][y]][y] = D[x][y];
}
void init()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            L[i][j] = j - 1;
            R[i][j] = j + 1;
            U[i][j] = i - 1;
            D[i][j] = i + 1;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (c[i][j] == '.')
                erase(i, j);
}
int run(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return 0;
    erase(x, y);
    switch (c[x][y])
    {
    case 'L':
        return run(x, L[x][y]) + 1;
    case 'R':
        return run(x, R[x][y]) + 1;
    case 'U':
        return run(U[x][y], y) + 1;
    case 'D':
        return run(D[x][y], y) + 1;
    }
    return -INF;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (c[i][j] != '.')
            {
                init();
                int tmp = run(i, j);
                if (tmp > ans1)
                    ans1 = tmp, ans2 = 0;
                if (tmp == ans1)
                    ++ans2;
            }
    std::cout << ans1 << ' ' << ans2 << std::endl;
    return 0;
}