// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
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
} pw2i[1000005], pw2[1000005], suf[1000005], ss[1000005], ans;
int T, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    pw2i[0] = 1;
    pw2i[1] = mint(2).inv();
    pw2[0] = 1;
    pw2[1] = 2;
    for (int i = 1; i <= 1000000; ++i)
        pw2i[i] = pw2i[i - 1] * pw2i[1];
    for (int i = 1; i <= 1000000; ++i)
        pw2[i] = pw2[i - 1] * pw2[1];
    while (T--)
    {
        std::cin >> n;
        std::fill(suf, suf + 1 + n, 0);
        std::fill(ss, ss + 1 + n, 0);
        suf[n] = 1;
        for (int i = n; i >= 0; --i)
        {
            suf[i] += ss[i] * pw2[i];
            if (i)
            {
                ss[i - 1] += ss[i];
                ss[i - 1] += suf[i] * pw2i[i];
                ss[i / 2] -= suf[i] * pw2i[i];
            }
            // for (int j = i - 1; j > i / 2; --j)
            // {
            //     suf[j] += suf[i] * pw2i[i] * pw2[j];
            // }
        }
        for (int i = 1; i <= n; ++i)
            std::cout << pw2i[i - i / 2 - 1] * suf[i] << '\n';
        // for (int i = 0; i <= n; ++i)
        //     std::cout << suf[i] << " \n"[i == n];
    }
    return 0;
}