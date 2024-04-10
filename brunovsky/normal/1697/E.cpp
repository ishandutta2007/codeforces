#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Pt2 {
    using T = int32_t;    // points, vectors, coefs, manh -- integer/frac/quot
    using L = int64_t;    // crosses, dotes, dist2, norm2 -- integer/frac/quot
    using H = __int128_t; // huge (circle predicates) -- int128/double
    static constexpr bool FLOAT = false;

    T x, y;
    Pt2() : x(0), y(0) {}
    Pt2(T x, T y) : x(x), y(y) {}

    auto paired() const { return make_pair(x, y); }
    friend bool operator==(Pt2 a, Pt2 b) { return a.paired() == b.paired(); }
    friend bool operator!=(Pt2 a, Pt2 b) { return a.paired() != b.paired(); }
    friend bool operator<(Pt2 a, Pt2 b) { return a.paired() < b.paired(); }
    friend bool operator>(Pt2 a, Pt2 b) { return a.paired() > b.paired(); }
    friend bool operator<=(Pt2 a, Pt2 b) { return a.paired() <= b.paired(); }
    friend bool operator>=(Pt2 a, Pt2 b) { return a.paired() >= b.paired(); }

    explicit operator bool() const noexcept { return x || y; }

    bool boxed(Pt2 lo, Pt2 hi) const {
        return lo.x <= x && x <= hi.x && lo.y <= y && y <= hi.y;
    }
    friend auto min(Pt2 a, Pt2 b) { return Pt2(min(a.x, b.x), min(a.y, b.y)); }
    friend auto max(Pt2 a, Pt2 b) { return Pt2(max(a.x, b.x), max(a.y, b.y)); }

    T& operator[](int i) { return *(&x + i); }
    T operator[](int i) const { return *(&x + i); }
    Pt2 operator-() const { return Pt2(-x, -y); }
    Pt2 operator+() const { return Pt2(x, y); }
    friend Pt2 operator+(Pt2 u, Pt2 v) { return Pt2(u.x + v.x, u.y + v.y); }
    friend Pt2 operator-(Pt2 u, Pt2 v) { return Pt2(u.x - v.x, u.y - v.y); }
    friend Pt2 operator*(T k, Pt2 u) { return Pt2(u.x * k, u.y * k); }
    friend Pt2 operator*(Pt2 u, T k) { return Pt2(u.x * k, u.y * k); }
    friend Pt2 operator/(Pt2 u, T k) { return Pt2(u.x / k, u.y / k); }
    friend Pt2& operator+=(Pt2& u, Pt2 v) { return u = u + v; }
    friend Pt2& operator-=(Pt2& u, Pt2 v) { return u = u - v; }
    friend Pt2& operator*=(Pt2& u, T k) { return u = u * k; }
    friend Pt2& operator/=(Pt2& u, T k) { return u = u / k; }

    friend auto refl(Pt2 u) { return Pt2(u.y, u.x); }  // reflection across xOy bisector
    friend auto conj(Pt2 u) { return Pt2(u.x, -u.y); } // complex conjugate
    friend auto perp_ccw(Pt2 u) { return Pt2(-u.y, u.x); } // rh rotation
    friend auto perp_cw(Pt2 u) { return Pt2(u.y, -u.x); }  // lh rotation

    friend auto manh(Pt2 u) { return abs(u.x) + abs(u.y); }
    friend auto manh(Pt2 a, Pt2 b) { return manh(a - b); }
    friend auto abs(Pt2 u) { return Pt2(abs(u.x), abs(u.y)); }

    friend auto dot(Pt2 u, Pt2 v) { return L(u.x) * v.x + L(u.y) * v.y; }
    friend auto norm2(Pt2 u) { return dot(u, u); }
    friend auto norm(Pt2 u) { return std::sqrt(double(norm2(u))); }

    friend auto cross(Pt2 u, Pt2 v) { return L(u.x) * v.y - L(u.y) * v.x; }
    friend auto cross(Pt2 a, Pt2 b, Pt2 c) { return cross(b - a, c - a); }

    friend auto dist2(Pt2 a, Pt2 b) { return norm2(a - b); }
    friend auto dist(Pt2 a, Pt2 b) { return norm(a - b); }

    friend auto int_norm(Pt2 u) { return abs(gcd(u.x, u.y)); }
    friend auto int_unit(Pt2 u) { return u / int_norm(u); }

    friend string to_string(Pt2 p) {
        return '(' + to_string(p.x) + ',' + to_string(p.y) + ')';
    }
    friend ostream& operator<<(ostream& out, Pt2 p) { return out << to_string(p); }
    friend istream& operator>>(istream& in, Pt2& p) { return in >> p.x >> p.y; }

    friend int orientation(Pt2 a, Pt2 b, Pt2 c) {
        auto sign = cross(a, b, c);
        return (sign > 0) - (sign < 0);
    }

    friend bool collinear(Pt2 a, Pt2 b, Pt2 c) { return orientation(a, b, c) == 0; }
    friend bool samedir(Pt2 u, Pt2 v) { return cross(u, v) == 0; }
    friend bool onsegment(Pt2 a, Pt2 b, Pt2 c) {
        return orientation(a, b, c) == 0 && dot(a - b, c - b) <= 0;
    }

    friend auto signed_linedist(Pt2 a, Pt2 u, Pt2 v) {
        return double(cross(a, u, v)) / dist(u, v);
    }
    friend auto linedist(Pt2 a, Pt2 u, Pt2 v) { return abs(signed_linedist(a, u, v)); }
    friend auto raydist(Pt2 a, Pt2 u, Pt2 v) {
        if (dot(a - u, v - u) <= 0) {
            return dist(a, u);
        } else {
            return linedist(a, u, v);
        }
    }
    friend auto segdist(Pt2 a, Pt2 u, Pt2 v) {
        if (dot(a - u, v - u) <= 0) {
            return dist(a, u);
        } else if (dot(a - v, u - v) <= 0) {
            return dist(a, v);
        } else {
            return linedist(a, u, v);
        }
    }
};

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

    static T lah(int n, int k) {
        ensure_factorial(n);
        return n <= 0 || k <= 0 || k > n ? 0 : choose(n - 1, k - 1) * fac[n] * ifact[k];
    }

    static T choose(const vector<int>& ks) {
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

    static T multinomial(const vector<int>& ks) { return choose(ks); }

    // Partial factorial n(n+1)...(n+k-1), with 1 for k=0 and n>=1
    static T rising(int n, int k) {
        ensure_factorial(n + k - 1);
        return n <= 0 || k < 0 ? 0 : fact[n + k - 1] * ifact[n - 1];
    }

    // Partial factorial n(n-1)...(n-k+1), with 1 for k=0 and n>=0
    static T falling(int n, int k) { // 1 for k=0, same as arrange(n, k)
        ensure_factorial(n);
        return n < 0 || k < 0 || k > n ? 0 : fact[n] * ifact[n - k];
    }

    // Layout n identical items over k distinct bins, >=a per bin
    static T layout(int n, int k, int a = 0) {
        return k == 0 ? n == 0 : choose(n + (1 - a) * (k - 1), k - 1);
    }

    // Layout n identical items over k distinct bins, >=a and <b per bin. O(k)
    static T bounded_layout(int n, int p, int a, int b) {
        n -= a * p, b -= a;
        T ans = 0;
        for (int k = 0; k <= p && b * k <= n && b > 0; k++) {
            ans += (k % 2 ? -1 : +1) * choose(p, k) * layout(n - b * k, p);
        }
        return ans;
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
            if (e & 1)
                ans *= v;
            if (e >>= 1)
                v *= v;
        }
        return ans;
    }

    static T inv(int n) {
        ensure_factorial(n);
        return n == 0 ? 0 : n < 0 ? -inv(-n) : fact[n - 1] * ifact[n];
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
    int N;
    cin >> N;
    vector<Pt2> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i];
    }
    mt19937 mt(random_device{}());
    shuffle(begin(pts), end(pts), mt);
    int D = 0, T = 0, Q = 0;
    vector<bool> used(N);
    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N && !used[u]; v++) {
            if (used[v]) {
                continue;
            }
            bool ok = true;
            auto d = manh(pts[u], pts[v]);
            for (int i = 0; i < N && ok; i++) {
                if (u != i && v != i) {
                    auto dui = manh(pts[u], pts[i]);
                    auto dvi = manh(pts[v], pts[i]);
                    ok &= d < dui && d < dvi;
                }
            }
            if (ok) {
                D++;
                used[u] = used[v] = true;
                break;
            }
        }
    }
    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N && !used[u]; v++) {
            for (int w = v + 1; w < N && !used[v]; w++) {
                if (used[w]) {
                    continue;
                }
                bool ok = true;
                auto d = manh(pts[u], pts[v]);
                auto du = manh(pts[u], pts[w]);
                auto dv = manh(pts[v], pts[w]);
                if (d != du || d != dv) {
                    continue;
                }
                vector<int> quads;
                for (int i = 0; i < N && ok; i++) {
                    if (u != i && v != i && w != i) {
                        auto dui = manh(pts[u], pts[i]);
                        auto dvi = manh(pts[v], pts[i]);
                        auto dwi = manh(pts[w], pts[i]);
                        if (d == dui && d == dvi && d == dwi) {
                            quads.push_back(i);
                        } else {
                            ok &= d < dui && d < dvi && d < dwi;
                        }
                    }
                }
                if (ok) {
                    if (quads.empty()) {
                        T++;
                        used[u] = used[v] = used[w] = true;
                    } else if (quads.size() == 1u) {
                        int z = quads[0];
                        Q++;
                        used[u] = used[v] = used[w] = used[z] = true;
                    } else {
                        assert(false);
                    }
                }
            }
        }
    }
    B::ensure_factorial(N);
    debug(D, T, Q, N);
    num ans = 0;
    for (int d = 0; d <= D; d++) {
        for (int t = 0; t <= T; t++) {
            for (int q = 0; q <= Q; q++) {
                int M = N - d - 2 * t - 3 * q;
                ans += B::choose(D, d) * B::choose(T, t) * B::choose(Q, q) *
                       B::choose(N, M) * B::fac(M);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}