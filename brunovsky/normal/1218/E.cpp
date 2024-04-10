#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

template <int mod>
struct modnum {
    static_assert(mod > 0 && 2LL * mod < INT_MAX);
    int n;

    modnum() : n(0) {}
    modnum(int v) : n(fit(v % mod)) {}
    explicit operator int() const { return n; }
    explicit operator bool() const { return n != 0; }

    static int fit(int v) { return v >= mod ? v - mod : (v < 0 ? v + mod : v); }
    static int modinv(int v, int m = mod) {
        v %= m, assert(v);
        return v == 1 ? 1 : (m - 1LL * modinv(m, v) * m / v);
    }
    friend modnum modpow(modnum b, long e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    modnum inv() const { return {modinv(n)}; }
    modnum operator-() const { return {fit(n)}; }
    modnum operator+() const { return {n}; }
    modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    modnum operator--(int) { return n = fit(n - 1), *this + 1; }
    modnum& operator++() { return n = fit(n + 1), *this; }
    modnum& operator--() { return n = fit(n - 1), *this; }
    modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    modnum& operator-=(modnum v) { return n = fit(n - v.n), *this; }
    modnum& operator*=(modnum v) { return n = (1LL * n * v.n) % mod, *this; }
    modnum& operator/=(modnum v) { return n = (1LL * n * modinv(v.n)) % mod, *this; }

    friend modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        return in >> v.n, v.n = fit(v.n % mod), in;
    }
};

