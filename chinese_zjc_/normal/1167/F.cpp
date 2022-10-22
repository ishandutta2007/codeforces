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
int n, a[500005], ans;
std::vector<int> rk;
struct BIT
{
    int sum[500005];
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
} pre, suf;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], rk.push_back(i);
    std::sort(rk.begin(), rk.end(), [&](const int &A, const int &B)
              { return a[A] < a[B]; });
    for (auto i : rk)
    {
        int tot = (i * (n - i + 1) + pre.query(i) * (n - i + 1) + (suf.query(n) - suf.query(i)) * i) % MOD;
        ans = (ans + tot * a[i]) % MOD;
        pre.add(i, i);
        suf.add(i, n - i + 1);
    }
    std::cout << ans << std::endl;
    return 0;
}