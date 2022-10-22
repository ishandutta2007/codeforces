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
} fact[100005], ifact[100005], pw[100005];
int T, n, a[100005], fa[100005];
long long pre[100005], suf[100005];
int count(int x)
{
    int l = x, r = x;
    while (r < n && !a[r])
        ++r;
    while (l > 0 && !a[l - 1])
        --l;
    return r - l;
}
mint C(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[m] * ifact[n - m] : 0; }
mint calc(int A, int B)
{
    mint res = 0;
    for (int i = 0; i <= std::min(A, B); ++i)
        res += C(A, i) * C(B, i);
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[100000] = fact[100000].inv();
    for (int i = 100000; i; --i)
        ifact[i - 1] = ifact[i] * i;
    pw[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        pw[i] = pw[i - 1] * 2;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        pre[0] = suf[n] = 0;
        for (int i = 0; i != n; ++i)
            pre[i + 1] = pre[i] + a[i];
        for (int i = n; i--;)
            suf[i] = suf[i + 1] + a[i];
        mint ans = 1;
        if (std::count(a, a + n, 0) == n)
            ans *= pw[n - 1];
        else
        {
            ans *= calc(count(0), count(n));
            if (pre[n] % 2 == 0 && std::binary_search(pre, pre + n + 1, pre[n] / 2))
                ans *= pw[count(std::lower_bound(pre, pre + n + 1, pre[n] >> 1) - pre) + 1];
            for (int i = n - 1; 2 * suf[i] < pre[n]; --i)
                if (suf[i] != suf[i + 1] && std::binary_search(pre, pre + n + 1, suf[i]))
                    ans *= calc(count(std::lower_bound(pre, pre + n + 1, suf[i]) - pre) + 1, count(i) + 1);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}