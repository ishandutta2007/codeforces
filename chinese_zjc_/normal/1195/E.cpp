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
int n, m, a, b, g[9000005], h[3005][3005], x, y, z, f[3005][3005], ans;
int d[3005], l, r;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> a >> b;
    cin >> g[0] >> x >> y >> z;
    for (int i = 1; i <= n * m; ++i)
    {
        g[i] = (g[i - 1] * x + y) % z;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            h[i][j] = g[i * m + j - m - 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        l = r = 1;
        for (int j = 1; j < b; ++j)
        {
            while (l < r && h[i][d[r - 1]] > h[i][j])
            {
                --r;
            }
            d[r++] = j;
        }
        for (int j = b; j <= m; ++j)
        {
            if (l < r && d[l] == j - b)
            {
                ++l;
            }
            while (l < r && h[i][d[r - 1]] > h[i][j])
            {
                --r;
            }
            d[r++] = j;
            f[i][j] = h[i][d[l]];
            // cout << f[i][j] << ' ';
        }
        // cout << endl;
    }
    for (int i = b; i <= m; ++i)
    {
        l = r = 1;
        for (int j = 1; j < a; ++j)
        {
            while (l < r && f[d[r - 1]][i] > f[j][i])
            {
                --r;
            }
            d[r++] = j;
        }
        for (int j = a; j <= n; ++j)
        {
            if (l < r && d[l] == j - a)
            {
                ++l;
            }
            while (l < r && f[d[r - 1]][i] > f[j][i])
            {
                --r;
            }
            d[r++] = j;
            ans += f[d[l]][i];
            // cout << f[d[l]][i] << ' ';
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}