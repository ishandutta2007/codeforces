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
int n, fa[200005], dp[200005], ans[200005];
std::vector<int> son[200005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        A = A * A % MOD;
        B >>= 1;
    }
    return res;
}
void dfs(int now)
{
    dp[now] = 1;
    for (auto i : son[now])
    {
        dfs(i);
        dp[now] = dp[now] * (dp[i] + 1) % MOD;
    }
}
void work(int now, int way)
{
    // std::cout << way << std::endl;
    ans[now] = (dp[now] * (way + 1)) % MOD;
    int pre[son[now].size() + 1], suf[son[now].size() + 1];
    pre[0] = 1;
    suf[son[now].size()] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
        pre[i + 1] = pre[i] * (dp[son[now][i]] + 1) % MOD;
    for (int i = son[now].size(); i--;)
        suf[i] = suf[i + 1] * (dp[son[now][i]] + 1) % MOD;
    for (int i = 0; i != (int)son[now].size(); ++i)
        work(son[now][i], ((way + 1) * pre[i] % MOD * suf[i + 1]) % MOD);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[i], son[fa[i]].push_back(i);
    // for (int i = 2; i <= n; ++i)
    //     std::cout << i << ' ' << fa[i] << std::endl;
    dfs(1);
    ans[1] = dp[1];
    int pre[son[1].size() + 1], suf[son[1].size() + 1];
    pre[0] = 1;
    suf[son[1].size()] = 1;
    for (int i = 0; i != (int)son[1].size(); ++i)
        pre[i + 1] = pre[i] * (dp[son[1][i]] + 1) % MOD;
    for (int i = son[1].size(); i--;)
        suf[i] = suf[i + 1] * (dp[son[1][i]] + 1) % MOD;
    for (int i = 0; i != (int)son[1].size(); ++i)
        work(son[1][i], (pre[i] * suf[i + 1]) % MOD);
    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}