namespace fft {

int next_two(int32_t N) { return N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0; }
int next_two(int64_t N) { return N > 1 ? 8 * sizeof(N) - __builtin_clzll(N - 1) : 0; }

using default_complex = complex<double>;
constexpr double TAU = 6.283185307179586476925286766559;
constexpr int INTMOD_BREAKEVEN = 160;
constexpr int SPLITMOD_BREAKEVEN = 200;
constexpr int INT4_BREAKEVEN = 1400;
constexpr int INT8_BREAKEVEN = 350;
constexpr int DOUBLE_BREAKEVEN = 650;

inline namespace primitive {

int get_primitive_root(int p) {
    static unordered_map<int, int> cache = {{998244353, 3}};
    if (cache.count(p)) {
        return cache.at(p);
    }
    assert(false && "Sorry, unimplemented");
}

} // namespace primitive

inline namespace caches {

template <typename T>
struct root_of_unity {
    using type = T;
    static type get(int n) { throw runtime_error("Unimplemented"); }
};

template <typename D>
struct root_of_unity<complex<D>> {
    using type = complex<D>;
    static type get(int n) {
        assert(n > 0);
        return type(cos(TAU / n), sin(TAU / n));
    }
};

template <int mod>
struct root_of_unity<modnum<mod>> {
    using type = modnum<mod>;
    static type get(int n) {
        modnum<mod> g = get_primitive_root(mod);
        assert(n > 0 && (mod - 1) % n == 0 && "Modulus cannot handle NTT this large");
        return modpow(g, (mod - 1) / n);
    }
};

struct fft_reverse_cache {
    static inline vector<vector<int>> rev;

    static const int* get(int N) {
        int n = next_two(N);
        for (int r = rev.size(); r <= n; r++) {
            int R = 1 << r;
            rev.emplace_back(R, 0);
            for (int i = 0; i < R; i++) {
                rev[r][i] = (rev[r][i >> 1] | ((i & 1) * R)) >> 1;
            }
        }
        return rev[n].data();
    }
};

template <typename C>
struct fft_cache {
    static inline vector<C> root = vector<C>(2, 1);
    static inline vector<C> inv = vector<C>(2, 1);
    static inline vector<C> scratch_a, scratch_b;

    static array<const C*, 2> get_root(int N) {
        for (int k = root.size(); k < N; k *= 2) {
            root.resize(2 * k);
            inv.resize(2 * k);
            auto z = root_of_unity<C>::get(2 * k);
            auto iz = C(1) / z;
            for (int i = k / 2; i < k; i++) {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * z;
                inv[2 * i] = inv[i];
                inv[2 * i + 1] = inv[i] * iz;
            }
        }
        return {root.data(), inv.data()};
    }

    static array<C*, 2> get_cache(int N) {
        if (int(scratch_a.size()) < N) {
            scratch_a.resize(N);
            scratch_b.resize(N);
        }
        return {scratch_a.data(), scratch_b.data()};
    }
};

} // namespace caches

inline namespace ext {

struct int_ext {
    template <typename C>
    static auto get(const C& c) {
        return llround(c.real());
    }
};

struct real_ext {
    template <typename C>
    static auto get(const C& c) {
        return c.real();
    }
};

struct imag_ext {
    template <typename C>
    static auto get(const C& c) {
        return c.imag();
    }
};

struct exact_ext {
    template <typename C>
    static const C& get(const C& c) {
        return c;
    }
};

} // namespace ext

inline namespace runners {

template <bool inverse, typename C>
void fft_transform_run(C* a, int N) {
    auto rev = fft_reverse_cache::get(N);
    auto [root, inv] = fft_cache<C>::get_root(N);
    for (int i = 0; i < N; i++) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int k = 1; k < N; k *= 2) {
        for (int i = 0; i < N; i += 2 * k) {
            for (int l = i, r = i + k, j = 0; j < k; j++, l++, r++) {
                auto z = inverse ? inv[j + k] : root[j + k];
                auto t = a[r] * z;
                a[r] = a[l] - t;
                a[l] = a[l] + t;
            }
        }
    }
    if constexpr (inverse) {
        auto inverseN = C(1) / C(N);
        for (int i = 0; i < N; i++) {
            a[i] *= inverseN;
        }
    }
}

template <typename Ext, typename C, typename T>
void fft_inverse_transform_run(T* a, C* c, int N) {
    fft_transform_run<1, C>(c, N);
    for (int i = 0; i < N; i++) {
        a[i] = Ext::get(c[i]);
    }
}

template <typename Ext, typename C, typename At, typename Bt, typename Ct>
void fft_multiply_run(At* ia, int A, Bt* ib, int B, Ct* ic) {
    if (A == 0 || B == 0)
        return;
    int S = A + B - 1;
    int N = 1 << next_two(S);
    auto [fa, fb] = fft_cache<C>::get_cache(N);
    copy_n(ia, A, fa);
    fill_n(fa + A, N - A, C(0));
    copy_n(ib, B, fb);
    fill_n(fb + B, N - B, C(0));
    fft_transform_run<0, C>(fa, N); // forward fft A
    fft_transform_run<0, C>(fb, N); // forward fft B
    for (int i = 0; i < N; i++) {
        fa[i] = fa[i] * fb[i]; // multiply A = A * B
    }
    fft_transform_run<1, C>(fa, N); // reverse fft A
    for (int i = 0; i < S; i++) {
        ic[i] = Ext::get(fa[i]);
    }
}

template <typename Ext, typename C, typename At, typename Ct>
void fft_square_run(At* ia, int A, Ct* ic) {
    if (A == 0)
        return;
    int S = 2 * A - 1;
    int N = 1 << next_two(S);
    auto [fa, fb] = fft_cache<C>::get_cache(N);
    copy_n(ia, A, fa);
    fill_n(fa + A, N - A, C(0));
    fft_transform_run<0, C>(fa, N); // forward fft A
    for (int i = 0; i < N; i++) {
        fa[i] = fa[i] * fa[i]; // multiply A = A * A
    }
    fft_transform_run<1, C>(fa, N); // reverse fft A
    for (int i = 0; i < S; i++) {
        ic[i] = Ext::get(fa[i]);
    }
}

} // namespace runners

template <typename Mod, typename At, typename Bt, typename Ct>
void ntt_split_lower_upper(Mod H, At* ia, int A, Bt* ismall, Ct* ilarge) {
    for (int i = 0; i < A; i++) {
        ismall[i] = ia[i] % H;
        ilarge[i] = ia[i] / H;
    }
}

