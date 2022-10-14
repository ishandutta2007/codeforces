#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
        return frac(gcd(a.n, b.n), a.d * (b.d / gcd(a.d, b.d)));
    }

    friend bool operator==(frac a, frac b) { return a.n == b.n && a.d == b.d; }
    friend bool operator!=(frac a, frac b) { return a.n != b.n || a.d != b.d; }
    friend bool operator<(frac a, frac b) {
        return __int128(a.n) * b.d < __int128(b.n) * a.d;
    }
    friend bool operator>(frac a, frac b) {
        return __int128(a.n) * b.d > __int128(b.n) * a.d;
    }
    friend bool operator<=(frac a, frac b) {
        return __int128(a.n) * b.d <= __int128(b.n) * a.d;
    }
    friend bool operator>=(frac a, frac b) {
        return __int128(a.n) * b.d >= __int128(b.n) * a.d;
    }

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

namespace std {

template <>
struct hash<frac> {
    size_t operator()(frac f) const noexcept {
        size_t a = hash<long>{}(f.n), b = hash<long>{}(f.d);
        return (a + b) * (a + b + 1) / 2 + b;
    }
};

template <>
struct numeric_limits<frac> : numeric_limits<long> {
    using base_t = numeric_limits<long>;
    static constexpr bool is_specialized = true, is_integral = false, has_infinity = true;
    static constexpr frac min() { return frac(1, base_t::max()); }
    static constexpr frac max() { return frac(base_t::max(), 1); }
    static constexpr frac lowest() { return frac(base_t::lowest(), 1); }
    static constexpr frac epsilon() { return 0; }
    static constexpr frac infinity() { return frac(1, 0); }
};

} // namespace std

struct Point {
    frac x, y;
    int id;
    frac slope() const { return y / x; }
    frac lo() const { return y / (x + 1); }
    frac hi() const { return (y + 1) / x; }
};

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<Point> ps(N);
    for (int i = 0; i < N; i++) {
        long a, b, c, d;
        cin >> a >> b >> c >> d;
        ps[i] = {frac(a, b), frac(c, d), i + 1};
    }

    unordered_map<frac, int> slopeidmap;
    vector<array<int, 2>> ids(N);
    for (int i = 0; i < N; i++) {
        ids[i][0] = slopeidmap.emplace(ps[i].lo(), slopeidmap.size()).first->second;
        ids[i][1] = slopeidmap.emplace(ps[i].hi(), slopeidmap.size()).first->second;
    }

    int V = slopeidmap.size();
    vector<set<int>> onid(V);
    vector<vector<int>> adj(V);

    for (int i = 0; i < N; i++) {
        auto [u, v] = ids[i];
        assert(u != v);
        onid[u].insert(i);
        onid[v].insert(i);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> assigned(N);
    vector<array<int, 2>> solutions;
    vector<bool> vis(V);

    auto other = [&](int i, int u) { return u ^ ids[i][0] ^ ids[i][1]; };
    auto process = [&](int i, int j) {
        assert(!assigned[i] && !assigned[j] && i != j);
        assigned[i] = assigned[j] = true;
        solutions.push_back({i, j});

        auto [ui, vi] = ids[i];
        auto [uj, vj] = ids[j];
        onid[ui].erase(i);
        onid[vi].erase(i);
        onid[uj].erase(j);
        onid[vj].erase(j);
    };

    auto dfs = y_combinator([&](auto self, int u, int p) -> void {
        vis[u] = true;
        vector<int> up;
        for (int i : onid[u]) {
            if (other(i, u) == p) {
                up.push_back(i);
            }
        }
        for (int i : up) {
            onid[u].erase(i);
        }
        for (int v : adj[u]) {
            if (v != p && !vis[v]) {
                self(v, u);
            }
        }
        while (onid[u].size() > 1u) {
            int i = *onid[u].begin();
            int j = *++onid[u].begin();
            process(i, j);
        }
        up.erase(remove_if(begin(up), end(up), [&](int i) { return assigned[i]; }),
                 end(up));
        if (!onid[u].empty() && !up.empty()) {
            int i = *onid[u].begin();
            int j = up[0];
            process(i, j);
        }
    });

    for (int u = 0; u < V; u++) {
        if (!vis[u]) {
            dfs(u, -1);
        }
    }

    cout << solutions.size() << '\n';
    for (auto [a, b] : solutions) {
        cout << a + 1 << ' ' << b + 1 << '\n';
    }
    return 0;
}