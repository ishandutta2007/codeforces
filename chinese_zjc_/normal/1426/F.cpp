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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
string s;
int dp[4][200005], n, sum;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
const int _3 = power(3, MOD - 2);
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    s = ' ' + s;
    sum = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '?')
        {
            sum = sum * 3 % MOD;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'a')
        {
            dp[1][i] = (dp[1][i - 1] + sum) % MOD;
        }
        else if (s[i] == '?')
        {
            dp[1][i] = (dp[1][i - 1] + sum * _3) % MOD;
        }
        else
        {
            dp[1][i] = dp[1][i - 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'b')
        {
            dp[2][i] = (dp[2][i - 1] + dp[1][i - 1]) % MOD;
        }
        else if (s[i] == '?')
        {
            dp[2][i] = (dp[2][i - 1] + dp[1][i - 1] * _3) % MOD;
        }
        else
        {
            dp[2][i] = dp[2][i - 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'c')
        {
            dp[3][i] = (dp[3][i - 1] + dp[2][i - 1]) % MOD;
        }
        else if (s[i] == '?')
        {
            dp[3][i] = (dp[3][i - 1] + dp[2][i - 1] * _3) % MOD;
        }
        else
        {
            dp[3][i] = dp[3][i - 1];
        }
    }
    cout << dp[3][n] << endl;
    return 0;
}