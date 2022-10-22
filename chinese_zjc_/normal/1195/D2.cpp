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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
int n, a[100005], t[20], ans;
string s[100005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
        {
            res = res * A % MOD;
        }
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
int work(int pos, int len)
{
    int res = 0;
    for (int i = 0; i < min(len, (int)s[pos].length()); ++i)
    {
        res = (res + 11 * (s[pos][i] - '0') * power(100, i) * t[len]) % MOD;
    }
    for (int i = len; i < s[pos].length(); ++i)
    {
        res = (res + 2 * (s[pos][i] - '0') * power(10, i + len) * t[len]) % MOD;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = to_string(a[i]);
        reverse(s[i].begin(), s[i].end());
        ++t[s[i].length()];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            ans = (ans + work(i, j)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}