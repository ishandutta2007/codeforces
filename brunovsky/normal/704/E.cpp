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

struct hld_forest {
    vector<int> subsize, parent, depth, roots, deepest;
    vector<int> heavy; // heavy child of this node, tree[u][0]
    vector<int> head;  // top of heavy path
    vector<int> time;  // index of node in preorder tour with no repetition

    explicit hld_forest(vector<vector<int>>& tree, int root = -1) {
        int N = tree.size();
        subsize.assign(N, 0);
        parent.assign(N, -1);
        heavy.assign(N, -1);
        depth.assign(N, 0);
        head.assign(N, 0);
        time.assign(N, 0);
        deepest.assign(N, -1);
        int timer = 0;

        auto dfs = y_combinator([&](auto self, int u, int p) -> void {
            subsize[u] = 1;
            int biggest = 0;
            for (int& v : tree[u]) {
                if (v != p) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    self(v, u);
                    subsize[u] += subsize[v];
                    if (biggest < subsize[v]) {
                        biggest = subsize[v];
                        heavy[u] = v;
                        swap(tree[u][0], v);
                    }
                }
            }
        });

        auto decompose = y_combinator([&](auto self, int u, int h) -> void {
            head[u] = h;
            time[u] = timer++;
            deepest[h] = u;
            for (int v : tree[u]) {
                if (v != parent[u]) {
                    self(v, v == heavy[u] ? h : v);
                }
            }
        });

