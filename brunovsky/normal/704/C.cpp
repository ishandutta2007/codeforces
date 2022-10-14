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
    constexpr modnum &operator++() { return n = fit(n + 1), *this; }
    constexpr modnum &operator--() { return n = fit(MOD + n - 1), *this; }
    constexpr modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum &operator-=(modnum v) { return n = fit(MOD + n - v.n), *this; }
    constexpr modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % MOD, *this; }
    constexpr modnum &operator/=(modnum v) { return *this *= v.inv(); }

    friend constexpr modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend constexpr modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend constexpr modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend constexpr modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream &operator<<(ostream &out, modnum v) { return out << v.n; }
    friend istream &operator>>(istream &in, modnum &v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

using num = modnum<1'000'000'007>;
using Clause = array<int, 2>;
using DP3 = array<array<array<num, 2>, 2>, 2>;
using DP1 = array<num, 2>;

int eval(int sign, int var) {
    return assert(sign == 0 || sign == 1), sign ? var > 0 : var < 0;
}

int get(Clause c, int var, bool required = true) {
    auto [u, v] = c;
    assert(abs(u) != abs(v));
    if (abs(u) == var) {
        return u;
    } else if (abs(v) == var) {
        return v;
    } else {
        assert(!required);
        return 0;
    }
}

int csize(Clause c) { return 1 + (c[1] != 0); }

auto combine1(DP1 a, DP1 b) {
    return DP1{a[0] * b[0] + a[1] * b[1], a[0] * b[1] + a[1] * b[0]};
}

auto extend3(DP3 dp, Clause c, int ahead, int prior) {
    DP3 ans = {};
    int av = get(c, ahead);
    int pv = get(c, prior);
    for (int v : {0, 1}) {             // value of prefix of clauses
        for (int f : {0, 1}) {         // value of first variable
            for (int l : {0, 1}) {     // value of prior variable
                for (int x : {0, 1}) { // value of ahead variable
                    int c = eval(l, pv) | eval(x, av);
                    ans[v ^ c][f][x] += dp[v][f][l];
                }
            }
        }
    }
    return ans;
}

auto fix3(DP3 dp, Clause c, int prior) {
    DP3 ans = {};
    int pv = get(c, prior);
    for (int v : {0, 1}) {         // value of prefix of clauses
        for (int f : {0, 1}) {     // value of first variable
            for (int l : {0, 1}) { // value of prior variable
                int c = eval(l, pv);
                ans[v ^ c][f][l] += dp[v][f][l];
            }
        }
    }
    return ans;
}

auto head3(DP3 dp, Clause c, int head, int first) {
    DP3 ans = {};
    int hv = get(c, head);
    int fv = get(c, first);
    for (int v : {0, 1}) {                             // value of prefix of clauses
        for (int f : {0, 1}) {                         // value of first variable
            for (int l : {0, 1}) {                     // value of last variable
                for (int h : {0, 1}) {                 // value of head
                    int c = eval(f, fv);               // previously it was this
                    int d = eval(f, fv) | eval(h, hv); // now we consider this
                    int o = c ^ d;
                    ans[v ^ o][f][l] += dp[v][f][l];
                }
            }
        }
    }
    return ans;
}

auto tail3(DP3 dp, Clause c, int tail, int last) {
    DP3 ans = {};
    int tv = get(c, tail);
    int lv = get(c, last);
    for (int v : {0, 1}) {                             // value of prefix of clauses
        for (int f : {0, 1}) {                         // value of first variable
            for (int l : {0, 1}) {                     // value of last variable
                for (int t : {0, 1}) {                 // value of tail
                    int c = eval(l, lv);               // previously it was this
                    int d = eval(l, lv) | eval(t, tv); // now we consider this
                    int o = c ^ d;
                    ans[v ^ o][f][l] += dp[v][f][l];
                }
            }
        }
    }
    return ans;
}

auto wrap3(DP3 dp, Clause cf, Clause cl, int wrap, int first, int last) {
    DP3 ans = {};
    int wvf = get(cf, wrap);
    int wvl = get(cl, wrap);
    int fv = get(cf, first);
    int lv = get(cl, last);
    for (int v : {0, 1}) {             // value of prefix of clauses
        for (int f : {0, 1}) {         // value of first variable
            for (int l : {0, 1}) {     // value of last variable
                for (int w : {0, 1}) { // value of wrap
                    int a = eval(f, fv);
                    int b = eval(l, lv);
                    int c = eval(f, fv) | eval(w, wvf);
                    int d = eval(l, lv) | eval(w, wvl);
                    int o = a ^ b ^ c ^ d;
                    ans[v ^ o][f][l] += dp[v][f][l];
                }
            }
        }
    }
    return ans;
}

auto extract3(DP3 dp) {
    DP1 ans = {};
    for (int v : {0, 1}) {
        for (int f : {0, 1}) {
            for (int e : {0, 1}) {
                ans[v] += dp[v][f][e];
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<Clause> clauses(N);
    vector<vector<int>> where(M + 1);
    for (int i = 0; i < N; i++) {
        auto &[x, y] = clauses[i];
        if (int t; cin >> t, t == 1) {
            cin >> x;
            where[abs(x)].push_back(i);
        } else if (t == 2) {
            cin >> x >> y;
            where[abs(x)].push_back(i);
            where[abs(y)].push_back(i);
        } else {
            assert(false);
        }
    }
    for (int i = 0; i < N; i++) {
        auto &[u, v] = clauses[i];
        if (where[abs(u)].size() < where[abs(v)].size()) {
            swap(u, v);
        }
    }

    DP1 ans = {1, 0};
    vector<vector<int>> adj(N);
    vector<bool> clause_used(N), variable_seen(M + 1);
    vector<vector<Clause>> paths, cycles;

    for (int v = 1; v <= M; v++) {
        if (where[v].size() == 2u) {
            int a = where[v][0], b = where[v][1];
            if (a != b) {
                adj[a].push_back(b);
                adj[b].push_back(a);
            } else {
                if (clauses[a][0] == clauses[a][1]) {
                    ans = combine1(ans, DP1{1, 1});
                } else {
                    ans = combine1(ans, DP1{0, 2});
                }
                clause_used[a] = true;
            }
        }
    }

    auto get_not_seen = [&](Clause clause) {
        auto [u, v] = clause;
        int w = variable_seen[abs(u)] ? abs(v) : abs(u);
        assert(w && !variable_seen[w]);
        return w;
    };

    for (int u = 0; u < N; u++) {
        int A = adj[u].size();
        if (clause_used[u]) {
            continue;
        } else if (A == 0) {
            if (csize(clauses[u]) == 1) {
                ans = combine1(ans, DP1{1, 1});
            } else {
                ans = combine1(ans, DP1{1, 3});
            }
            clause_used[u] = true;
        } else if (A == 1) {
            int v = adj[u][0], S = 2;
            vector<int> path = {u, v};
            while (adj[v].size() == 2u) {
                v = path[S++ - 2] ^ adj[v][0] ^ adj[v][1];
                path.push_back(v);
            }
            vector<Clause> cls;
            for (int w : path) {
                clause_used[w] = true;
                cls.push_back(clauses[w]);
            }
            paths.push_back(move(cls));
        }
    }
    for (int u = 0; u < N; u++) {
        int A = adj[u].size();
        if (A == 2 && !clause_used[u]) {
            int v = adj[u][0], S = 1;
            vector<int> cycle = {u};
            while (v != u) {
                cycle.push_back(v);
                v = cycle[S++ - 1] ^ adj[v][0] ^ adj[v][1];
            }
            vector<Clause> cls;
            for (int w : cycle) {
                clause_used[w] = true;
                cls.push_back(clauses[w]);
            }
            cycles.push_back(move(cls));
        }
    }

    for (auto &path : paths) {
        int S = path.size() - 1;
        int head = abs(path[0][1]);
        int tail = abs(path[S][1]);
        variable_seen[head] = variable_seen[tail] = true;

        vector<int> twice;
        for (int i = 0; i < S; i++) {
            int u = get_not_seen(path[i]);
            variable_seen[u] = true;
            twice.push_back(u);
        }

        int first = twice[0];
        int last = twice[S - 1];
        DP3 dp = {};
        for (int f : {0, 1}) {
            int fv = get(path[0], first);
            int o = eval(f, fv);
            dp[o][f][f] = 1;
        }

        for (int i = 1; i < S; i++) {
            dp = extend3(dp, path[i], twice[i], twice[i - 1]);
        }
        dp = fix3(dp, path[S], last);
        if (head) {
            dp = head3(dp, path[0], head, first);
        }
        if (tail) {
            dp = tail3(dp, path[S], tail, last);
        }
        ans = combine1(ans, extract3(dp));
    }

    for (auto &cycle : cycles) {
        int S = cycle.size() - 1;
        int wrap = abs(cycle[0][0]);
        if (!get(cycle[S], wrap, false)) {
            wrap = abs(cycle[0][1]);
            assert(S == 1 || !get(cycle[1], wrap, false));
            assert(get(cycle[S], wrap, false));
        }
        variable_seen[wrap] = true;

        vector<int> twice;
        for (int i = 0; i < S; i++) {
            int u = get_not_seen(cycle[i]);
            variable_seen[u] = true;
            twice.push_back(u);
        }

        int first = twice[0];
        int last = twice[S - 1];
        DP3 dp = {};
        for (int f : {0, 1}) {
            int fv = get(cycle[0], first);
            int o = eval(f, fv);
            dp[o][f][f] = 1;
        }

        for (int i = 1; i < S; i++) {
            dp = extend3(dp, cycle[i], twice[i], twice[i - 1]);
        }
        dp = fix3(dp, cycle[S], last);
        dp = wrap3(dp, cycle[0], cycle[S], wrap, first, last);
        ans = combine1(ans, extract3(dp));
    }

    num count = ans[1];
    for (int v = 1; v <= M; v++) {
        if (where[v].empty()) {
            count *= 2;
        }
    }
    cout << count << '\n';
    return 0;
}