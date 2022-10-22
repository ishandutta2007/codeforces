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
const int m = 6;
int a[10], n, b[100005], ans = INF, s, now;
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + m);
    a[7] = INF;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            s = b[i] - a[j];
            bool flag = false;
            for (int k = 1; k <= 6; ++k)
            {
                if ((b[1] - a[k]) >= s)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                continue;
            }
            now = 0;
            for (int k = 1; k <= 6; ++k)
            {
                now = max(now, *(lower_bound(b + 1, b + 1 + n, a[k + 1] + s) - 1) - a[k] - s);
            }
            ans = min(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}