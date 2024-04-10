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
int T, x, y, c[6], ans;
const int xx[6] = {1, 0, -1, -1, 0, 1}, yy[6] = {1, 1, 0, -1, -1, 0};
bool can[6];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> y >> x;
        for (int i = 0; i < 6; ++i)
        {
            cin >> c[i];
        }
        ans = INF;
        if (x <= 0 && y <= 0)
        {
            ans = min(ans, c[3] * min(abs(x), abs(y)) + max(abs(x) - abs(y), 0ll) * c[4] + max(abs(y) - abs(x), 0ll) * c[2]);
            ans = min(ans, c[3] * max(abs(x), abs(y)) + max(abs(x) - abs(y), 0ll) * c[5] + max(abs(y) - abs(x), 0ll) * c[1]);
            ans = min(ans, c[2] * abs(y) + c[4] * abs(x));
        }
        if (x <= 0 && y >= 0)
        {
            ans = min(ans, c[0] * abs(y) + c[4] * abs(y - x));
            ans = min(ans, c[3] * abs(x) + c[5] * abs(y - x));
            ans = min(ans, c[4] * abs(x) + c[5] * abs(y));
        }
        if (x >= 0 && y >= 0)
        {
            ans = min(ans, c[0] * min(abs(x), abs(y)) + max(abs(x) - abs(y), 0ll) * c[1] + max(abs(y) - abs(x), 0ll) * c[5]);
            ans = min(ans, c[0] * max(abs(x), abs(y)) + max(abs(x) - abs(y), 0ll) * c[2] + max(abs(y) - abs(x), 0ll) * c[4]);
            ans = min(ans, c[5] * abs(y) + c[1] * abs(x));
        }
        if (x >= 0 && y <= 0)
        {
            ans = min(ans, c[3] * abs(y) + c[1] * abs(y - x));
            ans = min(ans, c[0] * abs(x) + c[2] * abs(y - x));
            ans = min(ans, c[1] * abs(x) + c[2] * abs(y));
        }
        cout << ans << endl;
        // dfs(X, Y, 0);
    }
    return 0;
}