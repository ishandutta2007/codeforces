#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

namespace polymath {
#define TTT template <typename T>

TTT auto rand_poly(int n) {
    static mt19937 rng(random_device{}());
    static uniform_int_distribution<int> dist(1, T::MOD - 1);
    vector<T> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = T(dist(rng));
    }
    return v;
}

// Utility stuff, then elementary operations, then FFT and power series operations

TTT int size(const vector<T>& u) { return u.size(); }
TTT int deg(const vector<T>& u) { return size(u) - 1; }
TTT auto cell(const vector<T>& u, int i) { return i < size(u) ? u[i] : T(); }

TTT auto& reverse(vector<T>& u) { return reverse(begin(u), end(u)), u; }
TTT auto& grow(vector<T>& u, int n) { return u.resize(max(size(u), n)), u; }
TTT auto& resize(vector<T>& u, int n) { return u.resize(n), u; }
TTT auto& shrink(vector<T>& u, int n) { return u.resize(min(size(u), n)), u; }
TTT auto& trim(vector<T>& u, int upto = 0) {
    while (size(u) > upto && u.back() == T(0))
        u.pop_back();
    return u;
}

TTT auto reversed(vector<T> u) { return reverse(u), u; }
TTT auto grown(vector<T> u, int n) { return grow(u, n), u; }
TTT auto resized(vector<T> u, int n) { return resize(u, n), u; }
TTT auto shrunk(vector<T> u, int n) { return shrink(u, n), u; }
TTT auto trimmed(vector<T> u) { return trim(u), u; }

TTT auto& operator+=(vector<T>& u, T value) { return grow(u, 1), u[0] += value, u; }
TTT auto& operator-=(vector<T>& u, T value) { return grow(u, 1), u[0] -= value, u; }
TTT auto& operator*=(vector<T>& u, T value) {
    for (int i = 0; i < size(u); i++)
        u[i] *= value;
    return u;
}
TTT auto& operator/=(vector<T>& u, T value) { return u *= T(1) / value, u; }
TTT auto& operator+=(vector<T>& u, const vector<T>& v) {
    grow(u, size(v));
    for (int i = 0; i < size(v); i++)
        u[i] += v[i];
    return u;
}
TTT auto& operator-=(vector<T>& u, const vector<T>& v) {
    grow(u, size(v));
    for (int i = 0; i < size(v); i++)
        u[i] -= v[i];
    return u;
}

TTT auto operator-(vector<T> u) {
    for (int i = 0; i < size(u); i++)
        u[i] = -u[i];
    return u;
}

TTT auto operator+(vector<T> u, T value) { return u += value, u; }
TTT auto operator-(vector<T> u, T value) { return u -= value, u; }
TTT auto operator*(vector<T> u, T value) { return u *= value, u; }
TTT auto operator+(T value, vector<T> u) { return u += value, u; }
TTT auto operator-(T value, vector<T> u) { return u -= value, u; }
TTT auto operator*(T value, vector<T> u) { return u *= value, u; }
TTT auto operator/(vector<T> u, T value) { return u /= value, u; }
TTT auto operator+(vector<T> u, const vector<T>& v) { return u += v, u; }
TTT auto operator-(vector<T> u, const vector<T>& v) { return u -= v, u; }

TTT auto& pointwise_inplace(vector<T>& u, const vector<T>& o) {
    grow(u, size(o));
    for (int i = 0; i < size(o); i++)
        u[i] *= o[i];
    return u;
}
TTT auto pointwise(vector<T> u, const vector<T>& o) { return pointwise_inplace(u, o), u; }

TTT auto inner_product(const vector<T>& u, const vector<T>& v) {
    T sum = 0;
    for (int i = 0, n = min(size(u), size(v)); i < n; i++)
        sum += u[i] * v[i];
    return sum;
}

TTT auto& rem_shift(vector<T>& u, int s) {
    return u.erase(begin(u), begin(u) + min(size(u), s)), u;
}
TTT auto& add_shift(vector<T>& u, int s, T add = T(0)) {
    return u.insert(begin(u), s, add), u;
}

