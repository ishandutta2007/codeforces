// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const int MOD = 1000003;
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
} a[MOD], b[11];
void get(int pos)
{
    mint res = 0;
    for (int i = 0; i <= 10; ++i)
    {
        mint A = 1;
        for (int j = 0; j <= 10; ++j)
            if (i != j)
                A *= (pos - j + MOD);
        res += a[i] * A * b[i];
    }
    a[pos] = res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i <= 10; ++i)
    {
        b[i] = 1;
        for (int j = 0; j <= 10; ++j)
            if (i != j)
                b[i] *= (i - j + MOD);
        b[i] = b[i].inv();
    }
    for (int i = 0; i != 50; ++i)
    {
        std::cout << "? " << i << std::endl;
        std::cin >> a[i];
        // a[i] = 1000002 + i * i;
    }
    for (int i = 50; i != MOD; ++i)
        get(i);
    for (int i = 0; i != MOD; ++i)
        if (a[i].v % MOD == 0)
            return std::cout << "! " << i << std::endl, 0;
    std::cout << "! " << -1 << std::endl;
    return 0;
}