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
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
int n, a[500005], ans;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n << 1; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n + n);
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans - a[i] + MOD) % MOD;
    }
    for (int i = n + 1; i <= n << 1; ++i)
    {
        ans = (ans + a[i]) % MOD;
    }
    for (int i = n << 1; i > n; --i)
    {
        ans = ans * i % MOD;
    }
    for (int i = 1; i <= n; ++i)
    {
        ans = ans * power(i, MOD - 2) % MOD;
    }
    cout << ans << endl;
    return 0;
}