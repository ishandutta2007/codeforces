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
int n, c[5], f[1000005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        ++c[x];
    }
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i - 2] * (i - 1) + f[i - 1]) % MOD;
    ans = f[c[1]];
    for (int i = 1; i <= c[2]; ++i)
        ans = ans * (n - i + 1) % MOD;
    std::cout << ans << std::endl;
    return 0;
}