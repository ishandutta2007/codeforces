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
    using u32 = uint32_t;
    using u64 = uint64_t;
    static_assert(mod > 0 && mod < UINT_MAX / 2);

    uint32_t n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(int64_t v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    constexpr modnum(int32_t v) : modnum(v >= 0 ? u32(v) : u32(mod + v % int(mod))) {}
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
    friend constexpr modnum modpow(modnum b, long e) {
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
        int64_t n;
        return in >> n, v = modnum(n), in;
    }
};

template <typename num>
auto pascal_sieve(int N) {
    vector<num> fac, ifac;
    fac.resize(N + 1), ifac.resize(N + 1);
    fac[0] = fac[1] = ifac[1] = 1;

    for (int n = 1; n <= N; n++) {
        fac[n] = n * fac[n - 1];
    }
    ifac[N] = fac[N].inv();
    for (int n = N; n >= 1; n--) {
        ifac[n - 1] = n * ifac[n];
    }

    return make_pair(fac, ifac);
}

using num = modnum<1'000'000'007>;

template <typename T>
auto operator+(const vector<T> &a, const vector<T> &b) {
    vector<T> c(a.size());
    for (unsigned i = 0; i < c.size(); i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}

template <typename T>
auto operator-(const vector<T> &a, const vector<T> &b) {
    vector<T> c(a.size());
    for (unsigned i = 0; i < c.size(); i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}

void search(int MAXN) {
    for (int N = 1; N <= MAXN; N++) {
        vector<vector<int>> state(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            state[i][i] = 1;
        }
        bool add = true;
        int S = N;
        while (S > 1) {
            for (int i = 0; i + 1 < S; i++, add = !add) {
                state[i] = add ? state[i] + state[i + 1] : state[i] - state[i + 1];
            }
            state.pop_back(), S--;
        }
        debug(N, state[0]);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;
    auto [fac, ifac] = pascal_sieve<num>(N / 2);
    auto choose = [&](int n, int k) { return fac[n] * ifac[k] * ifac[n - k]; };

    vector<num> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    bool add = true;
    if (N > 1 && N % 2 != 0) {
        for (int i = 0; i + 1 < N; i++, add = !add) {
            a[i] = add ? a[i] + a[i + 1] : a[i] - a[i + 1];
        }
        a.pop_back(), N--;
    }
    if (N == 1) {
        cout << a[0] << '\n';
    } else if (N % 4 == 0) {
        int K = (N - 2) / 2;
        num ans = 0;
        for (int i = 0; i < N; i++) {
            ans += ((i & 1) ? -1 : 1) * choose(K, i / 2) * a[i];
        }
        cout << ans << '\n';
    } else if (N % 4 == 2) {
        int K = (N - 2) / 2;
        num ans = 0;
        for (int i = 0; i < N; i++) {
            ans += choose(K, i / 2) * a[i];
        }
        cout << ans << '\n';
    } else {
        assert(false);
    }
    return 0;
}