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
int fact(int x) { return x ? fact(x - 1) * x % MOD : 1; }
int n, a[200005], ans, cnt, tot, ken[200005], no[200005];
struct BIT
{
    int sum[200005];
    void add(int pos, int val)
    {
        while (pos <= n)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos)
    {
        int res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
} d;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], ken[i] = ken[i - 1] + !~a[i];
    tot = fact(cnt = ken[n]);
    ans = cnt * (cnt - 1) % MOD * inv(4) % MOD;
    for (int i = 1; i <= n; ++i)
        if (~a[i])
            no[a[i]] = 1;
    for (int i = 1; i <= n; ++i)
        no[i] = no[i - 1] + !no[i];
    for (int i = 1; i <= n; ++i)
        if (~a[i])
            ans = (ans + (ken[i] * (no[n] - no[a[i]]) + (ken[n] - ken[i]) * no[a[i]]) % MOD * inv(cnt)) % MOD;
    // for (int i = 1; i <= n; ++i)
    //     std::cout << no[i] << ' ' << ken[i] << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        if (~a[i])
        {
            d.add(a[i], 1);
            ans = (ans + d.query(n) - d.query(a[i])) % MOD;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}