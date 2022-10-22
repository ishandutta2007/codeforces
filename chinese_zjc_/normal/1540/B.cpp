//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int MOD = 1000000007;
int n, fa[10][205], depth[205], fact[405], ifact[405], ans, dp[205][205];
std::vector<int> to[205];
void init(int now)
{
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : to[now])
    {
        if (i == fa[0][now])
            continue;
        fa[0][i] = now;
        depth[i] = depth[now] + 1;
        init(i);
    }
}
int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        std::swap(A, B);
    for (int i = 9; ~i; --i)
        if (depth[A] - depth[B] >= 1 << i)
            A = fa[i][A];
    if (A == B)
        return A;
    for (int i = 9; ~i; --i)
        if (fa[i][A] != fa[i][B])
            A = fa[i][A], B = fa[i][B];
    return fa[0][A];
}
int power(int A, int B)
{
    int res = 1;
    if (B < 0)
        exit(114514);
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
int C(int n, int m) { return 0 <= n && n <= m ? fact[m] * ifact[n] % MOD * ifact[m - n] % MOD : 0; }
int work(int timj, int timk)
{
    if (~dp[timj][timk])
        return dp[timj][timk];
    int res = 0;
    if (timk == 0)
        res = 1;
    else
        for (int l = 0; l != timj; ++l)
            res = (res + power(inv(2), timk + l) * C(l, timk + l - 1)) % MOD;
    return dp[timj][timk] = res;
}
signed main()
{
    memset(dp, -1, sizeof(dp));
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n * 2; ++i)
        ifact[i] = power(fact[i] = fact[i - 1] * i % MOD, MOD - 2);
    for (int i = 1; i != n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(fa, 0, sizeof(fa));
        memset(depth, 0, sizeof(depth));
        init(i);
        // for (int i = 1; i <= n; ++i)
        //     std::cout << depth[i] << " \n"[i == n];
        for (int j = 1; j <= n; ++j)
            for (int k = j + 1; k <= n; ++k)
            {
                int lca = LCA(j, k), timj = depth[j] - depth[lca], timk = depth[k] - depth[lca];
                ans = (ans + work(timj, timk)) % MOD;
            }
        // std::cout << ans << std::endl;
    }
    std::cout << (ans * power(n, MOD - 2) % MOD) << std::endl;
    return 0;
}