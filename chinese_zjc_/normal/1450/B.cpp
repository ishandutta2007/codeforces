//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int T, n, k;
struct pos
{
    int x, y;
} p[105];
bool flag;
int dist(int A, int B)
{
    return llabs(p[A].x - p[B].x) + llabs(p[A].y - p[B].y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> p[i].x >> p[i].y;
        }
        for (int i = 1; i <= n; ++i)
        {
            flag = true;
            for (int j = 1; j <= n; ++j)
            {
                if (dist(i, j) > k)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << 1 << endl;
                break;
            }
        }
        if (!flag)
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}