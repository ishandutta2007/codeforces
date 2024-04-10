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

struct centroid_forest {
    vector<int> parent, depth, roots;

    explicit centroid_forest(const vector<vector<int>>& tree) {
        int N = tree.size();
        parent.assign(N, -1);
        depth.assign(N, -1);

        vector<int> subsize(N);

        auto subsize_dfs = y_combinator([&](auto self, int u, int p) -> void {
            subsize[u] = 1;
            for (int v : tree[u]) {
                if (v != p) {
                    self(v, u);
                    subsize[u] += subsize[v];
                }
            }
        });

        using P = pair<int, int>;
        auto dfs = y_combinator([&](auto self, int u, int p, int cp, int S) -> P {
            int processed = 0;

            bool changed;
            do {
                changed = false;
                for (int v : tree[u]) {
                    while (v != p && depth[v] == -1 && subsize[v] > S / 2) {
                        auto [more, root] = self(v, u, cp, S);
                        subsize[u] -= more;
                        S -= more;
                        processed += more;
                        cp = root;
                        changed = true;
                    }
                }
            } while (changed);

            // backtrack if u is not a centroid child of cp; else recurse on children
            if (S - subsize[u] > S / 2) {
                return make_pair(processed, cp);
            }

            parent[u] = cp;
            depth[u] = cp != -1 ? depth[cp] + 1 : 0;

            for (int v : tree[u]) {
                if (v != p && depth[v] == -1) {
                    self(v, u, u, subsize[v]);
                }
            }

            return make_pair(processed + subsize[u], u);
        });

        for (int u = 0; u < N; u++) {
            if (depth[u] == -1) {
                subsize_dfs(u, -1);
                dfs(u, -1, -1, subsize[u]);
            }
            if (parent[u] == -1) {
                roots.push_back(u);
            }
        }
    }

    int num_nodes() const { return parent.size(); }

    int ancestor(int u, int steps) const {
        while (steps--)
            u = parent[u];
        return u;
    }

    int below(int u, int a) const { return ancestor(u, depth[u] - depth[a] - 1); }

    int lca(int u, int v) const {
        while (depth[u] > depth[v])
            u = parent[u];
        while (depth[u] < depth[v])
            v = parent[v];
        while (u != v)
            u = parent[u], v = parent[v];
        return u;
    }

    int findroot(int u) const {
        while (parent[u] != -1)
            u = parent[u];
        return u;
    }

    bool conn(int u, int v) const { return findroot(u) == findroot(v); }
};

struct Func {
    int64_t a, b;
    Func(int64_t a, int64_t b) : a(a), b(b) {}
    int64_t eval(int t) const { return a * t + b; }
    static int64_t improv(const Func& f, const Func& g) {
        return (f.b - g.b + g.a - f.a - 1) / (g.a - f.a);
    }
    friend bool operator<(const Func& x, const Func& y) {
        return make_pair(x.a, x.b) < make_pair(y.a, y.b);
    }
    friend Func operator+(Func x, Func y) { return Func(x.a + y.a, x.b + y.b); }
};

using Options = vector<pair<int64_t, Func>>;
auto push_back_options(Options& opts, Func g, int M) {
    while (opts.size()) {
        auto [t, f] = opts.back();
        if (f.eval(t) <= g.eval(t)) {
            opts.pop_back();
        } else {
            break;
        }
    }
    int64_t t = opts.size() ? Func::improv(opts.back().second, g) : 0;
    if (t < M) {
        opts.emplace_back(t, g);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> tree(N);
    vector<vector<tuple<int, int, int>>> val_tree(N);
    for (int i = 1; i < N; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        val_tree[u].emplace_back(v, a, b);
        val_tree[v].emplace_back(u, a, b);
    }
    if (N == 1) {
        for (int i = 0; i < M; i++) {
            cout << 0 << " \n"[i + 1 == M];
        }
        return 0;
    }
    vector<int8_t> leaf(N);
    for (int i = 0; i < N; i++) {
        leaf[i] = tree[i].size() == 1u;
    }
    centroid_forest ctd(tree);

    vector<int64_t> A(N), B(N);
    vector<vector<int>> insubt(N);
    vector<Func> global;

    for (int r = 0; r < N; r++) {
        A[r] = B[r] = 0;
        vector<int> subts;
        auto prepare = y_combinator([&](auto self, int u, int p, int c) -> void {
            for (auto [v, a, b] : val_tree[u]) {
                if (v != p && ctd.depth[v] > ctd.depth[r]) {
                    A[v] = a + A[u], B[v] = b + B[u];
                    insubt[c].push_back(v);
                    self(v, u, c);
                }
            }
        });
        for (auto [c, a, b] : val_tree[r]) {
            if (ctd.depth[c] > ctd.depth[r]) {
                A[c] = a + A[r], B[c] = b + B[r];
                subts.push_back(c);
                insubt[c].clear();
                insubt[c].push_back(c);
                prepare(c, r, c);
            }
        }
        if (leaf[r]) {
            subts.push_back(r);
            insubt[r].clear();
            insubt[r].push_back(r);
        }

        int C = subts.size();
        vector<Options> fun;

        for (int c = 0; c < C; c++) {
            vector<Func> cand;
            for (int v : insubt[subts[c]]) {
                if (leaf[v]) {
                    cand.push_back(Func(A[v], B[v]));
                }
            }
            int S = cand.size();
            if (S == 0) {
                continue;
            }
            sort(begin(cand), end(cand));
            Options good;
            for (int i = 0; i < S; i++) {
                push_back_options(good, cand[i], M);
            }
            fun.push_back(move(good));
        }

        static mt19937 rng(random_device{}());
        shuffle(begin(fun), end(fun), rng);

        // We do small to large to avoid contracting cancer. Adds an extra log I think
        y_combinator([&](auto self, int l, int r) -> Options {
            if (l == r) {
                return {};
            } else if (l + 1 == r) {
                return move(fun[l]);
            }
            int m = (l + r) / 2;
            auto as = self(l, m);
            auto bs = self(m, r);
            int A = as.size();
            int B = bs.size();
            int a = 0, b = 0;
            global.push_back(as[a].second + bs[b].second);
            while (a + 1 < A || b + 1 < B) {
                int at = a + 1 == A ? M : as[a + 1].first;
                int bt = b + 1 == B ? M : bs[b + 1].first;
                if (at < bt) {
                    global.push_back(as[++a].second + bs[b].second);
                } else {
                    global.push_back(as[a].second + bs[++b].second);
                }
            }
            Options cs;
            a = b = 0;
            while (a < A || b < B) {
                if (b == B) {
                    push_back_options(cs, as[a++].second, M);
                } else if (a == A) {
                    push_back_options(cs, bs[b++].second, M);
                } else if (as[a].second < bs[b].second) {
                    push_back_options(cs, as[a++].second, M);
                } else {
                    push_back_options(cs, bs[b++].second, M);
                }
            }
            return cs;
        })(0, fun.size());
    }

    sort(begin(global), end(global));

    Options options;
    for (auto fn : global) {
        push_back_options(options, fn, M);
    }
    int O = options.size();

    for (int t = 0, i = 0; t < M; t++) {
        i += i + 1 < O && options[i + 1].first == t;
        cout << options[i].second.eval(t) << " \n"[t + 1 == M];
    }
    return 0;
}