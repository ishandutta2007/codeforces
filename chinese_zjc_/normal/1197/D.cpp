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
int n, m, k, a[300005], dp[300005][15], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    memset(dp, 0xf0, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][m - 1] = max(a[i] - k, dp[i - 1][0] + a[i] - k);
        ans = max(ans, dp[i][m - 1]);
        for (int j = m - 2; j >= 0; --j)
        {
            dp[i][j] = dp[i - 1][j + 1] + a[i];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}