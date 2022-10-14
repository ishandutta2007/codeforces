#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct twosat_scc {
    int N, C = 0; // N is the number of variables, C number of components
    vector<array<int, 2>> g;
    vector<int> off, cmap;
    vector<int8_t> assignment;

    explicit twosat_scc(int N = 0) : N(N) {}

    int add_var() { return N++; }

    void either(int u, int v) {
        u = u < 0 ? 2 * ~u : 2 * u + 1;
        v = v < 0 ? 2 * ~v : 2 * v + 1;
        assert(0 <= u && u < 2 * N && 0 <= v && v < 2 * N);
        g.push_back({u ^ 1, v});
        g.push_back({v ^ 1, u});
    }

    void equal(int u, int v) { either(u, ~v), either(~u, v); }
    void opposite(int u, int v) { either(u, v), either(~u, ~v); }
    void implies(int u, int v) { either(~u, v); }
    void set(int u) { either(u, u); }

    void at_most_one(const vector<int>& vars) {
        int V = vars.size();
        if (V <= 1) {
            return;
        }
        int cur = ~vars[0];
        for (int i = 2; i < V; i++) {
            int next = add_var();
            either(cur, ~vars[i]);
            either(cur, next);
            either(~vars[i], next);
            cur = ~next;
        }
        either(cur, ~vars[1]);
    }

    vector<int> index, lowlink;
    vector<bool> onstack;
    stack<int> S;
    int depth;

    void dfs(int u) {
        index[u] = lowlink[u] = depth++;
        S.push(u), onstack[u] = true;

        for (int e = off[u]; e < off[u + 1]; e++) {
            int v = g[e][1];
            if (!index[v]) {
                dfs(v);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            } else if (onstack[v]) {
                lowlink[u] = min(lowlink[u], index[v]);
            }
        }

        if (index[u] == lowlink[u]) {
            int v, c = C++;
            do {
                v = S.top(), S.pop(), onstack[v] = false;
                cmap[v] = c;
                if (assignment[v >> 1] == -1)
                    assignment[v >> 1] = v & 1;
            } while (u != v);
        }
    }

    bool solve() {
        assignment.assign(N, -1);
        cmap.assign(2 * N, 0);
        index.assign(2 * N, 0);
        lowlink.assign(2 * N, 0);
        onstack.assign(2 * N, false);
        off.assign(2 * N + 1, 0);
        S = stack<int>();
        depth = 1, C = 0;

        sort(begin(g), end(g));

        for (auto [u, v] : g) {
            off[u + 1]++;
        }
        for (int u = 1; u <= 2 * N; u++) {
            off[u] += off[u - 1];
        }
        for (int u = 0; u < 2 * N; u++) {
            if (!index[u]) {
                dfs(u);
            }
        }
        for (int u = 0; u < N; u++) {
            assert(assignment[u] >= 0);
            if (cmap[2 * u] == cmap[2 * u + 1]) {
                return false;
            }
        }
        return true;
    }
};

struct lca_incremental {
    vector<int> parent, depth, jump;

    lca_incremental() = default;
    lca_incremental(int N) : parent(N, -1), depth(N), jump(N) {}
    lca_incremental(const vector<vector<int>>& tree, int root) { add_tree(tree, root); }

    void add_tree(const vector<vector<int>>& tree, int root) {
        add_root(root);
        for (int v : tree[root]) {
            dfs_tree(tree, v, root);
        }
    }

    int num_nodes() const { return parent.size(); }

    void add_root(int u) {
        ensure_new(u);
        parent[u] = u;
        depth[u] = 0;
        jump[u] = u;
    }

    void add_child(int p, int u) {
        ensure_new(u);
        parent[u] = p;
        depth[u] = depth[p] + 1;
        int t = jump[p];
        jump[u] = depth[p] + depth[jump[t]] == 2 * depth[t] ? jump[t] : p;
    }

    auto get_path(int u, int v) {
        int a = lca(u, v);
        int D = depth[u] - depth[a] + 1;
        vector<int> path;
        while (u != a) {
            path.push_back(u), u = parent[u];
        }
        path.push_back(a);
        while (v != a) {
            path.push_back(v), v = parent[v];
        }
        reverse(begin(path) + D, end(path));
        return path;
    }

    int ancestor(int u, int steps) const {
        assert(0 <= steps && steps <= depth[u]);
        int dest = depth[u] - steps;
        while (depth[u] > dest) {
            if (depth[jump[u]] < dest) {
                u = parent[u];
            } else {
                u = jump[u];
            }
        }
        return u;
    }

    // Assumes u and v in the same tree, edit this otherwise
    int lca(int u, int v) const {
        if (depth[u] < depth[v]) {
            v = ancestor(v, depth[v] - depth[u]);
        } else if (depth[u] > depth[v]) {
            u = ancestor(u, depth[u] - depth[v]);
        }
        while (u != v) {
            if (jump[u] == jump[v]) {
                u = parent[u], v = parent[v];
            } else {
                u = jump[u], v = jump[v];
            }
        }
        return u;
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

    bool conn(int u, int v) const {
        return ancestor(u, depth[u]) == ancestor(v, depth[v]);
    }

  private:
    void ensure_new(int N) {
        if (int M = parent.size(); N >= M) {
            parent.resize(N + 1, -1);
            depth.resize(N + 1);
            jump.resize(N + 1);
        } else {
            assert(parent[N] == -1);
        }
    }

    void dfs_tree(const vector<vector<int>>& tree, int u, int p) {
        add_child(p, u);
        for (int v : tree[u]) {
            if (v != p) {
                dfs_tree(tree, v, u);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    lca_incremental lca(tree, 0);

    vector<tuple<int, int, string>> queries(Q);
    for (auto& [u, v, s] : queries) {
        cin >> u >> v >> s, u--, v--;
    }

    vector<array<char, 2>> variants(N, {'.', '.'});
    for (auto& [u, v, s] : queries) {
        auto path = lca.get_path(u, v);
        int S = path.size();
        for (int i = 0; i < S; i++) {
            int n = path[i];
            char a = s[i];
            char b = s[S - i - 1];
            char c = variants[n][0];
            char d = variants[n][1];
            if (a == b || c == '.') {
                variants[n] = {a, b};
            }
        }
    }

    twosat_scc sat(N + Q);

    for (int q = 0; q < Q; q++) {
        auto& [u, v, s] = queries[q];
        int qid = N + q;
        auto path = lca.get_path(u, v);
        int S = s.size();
        for (int i = 0; i < S; i++) {
            int n = path[i];
            char a = s[i];
            char b = s[S - i - 1];
            char c = variants[n][0];
            char d = variants[n][1];
            // n => pick d / ~n => pick c
            assert(c != '.' && d != '.');
            if (a != c)
                sat.implies(~n, qid);
            if (a != d)
                sat.implies(n, qid);
            if (b != c)
                sat.implies(~n, ~qid);
            if (b != d)
                sat.implies(n, ~qid);
        }
    }

    bool ok = sat.solve();
    if (ok) {
        cout << "YES\n";
        string ans(N, 'a');
        for (int u = 0; u < N; u++) {
            if (variants[u][0] != '.') {
                ans[u] = variants[u][sat.assignment[u]];
            }
        }
        cout << ans << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}