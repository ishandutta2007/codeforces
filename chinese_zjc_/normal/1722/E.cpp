// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, q, l[100005], r[100005];
long long ans[100005], sum[1005];
std::vector<int> ql[1005], qr[1005], a[1005];
void add(int pos, long long val)
{
    while (pos <= 1000)
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
long long query(int pos)
{
    long long res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> q;
        std::fill(ans + 1, ans + 1 + q, 0);
        for (int i = 1; i <= 1000; ++i)
            ql[i].clear(), qr[i].clear(), a[i].clear(), sum[i] = 0;
        for (int i = 1, h, w; i <= n; ++i)
        {
            std::cin >> h >> w;
            a[h].push_back(w);
        }
        for (int i = 1, L, R; i <= q; ++i)
        {
            std::cin >> L >> l[i] >> R >> r[i];
            ql[L].push_back(i);
            qr[R].push_back(i);
        }
        for (int i = 1; i <= 1000; ++i)
        {
            for (auto j : qr[i])
                ans[j] += query(r[j] - 1) - query(l[j]);
            for (auto j : a[i])
                add(j, i * j);
            for (auto j : ql[i])
                ans[j] -= query(r[j] - 1) - query(l[j]);
        }
        for (int i = 1; i <= q; ++i)
            std::cout << ans[i] << '\n';
    }
    return 0;
}