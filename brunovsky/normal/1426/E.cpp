#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace {

struct frac {
    long n, d;

    constexpr frac() : n(0), d(1) {}
    constexpr frac(long num) : n(num), d(1) {}
    constexpr frac(long num, long den) : n(num), d(den) {
        auto g = gcd(n, d);
        g = ((g < 0) == (d < 0)) ? g : -g;
        n /= g, d /= g;
    }

    explicit operator bool() const noexcept { return n != 0 && d != 0; }
    explicit operator long() const noexcept { return assert(d != 0), n / d; }
    explicit operator double() const noexcept { return assert(d != 0), 1.0 * n / d; }

    friend frac abs(frac f) { return frac(abs(f.n), f.d); }
    friend long floor(frac f) { return f.n >= 0 ? f.n / f.d : (f.n - f.d + 1) / f.d; }
    friend long ceil(frac f) { return f.n >= 0 ? (f.n + f.d - 1) / f.d : f.n / f.d; }
    friend frac gcd(frac a, frac b) {
        while (a != 0) {
            b = b % a;
            swap(a, b);
        }
        return abs(b);
    }

    friend bool operator==(frac a, frac b) { return a.n == b.n && a.d == b.d; }
    friend bool operator!=(frac a, frac b) { return a.n != b.n || a.d != b.d; }
    friend bool operator<(frac a, frac b) { return a.n * b.d < b.n * a.d; }
    friend bool operator>(frac a, frac b) { return a.n * b.d > b.n * a.d; }
    friend bool operator<=(frac a, frac b) { return a.n * b.d <= b.n * a.d; }
    friend bool operator>=(frac a, frac b) { return a.n * b.d >= b.n * a.d; }

    friend frac operator+(frac a, frac b) {
        return frac(a.n * b.d + b.n * a.d, a.d * b.d);
    }
    friend frac operator-(frac a, frac b) {
        return frac(a.n * b.d - b.n * a.d, a.d * b.d);
    }
    friend frac operator*(frac a, frac b) { return frac(a.n * b.n, a.d * b.d); }
    friend frac operator/(frac a, frac b) { return frac(a.n * b.d, a.d * b.n); }
    friend frac operator%(frac a, frac b) { return a - long(a / b) * b; }
    friend frac& operator+=(frac& a, frac b) { return a = a + b; }
    friend frac& operator-=(frac& a, frac b) { return a = a - b; }
    friend frac& operator*=(frac& a, frac b) { return a = a * b; }
    friend frac& operator/=(frac& a, frac b) { return a = a / b; }
    friend frac& operator%=(frac& a, frac b) { return a = a % b; }

    friend frac operator-(frac f) { return frac(-f.n, f.d); }
    friend bool operator!(frac f) { return f.n == 0; }

    friend string to_string(frac f) {
        if (f.d == 0) {
            return f.n ? f.n > 0 ? "inf" : "-inf" : "undef";
        } else if (f.d == 1) {
            return to_string(f.n);
        } else {
            return to_string(f.n) + '/' + to_string(f.d);
        }
    }

    friend ostream& operator<<(ostream& out, frac f) { return out << to_string(f); }
};

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

    friend mat operator^(mat a, int e) {
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

    void assign(int N, int M, T&& val = T()) { n = N, m = M, arr.assign(N, vec(M, val)); }

    void set_row(int i, T&& val = T()) {
        for (int j = 0; j < m; j++)
            arr[i][j] = val;
    }

    void set_col(int j, T&& val = T()) {
        for (int i = 0; i < n; i++)
            arr[i][j] = val;
    }

    void add_row(int i, T&& add) {
        for (int j = 0; j < m; j++)
            arr[i][j] += add;
    }

    void add_col(int j, T&& add) {
        for (int i = 0; i < n; i++)
            arr[i][j] += add;
    }

    void mul_row(int i, T&& mul) {
        for (int j = 0; j < m; j++)
            arr[i][j] *= mul;
    }

    void mul_col(int j, T&& mul) {
        for (int i = 0; i < n; i++)
            arr[i][j] *= mul;
    }

    void div_row(int i, T&& div) {
        for (int j = 0; j < m; j++)
            arr[i][j] /= div;
    }

    void div_col(int j, T&& div) {
        for (int i = 0; i < n; i++)
            arr[i][j] /= div;
    }

    void mul_add_row(int i, int src, T&& mul) {
        for (int j = 0; j < m; j++)
            arr[i][j] += mul * arr[src][j];
    }

    void mul_add_col(int j, int src, T&& mul) {
        for (int i = 0; i < n; i++)
            arr[i][j] += mul * arr[i][src];
    }
};

enum LPState { LP_FEASIBLE = 0, LP_OPTIMAL = 1, LP_UNBOUNDED = 2, LP_IMPOSSIBLE = 3 };
enum LPConstraintType { LP_LESS = 0, LP_EQUAL = 1, LP_GREATER = 2 };

#define LP_TSW(type, le, eq, ge) (type == LP_EQUAL ? (eq) : type == LP_LESS ? (le) : (ge))

template <typename F>
struct lp_constraint {
    vector<F> v;
    F b;
    LPConstraintType type;
};

template <typename F>
struct simplex {
    using constraint_t = lp_constraint<F>;
    static inline const F inf = F(1, 0);

    int N = 0, M = 0; // num variables / num constraints
    vector<F> z;
    vector<constraint_t> C;

    void set_objective(vector<F> f) {
        assert(!N || N == int(f.size()));
        z = move(f), N = z.size();
    }

    void add_constraint(constraint_t constraint) {
        assert(N && int(constraint.v.size()) == N);
        C.push_back(move(constraint)), M++;
    }

