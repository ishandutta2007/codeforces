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
int n, a[100005], sum, L, R;
int fact(int n) { return n ? fact(n - 1) * n % MOD : 1; }
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
int C(int n, int m) { return fact(n) * inv(fact(m) * fact(n - m) % MOD) % MOD; }
std::map<int, int> count;
int work()
{
    int res = 1;
    for (auto i : count)
        res = res * fact(i.second) % MOD;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        sum += a[i];
        ++count[a[i]];
    }
    if (sum % n)
        return std::cout << 0 << std::endl, 0;
    sum /= n;
    for (int i = 1; i <= n; ++i)
        if (sum < a[i])
            ++L;
        else if (sum > a[i])
            ++R;
    if (L == 0 && R == 0)
        return std::cout << 1 << std::endl, 0;
    if (L == 1 || R == 1)
        return std::cout << fact(n) * inv(work()) % MOD << std::endl, 0;
    std::cout << C(n, n - L - R) * 2 % MOD * fact(n - L - R) % MOD * fact(L) % MOD * fact(R) % MOD * inv(work()) % MOD << std::endl;
    return 0;
}