template <typename T>
void trim(vector<T>& v) {
    while (!v.empty() && v.back() == T(0))
        v.pop_back();
}

inline namespace naive {

template <typename At, typename Bt, typename Ct>
void naive_multiply_run(At* ia, int A, Bt* ib, int B, Ct* ic) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            ic[i + j] += ia[i] * ib[j];
        }
    }
}

template <typename At, typename Ct>
void naive_square_run(At* ia, int A, Ct* ic) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            ic[i + j] += ia[i] * ia[j];
        }
    }
}

template <typename Prom, typename Mod, typename At, typename Bt, typename Ct>
void naive_multiply_mod_run(Mod mod, At* ia, int A, Bt* ib, int B, Ct* ic) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            ic[i + j] += Prom(ia[i]) * Prom(ib[j]) % mod;
            if (ic[i + j] < 0)
                ic[i + j] += mod;
            else if (ic[i + j] >= mod)
                ic[i + j] -= mod;
        }
    }
}

template <typename Prom, typename Mod, typename At, typename Ct>
void naive_square_mod_run(Mod mod, At* ia, int A, Ct* ic) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            ic[i + j] += Prom(ia[i]) * Prom(ia[j]) % mod;
            if (ic[i + j] < 0)
                ic[i + j] += mod;
            else if (ic[i + j] >= mod)
                ic[i + j] -= mod;
        }
    }
}

template <typename T>
auto naive_multiply(const vector<T>& a, const vector<T>& b) {
    int A = a.size(), B = b.size(), S = A && B ? A + B - 1 : 0;
    vector<T> c(S);
    naive_multiply_run(a.data(), A, b.data(), B, c.data());
    return c;
}

template <typename T>
auto naive_square(const vector<T>& a) {
    int A = a.size(), S = A ? 2 * A - 1 : 0;
    vector<T> c(S);
    naive_square_run(a.data(), A, c.data());
    return c;
}

template <typename Prom = int64_t, typename Mod, typename T>
auto naive_multiply_mod(Mod mod, const vector<T>& a, const vector<T>& b) {
    int A = a.size(), B = b.size(), S = A && B ? A + B - 1 : 0;
    vector<T> c(S);
    naive_multiply_mod_run<Prom>(mod, a.data(), A, b.data(), B, c.data());
    return c;
}

template <typename Prom = int64_t, typename Mod, typename T>
auto naive_square_mod(Mod mod, const vector<T>& a) {
    int A = a.size(), S = A ? 2 * A - 1 : 0;
    vector<T> c(S);
    naive_square_mod_run<Prom>(mod, a.data(), A, c.data());
    return c;
}

} // namespace naive

template <int MOD>
auto ntt_multiply(const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
    int A = a.size(), B = b.size(), S = A && B ? A + B - 1 : 0;
    vector<modnum<MOD>> c(S);

    if (A <= INTMOD_BREAKEVEN || B <= INTMOD_BREAKEVEN) {
        naive_multiply_run(a.data(), A, b.data(), B, c.data());
    } else {
        fft_multiply_run<exact_ext, modnum<MOD>>(a.data(), A, b.data(), B, c.data());
    }

    return c;
}

template <int MOD>
auto ntt_square(const vector<modnum<MOD>>& a) {
    int A = a.size(), S = A ? 2 + A - 1 : 0;
    vector<modnum<MOD>> c(S);

    if (A <= INTMOD_BREAKEVEN) {
        naive_square_run(a.data(), A, c.data());
    } else {
        fft_square_run<exact_ext, modnum<MOD>>(a.data(), A, c.data());
    }

    return c;
}

