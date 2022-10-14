#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <char type, bool inverse, typename T>
void conv_transform(vector<T>& a) {
    int N = a.size();
    assert((N & (N - 1)) == 0);
    for (int h = 1; h < N; h *= 2) {
        for (int i = 0; i < N; i += 2 * h) {
            for (int j = i; j < i + h; j++) {
                if constexpr (type == '^') {
                    auto x = a[j];
                    auto y = a[j + h];
                    a[j] = x + y;
                    a[j + h] = x - y;
                } else if constexpr (type == '&' && !inverse) {
                    a[j] += a[j + h];
                } else if constexpr (type == '&' && inverse) {
                    a[j] -= a[j + h];
                } else if constexpr (type == '|' && !inverse) {
                    a[j + h] += a[j];
                } else if constexpr (type == '|' && inverse) {
                    a[j + h] -= a[j];
                }
            }
        }
    }
    if constexpr (inverse && type == '^') {
        for (int i = 0; i < N; i++) {
            a[i] /= T(N);
        }
    }
}

template <char type, typename T>
auto convolve(vector<T> a, vector<T> b) {
    assert(a.size() == b.size() && !a.empty());
    int N = a.size();
    assert((N & (N - 1)) == 0);
    conv_transform<type, 0>(a);
    conv_transform<type, 0>(b);
    for (int i = 0; i < N; i++) {
        a[i] = a[i] * b[i];
    }
    conv_transform<type, 1>(a);
    return a;
}

template <bool inverse, typename T>
void xor_conv_transform(vector<T>& a) {
    conv_transform<'^', inverse>(a);
}
template <bool inverse, typename T>
void and_conv_transform(vector<T>& a) {
    conv_transform<'&', inverse>(a);
}
template <bool inverse, typename T>
void or_conv_transform(vector<T>& a) {
    conv_transform<'|', inverse>(a);
}
template <typename T>
auto xor_convolution(const vector<T>& a, const vector<T>& b) {
    return convolve<'^'>(a, b);
}
template <typename T>
auto and_convolution(const vector<T>& a, const vector<T>& b) {
    return convolve<'&'>(a, b);
}
template <typename T>
auto or_convolution(const vector<T>& a, const vector<T>& b) {
    return convolve<'|'>(a, b);
}

/**
 * Given f : [0..2^n) -> T, compute sum over subsets (aka SOS DP)
 * F[i]: SUM f[j], ji
 * Complexity: O(N log N) == O(n 2^n)
 */
template <typename T>
auto sos_subsets(const vector<T>& f) {
    int N = f.size();
    assert((N & (N - 1)) == 0);
    vector<T> F(begin(f), end(f));
    for (int bit = 1; bit < N; bit <<= 1) {
        for (int mask = 0; mask < N; mask++) {
            if (mask & bit) {
                F[mask] += F[mask ^ bit];
            }
        }
    }
    return F;
}

/**
 * Given f : [0..2^n) -> T, compute sum over supersets (aka SOS DP)
 * F[i]: SUM f[j], ij
 * Complexity: O(N log N) == O(n 2^n)
 */
template <typename T>
auto sos_supersets(const vector<T>& f) {
    int N = f.size();
    assert((N & (N - 1)) == 0);
    vector<T> F(begin(f), end(f));
    for (int bit = 1; bit < N; bit <<= 1) {
        for (int mask = 0; mask < N; mask++) {
            if (mask & bit) {
                F[mask ^ bit] += F[mask];
            }
        }
    }
    return F;
}

/**
 * Given f : [0..2^n) -> T, compute mobius sum over subsets (inverse of SOS)
 * F[i]: SUM (-1)^|i-j| f[j], ji
 * Complexity: O(N log N) == O(n 2^n)
 */
template <typename T>
auto mobius_subsets(const vector<T>& f) {
    int N = f.size();
    assert((N & (N - 1)) == 0);
    vector<T> F(begin(f), end(f));
    for (int bit = 1; bit < N; bit <<= 1) {
        for (int mask = 0; mask < N; mask++) {
            if (mask & bit) {
                F[mask] -= F[mask ^ bit];
            }
        }
    }
    return F;
}

/**
 * Given f : [0..2^n) -> T, compute mobius sum over supersets (inverse of SOS)
 * F[i]: SUM (-1)^|i-j| f[j], ij
 * Complexity: O(N log N) == O(n 2^n)
 */
template <typename T>
auto mobius_supersets(const vector<T>& f) {
    int N = f.size();
    assert((N & (N - 1)) == 0);
    vector<T> F(begin(f), end(f));
    for (int bit = 1; bit < N; bit <<= 1) {
        for (int mask = 0; mask < N; mask++) {
            if (mask & bit) {
                F[mask ^ bit] -= F[mask];
            }
        }
    }
    return F;
}

/**
 * Given f : [0..2^n) -> T and g : [0..2^n) -> T, compute subset sum convolution
 * S[i]: SUM f[a]g[b], a&b=0, a|b=i
 * Complexity: O(N log^2 N) == O(n^2 2^n)
 * Reference: https://codeforces.com/blog/entry/72488
 */
template <typename T>
void subset_convolution(int n, const T* f, const T* g, T* S) {
    int N = 1 << n;
    vector<vector<T>> fhat(n + 1, vector<T>(N));
    vector<vector<T>> ghat(n + 1, vector<T>(N));

    for (int mask = 0; mask < N; mask++) {
        fhat[__builtin_popcount(mask)][mask] = f[mask];
        ghat[__builtin_popcount(mask)][mask] = g[mask];
    }
    for (int i = 0; i <= n; i++) {
        or_conv_transform<0>(fhat[i]);
        or_conv_transform<0>(ghat[i]);
    }

    vector<T> h;
    for (int i = 0; i <= n; i++) {
        h.assign(N, 0);
        for (int j = 0; j <= i; j++) {
            for (int x = 0; x < N; x++) {
                h[x] += fhat[j][x] * ghat[i - j][x];
            }
        }
        or_conv_transform<1>(h);
        for (int x = 0; x < N; x++) {
            if (__builtin_popcount(x) == i) {
                S[x] = h[x];
            }
        }
    }
}

template <typename T>
auto subset_convolution(const vector<T>& f, const vector<T>& g) {
    int N = f.size(), n = N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0;
    assert(N == (1 << n) && N == int(g.size()));
    vector<T> S(N);
    subset_convolution(n, f.data(), g.data(), S.data());
    return S;
}

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
    constexpr modnum& operator++() { return n = fit(n + 1), *this; }
    constexpr modnum& operator--() { return n = fit(mod + n - 1), *this; }
    constexpr modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum& operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    constexpr modnum& operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
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

using num = modnum<1'000'000'007>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    constexpr int b = 17, B = 1 << b;
    vector<num> fib(B);
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < B; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    vector<num> p(B);
    for (int i = 0; i < N; i++) {
        p[s[i]] += 1;
    }

    auto x = subset_convolution(p, p);
    auto y = xor_convolution(p, p);
    vector<num> z = p;
    for (int i = 0; i < B; i++) {
        x[i] *= fib[i];
        y[i] *= fib[i];
        z[i] *= fib[i];
    }

    auto v = and_convolution(y, and_convolution(x, z));

    num ans = 0;
    for (int i = 0; i < b; i++) {
        ans += v[1 << i];
    }
    cout << ans << '\n';
    return 0;
}