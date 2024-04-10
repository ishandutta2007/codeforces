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
int n, m, dp[5005][5005], ans;
string A, B;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> A >> B;
    A = ' ' + A;
    B = ' ' + B;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
            if (A[i] == B[j])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}