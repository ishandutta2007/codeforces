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
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int max[20][100005], n, a[100005], lg[100005], dp[100005], ans;
int cmax(int A, int B) { return a[A] < a[B] ? B : A; }
int query(int l, int r)
{
    int len = lg[r - l + 1];
    return cmax(max[len][l], max[len][r - (1 << len) + 1]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i < n; ++i)
        std::cin >> a[max[0][i] = i];
    a[max[0][n] = n] = n;
    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            max[i][j] = cmax(max[i - 1][j], max[i - 1][j + (1 << i >> 1)]);
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i - 1] + !(i & (i - 1));
    for (int i = n; --i;)
    {
        int to = query(i + 1, a[i]);
        dp[i] = dp[to] + (n - i) - (a[i] - to);
    }
    for (int i = 1; i <= n; ++i)
        /*std::cout << dp[i] << " \n"[i == n],*/ ans += dp[i];
    std::cout << ans << std::endl;
    return 0;
}