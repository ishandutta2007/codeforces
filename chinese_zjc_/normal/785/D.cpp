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
char s[200005];
int n, fact[200005], ifact[200005], pre[200005], suf[200005], ans;
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
int C(int M, int N)
{
    if (0 <= N && N <= M)
        return fact[M] * ifact[N] % MOD * ifact[M - N] % MOD;
    return 0;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = fact[0] = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[n] = power(fact[n], MOD - 2);
    for (int i = n; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + (s[i] == '(');
    for (int i = n; i; --i)
        suf[i] = suf[i + 1] + (s[i] == ')');
    for (int i = 1; i <= n; ++i)
        if (s[i] == '(')
            ans = (ans + C(pre[i] + suf[i] - 1, suf[i] - 1)) % MOD;
    std::cout << ans << std::endl;
    return 0;
}