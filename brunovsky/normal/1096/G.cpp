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

// Base include with my_complex, reverse/root/scratch caches, naive mult, fft_transform
namespace fft {

template <typename T>
struct my_complex {
    using self = my_complex<T>;
    T x, y;
    constexpr my_complex(T x = T(0), T y = T(0)) : x(x), y(y) {}

    constexpr T& real() { return x; }
    constexpr T& imag() { return y; }
    constexpr const T& real() const { return x; }
    constexpr const T& imag() const { return y; }
    constexpr void real(T v) { x = v; }
    constexpr void imag(T v) { y = v; }
    constexpr friend auto real(self a) { return a.x; }
    constexpr friend auto imag(self a) { return a.y; }
    constexpr self rot_ccw(self a) { return self(-a.y, a.x); }
    constexpr self rot_cw(self a) { return self(a.y, -a.x); }
    constexpr friend auto abs(self a) { return sqrt(norm(a)); }
    constexpr friend auto arg(self a) { return atan2(a.y, a.x); }
    constexpr friend auto norm(self a) { return a.x * a.x + a.y * a.y; }
    constexpr friend auto conj(self a) { return self(a.x, -a.y); }
    constexpr friend auto inv(self a) { return self(a.x / norm(a), -a.y / norm(a)); }
    constexpr friend auto polar(T r, T theta = T()) {
        return self(r * cos(theta), r * sin(theta));
    }
    constexpr T& operator[](int i) { assert(i == 0 || i == 1), *(&x + i); }
    constexpr const T& operator[](int i) const { assert(i == 0 || i == 1), *(&x + i); }

    constexpr self& operator+=(self b) { return *this = *this + b; }
    constexpr self& operator-=(self b) { return *this = *this - b; }
    constexpr self& operator*=(self b) { return *this = *this * b; }
    constexpr self& operator/=(self b) { return *this = *this / b; }

    constexpr friend self operator*(self a, T b) { return self(a.x * b, a.y * b); }
    constexpr friend self operator*(T a, self b) { return self(a * b.x, a * b.y); }
    constexpr friend self operator/(self a, T b) { return self(a.x / b, a.y / b); }
    constexpr friend self operator/(T a, self b) { return a * inv(b); }
    constexpr friend self operator+(self a) { return self(a.x, a.y); }
    constexpr friend self operator-(self a) { return self(-a.x, -a.y); }
    constexpr friend self operator+(self a, self b) { return self(a.x + b.x, a.y + b.y); }
    constexpr friend self operator-(self a, self b) { return self(a.x - b.x, a.y - b.y); }
    constexpr friend self operator/(self a, self b) { return a * inv(b); }
    constexpr friend self operator*(self a, self b) {
        return self(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
    }
};

using default_complex = my_complex<double>;
constexpr double TAU = 6.283185307179586476925286766559;

int next_two(int32_t N) { return N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0; }

template <typename T, typename D>
inline constexpr T fft_round(D coefficient) {
    return is_integral<T>::value ? llround(coefficient) : coefficient;
}

template <typename T>
void trim_vector(vector<T>& v) {
    if constexpr (is_floating_point<T>::value)
        while (!v.empty() && abs(v.back()) <= 10 * numeric_limits<T>::epsilon())
            v.pop_back();
    else
        while (!v.empty() && v.back() == T(0))
            v.pop_back();
}

template <typename T>
auto naive_multiply(const vector<T>& a, const vector<T>& b) {
    int A = a.size(), B = b.size(), C = A && B ? A + B - 1 : 0;
    vector<T> c(C);
    for (int i = 0; i < A && B; i++)
        for (int j = 0; j < B; j++)
            c[i + j] += a[i] * b[j];
    trim_vector(c);
    return c;
}

struct fft_reverse_cache {
    static inline vector<vector<int>> rev;

