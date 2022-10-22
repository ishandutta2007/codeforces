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
int phi[200005], siz[200005], n, m, disable[200005], from[200005], dp[200005], to[200005];
bool good[200005];
std::vector<int> p, g;
int power(int A, int B, int C)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % C;
        B >>= 1;
        A = A * A % C;
    }
    return res;
}
int dfs(int now)
{
    if (m % now || m == now)
        return 0;
    if (~dp[now])
        return dp[now];
    dp[now] = 0;
    for (auto i : g)
        if (dfs(now * i) > dp[now])
            dp[now] = dp[now * (to[now] = i)];
    return dp[now] += siz[now];
}
void work(int now, int lst, int pre)
{
    // std::cout << std::endl
    //           << "!" << now << std::endl;
    // std::cout << to[now] << std::endl;
    for (int i = now; i != m; i += now)
        if (good[i] && std::__gcd(m, i) == now)
            std::cout << pre * (i / now) * power(lst / now, phi[m / now] - 1, m / now) % m << " ", lst = i, pre = 1;
    if (to[now])
        work(now * to[now], lst * to[now] % m, pre * to[now] % m);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (m == 1)
        return std::cout << 1 << std::endl
                         << 0 << std::endl,
               0;
    for (int i = 1; i <= n; ++i)
        std::cin >> disable[i];
    for (int i = 2; i <= m; ++i)
    {
        if (!from[i])
        {
            from[i] = i;
            p.push_back(i);
            phi[i] = i - 1;
        }
        for (auto j : p)
        {
            if (i * j > m)
                break;
            if (i % j == 0)
            {
                phi[i * j] = phi[i] * j;
                from[i * j] = j;
                break;
            }
            phi[i * j] = phi[i] * phi[j];
            from[i * j] = j;
        }
    }
    // for (auto i : p)
    //     std::cout << i << " ";
    // std::cout << std::endl;
    for (int i = 1; i <= m; ++i)
        if (m % i == 0)
            siz[m / i] = phi[i];
    for (int i = 1; i <= n; ++i)
        --siz[std::__gcd(disable[i], m)];
    for (auto i : p)
        if (m % i == 0)
            g.push_back(i);
    for (int i = 0; i != m; ++i)
        good[i] = true;
    for (int i = 1; i <= n; ++i)
        good[disable[i]] = false;
    if (g.back() == m)
    {
        std::vector<int> ans;
        int now = std::find(good + 1, good + m, true) - good;
        while (now != m)
        {
            ans.push_back(now);
            now = std::find(good + now + 1, good + m, true) - good;
        }
        if (good[0])
            ans.push_back(0);
        std::cout << ans.size() << std::endl;
        for (auto i : ans)
        {
            static int lst = 1;
            std::cout << i * power(lst, phi[m] - 1, m) % m << ' ';
            lst = i;
        }
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    dfs(1);
    std::cout << dp[1] + good[0] << std::endl;
    work(1, 1, 1);
    if (good[0])
        std::cout << 0 << std::endl;
    else
        std::cout << std::endl;
    return 0;
}