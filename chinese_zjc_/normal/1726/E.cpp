// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
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
} fact[300005], ifact[300005], ffact[300005];
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
mint C(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[m] * ifact[n - m] : 0; }
poly f, g;
int T, n, a[10], b[10];
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i <= 300000; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[300000] = fact[300000].inv();
    for (int i = 300000; i; --i)
        ifact[i - 1] = ifact[i] * i;
    ffact[0] = ffact[1] = 1;
    for (int i = 2; i <= 300000; ++i)
        ffact[i] = ffact[i - 2] * i;
    f.resize(300001);
    f[0] = 1;
    for (int i = 2; i <= 300000; i += 2)
        f[i] = ffact[i - 1] * ifact[i];
    g.resize(300001);
    for (int i = 0; i <= 300000; ++i)
        g[i] = ifact[i];
    f = f * g;
    f.resize(300001);
    for (int i = 0; i <= 300000; ++i)
        f[i] *= fact[i];
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        mint ans = f[n];
        for (int i = 1; 4 * i <= n; ++i)
            ans += mint(2).pow(i) * ffact[2 * i - 1] * C(n - 2 * i, 2 * i) * f[n - 4 * i];
        std::cout << ans << std::endl;
        // int t = 0;
        // std::iota(a, a + n, 0);
        // std::map<std::vector<int>, int> ggg;
        // do
        // {
        //     for (int i = 0; i != n; ++i)
        //         b[a[i]] = i;
        //     bool flag = true;
        //     for (int i = 0; i != n; ++i)
        //         flag &= std::abs(a[i] - b[i]) <= 1;
        //     t += flag;
        //     if (flag)
        //     {
        //         std::vector<int> g;
        //         for (int i = 0; i != n; ++i)
        //             if (~b[i])
        //             {
        //                 int j = i, cnt = 0;
        //                 do
        //                 {
        //                     b[j] = -1;
        //                     j = a[j];
        //                     ++cnt;
        //                 } while (~b[j]);
        //                 g.push_back(cnt);
        //             }
        //         std::sort(g.begin(), g.end());
        //         ++ggg[g];
        //     }
        // } while (std::next_permutation(a, a + n));
        // std::cout << t << std::endl;
        // for (auto i : ggg)
        // {
        //     for (auto j : i.first)
        //         std::cout << j << ' ';
        //     std::cout << i.second << std::endl;
        // }
    }
    return 0;
}