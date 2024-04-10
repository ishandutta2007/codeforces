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
    static_assert(mod > 0 && mod < UINT_MAX / 2);

    u32 n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    constexpr modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(mod + v % int(mod))) {}
    explicit constexpr operator i32() const { return n; }
    explicit constexpr operator u32() const { return n; }
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

    template <typename U>
    static mat from(const vector<vector<U>>& vals) {
        int n = vals.size(), m = n ? vals[0].size() : 0;
        mat a(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = vals[i][j];
        return a;
    }

    static mat from(const vector<vector<T>>& vals) {
        int n = vals.size(), m = n ? vals[0].size() : 0;
        mat a(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = vals[i][j];
        return a;
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
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] = -a[i][j];
        return a;
    }

    friend mat& operator+=(mat& a, const mat& b) {
        assert(a.size() == b.size() && "Different matrix dims");
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] += b[i][j];
        return a;
    }

    friend mat& operator-=(mat& a, const mat& b) {
        assert(a.size() == b.size() && "Different matrix dims");
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] += b[i][j];
        return a;
    }

    friend mat operator*(const mat& a, const mat& b) {
        assert(a.m == b.n && "Invalid matrix multiplication col/row dims");
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

template <typename T>
optional<vector<T>> solve_linear_system(mat<T> a, vector<T> b) {
    assert(a.n == int(b.size()));
    int r = 0, c = 0;
    vector<int> cols;
    for (int i; r < a.n && c < a.m; c++) {
        for (i = r; i < a.n; i++) {
            if (a[i][c]) {
                break;
            }
        }
        if (i == a.n) {
            continue;
        }
        if (i != r) {
            swap(b[i], b[r]);
            for (int j = 0; j < a.m; j++) {
                swap(a[i][j], a[r][j]);
            }
        }
        b[r] /= a[r][c];
        for (int j = a.m - 1; j >= c; j--) {
            a[r][j] /= a[r][c];
        }
        for (i = 0; i < a.n; i++) {
            if (i != r && a[i][c]) {
                b[i] -= a[i][c] * b[r];
                for (int j = a.m - 1; j >= c; j--) {
                    a[i][j] -= a[i][c] * a[r][j];
                }
            }
        }
        cols.push_back(c), r++;
    }
    // Verify system is not trivially bogus
    for (int i = 0; i < a.n; i++) {
        if (b[i]) {
            bool all_zero = true;
            for (int j = 0; j < a.m && all_zero; j++) {
                all_zero &= a[i][j] == T();
            }
            if (all_zero) {
                return std::nullopt;
            }
        }
    }
    vector<T> ans(a.m);
    for (int i = r - 1; i >= 0; i--) {
        ans[cols[i]] = b[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> graph(N, vector<int>(N, -1));
        vector<int> edges(M);
        for (int e = 0; e < M; e++) {
            int u, v, c;
            cin >> u >> v >> c, u--, v--;
            graph[u][v] = graph[v][u] = e;
            edges[e] = c;
        }

        vector<array<int, 3>> tris;

        for (int u = 0; u < N; u++) {
            for (int v = u + 1; v < N; v++) {
                if (-1 != graph[u][v]) {
                    for (int w = v + 1; w < N; w++) {
                        if (-1 != graph[u][w] && -1 != graph[v][w]) {
                            int uv = graph[u][v];
                            int vw = graph[v][w];
                            int wu = graph[w][u];
                            tris.push_back({uv, vw, wu});
                        }
                    }
                }
            }
        }

        int K = tris.size();

        using num = modnum<3>;
        mat<num> m(K, M);
        vector<num> b(K); // zeros
        for (int i = 0; i < K; i++) {
            for (int e : tris[i]) {
                if (edges[e] == -1) {
                    m[i][e] = +1;
                } else {
                    b[i] -= edges[e] - 1;
                }
            }
        }

        if (auto ans = solve_linear_system(m, b)) {
            for (int e = 0; e < M; e++) {
                if (edges[e] == -1) {
                    cout << 1 + int(ans->at(e)) << " \n"[e + 1 == M];
                } else {
                    cout << edges[e] << " \n"[e + 1 == M];
                }
            }
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}