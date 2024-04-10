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
} ans, sum1[100005], sum2[100005];
mint solve(int n)
{
    mint res = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum1[i] = 0;
        sum2[i] = 0;
        for (int j = 1, k = n / i; i * j <= n; ++j)
        {
            while ((j + k) * i > n)
                --k;
            sum1[i] += k;
            sum2[i] += mint(i * j) * k + i * mint(k * (k + 1ll) / 2 % MOD);
        }
        sum1[i] *= n;
    }
    for (int i = n; i; --i)
        for (int j = i + i; j <= n; j += i)
        {
            sum1[i] -= sum1[j];
            sum2[i] -= sum2[j];
        }
    for (int i = 1; i <= n; ++i)
        if (std::__gcd(n, i) == 1)
            res += (sum1[i] - sum2[i]) * i;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        if (n % i == 0)
            ans += solve(n / i) * i;
    std::cout << ans << std::endl;
    return 0;
}