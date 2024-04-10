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
int n, k, a[5005], val[5005], ans, ninv;
std::vector<int> F;
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
    F.push_back(1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        F.push_back(0);
        for (int j = i; j; --j)
            F[j] = (F[j] * a[i] + MOD - F[j - 1]) % MOD;
        F[0] = F[0] * a[i] % MOD;
    }
    ninv = power(n, MOD - 2);
    val[0] = 1;
    for (int i = 0; i + 1 < F.size(); ++i)
        val[i + 1] = val[i] * ninv % MOD * (k - i) % MOD;
    for (int i = 0; i < F.size(); ++i)
        ans = (ans + F[i] * val[i]) % MOD;
    std::cout << (F[0] - ans + MOD) % MOD << std::endl;
    return 0;
}