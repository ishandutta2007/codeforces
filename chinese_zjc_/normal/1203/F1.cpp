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
int n, r, ans, dp[2][60005];
bool now = true, lst = false;
struct node
{
    int a, b;
} p[105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i].a >> p[i].b;
    int cnt = std::partition(p + 1, p + 1 + n, [&](const node &x)
                             { return x.b >= 0; }) -
              p - 1;
    std::sort(p + 1, p + 1 + cnt, [&](const node &A, const node &B)
              { return A.a < B.a; });
    for (int i = 1; i <= cnt; ++i)
        if (p[i].a <= r)
            r += p[i].b, ++ans;
    std::fill(dp[now], dp[now] + 60005, -INF);
    dp[now][r] = ans;
    // std::cout << r << ' ' << ans << std::endl;
    std::sort(p + 1 + cnt, p + 1 + n, [&](const node &A, const node &B)
              { return std::max(A.a, B.a - A.b) < std::max(B.a, A.a - B.b); });
    for (int i = cnt; ++i <= n;)
    {
        std::swap(now, lst);
        std::copy(dp[lst], dp[lst] + 60005, dp[now]);
        for (int j = std::max(p[i].a, -p[i].b); j <= 60000; ++j)
            dp[now][j + p[i].b] = std::max(dp[now][j + p[i].b], dp[lst][j] + 1);
    }
    ans = *std::max_element(dp[now], dp[now] + 60005);
    std::cout << (ans == n ? "YES" : "NO") << std::endl;
    return 0;
}