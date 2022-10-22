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
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 998244353;
vector<int> g, f;
int a[11], n, k, inv[9000005], ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    n >>= 1;
    for (int i = 1; i <= k; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + k);
    f.resize(a[k] - a[1] + 1);
    for (int i = 1; i <= k; ++i)
        f[a[i] - a[1]] = 1;
    inv[1] = 1;
    for (int i = 2; i <= 9000000; ++i)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    g.resize(f.size() * n);
    g[0] = 1;
    for (int m = 0; m + 1 < g.size(); ++m)
    {
        int sum = 0;
        for (int i = 0; i + 1 < f.size() && m - i >= 0; ++i)
            sum += n * f[i + 1] * (i + 1) * g[m - i];
        for (int i = 1; i < f.size() && m - i + 1 >= 0; ++i)
            sum -= g[m - i + 1] * (m - i + 1) * f[i];
        g[m + 1] = (sum % MOD + MOD) * inv[m + 1] % MOD;
    }
    for_each(g.begin(), g.end(), [&](const int &x) { ans = (ans + x * x) % MOD; });
    cout << ans << endl;
    return 0;
}