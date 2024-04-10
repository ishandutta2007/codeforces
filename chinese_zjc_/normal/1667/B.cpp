// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, dp[500005];
long long a[500005];
std::vector<long long> app;
#define lson (now << 1)
#define rson (lson | 1)
#define mid ((l + r) >> 1)
struct tree
{
    int t[1 << 20];
    void pushup(int now) { t[now] = std::max(t[lson], t[rson]); }
    void build(int now = 1, int l = 0, int r = app.size())
    {
        if (r - l == 1)
            return void(t[now] = INT_MIN / 2);
        build(lson, l, mid);
        build(rson, mid, r);
        pushup(now);
    }
    void update(int pos, int val, int now = 1, int l = 0, int r = app.size())
    {
        if (r - l == 1)
            return void(t[now] = std::max(t[now], val));
        if (pos < mid)
            update(pos, val, lson, l, mid);
        else
            update(pos, val, rson, mid, r);
        pushup(now);
    }
    int query(int L, int R, int now = 1, int l = 0, int r = app.size())
    {
        if (L <= l && r <= R)
            return t[now];
        if (r <= L || R <= l)
            return INT_MIN / 2;
        return std::max(query(L, R, lson, l, mid), query(L, R, rson, mid, r));
    }
} A, B, C;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        app.clear();
        app.push_back(a[0] = 0);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], app.push_back(a[i] += a[i - 1]);
        std::sort(app.begin(), app.end());
        app.erase(std::unique(app.begin(), app.end()), app.end());
        A.build();
        B.build();
        C.build();
        for (int i = 0; i <= n; ++i)
            a[i] = std::lower_bound(app.begin(), app.end(), a[i]) - app.begin();
        A.update(a[0], dp[0] - 0);
        B.update(a[0], dp[0]);
        C.update(a[0], dp[0] + 0);
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = std::max({i + A.query(0, a[i]), B.query(a[i], a[i] + 1), C.query(a[i] + 1, app.size()) - i});
            A.update(a[i], dp[i] - i);
            B.update(a[i], dp[i]);
            C.update(a[i], dp[i] + i);
        }
        std::cout << dp[n] << std::endl;
    }
    return 0;
}