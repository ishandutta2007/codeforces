#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
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

vector<num> fac, ifac;

num choose(int n, int k) {
    return (0 <= k && k <= n) ? fac[n] * ifac[k] * ifac[n - k] : 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string a, b;
    cin >> a >> b;

    int c00, c01, c10, c11;
    cin >> c00 >> c01 >> c10 >> c11;

    int A = a.size(), B = b.size();
    int length = c00 + c01 + c10 + c11 + 1;
    if (length > B || length < A) {
        cout << 0 << '\n';
        return 0;
    }
    if (length == 1 && A == 1) {
        cout << 1 << '\n';
        return 0; // fuck this case
    }

    fac.resize(length + 1);
    ifac.resize(length + 1);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= length; i++) {
        fac[i] = fac[i - 1] * i;
    }
    ifac[length] = fac[length].inv();
    for (int i = length - 1; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1);
    }

    // <=b - <a, a not inclusive
    auto go_figure = [&](int start, int b00, int b01, int b10, int b11) {
        if (b00 < 0 || b01 < 0 || b10 < 0 || b11 < 0) {
            return num(0);
        }
        if (b00 + b01 + b10 + b11 == 0) {
            return num(1);
        }
        if (start == 0) {
            swap(b00, b11);
            swap(b01, b10);
        }
        // no zeros
        if (b00 == 0 && b10 == 0 && b01 == 0) {
            return num(1);
        }
        if (b10 == b01 && b01 > 0) {
            return choose(b00 + b01 - 1, b00) * choose(b11 + b10, b11);
        }
        if (b10 == b01 + 1 && b10 > 0) {
            return choose(b00 + b10 - 1, b00) * choose(b11 + b10 - 1, b11);
        }
        return num(0);
    };

    auto solve = [&](const string &s, bool self) {
        int S = s.size();
        if (length > S || c10 < c01 || c10 > c01 + 1) {
            return num(0);
        }

        if (length < S) {
            return go_figure(1, c00, c01, c10, c11);
        }

        int a00 = c00, a01 = c01, a10 = c10, a11 = c11;
        num ans = 0;

        for (int i = 1; i < S; i++) {
            if (s[i] == '0') {
                s[i - 1] == '0' ? --a00 : --a10;
            }
            if (s[i] == '1') {
                // we can put a zero here, then anything afterwards
                if (s[i - 1] == '0') {
                    // s is 01, we try 00
                    ans += go_figure(0, a00 - 1, a01, a10, a11);
                } else {
                    // s is 11, we try 10
                    ans += go_figure(0, a00, a01, a10 - 1, a11);
                }
                s[i - 1] == '0' ? --a01 : --a11;
            }
        }

        if (self && a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
            ans++;
        }

        return ans;
    };

    num ans = solve(b, 1) - solve(a, 0);

    cout << ans << '\n';
    return 0;
}