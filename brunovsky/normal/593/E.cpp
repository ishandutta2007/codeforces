#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename T>
struct mat {
    using vec = vector<T>;

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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = vals[i][j];
            }
        }
        return a;
    }

    static mat identity(int n) {
        mat a(n, n);
        for (int i = 0; i < n; i++)
            a[i][i] = T(1);
        return a;
    }

    friend mat transpose(const mat& a) {
        auto [n, m] = a.size();
        mat b(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                b[i][j] = a[j][i];
        return b;
    }

    friend mat operator-(mat a) {
        auto [n, m] = a.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = -a[i][j];
        return a;
    }

    friend mat& operator+=(mat& a, const mat& b) {
        assert(a.size() == b.size());
        auto [n, m] = a.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] += b[i][j];
        return a;
    }

    friend mat& operator-=(mat& a, const mat& b) {
        assert(a.size() == b.size());
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] += b[i][j];
        return a;
    }

    friend mat operator*(const mat& a, const mat& b) {
        assert(a.m == b.n && "Different matrix mul operand dimensions");
        mat c(a.n, b.m);
        for (int i = 0; i < a.n; i++)
            for (int k = 0; k < a.m; k++)
                for (int j = 0; j < b.m; j++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    friend vec operator*(const mat& a, const vec& b) {
        assert(a.m == int(b.size()) && "Matrix and column have unequal dimensions");
        vec c(a.n);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                c[i] += a[i][j] * b[j];
        return c;
    }

    friend mat operator^(mat a, long e) {
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
    mat operator^=(long e) { return *this = *this ^ e; }

    friend string to_string(const mat& a) {
        vector<vector<string>> cell(a.n, vector<string>(a.m));
        vector<size_t> w(a.m);
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.m; j++) {
                if constexpr (std::is_same_v<T, string>) {
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
                s += string(w[j] + 1 - cell[i][j].size(), ' ') + cell[i][j];
            }
            s += '\n';
        }
        return s;
    }

    friend ostream& operator<<(ostream& out, const mat& a) { return out << to_string(a); }
};

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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<array<int, 4>> queries(Q);
    for (auto& [type, x, y, t] : queries) {
        cin >> type >> x >> y >> t;
        x--, y--;
    }

    int S = N * M;
    mat<bool> cat(N, M);

    auto id = [&](int i, int j) { return i * M + j; };

    auto make_transition = [&]() {
        mat<num> table(S, S);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                table[id(i, j)][id(i, j)] = !cat[i][j];

        for (int i = 0; i + 1 < N; i++)
            for (int j = 0; j < M; j++)
                table[id(i, j)][id(i + 1, j)] = !cat[i][j];

        for (int i = 1; i < N; i++)
            for (int j = 0; j < M; j++)
                table[id(i, j)][id(i - 1, j)] = !cat[i][j];

        for (int i = 0; i < N; i++)
            for (int j = 1; j < M; j++)
                table[id(i, j)][id(i, j - 1)] = !cat[i][j];

        for (int i = 0; i < N; i++)
            for (int j = 0; j + 1 < M; j++)
                table[id(i, j)][id(i, j + 1)] = !cat[i][j];

        return table;
    };

    // dp[s][t]: number of ways to go from s to t while avoiding cats
    vector<num> dp(S);
    dp[0] = 1;

    int T = 1;

    for (auto [type, x, y, t] : queries) {
        if (T < t) {
            dp = (make_transition() ^ (t - T)) * dp;
            T = t;
        }
        if (type == 1) {
            cout << dp[id(x, y)] << '\n';
        } else if (type == 2) {
            cat[x][y] = true;
            dp[id(x, y)] = 0;
        } else if (type == 3) {
            cat[x][y] = false;
        }
    }

    return 0;
}