        if (root != -1) {
            dfs(root, -1);
            decompose(root, root);
            roots.push_back(root);
        }
        for (int u = 0; u < N; u++) {
            if (subsize[u] == 0) {
                dfs(u, -1);
                decompose(u, u);
                roots.push_back(u);
            }
        }
    }

    int num_nodes() const { return subsize.size(); }

    int kth_ancestor(int u, int k) const {
        assert(0 <= k && k <= depth[u]);
        int dest = depth[u] - k;
        while (depth[u] > dest) {
            if (depth[head[u]] < dest) {
                u = parent[u];
            } else {
                u = head[u];
            }
        }
        return u;
    }

    int below(int u, int a) const { return kth_ancestor(u, depth[u] - depth[a] - 1); }

    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                u = parent[head[u]];
            } else {
                v = parent[head[v]];
            }
        }
        return depth[u] < depth[v] ? u : v;
    }

    int findroot(int u) const {
        while (parent[head[u]] != -1) {
            u = parent[head[u]];
        }
        return head[u];
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

    bool conn(int u, int v) const { return findroot(u) == findroot(v); }

    bool is_above(int a, int u) const {
        return time[a] <= time[u] && time[u] < time[a] + subsize[a];
    }

    bool is_above_on_heavy_path(int a, int u) const {
        return head[a] == head[u] && time[a] <= time[u];
    }

    bool on_path(int x, int u, int v) const {
        return is_above(lca(u, v), x) && (is_above(x, u) || is_above(x, v));
    }

    int heavy_node_length(int h) const { return depth[deepest[h]] - depth[h] + 1; }

    int kth_on_path(int u, int v, int k) const {
        int a = lca(u, v);
        if (k <= depth[u] - depth[a]) {
            return kth_ancestor(u, k);
        } else {
            return kth_ancestor(v, depth[u] + depth[v] - 2 * depth[a] - k);
        }
    }

    // Centroid and join of three nodes
    int join_node(int a, int b, int c) const {
        int x = lca(a, b), y = lca(b, c), z = lca(c, a);
        return x ^ y ^ z;
    }

    // Split the path from u to v into sorted heavy path segments [l,r), 0<=l<r<=N
    auto vertex_segments(int u, int v) const {
        vector<array<int, 2>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                ranges.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({time[u], time[v] + 1});
        } else {
            ranges.push_back({time[v], time[u] + 1});
        }
        return ranges;
    }

    // Split the path from u to v into sorted heavy path segments [l,r), 0<=l<r<=N
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_vertex_segments(int u, int v) const {
        vector<array<int, 2>> up, down;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                down.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({time[u], time[v] + 1});
        } else {
            up.push_back({time[v], time[u] + 1});
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // We consider edges here, so that vertex u is responsible for its parent edge
    auto edge_segments(int u, int v) const {
        vector<array<int, 2>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                ranges.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({time[u] + 1, time[v] + 1});
        } else if (depth[v] < depth[u]) {
            ranges.push_back({time[v] + 1, time[u] + 1});
        }
        return ranges;
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_edge_segments(int u, int v) const {
        vector<array<int, 2>> up, down;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({time[head[u]], time[u] + 1});
                u = parent[head[u]];
            } else {
                down.push_back({time[head[v]], time[v] + 1});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({time[u], time[v] + 1});
        } else if (depth[v] < depth[u]) {
            up.push_back({time[v], time[u] + 1});
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    auto cut_segments(int u, int v) const {
        vector<array<int, 3>> ranges;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                ranges.push_back({head[u], time[parent[head[u]]], time[u]});
                u = parent[head[u]];
            } else {
                ranges.push_back({head[v], time[parent[head[v]]], time[v]});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            ranges.push_back({head[v], time[u], time[v]});
        } else if (depth[v] < depth[u]) {
            ranges.push_back({head[u], time[v], time[u]});
        } else {
            ranges.push_back({head[u], time[u], time[u]}); // up or down doesn't matter
        }
        return ranges;
    }

    // Split the edge path from u to v into sorted heavy path segments [l,r), 1<=l<r<=N
    // down: l appears first on the path; up: l appears last on the path
    auto oriented_cut_segments(int u, int v) const {
        vector<array<int, 3>> down, up;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                up.push_back({head[u], time[head[u]] - 1, time[u]});
                u = parent[head[u]];
            } else {
                down.push_back({head[v], time[head[v]] - 1, time[v]});
                v = parent[head[v]];
            }
        }
        if (depth[u] < depth[v]) {
            down.push_back({head[u], time[u], time[v]});
        } else if (depth[v] < depth[u]) {
            up.push_back({head[u], time[v], time[u]});
        } else {
            up.push_back({head[u], time[u], time[u]}); // up or down doesn't matter
        }
        reverse(begin(down), end(down));
        return make_pair(move(up), move(down));
    }

    // Compute a minimal subtree that contains all the nodes with at most 2k-1 nodes
    auto compress_tree(vector<int> nodes) const {
        int k = nodes.size();
        auto cmp = [&](int a, int b) { return time[a] < time[b]; };
        sort(begin(nodes), end(nodes), cmp);

        for (int i = 0; i < k - 1; i++) {
            nodes.push_back(lca(nodes[i], nodes[i + 1]));
        }

        sort(begin(nodes) + k, end(nodes), cmp);
        inplace_merge(begin(nodes), begin(nodes) + k, end(nodes), cmp);
        nodes.erase(unique(begin(nodes), end(nodes)), end(nodes));
        k = nodes.size();

        vector<pair<int, int>> compressed_tree = {{nodes[0], -1}};
        for (int i = 1; i < k; i++) {
            compressed_tree.push_back({nodes[i], lca(nodes[i - 1], nodes[i])});
        }
        return compressed_tree;
    }
};

template <typename T>
struct quot {
    using unit_type = T;
    static inline const quot<T> inf = {1, 0};
    T n, d; // n/d

    quot() : n(0), d(1) {}
    quot(T num) : n(num), d(1) {}
    quot(T num, T den) : n(den >= 0 ? num : -num), d(den >= 0 ? den : -den) {}

    explicit operator bool() const noexcept { return n != 0 && d != 0; }
    explicit operator T() const noexcept { return assert(d), n / d; }
    explicit operator double() const noexcept { return assert(d), double(n) / d; }

