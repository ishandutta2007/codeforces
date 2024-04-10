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
    friend constexpr modnum operator<(modnum lhs, modnum rhs) { return lhs.n < rhs.n; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream &operator<<(ostream &out, modnum v) { return out << v.n; }
    friend istream &operator>>(istream &in, modnum &v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<998244353>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        vector<pair<int, num>> prev = {{1, 0}}, next;
        constexpr int SIZE = 2 * std::sqrt(100'001);
        prev.reserve(SIZE), next.reserve(SIZE);
        num ans = 0;

        for (int i = 1; i <= N; i++) {
            int A = a[i] - 1, ops = A, l = 1, r = 1, j = 0, P = prev.size();
            while (ops >= 0) {
                int parts = ops + 1;
                int vtop = (a[i] + parts - 1) / parts;
                int vbot = a[i] / parts;
                while (j + 1 < P && prev[j + 1].first <= vbot) {
                    j++;
                }
                next.push_back({vtop, i * num(ops) + prev[j].second});

                l = r + 1;
                ops = ops ? A / l : -1;
                r = A / max(ops, 1);
            }

            ans += next.back().second;
            swap(prev, next), next.clear();
        }
        cout << ans << '\n';
    }
    return 0;
}

// 9 7 -> 4 5 7 continue with 4 down. sums ending at a[i] don't touch i
// the values are kinda large which is annoying
// suppose we computed vals ending at a[i] already
// if we're computing ending at a[j] with j>i and the current head is >=a[i]
// we can reuse the sum of a[i]. how often will this happen?
// maybe pretty often I guess? If at any point you have a[i] <= head you can stop
// since you already know the answer
// can you have a[i] > head very often? I don't see any construction
// there should be at most SUM 2sqrt(a[i]) different values no?
// I guess we gotta constant optimize, as usual...