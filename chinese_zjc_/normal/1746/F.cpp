// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 Rand(seed);
int n, q, a[300005], b[300005], op[300005], l[300005], r[300005], k[300005];
long long sum[300005];
bool ans[300005];
std::vector<int> val, app;
void add(int pos, int val)
{
    while (pos <= n)
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
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], app.push_back(a[i]);
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> op[i] >> l[i] >> r[i];
        if (op[i] == 1)
            app.push_back(r[i]);
        else
            std::cin >> k[i], ans[i] = (r[i] - l[i] + 1) % k[i] == 0;
    }
    std::sort(app.begin(), app.end());
    app.erase(std::unique(app.begin(), app.end()), app.end());
    for (int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(app.begin(), app.end(), a[i]) - app.begin();
    for (int i = 1; i <= q; ++i)
        if (op[i] == 1)
            r[i] = std::lower_bound(app.begin(), app.end(), r[i]) - app.begin();
    val.resize(app.size());
    while (clock() < 2.7 * CLOCKS_PER_SEC)
    {
        // for (int i = 1; i <= n; ++i)
        //     std::cout << val[i] << " \n"[i == n];
        // std::generate(val.begin(), val.end(), Rand);
        for (auto &i : val)
            i = Rand();
        for (int i = 1; i <= n; ++i)
            sum[i] = b[i] = val[a[i]];
        for (int i = 1; i <= n; ++i)
            if (i + (i & -i) <= n)
                sum[i + (i & -i)] += sum[i];
        for (int i = 1; i <= q; ++i)
            if (op[i] == 1)
            {
                add(l[i], -b[l[i]]);
                add(l[i], b[l[i]] = val[r[i]]);
            }
            else
                ans[i] &= (query(r[i]) - query(l[i] - 1)) % k[i] == 0;
    }
    for (int i = 1; i <= q; ++i)
        if (op[i] == 2)
            std::cout << (ans[i] ? "YES" : "NO") << '\n';
    return 0;
}//?????