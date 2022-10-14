#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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
using num = modnum<998244353>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int U, V, M;
    cin >> U >> V >> M;

    vector<array<int, 2>> edges(M);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
        u--, v--;
    }

    int Q;
    cin >> Q;

    vector<num> pow2(M + Q + 1);
    pow2[0] = 1;
    for (int i = 1; i <= M + Q; i++) {
        pow2[i] = 2 * pow2[i - 1];
    }

    vector<int> deg[2];
    deg[0].resize(U), deg[1].resize(V);
    for (auto [u, v] : edges) {
        deg[0][u]++, deg[1][v]++;
    }

    vector<set<int>> adj[2];
    adj[0].resize(U), adj[1].resize(V);

    for (int e = 0; e < M; e++) {
        auto [u, v] = edges[e];
        adj[0][u].insert(e);
        adj[1][v].insert(e);
    }

    const array<int, 2> NONE = {-1, -1};
    vector<array<int, 2>> index[2];
    index[0].assign(U, NONE);
    index[1].assign(V, NONE);

    vector<list<int>> paths; // sequence of edges
    vector<array<num, 2>> phash;
    vector<array<array<int, 2>, 2>> endp;
    int P = paths.size();

    for (int side : {0, 1}) {
        for (int u = 0; u < (side == 0 ? U : V); u++) {
            if (adj[side][u].size() % 2 == 1) {
                int a = u, s = side;

                paths.push_back({});
                phash.push_back({0, 0});
                endp.push_back({NONE, NONE});

                index[s][a] = {P, 0};
                endp[P][0] = {a, s};

                do {
                    int e = *adj[s][a].begin();
                    int l = paths[P].size() % 2;
                    paths[P].push_back(e);
                    phash[P][l] += pow2[e + 1];

                    int b = edges[e][!s];
                    adj[s][a].erase(e);
                    adj[!s][b].erase(e);

                    s = !s, a = b;
                } while (adj[s][a].size() % 2 == 1);

                index[s][a] = {P, 1};
                endp[P][1] = {a, s};
                P++;
            }
        }
    }

    vector<int> reds;
    num global_hash = 0;

    for (int p = 0; p < P; p++) {
        global_hash += phash[p][0];
    }

    // Now decompose into cycles
    for (int u = 0, s = 0; u < U; u++) {
        assert(adj[s][u].size() % 2 == 0);

        while (!adj[s][u].empty()) {
            int a = u;
            do {
                int e = *adj[s][a].begin();
                int b = edges[e][!s];
                adj[s][a].erase(e);
                adj[!s][b].erase(e);

                reds.push_back(e);
                global_hash += pow2[e + 1];

                e = *adj[!s][b].begin();
                a = edges[e][s];
                adj[s][a].erase(e);
                adj[!s][b].erase(e);
            } while (a != u);
        }
    }

    auto answer_edges = [&]() {
        int R = reds.size();
        for (int p = 0; p < P; p++) {
            bool yes = true;
            for (int u : paths[p]) {
                if (yes) {
                    reds.push_back(u);
                }
                yes = !yes;
            }
        }
        int M = reds.size();
        num val = 0;
        cout << M << '\n';
        for (int i = 0; i < M; i++) {
            val += pow2[reds[i] + 1];
            cout << 1 + reds[i] << " \n"[i + 1 == M];
        }
        cout.flush();
        reds.resize(R);
        assert(val == global_hash);
    };

    auto flip_path = [&](int p) {
        global_hash -= phash[p][0];
        paths[p].reverse();
        int l = paths[p].size() % 2;
        if (l == 0) {
            swap(phash[p][0], phash[p][1]);
        }
        swap(endp[p][0], endp[p][1]);
        auto [a, sa] = endp[p][0];
        index[sa][a] = {p, 0};
        auto [b, sb] = endp[p][1];
        index[sb][b] = {p, 1};
        global_hash += phash[p][0];
    };

    auto merge_paths = [&](int p, int e, int q) {
        debug("merge");
        global_hash -= phash[p][0] + phash[q][0];
        int l = paths[p].size() % 2;
        paths[p].push_back(e);
        phash[p][l] += pow2[e + 1];
        l = paths[p].size() % 2;
        paths[p].splice(end(paths[p]), paths[q]);
        phash[p][0] += phash[q][l];
        phash[p][1] += phash[q][l ^ 1];
        auto [a, sa] = endp[p][1];
        index[sa][a] = NONE;
        auto [b, sb] = endp[q][0];
        index[sb][b] = NONE;
        auto [c, sc] = endp[q][1];
        index[sc][c] = {p, 1};
        endp[p][1] = {c, sc};
        global_hash += phash[p][0];
        paths[q].clear();
        endp[q] = {NONE, NONE};
        phash[q] = {0, 0};
    };

    auto add_path = [&](int e) {
        debug("add");
        auto [u, v] = edges[e];
        global_hash += pow2[e + 1];
        int p = P++;
        paths.push_back({e});
        phash.push_back({pow2[e + 1], 0});
        endp.push_back({{{u, 0}, {v, 1}}});
        index[0][u] = {p, 0};
        index[1][v] = {p, 1};
    };

    auto push_front = [&](int p, int u, int s, int e) {
        debug("front");
        global_hash -= phash[p][0];
        paths[p].push_front(e);
        swap(phash[p][0], phash[p][1]);
        phash[p][0] += pow2[e + 1];
        auto [a, sa] = endp[p][0];
        index[sa][a] = NONE;
        endp[p][0] = {u, s};
        index[s][u] = {p, 0};
        global_hash += phash[p][0];
    };

    auto push_back = [&](int p, int u, int s, int e) {
        debug("back");
        global_hash -= phash[p][0];
        int l = paths[p].size() % 2;
        paths[p].push_back(e);
        phash[p][l] += pow2[e + 1];
        auto [a, sa] = endp[p][1];
        index[sa][a] = NONE;
        endp[p][1] = {u, s};
        index[s][u] = {p, 1};
        global_hash += phash[p][0];
    };

    auto close_path = [&](int p, int e) {
        paths[p].push_back(e);
        auto [a, sa] = endp[p][0];
        index[sa][a] = NONE;
        auto [b, sb] = endp[p][1];
        index[sb][b] = NONE;
        endp[p] = {NONE, NONE};
    };

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int du = deg[0][u] % 2;
            int dv = deg[1][v] % 2;

            int e = M++;
            edges.push_back({u, v});

            if (du == 0 && dv == 0) {
                add_path(e);
            } else if (du == 0 && dv == 1) {
                auto [p, x] = index[1][v];
                assert(p != -1);
                if (x == 0) {
                    push_front(p, u, 0, e);
                } else {
                    push_back(p, u, 0, e);
                }
            } else if (du == 1 && dv == 0) {
                auto [p, x] = index[0][u];
                assert(p != -1);
                if (x == 0) {
                    push_front(p, v, 1, e);
                } else {
                    push_back(p, v, 1, e);
                }
            } else {
                auto [pu, xu] = index[0][u];
                auto [pv, xv] = index[1][v];
                assert(pu != -1);
                assert(pv != -1);
                if (pu != pv) {
                    if (xu == 1 && xv == 0) {
                        merge_paths(pu, e, pv);
                    } else if (xu == 0 && xv == 1) {
                        merge_paths(pv, e, pu);
                    } else if (xu == 0 && xv == 0) {
                        if (paths[pu].size() < paths[pv].size()) {
                            flip_path(pu);
                            merge_paths(pu, e, pv);
                        } else {
                            flip_path(pv);
                            merge_paths(pv, e, pu);
                        }
                    } else if (xv == 1 && xv == 1) {
                        if (paths[pu].size() < paths[pv].size()) {
                            flip_path(pu);
                            merge_paths(pv, e, pu);
                        } else {
                            flip_path(pv);
                            merge_paths(pu, e, pv);
                        }
                    } else {
                        assert(false);
                    }
                } else {
                    close_path(pu, e);
                }
            }

            deg[0][u]++, deg[1][v]++;
            assert(deg[0][u] % 2 == 1 || index[0][u] == NONE);
            assert(deg[1][v] % 2 == 1 || index[1][v] == NONE);
            cout << global_hash << endl;
        } else if (t == 2) {
            answer_edges();
        } else {
            assert(false);
        }
    }

    return 0;
}