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

template <typename T>
struct mat {
    using vec = vector<T>;
    using unit_type = T;
    int n, m;
    T* data = nullptr;

    mat() : n(0), m(0) {}
    mat(int n, int m, const T& v = T()) { assign(n, m, v); }
    mat(const mat& o) : n(o.n), m(o.m), data(new T[n * m]) {
        copy(o.data, o.data + n * m, data);
    }
    mat(mat&& o) : mat() { *this = move(o); }
    mat& operator=(const mat& o) { return *this = mat(o); }
    mat& operator=(mat&& o) noexcept {
        using std::swap;
        swap(n, o.n), swap(m, o.m), swap(data, o.data);
        return *this;
    }
    ~mat() { delete[] data; }

    bool operator==(const mat& o) const {
        return n == o.n && m == o.m && equal(data, data + n * m, o.data);
    }
    bool operator!=(const mat& o) const { return !(*this == o); }

    void assign(int n, int m, const T& v) {
        this->n = n, this->m = m, delete[] data, data = new T[n * m];
        std::fill(data, data + n * m, v);
    }

    array<int, 2> size() const { return {n, m}; }
    T* operator[](int x) const { return data + x * m; }
    T& operator[](array<int, 2> xy) const { return data + (xy[0] * m + xy[1]); }

    static mat from(const vector<vector<T>>& vals) {
        int n = vals.size(), m = n ? vals[0].size() : 0;
        mat a(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = vals[i][j];
        return a;
    }

    template <typename O = T>
    friend auto tovec(const mat& a) {
        vector<vector<O>> m(a.n, vector<T>(a.m));
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                m[i][j] = a[i][j];
        return m;
    }

    static mat identity(int n) {
        mat a(n, n);
        for (int i = 0; i < n; i++)
            a[i][i] = T(1);
        return a;
    }

    friend mat transpose(const mat& a) {
        mat b(a.m, a.n);
        for (int i = 0; i < a.m; i++)
            for (int j = 0; j < a.n; j++)
                b[i][j] = a[j][i];
        return b;
    }

    friend mat operator-(mat a) {
        for (int i = 0, s = a.n * a.m; i < s; i++)
            a[i] = -a[i];
        return a;
    }

    friend mat& operator+=(mat& a, const mat& b) {
        assert(a.size() == b.size() && "Different matrix dimensions");
        for (int i = 0, s = a.n * a.m; i < s; i++)
            a[i] += b[i];
        return a;
    }

    friend mat& operator-=(mat& a, const mat& b) {
        assert(a.size() == b.size() && "Different matrix dimensions");
        for (int i = 0, s = a.n * a.m; i < s; i++)
            a[i] -= b[i];
        return a;
    }

    friend mat operator*(const mat& a, const mat& b) {
        assert(a.m == b.n && "Invalid proper matrix multiplication");
        mat c(a.n, b.m);
        for (int i = 0; i < a.n; i++)
            for (int k = 0; k < a.m; k++)
                for (int j = 0; j < b.m; j++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    friend vec operator*(const mat& a, const vec& b) {
        assert(a.m == int(b.size()) && "Invalid matrix/vector multiplication");
        vec c(a.n);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                c[i] += a[i][j] * b[j];
        return c;
    }

    friend mat operator^(mat a, int64_t e) {
        assert(a.n == a.m && "Matrix exp operand is not square");
        mat c = mat::identity(a.n);
        while (e > 0) {
            if (e & 1)
                c = c * a;
            if (e >>= 1)
                a = a * a;
        }
        return c;
    }

    friend mat operator+(mat a, const mat& b) { return a += b; }
    friend mat operator-(mat a, const mat& b) { return a -= b; }
    mat operator*=(const mat& b) { return *this = *this * b; }
    mat operator^=(int64_t e) { return *this = *this ^ e; }

    friend string to_string(const mat& a) {
        vector<vector<string>> cell(a.n, vector<string>(a.m));
        vector<size_t> w(a.m);
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.m; j++) {
                using std::to_string;
                if constexpr (std::is_same<T, string>::value) {
                    cell[i][j] = a[i][j];
                } else {
                    cell[i][j] = to_string(a[i][j]);
                }
                w[j] = max(w[j], cell[i][j].size());
            }
        }
        string s;
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.m; j++) {
                s += string(w[j] + 1 - cell[i][j].size(), ' ');
                s += cell[i][j];
            }
            s += '\n';
        }
        return s;
    }

    friend ostream& operator<<(ostream& out, const mat& a) { return out << to_string(a); }
    friend istream& operator>>(istream& in, mat& a) {
        for (int i = 0; i < a.n * a.m; i++)
            in >> a.data[i];
        return in;
    }
};

using num = modnum<1'000'000'007>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    num zero = 0;
    num half = num(1) / 2;

    // a[x][y]: given that it goes to the x-th cup, it was in the y-th cup
    mat<num> A = mat<num>::from({
        {half, half, zero},
        {half, zero, half},
        {zero, half, half},
    });
    num q = 2;

    for (int64_t x : a) {
        A = A ^ x;
        q = modpow(q, x);
    }

    bool even = false, one = true;
    for (int64_t x : a) {
        even |= x % 2 == 0;
        one &= x == 1;
    }

    q /= 2;
    num p = A[1][1] * q;
    if (one) {
        p = 0, q = 1;
    }
    cout << p << '/' << q << '\n';
    return 0;
}