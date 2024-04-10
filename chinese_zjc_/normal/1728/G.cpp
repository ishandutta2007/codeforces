// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
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
} f[1 << 16], pre[16], suf[16], v[16][16], g[16][16], any;
int d, n, m, q, a[200005], p[16];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> d >> n >> m;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    std::sort(a, a + n);
    for (int i = 0; i != m; ++i)
        std::cin >> p[i];
    std::sort(p, p + m);
    std::fill(pre, pre + m, 1);
    std::fill(suf, suf + m, 1);
    for (int i = 0; i != m; ++i)
        for (int j = 0; j != n; ++j)
            if (a[j] < p[i])
                pre[i] *= std::abs(a[j] - p[i]);
            else
                suf[i] *= std::abs(a[j] - p[i]);
    for (int i = 0; i != m; ++i)
        for (int j = i; ++j != m;)
        {
            v[i][j] = 1;
            for (int k = 0; k != n; ++k)
                if (p[i] <= a[k] && a[k] < p[j])
                    v[i][j] *= std::min(std::abs(p[i] - a[k]), std::abs(p[j] - a[k]));
        }
    for (int i = 0; i != 1 << m; ++i)
        if (i + 1 == 1 << m)
            f[i] = mint(d + 1).pow(n);
        else
        {
            int lst = -1;
            f[i] = 1;
            for (int j = 0; j != m; ++j)
                if (~i >> j & 1)
                {
                    f[i] *= ~lst ? v[lst][j] : pre[j];
                    lst = j;
                }
            f[i] *= suf[lst];
        }
    for (int i = 0; i != m; ++i)
        for (int j = 0; j != 1 << m; ++j)
            if (j >> i & 1)
                f[j] -= f[j ^ 1 << i];
    for (int i = 0; i != 1 << m; ++i)
        if (i + 1 == 1 << m)
            any = f[i];
        else
        {
            int min = INT_MAX, max = INT_MIN;
            for (int j = 0; j != m; ++j)
                if (~i >> j & 1)
                {
                    min = std::min(min, j);
                    max = std::max(max, j);
                }
            g[min][max] += f[i];
        }
    std::cin >> q;
    for (int i = 0, x; i != q; ++i)
    {
        std::cin >> x;
        mint ans = any * (d + 1);
        for (int j = 0; j != m; ++j)
            for (int k = j; k != m; ++k)
                ans += g[j][k] * (d - std::max(std::abs(x - p[j]), std::abs(x - p[k])) + 1);
        std::cout << ans << '\n';
    }
    return 0;
}