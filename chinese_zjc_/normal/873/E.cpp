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
int n, a[3005], rk[3005], max[3005][3005], d[3005];
int cnt[4], ans[4];
int g(int x)
{
    return a[rk[x]] - a[rk[x + 1]];
}
int cmax(int A, int B)
{
    return g(A) > g(B) ? A : B;
}
void checkans()
{
    if (g(cnt[1]) > g(ans[1]))
        return void(std::copy(cnt, cnt + 4, ans));
    if (g(cnt[1]) < g(ans[1]))
        return;
    if (g(cnt[1] + cnt[2]) > g(ans[1] + ans[2]))
        return void(std::copy(cnt, cnt + 4, ans));
    if (g(cnt[1] + cnt[2]) < g(ans[1] + ans[2]))
        return;
    if (g(cnt[1] + cnt[2] + cnt[3]) > g(ans[1] + ans[2] + ans[3]))
        return void(std::copy(cnt, cnt + 4, ans));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], rk[i] = i;
    std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B)
              { return a[A] > a[B]; });
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            max[i][j] = cmax(max[i][j - 1], j);
    for (cnt[1] = 1; cnt[1] <= n; ++cnt[1])
        for (cnt[2] = (cnt[1] + 1) / 2; cnt[2] <= cnt[1] * 2; ++cnt[2])
        {
            int MIN = std::max(cnt[1] + 1, cnt[2] + 1) / 2, MAX = std::min(cnt[1], cnt[2]) * 2;
            cnt[3] = max[std::min(n, MIN + cnt[1] + cnt[2])][std::min(n, MAX + cnt[1] + cnt[2])] - cnt[1] - cnt[2];
            cnt[0] = n - cnt[1] - cnt[2] - cnt[3];
            // if (g(cnt[1]) == 10 && g(cnt[1] + cnt[2]) == 7 && n == 999)
            //     std::cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << g(cnt[1] + cnt[2] + cnt[3]) << std::endl
            //               << ans[1] << ' ' << ans[2] << ' ' << ans[3] << " " << MIN << ' ' << MAX << std::endl;
            // if (MIN <= cnt[3] && cnt[3] <= MAX && cnt[0] >= 0)
            // std::cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << std::endl;
            if (MIN <= cnt[3] && cnt[3] <= MAX && cnt[0] >= 0)
                checkans();
        }
    for (int i = 1; i <= n; ++i)
        if (i <= ans[1])
            d[rk[i]] = 1;
        else if (i <= ans[1] + ans[2])
            d[rk[i]] = 2;
        else if (i <= ans[1] + ans[2] + ans[3])
            d[rk[i]] = 3;
        else
            d[rk[i]] = -1;
    // std::cout << ans[1] << ' ' << ans[2] << " " << ans[3] << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << d[i] << " \n"[i == n];
    return 0;
}