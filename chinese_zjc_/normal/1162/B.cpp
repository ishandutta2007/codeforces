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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[2][55][55], least[2][55][55];
int Min(int x, int y)
{
    return min(a[0][x][y], a[1][x][y]);
}
int Max(int x, int y)
{
    return max(a[0][x][y], a[1][x][y]);
}
int near(int k, int x, int y)
{
    return max(least[k][x - 1][y], least[k][x][y - 1]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int k = 0; k < 2; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[k][i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            least[0][i][j] = Min(i, j);
            least[1][i][j] = Max(i, j);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (near(0, i, j) < least[0][i][j] && near(1, i, j) < least[1][i][j])
            {
                continue;
            }
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}