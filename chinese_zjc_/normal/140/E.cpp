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
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, MOD, a[1000005], dp[5005][5005], fact[1000005], tcaf[1000005];
long long ANS;
vector<int> ans[1000005];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> MOD;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= 5000; ++i)
    {
        for (int j = 1; j <= 5000; ++j)
        {
            dp[i][j] = (dp[i - 1][j] * (j - 1ll) + dp[i - 1][j - 1]) % MOD;
        }
    }
    fact[0] = 1;
    for (long long i = 1; i <= m; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    tcaf[m] = 1;
    for (long long i = m; i; --i)
    {
        tcaf[i - 1] = tcaf[i] * i % MOD;
    }
    ans[0].push_back(1);
    for (int i = 1; i <= n; ++i)
    {
        long long sum = 0;
        for (int j = 0; j <= a[i - 1]; ++j)
        {
            sum += ans[i - 1][j];
        }
        sum %= MOD;
        for (int j = 0; j <= a[i]; ++j)
        {
            ans[i].push_back(sum * dp[a[i]][j] % MOD * tcaf[m - j] % MOD);
            if (j <= a[i - 1])
            {
                ans[i].back() -= 1ll * ans[i - 1][j] * dp[a[i]][j] % MOD * fact[j] % MOD;
                if (ans[i].back() < 0)
                {
                    ans[i].back() += MOD;
                }
            }
        }
    }
    for (int i = 0; i <= a[n]; ++i)
    {
        ANS += ans[n][i];
    }
    cout << ANS % MOD << endl;
    return 0;
}