// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
constexpr int lim = 300000;
constexpr int MOD = 1000000007;
int n, cnt[lim + 5][20], max[lim + 5], pow2[lim + 5], ans;
constexpr int power(int A, int B)
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
struct node1
{
    int lst[lim + 5], p[lim + 5], cnt;
    node1() : lst(), p(), cnt()
    {
        for (int i = 2; i <= lim; ++i)
        {
            if (!lst[i])
            {
                lst[i] = i;
                p[cnt++] = i;
            }
            for (auto j : p)
            {
                if (i * j > lim)
                    break;
                lst[i * j] = j;
                if (i % j == 0)
                    break;
            }
        }
    }
};
node1 p;
struct node2
{
    int fact[lim + 5], ifact[lim + 5];
    node2() : fact(), ifact()
    {
        fact[0] = 1;
        for (int i = 1; i <= lim; ++i)
            fact[i] = 1ll * fact[i - 1] * i % MOD;
        ifact[lim] = power(fact[lim], MOD - 2);
        for (int i = lim; i; --i)
            ifact[i - 1] = 1ll * ifact[i] * i % MOD;
    }
    int C(int n, int m) { return 0 <= m && m <= n ? 1ll * fact[n] * ifact[m] % MOD * ifact[n - m] % MOD : 0; }
};
node2 f;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    pow2[0] = 1;
    for (int i = 1; i <= lim; ++i)
        pow2[i] = (pow2[i - 1] << 1) % MOD;
    for (int i = 1, x; i <= n; ++i)
    {
        std::cin >> x;
        while (x > 1)
        {
            int tmp = p.lst[x], val = 0;
            while (x % tmp == 0)
                ++val, x /= tmp;
            ++cnt[tmp][val];
            max[tmp] = std::max(max[tmp], val);
        }
    }
    for (auto i : p.p)
    {
        if (!i)
            break;
        if (!max[i])
            continue;
        for (int j = max[i]; j; --j)
        {
            cnt[i][j - 1] += cnt[i][j];
            const int pre = n - cnt[i][j], &suf = cnt[i][j];
            for (int k = 0, sum = 0; k <= suf; ++k)
            {
                sum = (sum + 1ll * f.C(pre, k) * k) % MOD;
                ans = (ans + 1ll * f.C(suf, k) * sum) % MOD;
            }
            for (int k = 0, sum = pow2[pre]; k <= suf; ++k)
            {
                sum = (sum + (MOD - 1ll) * f.C(pre, k)) % MOD;
                ans = (ans + 1ll * sum * f.C(suf, k) % MOD * k) % MOD;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}