    static const int* get(int N) {
        int n = next_two(N), r = rev.size();
        if (n >= r || rev[n].empty()) {
            rev.resize(max(r, n + 1));
            int R = 1 << n;
            rev[n].assign(R, 0);
            for (int i = 0; i < R; i++) {
                rev[n][i] = (rev[n][i >> 1] | ((i & 1) << n)) >> 1;
            }
        }
        return rev[n].data();
    }
};

template <typename T>
struct root_of_unity {};

template <typename D>
struct root_of_unity<my_complex<D>> {
    static auto get(int n) {
        assert(n > 0);
        return my_complex<D>(cos(TAU / n), sin(TAU / n));
    }
};

template <typename C>
struct fft_roots_cache {
    static inline vector<C> root = vector<C>(2, C(1));
    static inline vector<C> invroot = vector<C>(2, C(1));
    static inline vector<C> scratch_a, scratch_b;

    static auto get(int N) {
        for (int k = root.size(); k < N; k *= 2) {
            root.resize(2 * k);
            invroot.resize(2 * k);
            auto z = root_of_unity<C>::get(2 * k);
            auto iz = C(1) / z;
            for (int i = k / 2; i < k; i++) {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * z;
                invroot[2 * i] = invroot[i];
                invroot[2 * i + 1] = invroot[i] * iz;
            }
        }
        return make_pair(root.data(), invroot.data());
    }

