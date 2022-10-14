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

template <typename T>
struct Binomial {
    static T fac(int n) {
        ensure_factorial(n);
        return n < 0 ? 0 : fact[n];
    }

    static T invfac(int n) {
        ensure_factorial(n);
        return n < 0 ? 0 : ifact[n];
    }

    static T choose(int n, int k) {
        ensure_factorial(n);
        return n < 0 || k < 0 || k > n ? 0 : fact[n] * ifact[k] * ifact[n - k];
    }

    static T choose(const vector<int> &ks) {
        int n = 0;
        for (int k : ks) {
            n += k;
            if (k < 0) {
                return 0;
            }
        }
        ensure_factorial(n);
        T ans = fact[n];
        for (int k : ks) {
            ans *= ifact[k];
        }
        return ans;
    }

    static T multinomial(const vector<int> &ks) { return choose(ks); }

    static T rising(int n, int k) { // 1 for k=0
        ensure_factorial(n + k - 1);
        return n <= 0 || k < 0 ? 0 : fact[n + k - 1] * ifact[n - 1];
    }

    static T falling(int n, int k) { // 1 for k=0, same as arrange(n, k)
        ensure_factorial(n);
        return n < 0 || k < 0 || k > n ? 0 : fact[n] * ifact[n - k];
    }

    static T arrange(int n, int k) {
        ensure_factorial(n);
        return n < 0 || k < 0 || k > n ? 0 : fact[n] * ifact[n - k];
    }

    static T catalan(int n) {
        ensure_factorial(2 * n + 1);
        return n < 0 ? 0 : fact[2 * n] * ifact[n] * ifact[n + 1];
    }

    // {i1+...+ik=n}  catalan(ij)
    static T catalan_conv(int n, int k) {
        ensure_factorial(2 * n + k);
        return n < 0 || k < 1 ? 0 : choose(2 * n + k - 1, n) * k * inv(n + k);
    }

    // Chance of k successes in a binomial(n,p) (n events, success with probability p)
    static T binomial_success(int n, int k, T p) {
        return n < 0 || k < 0 ? 0 : choose(n, k) * binpow(p, k) * binpow(1 - p, n - k);
    }

    static T binpow(T v, int64_t e) {
        T ans = 1;
        while (e > 0) {
            ans = (e & 1) ? v * ans : ans;
            v *= v, e >>= 1;
        }
        return ans;
    }

    static T inv(int n) {
        ensure_factorial(n);
        return n <= 0 ? 0 : fact[n - 1] * ifact[n];
    }

    // * Cache
    static inline vector<T> fact = {1, 1};
    static inline vector<T> ifact = {1, 1};

    static void ensure_factorial(int n) {
        if (int m = fact.size(); n >= m) {
            n = 1 << (8 * sizeof(int) - __builtin_clz(n - 1));
            fact.resize(n + 1);
            ifact.resize(n + 1);
            for (int i = m; i <= n; i++) {
                fact[i] = T(i) * fact[i - 1];
            }
            ifact[n] = T(1) / fact[n];
            for (int i = n; i > m; i--) {
                ifact[i - 1] = T(i) * ifact[i];
            }
        }
    }
};

using num = modnum<998244353>;
using B = Binomial<num>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    string s;
    cin >> N >> K >> s;

    B::ensure_factorial(N);

    // how many zeros between each 1..1
    vector<int> runs = {0};
    for (int i = 0; i < N; i++) {
        if (s[i] == '0') {
            runs.back()++;
        } else {
            runs.push_back(0);
        }
    }
    int O = runs.size() - 1;
    debug(runs);

    if (K == 0 || K > O) {
        cout << 1 << '\n';
        return 0;
    }
    // 1 <= K <= O we know now

    int Z = 0;
    for (int i = 0; i < K; i++) {
        Z += runs[i];
    }

    num ans = 0;

    for (int i = K; i <= O; i++) {
        Z += runs[i];

        // Z 0s and K 1s in the gap
        if (i < O) {
            // always move the leftmost 1
            ans += B::choose(Z + K, K) - B::choose(Z + K - 1 - runs[i - K], K - 1);
        } else {
            // anyway goes
            ans += B::choose(Z + K, K);
        }

        Z -= runs[i - K];
    }

    cout << ans << '\n';
    return 0;
}