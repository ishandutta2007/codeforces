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
int n, a[1000005], ans;
void solve(int l, int r)
{
    if (l == r)
    {
        ans = (ans + a[l]) % MOD;
        return;
    }
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    int lsum = 0, rsum = 0;
    for (int i = mid, sum = 1; i >= l; --i)
    {
        lsum = (lsum + sum * std::max(0ll, std::min(a[i], a[i + 1]))) % MOD;
        sum = sum * std::max(0ll, std::min(a[i], std::min(a[i - 1], a[i + 1]))) % MOD;
    }
    for (int i = mid + 1, sum = 1; i <= r; ++i)
    {
        rsum = (rsum + sum * std::max(0ll, std::min(a[i], a[i - 1]))) % MOD;
        sum = sum * std::max(0ll, std::min(a[i], std::min(a[i - 1], a[i + 1]))) % MOD;
    }
    // std::cout << lsum << ' ' << rsum << std::endl;
    ans = (ans + lsum * rsum) % MOD;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], --a[i];
    solve(1, n);
    std::cout << ans << std::endl;
    return 0;
}