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
} ans[300005];
int n, k, q, cnt[300005], b[5], a[300005];
typedef std::vector<mint> poly;
void NTT(poly &X)
{
    static std::vector<std::size_t> rev;
    if (rev.size() != X.size())
    {
        rev.resize(X.size());
        for (std::size_t i = 0; i != rev.size(); ++i)
            rev[i] = (rev[i >> 1] | (i & 1 ? rev.size() : 0)) >> 1;
    }
    for (std::size_t i = 0; i != rev.size(); ++i)
        if (i < rev[i])
            std::swap(X[i], X[rev[i]]);
    for (std::size_t i = 1; i != X.size(); i <<= 1)
    {
        mint w = mint(3).pow((MOD - 1) / i / 2);
        for (std::size_t j = 0; j != X.size(); j += i << 1)
        {
            mint W = 1;
            for (std::size_t k = 0; k != i; ++k, W *= w)
            {
                mint A = X[j + k], B = X[i + j + k] * W;
                X[j + k] = A + B;
                X[i + j + k] = A - B;
            }
        }
    }
}
void INTT(poly &X)
{
    NTT(X);
    std::reverse(X.begin() + 1, X.end());
    mint inv = mint(X.size()).inv();
    for (auto &i : X)
        i *= inv;
}
std::size_t up(std::size_t x) { return x == 1 ? 1 : 1 << (32 - __builtin_clz(x - 1)); }
poly operator*(poly A, poly B)
{
    std::size_t len = A.size() + B.size() - 1;
    A.resize(up(len));
    B.resize(A.size());
    NTT(A);
    NTT(B);
    for (std::size_t i = 0; i != A.size(); ++i)
        A[i] *= B[i];
    INTT(A);
    A.resize(len);
    return A;
}
mint C(int n, int m)
{
    switch (m)
    {
    case 0:
        return 1;
    case 1:
        return n;
    case 2:
        return n * (n - 1ll) / 2 % MOD;
    }
    return 0;
}
poly build(int l, int r)
{
    if (r - l == 1)
    {
        poly res(1, 1);
        for (int i = 1; i <= std::min(2, cnt[l]); ++i)
            res.push_back(C(2, i));
        return res;
    }
    int mid = (l + r) >> 1;
    return build(l, mid) * build(mid, r);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1, c; i <= n; ++i)
    {
        std::cin >> c;
        ++cnt[c];
    }
    for (int i = 0; i != k; ++i)
        std::cin >> b[i];
    std::cin >> q;
    for (int i = 0; i != q; ++i)
        std::cin >> a[i], a[i] >>= 1;
    std::sort(b, b + k);
    poly res(1, 1);
    for (int i = 0; i != k; ++i)
    {
        res = res * (build(i == 0 ? 0 : b[i - 1], b[i]));
        for (int j = 0; j != q; ++j)
            if (0 <= a[j] - b[i] - 1 && a[j] - b[i] - 1 < int(res.size()))
                ans[j] += res[a[j] - b[i] - 1];
    }
    for (int i = 0; i != q; ++i)
        std::cout << ans[i] << '\n';
    return 0;
}