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
const int MOD = 998244353;
int n, dp[1000005], sum[1000005], d[1000005];
int D(int x)
{
    int cnt = 0;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0)
            cnt += 1 + (i * i != x);
    return cnt;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            ++d[j];
    sum[1] = dp[1] = 1;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + (dp[i] = (d[i] + sum[i - 1]) % MOD) % MOD;
    std::cout << dp[n] << std::endl;
    return 0;
}