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
} fact[200005], ifact[200005];
mint C(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[m] * ifact[n - m] : 0; }
int T, n, l, r;
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[200000] = fact[200000].inv();
    for (int i = 200000; i; --i)
        ifact[i - 1] = ifact[i] * i;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> l >> r;
        int min = std::min(1 - l, r - n);
        mint ans;
        for (int lim = n / 2; lim <= (n + 1) / 2; ++lim)
        {
            ans += C(n, lim) * min;
            for (int i = min + 1; i <= min + n; ++i)
            {
                int a = std::min((n - i) - l + 1, n), b = std::min(r - (1 + i) + 1, n);
                ans += C(a + b - n, lim - (n - a));
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}