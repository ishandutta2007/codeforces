// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::vector<int> app[200005];
int n, q, a[200005], b[200005], sum[200005], ans[200005];
std::vector<std::pair<int, int>> c[200005];
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
    while (pos <= n)
    {
        res += sum[pos];
        pos += pos & -pos;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            app[std::max(b[i], b[j])].push_back(std::min(b[i], b[j]));
    for (int i = 1; i <= q; ++i)
    {
        static int l, r;
        std::cin >> l >> r;
        c[r].push_back({l, i});
    }
    for (int r = 1; r <= n; ++r)
    {
        for (auto i : app[r])
            add(i, 1);
        for (auto i : c[r])
            ans[i.second] = query(i.first);
    }
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << '\n';
    return 0;
}