// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 998244353;
struct mint
{
    unsigned v;
    mint(unsigned v_ = 0) : v(v_) {}
    mint &operator+=(const mint &X) { return (v += X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator-=(const mint &X) { return (v += MOD - X.v) >= MOD ? v -= MOD : v, *this; }
    mint &operator*=(const mint &X) { return v = 1llu * v * X.v % MOD, *this; }
    mint &operator/=(const mint &X) { return *this *= X.inv(); }
    mint pow(long long B) const
    {
        if (!v)
            return 0;
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
} fact[2005], ifact[2005], dp[55][2005][55], ans;
int n, k, a[55];
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i <= 2000; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[2000] = fact[2000].inv();
    for (int i = 2000; i; --i)
        ifact[i - 1] = ifact[i] * i;
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    mint tot = std::accumulate(a + 1, a + 1 + n, mint());
    dp[0][0][0] = MOD - 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= a[i] / k; ++j)
        {
            mint v = (j & 1 ? MOD - 1 : 1) * ((a[i] - j * k) / tot).pow(j) * ifact[j];
            for (int l = j; l <= 2000; ++l)
                for (int o = 0; o < i; ++o)
                    dp[i][l][o] += dp[i - 1][l - j][o] * v;
            if (j)
            {
                v = (j & 1 ? MOD - 1 : 1) * ((a[i] - j * k) / tot).pow(j - 1) * ifact[j - 1];
                for (int l = j; l <= 2000; ++l)
                    for (int o = 1; o <= i; ++o)
                        dp[i][l][o] += dp[i - 1][l - j][o - 1] * v;
            }
        }
    dp[n][0][0] += 1;
    mint w = k / tot;
    for (int i = 0; i <= 2000; ++i)
        for (int j = 0; j <= std::min(n, i); ++j)
            ans += dp[n][i][j] * fact[i - j] * (w * i).pow(j - i - 1);
    std::cout << ans << std::endl;
    return 0;
}