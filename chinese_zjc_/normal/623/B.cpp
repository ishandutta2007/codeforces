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
int n, a[1000005], dp[3][1000005], A, B, ans = INF;
std::set<int> s;
void work(int x)
{
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
        {
            s.insert(i);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        s.insert(x);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> A >> B;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    work(a[1] - 1);
    work(a[1]);
    work(a[1] + 1);
    work(a[n] - 1);
    work(a[n]);
    work(a[n] + 1);
    for (auto x : s)
    {
        for (int i = 1; i <= n; ++i)
        {
            dp[0][i] = dp[1][i] = dp[2][i] = INF;
            int val = a[i] % x == 0 ? 0 : (a[i] % x == 1 || a[i] % x == x - 1 ? B : INF);
            dp[0][i] = std::min(dp[0][i], dp[0][i - 1] + val);
            dp[1][i] = std::min(dp[1][i], std::min(dp[0][i - 1], dp[1][i - 1]) + A);
            dp[2][i] = std::min(dp[2][i], std::min(dp[1][i - 1], dp[2][i - 1]) + val);
        }
        ans = std::min(ans, std::min(dp[0][n], std::min(dp[1][n], dp[2][n])));
    }
    std::cout << ans << std::endl;
    return 0;
}