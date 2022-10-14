#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

bool reps(int64_t a, int64_t s, int64_t n, int64_t cand) {
    int64_t al = a + s * (n - 1);
    return a <= cand && cand <= al && (cand - a) % s == 0;
}

auto get_primes(int n) {
    map<int, int> factors;
    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            n /= p;
            factors[p]++;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

template <typename T>
auto get_divisors(const map<T, int> &factors, bool one, bool self) {
    vector<T> divs = {1};
    for (const auto &[p, e] : factors) {
        int D = divs.size();
        divs.resize(D * (e + 1));
        for (int n = 1; n <= e; n++) {
            for (int d = 0; d < D; d++) {
                divs[d + n * D] = divs[d + (n - 1) * D] * p;
            }
        }
    }
    if (!one) {
        divs.erase(begin(divs));
    }
    if (!self && !divs.empty()) {
        divs.erase(begin(divs) + (divs.size() - 1));
    }
    return divs;
}

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
    static constexpr inline uint32_t MOD = mod;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;
    static_assert(MOD > 0 && MOD < UINT_MAX / 2);

    u32 n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= MOD ? v % MOD : v) {}
    constexpr modnum(u32 v) : n(v >= MOD ? v % MOD : v) {}
    constexpr modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(MOD + v % int(MOD))) {}
    constexpr modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(MOD + v % int(MOD))) {}
    explicit constexpr operator i32() const { return n; }
    explicit constexpr operator u32() const { return n; }
    explicit constexpr operator bool() const { return n != 0; }

    static constexpr u32 fit(u32 x) { return x >= MOD ? x - MOD : x; }
    static constexpr int modinv(u32 x) {
        int nx = 1, ny = 0;
        u32 y = MOD;
        while (x) {
            auto k = y / x;
            y = y % x;
            ny = ny - k * nx;
            swap(x, y), swap(nx, ny);
        }
        return ny < 0 ? MOD + ny : ny;
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
    constexpr modnum operator-() const { return n == 0 ? n : MOD - n; }
    constexpr modnum operator+() const { return *this; }
    constexpr modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    constexpr modnum operator--(int) { return n = fit(MOD + n - 1), *this + 1; }
    constexpr modnum &operator++() { return n = fit(n + 1), *this; }
    constexpr modnum &operator--() { return n = fit(MOD + n - 1), *this; }
    constexpr modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum &operator-=(modnum v) { return n = fit(MOD + n - v.n), *this; }
    constexpr modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % MOD, *this; }
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int64_t b, q, y;
        cin >> b >> q >> y;
        int64_t c, r, z;
        cin >> c >> r >> z;
        if (r % q != 0 || z > y) {
            cout << 0 << '\n';
            continue;
        }
        int64_t B = b + q * (y - 1);
        int64_t C = c + r * (z - 1);
        if (!reps(b, q, y, c) || !reps(b, q, y, C)) {
            cout << 0 << '\n';
            continue;
        }
        int64_t prev = c - r;
        int64_t next = C + r;
        if (!reps(b, q, y, prev) || !reps(b, q, y, next)) {
            cout << -1 << '\n';
            continue;
        }
        // Then it works... jesus christ
        // lcm(a,b)=c <=> ab=c gcd(a,b) <=> a/gcd(a,b) = c/b <=> a = gcd(a,b)c/b
        auto primes = get_primes(q);
        auto divs = get_divisors(primes, true, true);
        num ans = 0;
        for (int g : divs) {
            int64_t p = g * r / q;
            if (lcm(p, q) != r) {
                continue;
            }
            // pick start and end
            // start must be (prev,c] and end must be [C,next)
            int64_t s = (c - prev) / p;
            int64_t e = (next - C) / p;
            num add = num(s) * num(e);
            ans += add;
        }
        cout << ans << '\n';
    }
    return 0;
}