// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, c[70005], d[70005], pre[70005], cur, pos;
void set(int pos, int val)
{
    for (int i = pos, j = 1; val >= j; ++i, j <<= 1)
    {
        int t = (val + j) / (j << 1);
        cur += t - d[i];
        d[i] = t;
    }
}
int check(int x)
{
    for (int i = 0; i != 70000; ++i)
        c[i] = std::max(0, (x - i + 1) >> 1);
    return std::accumulate(c, c + 70000, 0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    int l = 0, r = 70000;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid) >= n)
            r = mid;
        else
            l = mid + 1;
    }
    check(l);
    cur = std::accumulate(c, c + 70000, 0);
    for (int i = 0; cur > n; ++i)
        if (c[i] * 2 - 1 + i == l)
            --c[i], --cur;
    for (int i = 0; i != 70000; ++i)
        pre[i + 1] = pre[i] + c[i];
    long long tot = 0;
    for (int i = 0; i != 70000; ++i)
        tot += i * c[i] + c[i] * c[i];
    std::cout << tot << std::endl;
    cur = 0;
    int lst = 0;
    for (int i = 0, x; i != q; ++i)
    {
        std::cin >> x;
        while (pre[pos] + (2 * c[pos] - 1) < x)
            set(pos, c[pos] * 2 - 1), lst = c[pos] - 1, ++pos;
        int t = lst + x - cur;
        // std::cout << pos << ' ' << t << std::endl;
        set(pos, lst = t);
        // std::cout << cur << ' ' << x << std::endl;
        int ctz = __builtin_ctz(t);
        std::cout << pos + ctz + (t >> ctz) << '\n';
        // for (int j = 0; j != 4; ++j)
        //     std::cout << d[j] << " \n"[j + 1 == 4];
    }
    return 0;
}