    void add_constraints(const vector<constraint_t>& constraints) {
        for (const auto& constraint : constraints)
            add_constraint(constraint);
    }

    void clear() { N = M = 0, z.clear(), C.clear(); }

    int S = 0, A = 0; // slack and artificial variable count
    mat<F> tab;
    vector<int> var_to_row, row_to_var;

    int slackvar(int i) const { return --i, LP_TSW(C[i].type, 1, 0, -1); }
    int artifvar(int i) const {
        return --i, LP_TSW(C[i].type, -(C[i].b < 0), C[i].b >= 0 ? 1 : -1, C[i].b > 0);
    }
    void make_basic(int r, int c) {
        var_to_row[row_to_var[r]] = 0, var_to_row[c] = r, row_to_var[r] = c;
    }

    void pivot(int r, int c) {
        make_basic(r, c);
        tab.mul_row(r, 1 / tab[r][c]);
        for (int i = 0; i <= M; i++) {
            if (i != r) {
                tab.mul_add_row(i, r, -tab[i][c]);
            }
        }
    }

    LPState optimize() {
        int iterations = 0;
        do {
            int r = 0, c = min_element(begin(tab[0]) + 1, end(tab[0])) - begin(tab[0]);
            if (tab[0][c] >= 0) {
                return LP_OPTIMAL;
            }
            int bland = INT_MAX;
            F best = inf;
            for (int i = 1; i <= M; i++) {
                if (int j = row_to_var[i]; tab[i][c] > 0) {
                    auto ratio = tab[i][0] / tab[i][c];
                    if (0 <= ratio && (ratio < best || (ratio == best && j < bland))) {
                        best = ratio, r = i, bland = j;
                    }
                }
            }
            if (r == 0) {
                return LP_UNBOUNDED;
            }
            pivot(r, c);
        } while (++iterations < 100 * N * M);

        throw runtime_error("oops: simplex::optimize took too many iterations\n");
    }

    pair<LPState, F> compute() {
        S = A = 0;
        for (int i = 1; i <= M; i++) {
            S += slackvar(i) != 0, A += artifvar(i) != 0;
        }

        tab = mat<F>(M + 1, N + S + A + 1, 0);
        var_to_row.assign(N + S + A + 1, 0);
        row_to_var.assign(M + 1, 0);

        for (int i = 1, s = 1 + N, a = 1 + N + S; i <= M; i++) {
            const auto& [v, b, type] = C[i - 1];
            tab[i][0] = b;
            for (int j = 1; j <= N; j++) {
                tab[i][j] = v[j - 1];
            }
            if (int c = slackvar(i); c != 0) {
                make_basic(i, s);
                tab[i][s++] = F(c);
            }
            if (int c = artifvar(i); c != 0) {
                make_basic(i, a);
                tab.mul_add_row(0, i, -F(c));
                tab[i][a++] = F(c);
            }
            if (int j = row_to_var[i]; j != 0 && tab[i][j] != 1) {
                tab.mul_row(i, 1 / tab[i][j]);
            }
        }

        if (A > 0) {
            auto res = optimize();
            if (res != LP_OPTIMAL || tab[0][0] != 0) {
                assert(res == LP_OPTIMAL && tab[0][0] < 0);
                return {LP_IMPOSSIBLE, tab[0][0]};
            }

            for (int a = 1 + N + S; a <= N + S + A; a++) {
                row_to_var[var_to_row[a]] = 0;
            }
            tab.resize(M + 1, N + S + 1);
            for (int i = 1; i <= M; i++) {
                if (row_to_var[i])
                    continue;
                for (int j = 1; j <= N + S; j++) {
                    if (!var_to_row[j] && tab[i][j] != 0 && tab[i][0] / tab[i][j] >= 0) {
                        pivot(i, j);
                        break;
                    }
                }
            }
            tab.set_row(0, 0);
        }

        for (int j = 1; j <= N; j++) {
            tab[0][j] = -z[j - 1];
        }
        for (int j = 1; j <= N; j++) {
            if (int i = var_to_row[j]; i != 0) {
                tab.mul_add_row(0, i, -tab[0][j] * tab[i][j]);
            }
        }

        auto res = optimize();
        return {res, tab[0][0]};
    }

    vector<F> extract() const {
        vector<F> x(N, 0);
        for (int j = 1; j <= N; j++) {
            if (int r = var_to_row[j]; r != 0) {
                x[j - 1] = tab[r][0] / tab[r][j];
            }
        }
        return x;
    }
};

} // namespace

auto solve() {
    int n, a1, a2, a3, b1, b2, b3;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    assert(a1 + a2 + a3 == n && b1 + b2 + b3 == n);
    simplex<frac> smp;
    smp.set_objective({0, 1, 0, 0, 0, 1, 1, 0, 0});
    smp.add_constraint({{1, 1, 1, 0, 0, 0, 0, 0, 0}, a1, LP_EQUAL});
    smp.add_constraint({{0, 0, 0, 1, 1, 1, 0, 0, 0}, a2, LP_EQUAL});
    smp.add_constraint({{0, 0, 0, 0, 0, 0, 1, 1, 1}, a3, LP_EQUAL});
    smp.add_constraint({{1, 0, 0, 1, 0, 0, 1, 0, 0}, b1, LP_EQUAL});
    smp.add_constraint({{0, 1, 0, 0, 1, 0, 0, 1, 0}, b2, LP_EQUAL});
    smp.add_constraint({{0, 0, 1, 0, 0, 1, 0, 0, 1}, b3, LP_EQUAL});
    auto max_rounds = smp.compute().second;
    smp.set_objective({0, -1, 0, 0, 0, -1, -1, 0, 0});
    auto min_rounds = -smp.compute().second;
    cout << min_rounds << ' ' << max_rounds << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}