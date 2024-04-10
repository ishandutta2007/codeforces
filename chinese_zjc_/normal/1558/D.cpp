// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
int fact[400005], ifact[400005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = 1ll * res * A % MOD;
        B >>= 1;
        A = 1ll * A * A % MOD;
    }
    return res;
}
int C(int n, int m) { return 0 <= m && m <= n ? 1ll * fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
int T, n, m, sum[400005];
std::pair<int, int> a[200005];
std::set<int> ans;
std::vector<int> app;
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
int find(int rk)
{
    int res = 0;
    for (int i = 18; i--;)
        if ((1 << i) - sum[res | 1 << i] < rk)
            rk -= (1 << i) - sum[res | 1 << i], res |= 1 << i;
    ++res;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (long long i = 1; i <= 400000; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifact[400000] = power(fact[400000], MOD - 2);
    for (long long i = 400000; i; --i)
        ifact[i - 1] = ifact[i] * i % MOD;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 0; i != m; ++i)
            std::cin >> a[i].first >> a[i].second;
        ans.clear();
        app.clear();
        for (int i = m; i--;)
        {
            ans.insert(find(a[i].second + 1));
            app.push_back(find(a[i].second));
            add(find(a[i].second), 1);
        }
        for (auto i : app)
            add(i, -1);
        std::cout << C(n - 1 + n - ans.size(), n) << std::endl;
    }
    return 0;
}