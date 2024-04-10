// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
struct mint
{
    unsigned v;
    mint(unsigned v_ = 0) : v(v_) {}
    mint operator-() const { return v ? MOD - v : *this; }
    mint &operator+=(const mint &X) { return (v += X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator-=(const mint &X) { return (v += MOD - X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator*=(const mint &X) { return v = 1llu * v * X.v % MOD, *this; }
    mint &operator/=(const mint &X) { return *this *= X.inv(); }
    mint pow(long long B) const
    {
        B %= MOD - 1;
        if (B < 0)
            B += MOD - 1;
        mint res = 1, A = *this;
        while (B)
        {
            if (B & 1)
                res *= A;
            B >>= 1;
            A *= A;
        }
        return res;
    }
    mint inv() const { return pow(MOD - 2); }
    friend mint operator+(const mint &A, const mint &B) { return mint(A) += B; }
    friend mint operator-(const mint &A, const mint &B) { return mint(A) -= B; }
    friend mint operator*(const mint &A, const mint &B) { return mint(A) *= B; }
    friend mint operator/(const mint &A, const mint &B) { return mint(A) /= B; }
    friend std::istream &operator>>(std::istream &A, mint &B) { return A >> B.v; }
    friend std::ostream &operator<<(std::ostream &A, const mint &B) { return A << B.v; }
    explicit operator bool() const { return v; }
} a[200005], ans[200005];
long long b[200005];
int n, m, rk[200005], l[200005], r[200005], sa[200005];
std::vector<long long> app;
std::vector<int> q[200005];
bool cmp(int A, int B) { return b[A] < b[B]; }
struct BIT
{
    mint sum[200005];
    void add(int pos, mint val)
    {
        ++pos;
        while (pos <= n + 1)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    void add(int L, int R, mint val)
    {
        add(L, val);
        add(R + 1, -val);
    }
    mint query(int pos)
    {
        ++pos;
        mint res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    void clear(int pos)
    {
        add(pos, pos, -query(pos));
    }
} A, B;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        a[i] = a[i + 1] - a[i];
    a[n] = 0;
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i], b[i] += b[i - 1];
    std::iota(rk, rk + 1 + n, 0);
    std::sort(rk, rk + 1 + n, cmp);
    for (int i = 1; i <= m; ++i)
        std::cin >> l[i] >> r[i], --l[i], q[r[i]].push_back(i);
    for (int i = 0; i <= n; ++i)
        sa[rk[i]] = i;
    for (int i = 1; i <= n; ++i)
    {
        A.add(0, sa[i], -a[i]);
        B.add(0, sa[i], a[i] * (b[i] % MOD + MOD));
        A.add(sa[i], n, a[i]);
        B.add(sa[i], n, -a[i] * (b[i] % MOD + MOD));
        A.clear(sa[i]);
        B.clear(sa[i]);
        for (auto j : q[i])
            ans[j] = A.query(sa[l[j]]) * (b[l[j]] % MOD + MOD) + B.query(sa[l[j]]);
    }
    for (int i = 1; i <= m; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}