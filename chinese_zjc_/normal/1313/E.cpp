// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, za[1500005], zb[1500005];
long long ans;
char a[1500005], b[1500005], s[1000005];
struct BIT
{
    long long sum[500005];
    void add(int pos, long long val)
    {
        while (pos)
        {
            sum[pos] += val;
            pos -= pos & -pos;
        }
    }
    long long query(int pos)
    {
        long long res = 0;
        while (pos <= n)
        {
            res += sum[pos];
            pos += pos & -pos;
        }
        return res;
    }
} A, B;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    std::cin >> (a + 1 + m) >> (b + 1) >> (s + 1);
    std::copy(s + 1, s + 1 + m, a + 1);
    std::copy(s + 1, s + 1 + m, b + 1 + n);
    for (int i = 2, l = 1, r = 1; i <= n + m; ++i)
    {
        if (i <= r)
            za[i] = std::min(za[i - l + 1], r - i + 1);
        while (i + za[i] <= n + m && a[i + za[i]] == a[1 + za[i]])
            ++za[i];
        if (i + za[i] - 1 > r)
            l = i, r = i + za[i] - 1;
    }
    for (int i = n + m - 1, l = n + m, r = n + m; i >= 1; --i)
    {
        if (i >= l)
            zb[i] = std::min(zb[i - r + n + m], i - l + 1);
        while (i - zb[i] >= 1 && b[i - zb[i]] == b[n + m - zb[i]])
            ++zb[i];
        if (i - zb[i] + 1 < l)
            l = i - zb[i] + 1, r = i;
    }
    for (int i = 1; i <= n + m; ++i)
        za[i] = std::min(za[i], m - 1);
    for (int i = 1; i <= n + m; ++i)
        zb[i] = std::min(zb[i], m - 1);
    for (int i = 1, j = 1; i <= n; ++i)
    {
        while (j <= n && j - i + 1 < m)
            A.add(zb[j], 1), B.add(zb[j], zb[j]), ++j;
        int g = m - za[i + m];
        ans += B.query(g) - (g - 1) * A.query(g);
        A.add(zb[i], -1);
        B.add(zb[i], -zb[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}