TTT auto& operator>>=(vector<T>& u, int s) { return rem_shift(u, s); }
TTT auto& operator<<=(vector<T>& u, int s) { return add_shift(u, s); }
TTT auto operator>>(vector<T> u, int s) { return u >>= s, u; }
TTT auto operator<<(vector<T> u, int s) { return u <<= s, u; }

TTT auto& derivative_inplace(vector<T>& u) {
    for (int i = 1; i < size(u); i++)
        u[i - 1] = T(i) * u[i];
    return size(u) > 0 ? u.pop_back(), u : u;
}
TTT auto derivative(vector<T> u) { return derivative_inplace(u), u; }

TTT auto& integral_inplace(vector<T>& u, T zero = 0) {
    u.push_back(T(0));
    for (int i = size(u) - 1; i > 0; i--)
        u[i] = u[i - 1] / T(i);
    return u[0] = zero, u;
}
TTT auto integral(vector<T> u) { return integral_inplace(u), u; }

TTT auto eval(const vector<T>& u, T x) {
    T sum = 0;
    for (int i = size(u) - 1; i >= 0; i--)
        sum = u[i] + sum * x;
    return sum;
}

} // namespace polymath

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
    constexpr modnum& operator++() { return n = fit(n + 1), *this; }
    constexpr modnum& operator--() { return n = fit(MOD + n - 1), *this; }
    constexpr modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum& operator-=(modnum v) { return n = fit(MOD + n - v.n), *this; }
    constexpr modnum& operator*=(modnum v) { return n = (u64(n) * v.n) % MOD, *this; }
    constexpr modnum& operator/=(modnum v) { return *this *= v.inv(); }

    friend constexpr modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend constexpr modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend constexpr modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend constexpr modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<998244353>;
using poly = vector<num>;
using namespace polymath;
const num zero = 0;

constexpr int M = 1'000'000;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        double in;
        cin >> in;
        x[i] = llround(M * in);
        x[i] = min(x[i], (i + 1) * M);
    }
    for (int i = N - 2; i >= 0; i--) {
        x[i] = min(x[i], x[i + 1]);
    }

    vector<int> pts = {0};
    for (int i = 0; i < N; i++) {
        pts.push_back((i + 1) * M);
        for (int j = 0; x[i] + j * M < N * M; j++) {
            pts.push_back(x[i] + j * M);
        }
        for (int j = -1; x[i] + j * M > 0; j--) {
            pts.push_back(x[i] + j * M);
        }
    }
    sort(begin(pts), end(pts));
    pts.erase(unique(begin(pts), end(pts)), end(pts));

    const int P = pts.size() - 1;
    const int G = lower_bound(begin(pts), end(pts), M) - begin(pts);

    vector<poly> fn(P);
    int T = 0;
    while (T < G && pts[T] < x[0]) {
        fn[T++] = {num(1)};
    }
    for (int i = 1; i < N; i++) {
        vector<poly> gn(P);
        num lead = 0;
        T += G;
        for (int s = 0; s < G; s++) {
            integral_inplace(fn[s]);
            poly& q = fn[s];
            num a = pts[s], b = pts[s + 1];
            gn[s] = (q - eval(q, zero) + lead);
            lead += eval(q, b - a) - eval(q, zero);
        }
        for (int s = G; s < T; s++) {
            integral_inplace(fn[s]);
            poly& p = fn[s - G];
            num c = pts[s - G], d = pts[s - G + 1];
            lead -= eval(p, d - c) - eval(p, zero);
            poly& q = fn[s];
            num a = pts[s], b = pts[s + 1];
            gn[s] = (q - eval(q, zero) + eval(p, d - c) - p + lead);
            lead += eval(q, b - a) - eval(q, zero);
            assert(a - c == M && b - d == M);
        }
        swap(fn, gn);
        while (pts[T] > x[i]) {
            fn[--T] = {};
        }
    }

    num area = 0;
    for (int s = 0; s < T; s++) {
        integral_inplace(fn[s]);
        auto& q = fn[s];
        num a = pts[s], b = pts[s + 1];
        num trap = eval(q, b - a) - eval(q, zero);
        area += trap;
    }
    cout << area / modpow(num(M), N) << '\n';
    return 0;
}