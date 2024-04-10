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
int n, q, T, dp[2][105], l, r;
string s, ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> q >> s;
        s = ' ' + s;
        for (int i = 1; i <= q; ++i)
        {
            cin >> l >> r;
            ans = "NO";
            for (int j = 1; j < l; ++j)
            {
                if (s[j] == s[l])
                {
                    ans = "YES";
                    break;
                }
            }
            for (int j = n; j > r; --j)
            {
                if (s[j] == s[r])
                {
                    ans = "YES";
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}