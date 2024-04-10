#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct modnum {
    // change these if you need another size of integers
    static inline uint32_t MOD;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;

    u32 n;

    modnum() : n(0) {}
    modnum(u64 v) : n(v >= MOD ? v % MOD : v) {}
    modnum(u32 v) : n(v >= MOD ? v % MOD : v) {}
    modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(MOD + v % int(MOD))) {}
    modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(MOD + v % int(MOD))) {}
    explicit operator i32() const { return n; }
    explicit operator u32() const { return n; }
    explicit operator bool() const { return n != 0; }

    static u32 fit(u32 x) { return x >= MOD ? x - MOD : x; }
    static int modinv(u32 x) {
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
    friend modnum modpow(modnum b, int64_t e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    modnum inv() const { return modinv(n); }
    modnum operator-() const { return n == 0 ? n : MOD - n; }
    modnum operator+() const { return *this; }
    modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    modnum operator--(int) { return n = fit(MOD + n - 1), *this + 1; }
    modnum &operator++() { return n = fit(n + 1), *this; }
    modnum &operator--() { return n = fit(MOD + n - 1), *this; }
    modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    modnum &operator-=(modnum v) { return n = fit(MOD + n - v.n), *this; }
    modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % MOD, *this; }
    modnum &operator/=(modnum v) { return *this *= v.inv(); }

    friend modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream &operator<<(ostream &out, modnum v) { return out << v.n; }
    friend istream &operator>>(istream &in, modnum &v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q >> modnum::MOD;

    vector<modnum> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<modnum> D(N + 2);
    int zeros = 0;

    for (int i = 0; i < N; i++) {
        D[i] = A[i] - B[i];
        D[i] -= i > 0 ? A[i - 1] - B[i - 1] : 0;
        D[i] -= i > 1 ? A[i - 2] - B[i - 2] : 0;
        zeros += D[i] == 0;
    }

    vector<modnum> fib(N + 1);
    fib[1] = fib[2] = 1;
    for (int i = 3; i < N + 1; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    while (Q--) {
        char c;
        int l, r;
        cin >> c >> l >> r, l--;
        modnum m = c == 'A' ? +1 : -1;
        zeros -= D[l] == 0;
        zeros -= r < N && D[r] == 0;
        zeros -= r + 1 < N && D[r + 1] == 0;
        D[l] += m;
        D[r] -= m * (fib[r - l] + fib[r - l - 1]);
        D[r + 1] -= m * fib[r - l];
        zeros += D[l] == 0;
        zeros += r < N && D[r] == 0;
        zeros += r + 1 < N && D[r + 1] == 0;
        cout << (zeros == N ? "YES\n" : "NO\n");
    }
    return 0;
}