// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const long long MOD = 1000000007;
// #define debug
int n, m, f[200005], g[200005], in[400005], t, ans;
template <void (*work)(int &, int)>
struct BIT
{
    int sum[400005];
    void add(int pos, int val)
    {
        while (pos <= m)
        {
            work(sum[pos], val);
            pos += pos & -pos;
        }
    }
    int query(int pos)
    {
        int res = 0;
        while (pos)
        {
            work(res, sum[pos]);
            pos -= pos & -pos;
        }
        return res;
    }
    void clear()
    {
        std::memset(sum, 0, sizeof(sum));
    }
};
void add(int &A, int B) { A = (A + B) % MOD; }
void max(int &A, int B) { A = std::max(A, B); }
BIT<add> ADD;
BIT<max> MAX;
struct node
{
    int l, r, p;
    bool g;
} a[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].l >> a[i].r, ++a[i].l, ++a[i].r, a[i].p = i, in[a[i].l] = in[a[i].r] = i;
    std::cin >> t;
    for (int i = 1, p; i <= t; ++i)
        std::cin >> p, a[p].g = true;
    a[0].l = 1;
    m = a[0].r = n + n + 2;
    std::sort(a, a + 1 + n, [&](const node &A, const node &B)
              { return A.r < B.r; });
    for (int i = 0; i <= n; ++i)
        ADD.add(a[i].l, f[a[i].p] = (1 + ADD.query(a[i].r) - ADD.query(a[i].l) + MOD) % MOD);
    ADD.clear();
    std::sort(a, a + 1 + n, [&](const node &A, const node &B)
              { return A.l < B.l; });
    for (int i = n; i >= 0; --i)
    {
        int end = MAX.query(a[i].r);
        g[a[i].p] = end == 0 ? a[i].g : (ADD.query(end - 1) + g[in[end]] + 1) % MOD;
        ADD.add(a[i].r, f[a[i].p]);
        if (a[i].g)
            MAX.add(a[i].r, a[i].r);
    }
    std::cout << (g[0] + MOD - 1) % MOD << std::endl;
    return 0;
}