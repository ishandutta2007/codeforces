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

    static int fit(int v) { return v >= mod ? v - mod : (v < 0 ? v + mod : v); }
    static int modinv(int v, int m = mod) {
        v %= m, assert(v);
        return v == 1 ? 1 : (m - 1LL * modinv(m, v) * m / v);
    }

    modnum inv() const { return {modinv(n)}; }
    modnum operator-() const { return {fit(n)}; }
    modnum operator+() const { return {n}; }
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

    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        return in >> v.n, v.n = fit(v.n % mod), in;
    }
};

using num = modnum<1'000'000'007>;

template <typename T>
struct mat {
    using vec = vector<T>;
    int n = 0, m = 0;
    vector<vec> arr;

    mat() = default;
    mat(int n, int m, const T& v = T()) : n(n), m(m), arr(n, vec(m, v)) {}
    mat(vector<vec> v) : n(v.size()), m(n ? v[0].size() : 0), arr(move(v)) {}

    array<int, 2> size() const { return {n, m}; }
    auto& operator[](int x) { return arr[x]; }
    const auto& operator[](int x) const { return arr[x]; }
    auto& operator[](array<int, 2> x) { return arr[x[0]][x[1]]; }
    const auto& operator[](array<int, 2> x) const { return arr[x[0]][x[1]]; }

    bool operator<(const mat& b) const { return tie(n, m, arr) < tie(b.n, b.m, b.arr); }
    bool operator>(const mat& b) const { return b < *this; }
    bool operator<=(const mat& b) const { return !(b < *this); }
    bool operator>=(const mat& b) const { return !(*this < b); }
    bool operator==(const mat& b) const { return n == b.n && m == b.m && arr == b.arr; }
    bool operator!=(const mat& b) const { return !(*this == b); }

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
        assert(a.n == b.n && a.m == b.m);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] += b[i][j];
        return a;
    }

    friend mat& operator-=(mat& a, const mat& b) {
        assert(a.n == b.n && a.m == b.m);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] -= b[i][j];
        return a;
    }

    friend mat operator+(mat a, const mat& b) { return a += b; }
    friend mat operator-(mat a, const mat& b) { return a -= b; }

    friend mat operator*(const mat& a, const mat& b) {
        assert(a.m == b.n && "Different matrix mul operand dimensions");
        mat c(a.n, b.m);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < a.m; k++)
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
        mat c = identity(a.n);
        while (e > 0) {
            if (e & 1)
                c = c * a;
            if (e >>= 1)
                a = a * a;
        }
        return c;
    }

    void resize(int N, int M, T&& val = T()) {
        if (n != N)
            arr.resize(N, vec(M, val));
        if (m != M)
            for (auto& row : arr)
                row.resize(M, val);
        n = N, m = M;
    }
};

int convert(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 'a';
    } else if ('A' <= c && c <= 'Z') {
        return c - 'A' + ('Z' - 'A' + 1);
    } else {
        assert(false);
    }
}

auto solve() {
    long N;
    int M, K;
    cin >> N >> M >> K;
    mat<num> paths(M, M);

    for (int u = 0; u < M; u++) {
        for (int v = 0; v < M; v++) {
            paths[u][v] = 1;
        }
    }

    vector<array<int, 2>> banned(K);
    for (auto& [u, v] : banned) {
        string s;
        cin >> s;
        assert(s.size() == 2u);
        u = convert(s[0]), v = convert(s[1]);
        paths[u][v] = 0;
    }

    if (N == 1) {
        return M;
    } else {
        paths = paths ^ (N - 1);
        num ans = 0;
        for (int u = 0; u < M; u++) {
            for (int v = 0; v < M; v++) {
                ans += paths[u][v];
            }
        }
        return ans.n;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}