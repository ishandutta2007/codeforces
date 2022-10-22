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
        mint res = 1, A = *this;
        while (B)
        {
            if (B & 1)
                res *= A;
            A *= A;
            B >>= 1;
        }
        return res;
    }
    mint inv() const { return pow(MOD - 2); }
    friend mint operator+(const mint &A, const mint &B) { return mint(A) += B; }
    friend mint operator-(const mint &A, const mint &B) { return mint(A) -= B; }
    friend mint operator*(const mint &A, const mint &B) { return mint(A) *= B; }
    friend mint operator/(const mint &A, const mint &B) { return mint(A) /= B; }
    friend std::ostream &operator<<(std::ostream &A, const mint &B) { return A << B.v; }
} fact[200005], ifact[200005], f[200005], g[200005];
int n;
mint P(int n, int m) { return 0 <= m && m <= n ? fact[n] * ifact[n - m] : 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i; --i)
        ifact[i - 1] = ifact[i] * i;
    f[1] = fact[n - 1];
    for (int i = 2; i <= n; ++i)
        f[i] = /* (i - 1) *  */ fact[n - i] * (P(n - (n + 1) / 2, i - 1) - P(i - 2, i - 1));
    // for (int j = (n - 1) / 2; j <= n - i; ++j)
    //     f[i] += (i - 1) * fact[n - i] * fact[n - j - 2] * ifact[n - i - j];
    mint sum = 0;
    for (int i = n; i; --i)
    {
        g[i] = f[i] - sum;
        sum += f[i] / (i - 1);
    }
    for (int i = 1; i <= n; ++i)
        std::cout << g[i] << " \n"[i == n];
    return 0;
}