template <typename Prom = int64_t, typename C = default_complex, typename Mod, typename T>
auto ntt_split_multiply(Mod mod, const vector<T>& a, const vector<T>& b) {
    int A = a.size(), B = b.size(), S = A && B ? A + B - 1 : 0;
    vector<T> c(S);
    if (A == 0 || B == 0)
        return c;

    if (A <= SPLITMOD_BREAKEVEN || B <= SPLITMOD_BREAKEVEN) {
        naive_multiply_mod_run<Prom>(mod, a.data(), A, b.data(), B, c.data());
        return c;
    }

    // a = a0 + H * a1    |    b = b0 + H * b1
    Mod H = sqrt(mod), Q = H * H % mod;
    vector<T> a0(A), a1(A), b0(B), b1(B);
    ntt_split_lower_upper(H, a.data(), A, a0.data(), a1.data());
    ntt_split_lower_upper(H, b.data(), B, b0.data(), b1.data());

    vector<Prom> c00(S), c01(S), c10(S), c11(S);
    fft_multiply_run<int_ext, C>(a0.data(), A, b0.data(), B, c00.data());
    fft_multiply_run<int_ext, C>(a0.data(), A, b1.data(), B, c01.data());
    fft_multiply_run<int_ext, C>(a1.data(), A, b0.data(), B, c10.data());
    fft_multiply_run<int_ext, C>(a1.data(), A, b1.data(), B, c11.data());

    for (int i = 0; i < S; i++) {
        c[i] = c00[i] % mod;
        c[i] = (c[i] + (c10[i] % mod * H % mod)) % mod;
        c[i] = (c[i] + (c01[i] % mod * H % mod)) % mod;
        c[i] = (c[i] + (c11[i] % mod * Q % mod)) % mod;
        if (c[i] < 0)
            c[i] += mod;
        else if (c[i] >= mod)
            c[i] -= mod;
    }

    return c;
}

template <typename Prom = int64_t, typename C = default_complex, typename Mod, typename T>
auto ntt_split_square(Mod mod, const vector<T>& a) {
    int A = a.size(), S = A ? 2 * A - 1 : 0;
    vector<T> c(S);
    if (A == 0)
        return c;

    if (A <= SPLITMOD_BREAKEVEN) {
        naive_square_mod_run<Prom>(mod, a.data(), A, c.data());
        return c;
    }

    // a = a0 + H * a1    |    b = b0 + H * b1
    Mod H = sqrt(mod), Q = H * H % mod;
    vector<T> a0(A), a1(A);
    ntt_split_lower_upper(H, a.data(), A, a0.data(), a1.data());

    vector<Prom> c0(S), c1(S), c2(S);
    fft_multiply_run<int_ext, C>(a0.data(), A, a0.data(), A, c0.data());
    fft_multiply_run<int_ext, C>(a0.data(), A, a1.data(), A, c1.data());
    fft_multiply_run<int_ext, C>(a1.data(), A, a1.data(), A, c2.data());

    for (int i = 0; i < S; i++) {
        c[i] = c0[i] % mod;
        c[i] = (c[i] + 2 * (c1[i] % mod * H % mod)) % mod;
        c[i] = (c[i] + (c2[i] % mod * Q % mod)) % mod;
        if (c[i] < 0)
            c[i] += mod;
        else if (c[i] >= mod)
            c[i] -= mod;
    }

    return c;
}

template <typename C = default_complex, typename T>
auto fft_multiply(const vector<T>& a, const vector<T>& b) {
    int A = a.size(), B = b.size(), S = A && B ? A + B - 1 : 0;
    vector<T> c(S);

    if constexpr (is_integral<T>::value) {
        if (sizeof(T) == 4 && (A <= INT4_BREAKEVEN || B <= INT4_BREAKEVEN)) {
            naive_multiply_run(a.data(), A, b.data(), B, c.data());
        } else if (sizeof(T) == 8 && (A <= INT8_BREAKEVEN || B <= INT8_BREAKEVEN)) {
            naive_multiply_run(a.data(), A, b.data(), B, c.data());
        } else {
            fft_multiply_run<int_ext, C>(a.data(), A, b.data(), B, c.data());
        }
    } else if constexpr (is_floating_point<T>::value) {
        if (A <= DOUBLE_BREAKEVEN || B <= DOUBLE_BREAKEVEN) {
            naive_multiply_run(a.data(), A, b.data(), B, c.data());
        } else {
            fft_multiply_run<real_ext, C>(a.data(), A, b.data(), B, c.data());
        }
    } else {
        assert(false && "Unimplemented, fill in...");
    }

    return c;
}

