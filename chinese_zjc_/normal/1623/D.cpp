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
} p, s, k;
int T, n, m, sx, sy, ex, ey, a, b;
std::vector<long long> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> sx >> sy >> ex >> ey >> p;
        p /= 100;
        g.clear();
        k = 2ll * (n - 1) * (m - 1) % MOD;
        a = sy <= ey ? ey - sy : 2 * m - ey - sy;
        b = sy <= ey ? 2 * m - ey - sy : 2 * (m - 1) - (sy - ey);
        for (int i = 0; i != n - 1; ++i)
            g.push_back(2ll * i * (m - 1) + a), g.push_back(2ll * i * (m - 1) + b);
        a = sx <= ex ? ex - sx : 2 * n - ex - sx;
        b = sx <= ex ? 2 * n - ex - sx : 2 * (n - 1) - (sx - ex);
        for (int i = 0; i != m - 1; ++i)
            g.push_back(2ll * i * (n - 1) + a), g.push_back(2ll * i * (n - 1) + b);
        std::sort(g.begin(), g.end());
        g.erase(std::unique(g.begin(), g.end()), g.end());
        while (g.back() >= 2ll * (n - 1) * (m - 1))
            g.pop_back();
        s = (1 - p).pow(g.size());
        // std::cout << k << ' ' << g.size() << std::endl;
        // for (auto i : g)
        //     std::cout << i << ' ';
        // std::cout << std::endl;
        mint ans = 0;
        for (std::size_t i = 0; i != g.size(); ++i)
            ans += p * (1 - p).pow(i) * ((g[i] % MOD) / (1 - s) + s * k / (1 - s).pow(2));
        std::cout << ans << std::endl;
    }
    return 0;
}