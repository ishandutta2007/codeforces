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
int n, a[100005], lg[32], sum[100005], ans = INF;
int Log(int now)
{
    return lower_bound(lg, lg + 32, now) - lg;
}
signed main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 32; ++i)
    {
        lg[i] = 1 << i;
    }
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 3; i <= n; ++i)
    {
        if (Log(a[i - 2]) == Log(a[i - 1]) && Log(a[i - 1]) == Log(a[i]))
        {
            cout << 1 << endl;
            return 0;
        }
    }
    if (n <= 500)
    {
        for (int i = 1; i <= n; ++i)
        {
            sum[i] = sum[i - 1] ^ a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                for (int k = j + 1; k <= n; ++k)
                {
                    if ((sum[j] ^ sum[i - 1]) > (sum[k] ^ sum[j]))
                    {
                        ans = min(ans, k - i - 1);
                    }
                }
            }
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}