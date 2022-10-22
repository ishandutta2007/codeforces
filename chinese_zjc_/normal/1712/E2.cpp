// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, sum[200005];
long long ans[200005];
std::vector<int> g[200005], f[200005];
std::vector<std::pair<int, int>> h[200005], q[200005];
void add(int pos, int val)
{
    while (pos)
    {
        sum[pos] += val;
        pos -= pos & -pos;
    }
}
int query(int pos)
{
    int res = 0;
    while (pos <= 200000)
    {
        res += sum[pos];
        pos += pos & -pos;
    }
    return res;
}
int lcm(int x, int y) { return 1ll * x / std::__gcd(x, y) * y; }
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 1; i <= 200000; ++i)
        for (int j = i + i; j <= 200000; j += i)
        {
            g[j].push_back(i);
            if (j % (i << 1))
                f[j].push_back(i << 1);
        }
    for (int i = 1; i <= 200000; ++i)
    {
        for (int j = 0; j != int(g[i].size()); ++j)
        {
            h[i].push_back({g[i][j], g[i].size() - j - 1});
            h[i].push_back({g[i][j], f[i].end() - std::upper_bound(f[i].begin(), f[i].end(), i - g[i][j])});
        }
        for (int j = 0; j != int(f[i].size()); ++j)
        {
            h[i].push_back({f[i][j], f[i].end() - std::upper_bound(f[i].begin(), f[i].end(), std::max(f[i][j], i - f[i][j]))});
        }
    }
    std::cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        ans[i] += (r - l + 1ll) * (r - l) * (r - l - 1) / 6;
        // for (int a = l; a <= r; ++a)
        // {
        //     for (int b = a + 1; b <= r; ++b)
        //         for (int c = b + 1; c <= r; ++c)
        //         {
        //             if (!(lcm(a, lcm(b, c)) < a + b + c) &&
        //                 ((c % b == 0 && c % a == 0) ||
        //                  (a + b + c > c * 2 && c % a == 0 && b % 2 == 0 && c % b && c % (b >> 1) == 0) ||
        //                  (a + b + c > c * 2 &&
        //                   b % 2 == 0 && c % b && c % (b >> 1) == 0 &&
        //                   a % 2 == 0 && c % a && c % (a >> 1) == 0)))
        //                 std::cout << a << ' ' << b << ' ' << c << std::endl;
        //         }
        // }
        q[r].push_back({l, i});
    }
    for (int i = 1; i <= 200000; ++i)
    {
        for (auto j : h[i])
            add(j.first, j.second);
        for (auto k : q[i])
            ans[k.second] -= query(k.first);
    }
    for (int i = 1; i <= T; ++i)
        std::cout << ans[i] << '\n';
    return 0;
}