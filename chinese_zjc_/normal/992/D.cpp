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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, a[200005], sum[200005], len[200005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n; i > 0; --i)
    {
        if (a[i] == 1)
        {
            len[i] = 1 + len[i + 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int t = a[i], r = i;
        if (k == 1)
        {
            ++ans;
        }
        while (t < 5e14 && r < n)
        {
            ++r;
            if (len[r] == 0)
            {
                if (t < 5e14 / a[r])
                {
                    t *= a[r];
                }
                else
                    break;
                // cout << i << ' ' << r << ' ' << t << endl;
                if (k * (sum[r] - sum[i - 1]) == t)
                {
                    ++ans;
                }
            }
            else
            {
                int L = sum[r] - sum[i - 1], R = sum[r + len[r] - 1] - sum[i - 1];
                if (t % k == 0 && L * k <= t && t <= R * k)
                {
                    ++ans;
                }
                r += len[r] - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}