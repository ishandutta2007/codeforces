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
int t[105], n, tmp, sum, ans = 1, way[2][105][10005], has;
bool now = true, lst;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tmp;
        if (!t[tmp])
        {
            ++has;
        }
        ++t[tmp];
        sum += tmp;
    }
    if (has == 2)
    {
        cout << n << endl;
        return 0;
    }
    way[lst][0][0] = 1;
    for (int i = 1; i <= 100; ++i, swap(now, lst))
    {
        memset(way[now], 0, sizeof(way[now]));
        for (int j = 0; j <= t[i]; ++j)
        {
            for (int k = j; k <= n; ++k)
            {
                for (int l = j * i; l <= 10000; ++l)
                {
                    way[now][k][l] += way[lst][k - j][l - j * i];
                }
            }
        }
        for (int k = 0; k <= n; ++k)
        {
            for (int l = 0; l <= 10000; ++l)
            {
                way[now][k][l] = min(way[now][k][l], 2ll);
            }
        }
    }
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 2; j <= t[i]; ++j)
        {
            if (way[lst][j][j * i] == 1)
            {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}