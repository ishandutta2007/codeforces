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
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, n;
char a[205][205];
struct L
{
    int x, y;
    char g()
    {
        return a[x][y];
    }
} c[4], did[4];
bool dfs(int now, int tim)
{
    if (tim > 2)
    {
        return false;
    }
    if (now == 4)
    {
        if (c[0].g() == c[1].g() && c[2].g() != c[0].g() && c[2].g() == c[3].g())
        {
            cout << tim << endl;
            for (int i = 0; i < tim; ++i)
            {
                cout << did[i].x << ' ' << did[i].y << endl;
            }
            return true;
        }
        return false;
    }
    if (dfs(now + 1, tim))
    {
        return true;
    }
    a[c[now].x][c[now].y] ^= 1;
    did[tim] = c[now];
    if (dfs(now + 1, tim + 1))
    {
        return true;
    }
    a[c[now].x][c[now].y] ^= 1;
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
            }
        }
        c[0] = {1, 2};
        c[1] = {2, 1};
        c[2] = {n - 1, n};
        c[3] = {n, n - 1};
        dfs(0, 0);
    }
    return 0;
}