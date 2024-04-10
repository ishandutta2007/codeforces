// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int T, n, m, v[1 << 19], ans, pow2[500005];
std::vector<int> s;
#define lson (now << 1)
#define rson (lson | 1)
#define lmid ((l + r) >> 1)
#define rmid (lmid + 1)
void build(int now = 1, int l = 1, int r = n)
{
    v[now] = (1 << 30) - 1;
    if (l == r)
        return;
    build(lson, l, lmid);
    build(rson, rmid, r);
}
void modify(int L, int R, int val, int now = 1, int l = 1, int r = n)
{
    if (r < L || R < l)
        return;
    if (L <= l && r <= R)
    {
        v[now] &= val;
        return;
    }
    modify(L, R, val, lson, l, lmid);
    modify(L, R, val, rson, rmid, r);
}
void visit(int val = (1 << 30) - 1, int now = 1, int l = 1, int r = n)
{
    val &= v[now];
    if (l == r)
    {
        s.push_back(val);
        return;
    }
    visit(val, lson, l, lmid);
    visit(val, rson, rmid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    pow2[0] = 1;
    for (int i = 1; i <= 500000; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        std::cin >> n >> m;
        build();
        for (int i = 1, l, r, x; i <= m; ++i)
        {
            std::cin >> l >> r >> x;
            modify(l, r, x);
        }
        s.clear();
        visit();
        for (int i = 0; i != 30; ++i)
        {
            int c = std::count_if(s.begin(), s.end(), [&](const int &x)
                                  { return x >> i & 1; });
            int t = n - c;
            if (c)
                ans = (ans + pow2[t + i + c - 1]) % MOD;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}