    static int sign(T x) { return x > 0 ? +1 : x < 0 ? -1 : 0; }
    static bool undefined(quot f) { return f.n == 0 && f.d == 0; }
    static int infsign(quot f) { return f.d == 0 ? sign(f.n) : 0; }

    friend quot abs(quot f) { return quot(abs(f.n), f.d); }
    friend quot inv(quot f) { return quot(f.d, f.n); }
    friend T floor(quot f) { return f.n >= 0 ? f.n / f.d : (f.n - f.d + 1) / f.d; }
    friend T ceil(quot f) { return f.n >= 0 ? (f.n + f.d - 1) / f.d : f.n / f.d; }

    friend bool operator==(quot a, quot b) { return compare(a, b) == 0; }
    friend bool operator!=(quot a, quot b) { return compare(a, b) != 0; }
    friend bool operator<(quot a, quot b) { return compare(a, b) < 0; }
    friend bool operator>(quot a, quot b) { return compare(a, b) > 0; }
    friend bool operator<=(quot a, quot b) { return compare(a, b) <= 0; }
    friend bool operator>=(quot a, quot b) { return compare(a, b) >= 0; }

    static int compare(quot a, quot b) {
        if (a.d == 0 || b.d == 0) {
            return infsign(a) - infsign(b);
        }
        T x = floor(a), y = floor(b);
        while (x == y) {
            a.n -= x * a.d;
            b.n -= y * b.d;
            if (a.n == 0 || b.n == 0) {
                return sign(a.n - b.n);
            }
            swap(a.n, b.d), swap(a.d, b.n);
            x = a.n / a.d, y = b.n / b.d;
        }
        return sign(x - y);
    }

    friend quot operator+(quot a, quot b) {
        if (a.d == b.d) {
            return quot(a.n + b.n, a.d);
        } else if (a.d == 0 || b.d == 0) {
            return a.d == 0 ? a : b;
        } else if (a.d < b.d && b.d % a.d == 0) {
            return quot(a.n * (b.d / a.d) + b.n, b.d);
        } else if (a.d > b.d && a.d % b.d == 0) {
            return quot(a.n + b.n * (a.d / b.d), a.d);
        } else {
            return quot(a.n * b.d + b.n * a.d, a.d * b.d);
        }
    }
    friend quot operator-(quot a, quot b) { return a + (-b); }
    friend quot operator*(quot a, quot b) {
        if (a.n == b.d) {
            return quot(b.n, a.d);
        } else if (a.d == b.n) {
            return quot(a.n, b.d);
        } else {
            return quot(a.n * b.n, a.d * b.d);
        }
    }
    friend quot operator/(quot a, quot b) { return a * inv(b); }
    friend quot operator%(quot a, quot b) { return a - T(a / b) * b; }
    friend quot& operator+=(quot& a, quot b) { return a = a + b; }
    friend quot& operator-=(quot& a, quot b) { return a = a - b; }
    friend quot& operator*=(quot& a, quot b) { return a = a * b; }
    friend quot& operator/=(quot& a, quot b) { return a = a / b; }
    friend quot& operator%=(quot& a, quot b) { return a = a % b; }

    friend quot operator-(quot f) { return quot(-f.n, f.d); }
    friend bool operator!(quot f) { return f.n == 0; }

    friend string to_string(quot f) {
        if (f.d == 0) {
            return f.n ? f.n > 0 ? "inf" : "-inf" : "undef";
        } else if (f.d == 1) {
            return to_string(f.n);
        } else {
            return to_string(f.n) + '/' + to_string(f.d);
        }
    }

    friend ostream& operator<<(ostream& out, quot f) { return out << to_string(f); }
};

using F = quot<int64_t>;

struct Suit {
    static inline F global; // simulation time
    F t;
    int s, l, r, k;
    bool rightwards;

    auto fn() const {
        return rightwards ? make_pair(+s, l - t * s) : make_pair(-s, r + t * s);
    }

    auto vanish() const { return t + F(r - l, s); }

