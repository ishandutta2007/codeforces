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
                auto x = a[j];
                auto y = a[j + h];
                if constexpr (type == '^' && !inverse) { // 1,1,1,-1  Ax+By/Cx+Dy
                    a[j] = x + y;
                    a[j + h] = x - y;
                } else if constexpr (type == '^' && inverse) { // 1,1,1,-1  Dx-By/-Cx+Ay
                    a[j] = -x - y;
                    a[j + h] = y - x;
                } else if constexpr (type == '&' && !inverse) { // 0,1,1,1  Ax+By/Cx+Dy
                    a[j] = y;
                    a[j + h] = x + y;
                } else if constexpr (type == '&' && inverse) { // 0,1,1,1  Dx-By/-Cx+Ay
                    a[j] = x - y;
                    a[j + h] = -x;
                } else if constexpr (type == '|' && !inverse) { // 1,1,1,0  Ax+By/Cx+Dy
                    a[j] = x + y;
                    a[j + h] = x;
                } else if constexpr (type == '|' && inverse) { // 1,1,1,0  Dx-By/-Cx+Ay
                    a[j] = -y;
                    a[j + h] = y - x;
                }
            }
        }
    }
    if constexpr (inverse) {
        int n = N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0;
        if constexpr (type == '^') {
            const T div = 1 << n;
            for (int i = 0; i < N; i++) {
                a[i] /= div;
            }
        } else if constexpr (type == '&') {
            if (n & 1) {
                for (int i = 0; i < N; i++) {
                    a[i] = -a[i];
                }
            }
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

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
    using u32 = uint16_t;
    using u64 = uint32_t;
    using i32 = int16_t;
    using i64 = int32_t;
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

using num = modnum<31607>;

auto first_gray_code() { return make_tuple(0u, 0u, -1, -1); }
void next_gray_code(unsigned& u, unsigned n, int& in, int& out) {
    assert(n > 0);
    unsigned b = u ^ n ^ (n >> 1);
    if (u & b) {
        in = -1, out = __builtin_ctz(b);
    } else {
        in = __builtin_ctz(b), out = -1;
    }
    u ^= b;
}

#define FOR_EACH_MASK_GRAY_CODE(mask, max_size, in, out)        \
    for (auto [mask, n##max_size, in, out] = first_gray_code(); \
         int(n##max_size) < (1 << max_size);                    \
         n##max_size++, next_gray_code(mask, n##max_size, in, out))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<num>> A(n, vector<num>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            A[i][j] /= 10000;
        }
    }

    const int S = 4 << n;
    const unsigned DIAG0 = 1 << n;
    const unsigned DIAG1 = 2 << n;

    vector<num> dp(S);
    dp[S - 1] = 1;
    and_conv_transform<0>(dp);

    for (int i = 0; i < n; i++) {
        vector<num> row(S);
        num p = 1;
        for (int j = 0; j < n; j++) {
            p *= 1 - A[i][j];
        }

        vector<num> add(n), rem(n);
        for (int j = 0; j < n; j++) {
            add[j] = A[i][j] / (1 - A[i][j]);
            rem[j] = (1 - A[i][j]) / A[i][j];
        }

        FOR_EACH_MASK_GRAY_CODE(mask, n, in, out) {
            if (in != -1) {
                p *= add[in];
            } else if (out != -1) {
                p *= rem[out];
            }
            bool col0 = mask & (1 << i);
            bool coln = mask & (1 << (n - i - 1));

            unsigned target = mask | (col0 ? DIAG0 : 0) | (coln ? DIAG1 : 0);
            row[target] = p;
        }
        row[S - 1] = 0; // prohibit winning row

        and_conv_transform<0>(row);
        for (int mask = 0; mask < S; mask++) {
            dp[mask] *= row[mask];
        }
    }

    and_conv_transform<1>(dp);

    cout << 1 - dp[0] << '\n';
    return 0;
}