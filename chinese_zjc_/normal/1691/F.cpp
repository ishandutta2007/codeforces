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
} fact[200005], ifact[200005], ans;
int n, k, siz[200005];
std::vector<int> to[200005];
mint C(int n) { return k <= n ? fact[n] * ifact[k] * ifact[n - k] : 0; }
void work(int now, int fa)
{
    siz[now] = 1;
    std::vector<int> s;
    for (auto i : to[now])
    {
        if (i == fa)
            continue;
        work(i, now);
        s.push_back(siz[i]);
        siz[now] += siz[i];
    }
    s.push_back(n - siz[now]);
    mint sum = 0;
    for (auto i : s)
        sum += C(i);
    ans += n * (C(n) - sum);
    for (auto i : s)
        ans += i * (C(n - i) - (sum - C(i))) * (n - i);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1, x, y; i < n; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i; --i)
        ifact[i - 1] = ifact[i] * i;
    work(1, 0);
    std::cout << ans << std::endl;
    return 0;
}