    bool within(F ti) const { return t <= ti && ti <= vanish(); }

    static auto collision(const Suit& a, const Suit& b) {
        auto [ma, ca] = a.fn();
        auto [mb, cb] = b.fn();
        auto t = F(cb - ca) / F(ma - mb);
        if (ca == cb && ma == mb) {
            return max(a.t, b.t);
        }
        if (ca != cb && ma == mb) {
            return F::inf;
        }
        return a.within(t) && b.within(t) ? t : F::inf;
    }

    static bool by_start_time(const Suit& a, const Suit& b) {
        return make_pair(a.t, a.k) < make_pair(b.t, b.k);
    }

    friend bool operator<(const Suit& a, const Suit& b) {
        auto [ma, ca] = a.fn();
        auto [mb, cb] = b.fn();
        return make_pair(ma * global + ca, a.k) < make_pair(mb * global + cb, b.k);
    }

#ifdef LOCAL
    friend string to_string(Suit x) {
        return format("(t={} s={} [{},{}] {} {})", //
                      x.t, x.s, x.l, x.r, "<>"[x.rightwards], x.k);
    }
    friend ostream& operator<<(ostream& out, Suit x) { return out << to_string(x); }
#endif
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<array<int, 4>> tree_suits(M);
    for (auto& [t, c, u, v] : tree_suits) {
        cin >> t >> c >> u >> v, u--, v--;
    }
    sort(begin(tree_suits), end(tree_suits));

    hld_forest hld(tree, 0);

    vector<vector<Suit>> suits(N);
    for (int i = 0; i < M; i++) {
        auto [t, c, u, v] = tree_suits[i];
        auto [up, down] = hld.oriented_cut_segments(u, v);
        F time = t;
        for (auto [s, l, r] : up) {
            suits[s].push_back({time, c, l, r, 0, false});
            time += F(r - l, c);
        } // false: we go from r to l
        for (auto [s, l, r] : down) {
            suits[s].push_back({time, c, l, r, 0, true});
            time += F(r - l, c);
        } // true: we go from l to r
    }

    F ans = F::inf;

    for (int s = 0; s < N; s++) {
        int K = suits[s].size();
        sort(begin(suits[s]), end(suits[s]), Suit::by_start_time);
        for (int i = 0; i < K; i++) {
            suits[s][i].k = i;
        }

        set<Suit> suitset;
        using Event = pair<F, int>;
        priority_queue<Event, vector<Event>, greater<Event>> heap;

        auto collide_after = [&](auto x) {
            if (x != end(suitset) && next(x) != end(suitset)) {
                auto y = next(x);
                auto time = Suit::collision(*x, *y);
                if (time < F::inf) {
                    heap.emplace(time, x->k);
                    ans = min(ans, time);
                }
            }
        };
        auto collide_before = [&](auto y) {
            if (y != begin(suitset) && y != end(suitset)) {
                auto x = prev(y);
                auto time = Suit::collision(*x, *y);
                if (time < F::inf) {
                    heap.emplace(time, x->k);
                    ans = min(ans, time);
                }
            }
        };
        auto flush_heap = [&](F endtime) {
            while (!heap.empty() && heap.top().first < endtime) {
                auto [time, j] = heap.top();
                heap.pop();
                auto pos = suitset.find(suits[s][j]);
                Suit::global = time;
                if (pos != end(suitset)) {
                    pos = suitset.erase(pos);
                    collide_before(pos);
                }
            }
        };

        for (int i = 0; i < K; i++) {
            auto [at, ac, al, ar, ab, ak] = suits[s][i];
            flush_heap(at);
            Suit::global = at;
            auto pos = suitset.insert(suits[s][i]).first;
            collide_before(pos);
            collide_after(pos);
            heap.emplace(suits[s][i].vanish(), i);
        }

        flush_heap(F::inf);
    }

    if (ans < F::inf) {
        cout << setprecision(9) << showpoint << fixed;
        cout << double(ans) << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}