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
int n, p, k, sum[100005], T, x, y, ans;
char a[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> p >> k;
        ans = INF;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        cin >> y >> x;
        for (int i = 1; i <= n; ++i)
        {
            if (i > k)
            {
                sum[i] = sum[i - k] + (a[i] == '0' ? y : 0);
            }
            else
            {
                sum[i] = a[i] == '0' ? y : 0;
            }
        }
        for (int i = p; i <= n; ++i)
        {
            ans = min(ans, sum[(n - i) / k * k + i] - sum[max(0ll, i - k)] + (i - p) * x);
        }
        cout << ans << endl;
    }
    return 0;
}