template <typename C = default_complex, typename T>
auto fft_square(const vector<T>& a) {
    int A = a.size(), S = A ? 2 * A - 1 : 0;
    vector<T> c(S);

    if constexpr (is_integral<T>::value) {
        if (sizeof(T) <= 4 && A <= INT4_BREAKEVEN) {
            naive_square_run(a.data(), A, c.data());
        } else if (sizeof(T) > 4 && A <= INT8_BREAKEVEN) {
            naive_square_run(a.data(), A, c.data());
        } else {
            fft_square_run<int_ext, C>(a.data(), A, c.data());
        }
    } else if constexpr (is_floating_point<T>::value) {
        if (A <= DOUBLE_BREAKEVEN) {
            naive_square_run(a.data(), A, c.data());
        } else {
            fft_square_run<real_ext, C>(a.data(), A, c.data());
        }
    }

    return c;
}

template <typename C = default_complex, typename T>
auto fft_transform(const vector<T>& a) {
    int A = a.size(), n = next_two(A), N = 1 << n;
    vector<C> c(N);
    if (A == 0)
        return c;

    copy_n(a.data(), A, c.data());
    fft_transform_run<0, C>(c.data(), N);
    return c;
}

template <typename T, typename C>
auto fft_inverse_transform(vector<C> c) {
    int N = c.size();
    vector<T> a(N);
    if (N == 0)
        return a;

    if constexpr (is_integral<T>::value) {
        fft_inverse_transform_run<int_ext>(a.data(), c.data(), N);
    } else if constexpr (is_floating_point<T>::value) {
        fft_inverse_transform_run<real_ext>(a.data(), c.data(), N);
    } else {
        assert(false && "Unimplemented, fill in...");
    }
    trim(a);
    return a;
}

} // namespace fft

using num = modnum<998244353>;

auto fft_expand(const vector<num>& roots) {
    int P = roots.size();
    vector<vector<num>> polys(P);
    for (int i = 0; i < P; i++) {
        // x - roots[i]
        polys[i] = {-roots[i], 1};
    }
    while (P > 1) {
        vector<vector<num>> new_polys((P + 1) / 2);
        for (int i = 0; i + 1 < P; i += 2) {
            new_polys[i / 2] = fft::ntt_multiply(polys[i], polys[i + 1]);
        }
        if (P & 1) {
            new_polys[P / 2] = move(polys[P - 1]);
        }
        polys = move(new_polys);
        P = polys.size();
    }
    return polys[0];
}

auto solve() {
    int N, K;
    cin >> N >> K;
    vector<num> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;
    for (int query = 0; query < Q; query++) {
        int type;
        cin >> type;
        if (type == 1) {
            vector<num> roots(N);
            num q, d;
            int index;
            cin >> q >> index >> d, index--;
            for (int i = 0; i < N; i++) {
                if (i == index) {
                    roots[i] = q - d;
                } else {
                    roots[i] = q - A[i];
                }
            }
            auto poly = fft_expand(roots);
            cout << poly[N - K] << endl;
        } else {
            vector<num> roots(N);
            num q, d;
            int L, R;
            cin >> q >> L >> R >> d, L--, R--;
            for (int i = 0; i < N; i++) {
                if (L <= i && i <= R) {
                    roots[i] = q - (A[i] + d);
                } else {
                    roots[i] = q - A[i];
                }
            }
            auto poly = fft_expand(roots);
            cout << poly[N - K] << endl;
        }
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}