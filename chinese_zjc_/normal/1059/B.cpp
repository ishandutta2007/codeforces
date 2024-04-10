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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m;
bool a[1005][1005], b[1005][1005];
const int xx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, yy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool check(int i, int j)
{
    for (int k = 0; k < 8; ++k)
    {
        if (!a[i + xx[k]][j + yy[k]])
            return false;
    }
    return true;
}
void paint(int i, int j)
{
    for (int k = 0; k < 8; ++k)
    {
        b[i + xx[k]][j + yy[k]] = true;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            static char c;
            cin >> c;
            a[i][j] = c == '#';
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (check(i, j))
            {
                paint(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}