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
int n, m, k, T, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        // cout << T << endl;
        cin >> n >> m >> k;
        if (n == m)
        {
            if (n <= k)
            {
                if ((n - k) & 1)
                {
                    cout << n - 1 + (k - n) / 2 * 2 << endl;
                }
                else
                {
                    cout << n + (k - n) / 2 * 2 << endl;
                }
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }
        ans = min(n, m);
        n -= ans;
        m -= ans;
        k -= ans;
        if (m == 0)
        {
            m = n;
            n = 0;
        }
        if (m > k)
        {
            cout << -1 << endl;
            continue;
        }
        ans += m / 2 * 2;
        k -= m / 2 * 2;
        m -= m / 2 * 2;
        if (m == 1)
        {
            ans += k - 1;
        }
        else
        {
            if (k & 1)
            {
                --ans;
            }
            ans += k / 2 * 2;
        }
        cout << ans << endl;
    }
    return 0;
}