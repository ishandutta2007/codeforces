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
int n, sum[1 << 24], pop[1 << 24], pre[1 << 24], k, a[2], fact[25], ans;
template <class fun>
void dfs(int now, int lim, int S0, int S1, int cnt0, int cnt1, fun f)
{
    if (now == lim)
        return f(std::make_pair(S0, S1), std::make_pair(cnt0, cnt1));
    dfs(now + 1, lim, S0 + sum[1 << now], S1 + sum[1 << now], cnt0 + 1, cnt1, f);
    dfs(now + 1, lim, S0, S1 + sum[1 << now], cnt0, cnt1 + 1, f);
    dfs(now + 1, lim, S0, S1, cnt0, cnt1, f);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
        std::cin >> sum[1 << i];
    for (int i = 1; i != 1 << n; ++i)
        sum[i] = sum[i & (i - 1)] + sum[i & -i], pop[i] = pop[i & (i - 1)] + 1;
    std::cin >> k;
    for (int i = 0; i != k; ++i)
        std::cin >> a[i];
    std::sort(a, a + k);
    fact[0] = 1;
    for (int i = 0; i != n; ++i)
        fact[i + 1] = fact[i] * (i + 1) % MOD;
    ans = fact[n];
    if (k >= 1)
    {
        for (int i = 0; i != k; ++i)
            for (int j = 0; j != 1 << n; ++j)
                if (sum[j] == a[i])
                    ans = (ans - fact[pop[j]] * fact[n - pop[j]] + MOD * MOD) % MOD;
        if (k == 2)
        {
            std::map<std::pair<int, int>, std::map<std::pair<int, int>, int>> map;
            int half = n / 2;
            dfs(0, half, 0, 0, 0, 0, [&](const std::pair<int, int> &A, const std::pair<int, int> &B)
                { ++map[A][B]; });
            // std::cout << "?" << std::endl;
            dfs(half, n, 0, 0, 0, 0, [&](const std::pair<int, int> &A, const std::pair<int, int> &B)
                {
                    const std::map<std::pair<int, int>, int> &nxt = map[{a[0] - A.first, a[1] - A.second}];
                    for (auto i : nxt)
                        ans = (ans + fact[B.first + i.first.first] *
                                         fact[B.second + i.first.second] % MOD *
                                         fact[n - B.first - B.second - i.first.first - i.first.second] % MOD *
                                         i.second) %
                              MOD;
                });
        }
    }
    std::cout << ans << std::endl;
    return 0;
}