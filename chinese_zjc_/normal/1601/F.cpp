// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const long long m = 998244353;
const long long MOD = 1000000007;
const int lim = 6;
long long pow10[15], n, ans, sum[13], tim;
int len;
std::vector<int> app[13];
int getlen(long long x)
{
    int res = 0;
    while (pow10[res] <= x)
        ++res;
    return res;
}
long long rk(long long x)
{
    long long res = 0;
    int l = getlen(x);
    for (int i = 1; i <= l; ++i)
        res += x / pow10[l - i] - (pow10[i - 1] - 1);
    if (l < len)
    {
        for (int i = l + 1; i < len; ++i)
            res += (x - pow10[l - 1]) * pow10[i - l];
        if (n / pow10[len - l] < x)
            res += n - (pow10[len - 1] - 1);
        else
            res += (x - pow10[l - 1]) * pow10[len - l];
    }
    return res;
}
void dfs1(int now, int val)
{
    app[now].push_back((tim - val + m) % m);
    sum[now] += (tim++ - val + m) % m;
    if (now < len - lim)
        for (int i = 0; i <= 9; ++i)
            dfs1(now + 1, val * 10 + i);
}
void dfs2(long long now)
{
    if (now > n)
        return;
    ans = (ans + (tim++ - now + m * m) % m) % MOD;
    for (int i = 0; i <= 9; ++i)
        dfs2(now * 10 + i);
}
void dfs3(int now, int val)
{
    app[now].push_back((tim - val + m) % m);
    sum[now] += (tim++ - val + m) % m;
    if (now < len - lim - 1)
        for (int i = 0; i <= 9; ++i)
            dfs3(now + 1, val * 10 + i);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    pow10[0] = 1;
    for (int i = 1; i <= 13; ++i)
        pow10[i] = pow10[i - 1] * 10;
    std::cin >> n;
    len = getlen(n);
    for (int i = 1; i <= std::min(pow10[lim - 1] - 1, n); ++i)
        ans = (ans + (rk(i) - i + m * m) % m) % MOD;
    if (pow10[lim - 1] <= n)
    {
        tim = 0;
        for (int i = 0; i != 13; ++i)
            sum[i] = 0, app[i].clear();
        dfs1(0, 0);
        for (int i = 0; i != 13; ++i)
            std::sort(app[i].begin(), app[i].end());
        for (int i = pow10[lim - 1]; i < n / pow10[len - lim]; ++i)
        {
            long long st = rk(i);
            for (int j = 0; j <= len - lim; ++j)
            {
                long long val = (st - i * pow10[j] + m * m) % m;
                ans = (ans + val * app[j].size() + sum[j] -
                       m * (app[j].end() - std::lower_bound(app[j].begin(), app[j].end(), m - val)) + MOD * MOD) %
                      MOD;
            }
        }
        tim = rk(n / pow10[len - lim]);
        dfs2(n / pow10[len - lim]);
        tim = 0;
        for (int i = 0; i != 13; ++i)
            sum[i] = 0, app[i].clear();
        dfs3(0, 0);
        for (int i = 0; i != 13; ++i)
            std::sort(app[i].begin(), app[i].end());
        for (int i = n / pow10[len - lim] + 1; i <= pow10[lim] - 1; ++i)
        {
            long long st = rk(i);
            for (int j = 0; j <= len - lim - 1; ++j)
            {
                long long val = (st - i * pow10[j] + m * m) % m;
                ans = (ans + val * app[j].size() + sum[j] -
                       m * (app[j].end() - std::lower_bound(app[j].begin(), app[j].end(), m - val)) + MOD * MOD) %
                      MOD;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}