    static auto get_scratch(int N) {
        if (int(scratch_a.size()) < N) {
            scratch_a.resize(N);
            scratch_b.resize(N);
        }
        return make_pair(ref(scratch_a), ref(scratch_b));
    }
};

template <typename T>
void fft_bit_reverse(vector<T>& a, int N) {
    auto rev = fft_reverse_cache::get(N);
    for (int i = 0; i < N; i++) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
}

template <bool inverse, bool standard = true, typename T>
void fft_transform(vector<T>& a, int N) {
    // With standard=true, reverse bits at start and end of forward transform.
    // With standard=false, reverse bits at start of forward and backward transform.
    if constexpr (!standard || !inverse) {
        fft_bit_reverse(a, N);
    }
    auto [root, invroot] = fft_roots_cache<T>::get(N);
    for (int k = 1; k < N; k *= 2) {
        for (int i = 0; i < N; i += 2 * k) {
            for (int l = i, r = i + k, j = 0; j < k; j++, l++, r++) {
                auto z = inverse ? invroot[j + k] : root[j + k];
                auto t = a[r] * z;
                a[r] = a[l] - t;
                a[l] = a[l] + t;
            }
        }
    }
    if constexpr (inverse) {
        auto inv = T(1) / T(N);
        for (int i = 0; i < N; i++) {
            a[i] *= inv;
        }
    } else if constexpr (standard) {
        fft_bit_reverse(a, N);
    }
}

template <typename T> // a is fft'd and not bit-reversed, extend it to more roots
void fft_doubling_inplace(vector<T>& a, int N) {
    auto fb = fft_roots_cache<T>::get_scratch(N).second;
    for (int i = 0; i < N; i++) {
        fb[i] = a[i];
    }
    fft_transform<1>(fb, N);
    T r = 1, zeta = root_of_unity<T>::get(2 * N);
    for (int i = 0; i < N; i++) {
        fb[i] *= r, r *= zeta;
    }
    fft_transform<0>(fb, N);
    a.resize(max(int(a.size()), 2 * N));
    for (int i = 0; i < N; i++) {
        a[N + i] = fb[i];
    }
}

} // namespace fft

// NTT with modnums | 60,125,270ms for 250K,500K,1M
namespace fft {

template <uint32_t MOD>
struct root_of_unity<modnum<MOD>> {
    using type = modnum<MOD>;
    static constexpr int ntt_primitive_root(int p) {
        if (p == 2 || p == 3)
            return p - 1;
        if (p == 167772161 || p == 469762049 || p == 998244353)
            return 3;
        if (p == 1000000007)
            return 5;
        assert(p % 2 == 1);

        auto modpow = [](int base, int64_t e, int mod) {
            int x = 1;
            base = base % mod;
            while (e > 0) {
                if (e & 1)
                    x = int64_t(x) * int64_t(base) % mod;
                if (e >>= 1)
                    base = int64_t(base) * int64_t(base) % mod;
            }
            return x;
        };

        int divs[20] = {2};
        int cnt = 1;
        int x = (p - 1) / 2; // phi(p)
        while (x % 2 == 0) {
            x /= 2;
        }
        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) {
                divs[cnt++] = i;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            divs[cnt++] = x;
        }
        for (int g = 2;; g++) {
            bool ok = true;
            for (int i = 0; i < cnt; i++) {
                if (modpow(g, (p - 1) / divs[i], p) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return g;
            }
        }
        __builtin_unreachable();
    }
    static constexpr type get(int n) {
        modnum<MOD> g = ntt_primitive_root(MOD);
        assert(n > 0 && (MOD - 1) % n == 0 && "Modulus cannot handle NTT this large");
        return modpow(g, int64_t(MOD - 1) / n);
    }
};

template <uint32_t MOD>
auto ntt_multiply(const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
    using T = modnum<MOD>;
    if (a.empty() || b.empty()) {
        return vector<T>();
    }
    int A = a.size(), B = b.size();
    int S = A + B - 1, s = next_two(S), N = 1 << s;
    if (min(A, B) <= 5 || 1.0 * A * B <= 2.5 * N * s) {
        return naive_multiply(a, b);
    }

    auto fb = fft_roots_cache<T>::get_scratch(N).second;
    vector<T> c(N);
    copy_n(begin(a), A, begin(c));
    copy_n(begin(b), B, begin(fb));
    fill_n(begin(fb) + B, N - B, T(0));
    fft_transform<0>(c, N);
    fft_transform<0>(fb, N);
    for (int i = 0; i < N; i++) {
        c[i] = c[i] * fb[i];
    }
    fft_transform<1>(c, N);
    trim_vector(c);
    return c;
}

} // namespace fft

// Core operations, multiplication, fft
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

// TODO: Fill in core FFT functions
TTT void fft(vector<T>& u) { fft::fft_transform<0>(u, u.size()); }
TTT void ifft(vector<T>& u) { fft::fft_transform<1>(u, u.size()); }
TTT auto convolve(const vector<T>& a, const vector<T>& b) {
    return fft::ntt_multiply(a, b);
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
TTT auto& operator*=(vector<T>& u, const vector<T>& v) { return u = convolve(u, v), u; }

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
TTT auto operator*(const vector<T>& u, const vector<T>& v) { return convolve(u, v); }

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

// Series inverse, exp, log, pow, division, composition
namespace polymath {

// Compute first n terms of series 1/u. O(n log n)
TTT auto inverse(const vector<T>& u, int n = -1) {
    assert(size(u) > 0 && u[0] != T(0));
    n = n < 0 ? size(u) : n;

    vector<T> ans(n, T(1) / u[0]);

    for (int d = 1; d < n; d *= 2) {
        vector<T> f(2 * d), g(2 * d);

        for (int j = 0; j < min(2 * d, size(u)); j++)
            f[j] = u[j];
        for (int j = 0; j < d; j++)
            g[j] = ans[j];

        fft(f), fft(g);
        for (int j = 0; j < 2 * d; j++)
            f[j] *= g[j];

        ifft(f);
        for (int j = 0; j < d; j++)
            f[j] = 0;

        fft(f);
        for (int j = 0; j < 2 * d; j++)
            f[j] *= g[j];

        ifft(f);
        for (int j = d; j < min(2 * d, n); j++)
            ans[j] = -f[j];
    }

    return ans;
}

// Compute first n terms of series exp(u). O(n log n)
TTT auto exp(const vector<T>& u, int n = -1) {
    assert(size(u) == 0 || u[0] == T(0));
    n = n < 0 ? size(u) : n;

    vector<T> b{1, size(u) > 1 ? u[1] : 0}, c{1}, z1, z2{1, 1};
    b.reserve(n);

    for (int m = 2; m < n; m *= 2) {
        auto y = b;
        resize(y, 2 * m);
        fft(y);

        z1 = move(z2);
        vector<T> z(m);
        for (int i = 0; i < m; ++i)
            z[i] = y[i] * z1[i];
        ifft(z);
        fill(begin(z), begin(z) + m / 2, T(0));
        fft(z);
        for (int i = 0; i < m; ++i)
            z[i] *= -z1[i];
        ifft(z);

        c.insert(end(c), begin(z) + m / 2, end(z));
        z2 = c;
        resize(z2, 2 * m);
        fft(z2);

        vector<T> x(begin(u), begin(u) + min(size(u), m));
        resize(x, m);
        derivative_inplace(x);
        x.push_back(T(0));

        fft(x);
        for (int i = 0; i < m; ++i)
            x[i] *= y[i];
        ifft(x);

        x -= derivative(b);
        resize(x, 2 * m);
        for (int i = 0; i < m - 1; ++i)
            x[m + i] = x[i], x[i] = T(0);

        fft(x);
        for (int i = 0; i < 2 * m; ++i)
            x[i] *= z2[i];
        ifft(x);

        x.pop_back();
        integral_inplace(x);
        for (int i = m; i < min(size(u), 2 * m); ++i)
            x[i] += u[i];
        fill(begin(x), begin(x) + m, T(0));

        fft(x);
        for (int i = 0; i < 2 * m; ++i)
            x[i] *= y[i];
        ifft(x);

        b.insert(end(b), begin(x) + m, end(x));
    }

    resize(b, n);
    return b;
}

// Compute first n terms of series log(u). O(n log n)
TTT auto log(const vector<T>& u, int n = -1) {
    assert(size(u) > 0 && u[0] == 1);
    n = n < 0 ? size(u) : n;
    auto v = derivative(u) * inverse(u, n);
    resize(integral_inplace(v), n - 1);
    return v;
}

// Compute first n terms of u^k. O(n log n)
TTT auto pow(const vector<T>& u, int64_t k, int n = -1) {
    n = n < 0 ? size(u) : n;
    if (k == 0) {
        return resized(vector<T>{1}, n);
    } else if (k == 1) {
        return resized(u, n);
    } else if (k == 2) {
        return resized(u * u, n);
    } else if (k < 0) {
        return inverse(pow(u, -k, n));
    }

    for (int i = 0; i < size(u) && i * k < n; i++) {
        if (u[i] != 0) {
            auto ans = exp(T(k) * log((u >> i) / u[i], n)) * modpow(u[i], k);
            resize(ans <<= i * k, n);
            return ans;
        }
    }

    return vector<T>(n, 0);
}

// Compute quotient u/v as proper polynomial division. O(n log n)
TTT auto operator/(vector<T> u, vector<T> v) {
    trim(u), trim(v);
    assert(size(v) > 0);

    if (size(u) < size(v)) {
        return vector<T>();
    } else {
        int n = size(u) - size(v) + 1;
        reverse(u), reverse(v);
        auto q = u * inverse(v, n);
        shrink(q, n), reverse(q), trim(q);
        return q;
    }
}

// Compute remainder u%v as proper polynomial division. O(n log n)
TTT auto operator%(vector<T> u, vector<T> v) { return u -= v * (u / v), trim(u), u; }

TTT auto& operator/=(vector<T>& u, vector<T> v) { return u = u / move(v), u; }
TTT auto& operator%=(vector<T>& u, vector<T> v) { return u = u % move(v), u; }

// Compute quotient and remainder of u/v as proper polynomial division. O(n log n)
TTT auto divrem(vector<T> u, vector<T> v) {
    auto q = u / v;
    u -= q * v, trim(u);
    return make_pair(move(q), move(u));
}

// Get k-th term of linear recurrence with coefs. rec and initial values x. O(n log n)
TTT auto kitamasa(const vector<T>& x, const vector<T>& rec, int64_t k) {
    // Source: Nyaan https://judge.yosupo.jp/submission/36598
    if (k < size(x)) {
        return x[k];
    }
    auto Q = -rec;
    trim(Q), Q <<= 1, Q[0] = 1;
    int rec_len = size(Q) - 1;
    auto P = shrunk(x, rec_len) * Q;
    resize(P, rec_len);

    T ret = 0;
    int N = 1;
    while (N < size(Q)) {
        N <<= 1;
    }

    P.resize(2 * N);
    Q.resize(2 * N);
    fft(P), fft(Q);

    T dw = T(1) / fft::root_of_unity<T>::get(2 * N);
    vector<T> A(2 * N), B(2 * N);
    const int* bits = fft::fft_reverse_cache::get(N);

    while (k > 0) {
        T inv2 = T(1) / T(2);

        B.resize(N);
        for (int j = 0; j < N; j++) {
            int i = bits[j], l = i << 1, r = i << 1 | 1;
            B[i] = Q[l] * Q[r];
        }

        A.resize(N);
        if (k & 1) {
            // odd degree of P(x)Q(-x)
            for (int j = 0; j < N; j++) {
                int i = bits[j], l = i << 1, r = i << 1 | 1;
                A[i] = (P[l] * Q[r] - P[r] * Q[l]) * inv2;
                inv2 *= dw;
            }
        } else {
            // even degree of P(x)Q(-x)
            for (int i = 0; i < N; i++) {
                int l = i << 1, r = i << 1 | 1;
                A[i] = (P[l] * Q[r] + P[r] * Q[l]) * inv2;
            }
        }
        swap(P, A);
        swap(Q, B);
        k >>= 1;
        if (k < N) {
            break;
        }
        fft::fft_doubling_inplace(P, N);
        fft::fft_doubling_inplace(Q, N);
    }
    ifft(P), ifft(Q);
    return ret + (P * inverse(Q))[k];
}

// Composition p(q(x)), naively quadratic, complexity O(n log n)
TTT auto naive_composition(const vector<T>& p, vector<T> q, int n = -1) {
    n = n < 0 ? (size(p) - 1) * (size(q) - 1) + 1 : n;
    if (n == 0) {
        return vector<T>();
    }

    trim(q);
    vector<T> ans(n), u{1};
    u.reserve(n);

    for (int i = 0; i < min(n, size(p)); i++) {
        ans += p[i] * u, u = shrunk(u * q, n);
    }

    return ans;
}

// Composition p(q(x)), square-root decomposition, complexity O((n log n)^3/2)
TTT auto sqrt_composition(const vector<T>& p, vector<T> q, int n = -1) {
    // Source: https://judge.yosupo.jp/submission/43112
    n = n < 0 ? (size(p) - 1) * (size(q) - 1) + 1 : n;
    if (n == 0) {
        return vector<T>();
    }

    trim(q);
    int k = sqrt(n);
    int d = n / k + (k * k < n);

    vector<vector<T>> small(d + 1);
    small[0] = {1}, small[1] = shrunk(q, n);
    for (int i = 2; i <= d; i++) {
        small[i] = small[i / 2] * small[(i + 1) / 2];
        shrink(small[i], n);
    }

    vector<vector<T>> fi(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < d && i * d + j < min(n, size(p)); j++) {
            int x = i * d + j;
            fi[i] += p[x] * small[j];
        }
    }

    vector<T> ans(n), big = {1};
    for (int i = 0; i < k; i++) {
        fi[i] = shrunk(fi[i] * big, n);
        ans += fi[i];
        big = shrunk(big * small[d], n);
    }
    return ans;
}

TTT auto composition(const vector<T>& u, const vector<T>& v, int n = -1) {
    return sqrt_composition(u, v, n);
}

} // namespace polymath

using num = modnum<998244353>;
using poly = vector<num>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    N /= 2;
    poly half(10, 0);
    while (K--) {
        int x;
        cin >> x;
        half[x] = 1;
    }
    half = polymath::pow(half, N, 10 * N);
    num ans = polymath::inner_product(half, half);
    cout << ans << '\n';
    return 0;
}