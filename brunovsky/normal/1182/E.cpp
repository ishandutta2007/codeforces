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

long modlog(long a, long b, long m) {
    long n = long(sqrt(m)) + 1, x = 1, f = 1, j = 1;
    unordered_map<long, long> A;
    while (j <= n && (x = f = x * a % m) != b % m)
        A[x * b % m] = j++;
    if (x == b % m)
        return j;
    if (gcd(m, x) == gcd(m, b))
        for (int i = 2; i < n + 2; i++)
            if (A.count(x = x * f % m))
                return n * i - A[x];
    return -1;
}

/**
 * Consider an (unknown) <=n-order linear recurrence (LR) given by a[0..n) such that
 *            x[n+k+1] = a[0]x[n+k] + a[1]x[n+k-1] + ... + a[n-1]x[k+1]
 * with some given initial values.
 *
 * Recover the linear recurrence given some of its output.
 * In general, for an LR of expected size N, the output (x) should have size >N
 * to ensure that a meaningful LR was produced.
 *
 * Complexity: O(N^2), N=|x|.
 * Reference: kactl, https://crypto.stanford.edu/~mironov/cs359/massey.pdf
 */
template <typename T>
auto berlekamp_massey(const vector<T> &values) {
    int N = values.size(), L = 0, m = 1;
    vector<T> C(N), B(N);
    C[0] = B[0] = 1;

    T b = 1;
    for (int i = 0; i < N; i++, m++) {
        T d = values[i];
        for (int j = 1; j < L + 1; j++) {
            d += C[j] * values[i - j];
        }
        if (!d) {
            continue;
        }
        vector<T> tmp = C;
        T coef = d / b;
        for (int j = m; j < N; j++) {
            C[j] -= coef * B[j - m];
        }
        if (2 * L > i) {
            continue;
        }
        L = i + 1 - L, B = move(tmp), b = d, m = 0;
    }

    C.resize(L + 1), C.erase(C.begin());
    for (auto &n : C) {
        n = -n;
    }
    return C;
}

/**
 * Compute k-th term (1-indexed) linear recurrence rec with given starting values.
 * Complexity: O(N^2 log k). Computation table can be saved for a fixed recurrence.
 * Reference: ecnerwala
 */
template <typename T>
auto linear_recurrence(const vector<T> &values, const vector<T> &rec, int64_t k) {
    int N = int(rec.size());
    assert(values.size() >= rec.size());

    auto combine = [&](vector<T> &a, const vector<T> &b) {
        vector<T> res(2 * N + 1);
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                res[i + j] += a[i] * b[j];
        for (int i = 2 * N; i > N; --i)
            for (int j = 0; j < N; j++)
                res[i - 1 - j] += res[i] * rec[j];
        res.resize(N + 1);
        a = move(res);
    };

    vector<T> pol(N + 1), e(N + 1);
    pol[0] = e[1] = 1;

    while (k > 0) {
        if (k & 1)
            combine(pol, e);
        if (k >>= 1)
            combine(e, e);
    }
    debug(pol, values);

    T res = 0;
    for (int i = 0; i < N; i++) {
        res += pol[i + 1] * values[i];
    }
    return res;
}

constexpr int MOD = 1'000'000'007, Q = MOD - 1;
constexpr int g = 5; // Primitive root
using num = modnum<MOD>;
using qnum = modnum<Q>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long N;
    num f1, f2, f3, c;
    cin >> N >> f1 >> f2 >> f3 >> c;
    num h1 = f1 * c;
    num h2 = f2 * c * c;
    num h3 = f3 * c * c * c;
    qnum x1 = modlog(g, int(h1), MOD);
    qnum x2 = modlog(g, int(h2), MOD);
    qnum x3 = modlog(g, int(h3), MOD);

    vector<qnum> rec = {1, 1, 1};
    vector<qnum> values = {x1, x2, x3};

    auto get = [&](long n) {
        auto xn = linear_recurrence(values, rec, n);
        auto gxn = modpow(num(g), int(xn));
        auto cn = modpow(c, N);
        return gxn / cn;
    };
    cout << get(N) << '\n';
    return 0;
}