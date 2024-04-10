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
int u[2000005], n, k, ans[4000005], v[2000005];
bool vis[2000005];
std::vector<int> p;
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
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    u[1] = 1;
    for (int i = 2; i <= k; ++i)
    {
        if (!vis[i])
        {
            p.push_back(i);
            u[i] = MOD - 1;
        }
        for (auto j : p)
        {
            if (i * j > k)
                break;
            vis[i * j] = true;
            if (i % j == 0)
                break;
            // std::cout << i << ' ' << j << std::endl;
            u[i * j] = MOD - u[i];
        }
    }
    // for (int i = 1; i <= k; ++i)
    //     for (int j = 1; j <= i; ++j)
    //         ans[i] = (ans[i] + power(i / j, n) * u[j]) % MOD;
    for (int i = 1; i <= k; ++i)
        v[i] = power(i, n);
    for (int i = 1; i <= k; ++i)
        for (int j = 1; i * j <= k; ++j)
        {
            ans[i * j] = (ans[i * j] + v[j] * u[i]) % MOD;
            ans[i * j + i] = (ans[i * j + i] + v[j] * (MOD - u[i])) % MOD;
        }
    int res = 0;
    for (int i = 1; i <= k; ++i)
        res = (res + ((ans[i] = (ans[i] + ans[i - 1]) % MOD) ^ i)) % MOD;
    std::cout << res << std::endl;
    return 0;
}