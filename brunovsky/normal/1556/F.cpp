#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
    static constexpr inline uint32_t MOD = mod;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;
    static_assert(mod > 0 && mod < UINT_MAX / 2);

    u32 n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    constexpr modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(mod + v % int(mod))) {}
    explicit constexpr operator int() const { return n; }
    explicit constexpr operator bool() const { return n != 0; }

    static constexpr u32 fit(u32 x) { return x >= mod ? x - mod : x; }
    static constexpr int modinv(u32 x) {
        int nx = 1, ny = 0;
        u32 y = mod;
        while (x) {
            auto k = y / x;
            y = y % x;
            ny = ny - k * nx;
            swap(x, y), swap(nx, ny);
        }
        return ny < 0 ? mod + ny : ny;
    }
    friend constexpr modnum modpow(modnum b, int64_t e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    constexpr modnum inv() const { return modinv(n); }
    constexpr modnum operator-() const { return n == 0 ? n : mod - n; }
    constexpr modnum operator+() const { return *this; }
    constexpr modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    constexpr modnum operator--(int) { return n = fit(mod + n - 1), *this + 1; }
    constexpr modnum &operator++() { return n = fit(n + 1), *this; }
    constexpr modnum &operator--() { return n = fit(mod + n - 1), *this; }
    constexpr modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum &operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    constexpr modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
    constexpr modnum &operator/=(modnum v) { return *this *= v.inv(); }

    friend constexpr modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend constexpr modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend constexpr modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend constexpr modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream &operator<<(ostream &out, modnum v) { return out << v.n; }
    friend istream &operator>>(istream &in, modnum &v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<1'000'000'007>;
num scc[1 << 14], out[14][1 << 14], all[1 << 14], a[14], win[14][14];

#define FOR_EACH_BIT_NUMBER(bit, i, mask)                                            \
    for (remove_const<decltype(mask)>::type z##bit = (mask), bit = z##bit & -z##bit, \
                                            i = __builtin_ctz(bit);                  \
         z##bit;                                                                     \
         z##bit ^= bit, z##bit && (bit = z##bit & -z##bit, i = __builtin_ctz(bit)))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    const int ALL = 1 << N, FULL = ALL - 1;

    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            win[u][v] = u != v ? a[u] / (a[u] + a[v]) : 0;
        }
    }

    for (int u = 0; u < N; u++) {
        out[u][0] = 1;
        for (int mask = 1; mask < ALL; mask++) {
            int v = __builtin_ctz(mask);
            out[u][mask] = win[u][v] * out[u][mask ^ (1 << v)];
        }
    }

    fill(all, all + ALL, 1);
    for (int mask = 1; mask < ALL; mask++) {
        FOR_EACH_BIT_NUMBER (vbit, v, mask) { all[mask] *= out[v][FULL ^ mask]; }
    }

    num ans = 0;
    fill(scc, scc + ALL, 1);
    for (int mask = 1; mask < ALL; mask++) {
        for (int sub = mask & (mask - 1); sub; sub = mask & (sub - 1)) {
            // what if sub is an scc, but all edges go sub->mask^sub?
            num p = 1;
            FOR_EACH_BIT_NUMBER (vbit, v, sub) { p *= out[v][mask ^ sub]; }
            scc[mask] -= scc[sub] * p;
        }
        ans += scc[mask] * all[mask] * __builtin_popcount(mask);
    }

    cout << ans << '\n';
    return 0;
}

// The SCCs form a chain
// Probability you get an SCC for a subset