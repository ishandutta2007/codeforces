// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, p[200005], w[200005], b[200005], k[200005], t[5000005], a[5000005], ans[5000005], val = 1;
long long seed, base, left;
std::deque<int> que;
int rnd()
{
    int ret = seed;
    seed = (seed * base + 233) % 1000000007;
    return ret;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> p[i] >> k[i] >> b[i] >> w[i];
    for (int i = 1; i <= m; ++i)
    {
        seed = b[i];
        base = w[i];
        for (int j = p[i - 1]; j != p[i]; ++j)
            t[j] = rnd() % 2, a[j] = (rnd() % k[i]) + 1;
    }
    for (int i = n; i--;)
        t[i] ^= t[0];
    for (int i = 0; i != n; ++i)
        left += t[i] ? -a[i] : +a[i];
    if (left == std::accumulate(a, a + n, 0ll))
        ++ans[0];
    else
    {
        if (left > 0)
        {
            ++ans[0];
            --a[0];
            for (int i = 0; i != n; ++i)
                t[i] ^= 1;
        }
        left = 0;
        for (int i = 0; i != n; ++i)
        {
            if (!t[i])
            {
                left += a[i];
                ans[i] += a[i];
                a[i] = 0;
            }
            else
            {
                long long down = std::min(left, static_cast<long long>(a[i]));
                left -= down;
                ans[i] += down;
                a[i] -= down;
            }
        }
        for (int i = 0; i != n; ++i)
        {
            if (!t[i])
            {
                left += a[i];
                ans[i] += a[i];
                a[i] = 0;
            }
            else
            {
                long long down = std::min(left, static_cast<long long>(a[i]));
                left -= down;
                ans[i] += down;
                a[i] -= down;
            }
        }
    }
    for (long long i = 1; i <= n; ++i)
        val = 1ll * val * (((ans[i - 1] ^ (i * i)) + 1) % 1000000007) % 1000000007;
    std::cout << val << std::endl;
    return 0;
}