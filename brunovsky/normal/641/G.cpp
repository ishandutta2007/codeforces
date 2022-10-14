#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
using randint = uniform_int_distribution<int>;
using randll = uniform_int_distribution<long long>;
using randd = uniform_real_distribution<double>;
// return x with probability p, y with probability 1-p
template <class T>
T pick(T x, T y, double p = 0.5) {
    assert(-0.0001 <= p && p <= 1.0001);
    return randd(0, 1)(rng) <= p ? x : y;
}

template <typename T>
struct modular_base {
    using Type = typename decay<decltype(T::value)>::type;
    static vector<Type> MOD_INV;
    constexpr modular_base() : value() {}
    template <typename U>
    modular_base(const U &x) {
        value = normalize(x);
    }
    template <typename U>
    static Type normalize(const U &x) {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }
    const Type &operator()() const { return value; }
    template <typename U>
    explicit operator U() const {
        return static_cast<U>(value);
    }
    constexpr static Type mod() { return T::value; }
    modular_base &operator+=(const modular_base &otr) {
        if ((value += otr.value) >= mod())
            value -= mod();
        return *this;
    }
    modular_base &operator-=(const modular_base &otr) {
        if ((value -= otr.value) < 0)
            value += mod();
        return *this;
    }
    template <typename U>
    modular_base &operator+=(const U &otr) {
        return *this += modular_base(otr);
    }
    template <typename U>
    modular_base &operator-=(const U &otr) {
        return *this -= modular_base(otr);
    }
    modular_base &operator++() { return *this += 1; }
    modular_base &operator--() { return *this -= 1; }
    modular_base operator++(int) {
        modular_base result(*this);
        *this += 1;
        return result;
    }
    modular_base operator--(int) {
        modular_base result(*this);
        *this -= 1;
        return result;
    }
    modular_base operator-() const { return modular_base(-value); }
    template <typename U = T>
    typename enable_if<is_same<typename modular_base<U>::Type, int>::value,
                       modular_base>::type &
    operator*=(const modular_base &rhs) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename modular_base<U>::Type, int64_t>::value,
                       modular_base>::type &
    operator*=(const modular_base &rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value /
                                         mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename modular_base<U>::Type>::value,
                       modular_base>::type &
    operator*=(const modular_base &rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }
    template <typename U>
    modular_base &operator^=(U e) {
        if (e < 0)
            *this = 1 / *this, e = -e;
        modular_base res = 1;
        for (; e; *this *= *this, e >>= 1)
            if (e & 1)
                res *= *this;
        return *this = res;
    }
    template <typename U>
    modular_base operator^(U e) const {
        return modular_base(*this) ^= e;
    }
    modular_base &operator/=(const modular_base &otr) {
        Type a = otr.value, m = mod(), u = 0, v = 1;
        if (a < (int)MOD_INV.size())
            return *this *= MOD_INV[a];
        while (a) {
            Type t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return *this *= u;
    }
    template <typename U>
    friend const modular_base<U> &abs(const modular_base<U> &v) {
        return v;
    }
    Type value;
};
template <typename T>
bool operator==(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return lhs.value == rhs.value;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
bool operator==(const modular_base<T> &lhs, U rhs) {
    return lhs == modular_base<T>(rhs);
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
bool operator==(U lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) == rhs;
}
template <typename T>
bool operator!=(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
bool operator!=(const modular_base<T> &lhs, U rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
bool operator!=(U lhs, const modular_base<T> &rhs) {
    return !(lhs == rhs);
}
template <typename T>
bool operator<(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return lhs.value < rhs.value;
}
template <typename T>
bool operator>(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return lhs.value > rhs.value;
}
template <typename T>
bool operator<=(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return lhs.value <= rhs.value;
}
template <typename T>
bool operator>=(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return lhs.value >= rhs.value;
}
template <typename T>
modular_base<T> operator+(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) += rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator+(const modular_base<T> &lhs, U rhs) {
    return modular_base<T>(lhs) += rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator+(U lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) += rhs;
}
template <typename T>
modular_base<T> operator-(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) -= rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator-(const modular_base<T> &lhs, U rhs) {
    return modular_base<T>(lhs) -= rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator-(U lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) -= rhs;
}
template <typename T>
modular_base<T> operator*(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) *= rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator*(const modular_base<T> &lhs, U rhs) {
    return modular_base<T>(lhs) *= rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator*(U lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) *= rhs;
}
template <typename T>
modular_base<T> operator/(const modular_base<T> &lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) /= rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator/(const modular_base<T> &lhs, U rhs) {
    return modular_base<T>(lhs) /= rhs;
}
template <typename T, typename U,
          typename enable_if<is_integral<U>::value>::type * = nullptr>
modular_base<T> operator/(U lhs, const modular_base<T> &rhs) {
    return modular_base<T>(lhs) /= rhs;
}
template <typename T>
istream &operator>>(istream &in, modular_base<T> &number) {
    typename common_type<typename modular_base<T>::Type, int64_t>::type x;
    in >> x;
    number.value = modular_base<T>::normalize(x);
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, const modular_base<T> &number) {
    return out << number();
}
/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using modular = modular_base<VarMod>;
*/
constexpr int mod = 1e9 + 7; // 1000000007
// constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using modular = modular_base<integral_constant<decay<decltype(mod)>::type, mod>>;
template <typename T>
vector<typename modular_base<T>::Type> modular_base<T>::MOD_INV;
template <typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(int SZ) {
    auto &inv = modular_base<T>::MOD_INV;
    if (inv.empty())
        inv.assign(2, 1);
    for (; inv.size() <= SZ;)
        inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()]) %
                      mod);
}
template <typename T>
vector<T> precalc_power(T base, int SZ) {
    vector<T> res(SZ + 1, 1);
    for (auto i = 1; i <= SZ; ++i)
        res[i] = res[i - 1] * base;
    return res;
}

template <class T>
struct linear_recurrence {
    int n;
    vector<T> init, coef;
    linear_recurrence(const vector<T> &init, const vector<T> &coef)
        : n((int)coef.size()), init(init), coef(coef) {
        assert((int)coef.size() == (int)init.size());
    }
    // Berlekamp Massey Algorithm / find the minimal linear recurrence relation
    // O(n * sz + sz log mod)
    linear_recurrence(const vector<T> &s) {
        assert(!s.empty());
        int sz = (int)s.size();
        n = 0;
        vector<T> B(sz), C;
        coef.resize(sz);
        coef[0] = B[0] = 1;
        T b = 1;
        for (auto i = 0, m = 0; i < sz; ++i) {
            ++m;
            T d = s[i];
            for (auto j = 1; j <= n; ++j)
                d += coef[j] * s[i - j];
            if (!d)
                continue;
            C = coef;
            T c = d / b;
            for (auto j = m; j < sz; ++j)
                coef[j] -= c * B[j - m];
            if (2 * n > i)
                continue;
            n = i + 1 - n, B = C, b = d, m = 0;
        }
        n = max(n, 1);
        coef.resize(n + 1), coef.erase(coef.begin());
        for (auto &x : coef)
            x = -x;
        reverse(coef.begin(), coef.end());
        init.resize(n);
        for (auto i = 0; i < n; ++i)
            init[i] = s[i];
    }
    // n^2 log i (or n log n log i if FFT is used)
    T operator[](long long i) const {
        assert(0 <= i);
        auto combine = [&](const vector<T> &a, const vector<T> &b) {
            vector<T> res(2 * n + 1);
            for (auto i = 0; i <= n; ++i)
                for (auto j = 0; j <= n; ++j)
                    res[i + j] += a[i] * b[j];
            for (auto i = n << 1; i > n; --i)
                for (auto j = 0; j < n; ++j)
                    res[i - 1 - j] += res[i] * coef[n - 1 - j];
            res.resize(n + 1);
            return res;
        };
        vector<T> pol(n + 1), e(pol);
        pol[0] = e[1] = 1;
        for (++i; i; i >>= 1, e = combine(e, e))
            if (i & 1)
                pol = combine(pol, e);
        T res = 0;
        for (auto i = 0; i < n; ++i)
            res += pol[i + 1] * init[i];
        return res;
    }
};

template <class T>
vector<T> sparse_minimal_polynomial(int n, const vector<tuple<int, int, T>> &a) {
    vector<T> v(n), p(n), s;
    generate(v.begin(), v.end(), rng), generate(p.begin(), p.end(), rng);
    for (auto rep = 0; rep < n << 1; ++rep) {
        T x = 0;
        for (auto i = 0; i < n; ++i)
            x += v[i] * p[i];
        s.push_back(x);
        vector<T> p_next(n);
        for (auto [i, j, val] : a)
            p_next[i] += val * p[j];
        swap(p, p_next);
    }
    auto poly = linear_recurrence(s).coef;
    for (auto &x : poly)
        x = -x;
    poly.push_back(1);
    return poly;
}

template <class T> // calculate the determinant of the sparse matrix
T sparse_determinant(int n, vector<tuple<int, int, T>> a) {
    vector<T> D(n);
    T det_D = 1;
    for (auto &x : D) {
        do
            x = rng();
        while (!x);
        det_D *= x;
    }
    for (auto &[i, j, val] : a)
        val *= D[i];
    T det = sparse_minimal_polynomial(n, a)[0] * (n & 1 ? -1 : 1);
    return det / det_D;
}

using num = modular;

string to_string(num x) { return to_string(int(x)); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }
    vector<tuple<int, int, num>> a;
    vector<int> deg(N);
    for (int u = 0; u < K; u++) {
        for (int v = u + 1; v < K; v++) {
            a.push_back({u, v, mod - 1});
            a.push_back({v, u, mod - 1});
        }
        deg[u] = K - 1;
    }
    for (int u = K; u < N; u++) {
        for (int i = 0; i < K; i++) {
            int v;
            cin >> v, v--;
            a.push_back({u, v, mod - 1});
            a.push_back({v, u, mod - 1});
            deg[u]++, deg[v]++;
        }
    }
    for (int u = 0; u < N; u++) {
        a.push_back({u, u, deg[u]});
    }
    vector<tuple<int, int, num>> b; // remove row and col N-1
    for (auto [u, v, x] : a) {
        if (u + 1 < N && v + 1 < N) {
            b.push_back({u, v, x});
        }
    }
    auto det = sparse_determinant(N - 1, b);
    cout << det << '\n';
    return 0;
}