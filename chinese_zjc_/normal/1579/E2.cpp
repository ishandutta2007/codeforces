// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005];
long long ans;
std::vector<int> app;
struct BIT
{
    int sum[200005];
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
} bit;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        app.clear();
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], app.push_back(a[i]);
        std::sort(app.begin(), app.end());
        app.erase(std::unique(app.begin(), app.end()), app.end());
        for (int i = 1; i <= n; ++i)
            a[i] = std::upper_bound(app.begin(), app.end(), a[i]) - app.begin();
        bit.add(a[1], 1);
        for (int i = 2; i <= n; ++i)
        {
            ans += std::min(bit.query(a[i] - 1), bit.query(app.size()) - bit.query(a[i]));
            bit.add(a[i], +1);
        }
        for (int i = 1; i <= n; ++i)
            bit.add(a[i], -1);
        std::cout << ans << std::endl;
    }
    return 0;
}