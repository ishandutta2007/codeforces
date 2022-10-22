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
const int MOD = 1000000007;
int phi[100005], lst[100005], m, dp[100005], ans;
std::vector<int> p;
int dfs(int now, int cho, int mul, int lim, const std::vector<int> &z)
{
    if (now == (int)z.size())
        return (cho & 1 ? -1 : +1) * lim / mul;
    return dfs(now + 1, cho + 1, mul * z[now], lim, z) + dfs(now + 1, cho, mul, lim, z);
}
int work(int a, int b) // calc \sum_{i=1}^a[gcd(b,i)=1]
{
    std::vector<int> z;
    while (b > 1)
    {
        z.push_back(lst[b]);
        while (b % z.back() == 0)
            b /= z.back();
    }
    return dfs(0, 0, 1, a, z);
}
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int inv(int x) { return power(x, MOD - 2); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m;
    phi[1] = 1;
    for (int i = 2; i <= m; ++i)
    {
        if (!phi[i])
        {
            phi[i] = i - 1;
            lst[i] = i;
            p.push_back(i);
        }
        for (auto j : p)
        {
            if (i * j > m)
                break;
            if (i % j == 0)
            {
                phi[i * j] = phi[i] * j;
                lst[i * j] = j;
                break;
            }
            phi[i * j] = phi[i] * phi[j];
            lst[i * j] = j;
        }
    }
    // for (int i = 1; i <= m; ++i)
    //     std::cout << phi[i] << " \n"[i == m];
    dp[1] = 1;
    for (int i = 2; i <= m; ++i)
    {
        int k = work(m / i, 1), b = work(m, i) * dp[1] + m;
        for (int j = 2; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                b += work(m / j, i / j) * dp[j] % MOD;
                if (j * j != i)
                    b += work(m / (i / j), i / (i / j)) * dp[i / j] % MOD;
            }
        }
        b %= MOD;
        dp[i] = b * inv(m - k) % MOD;
        // std::cout << k << ' ' << b << std::endl;
        // std::cout << dp[i] << std::endl;
    }
    for (int i = 1; i <= m; ++i)
        ans = (ans + dp[i]) % MOD;
    std::cout << ans * inv(m) % MOD << std::endl;
    return 0;
}