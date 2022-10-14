#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T, typename V>
struct merging_interval_processor : map<array<T, 2>, V> {
    static constexpr inline T inf = numeric_limits<T>::max();
    using run_t = array<T, 2>;
    using base_t = map<array<T, 2>, V>;

    run_t universe() const {
        return {base_t::begin()->first[0], base_t::rbegin()->first[1]};
    }

    template <typename Fn>
    void write(run_t intv, V color, Fn&& processor) {
        auto& [L, R] = intv;
        if (L >= R) {
            return;
        }
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::upper_bound({R, inf});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[1] > R) {
                if (phi->second == color) { // extend new rightwards, removing old
                    R = phi->first[1];
                } else if (phi->first[0] < L) { // splice
                    auto [x, y] = phi->first;
                    auto red = phi->second;
                    processor(intv, red);
                    base_t::erase(phi);
                    base_t::emplace_hint(hi, run_t{x, L}, red);
                    base_t::emplace_hint(hi, run_t{L, R}, color);
                    base_t::emplace_hint(hi, run_t{R, y}, red);
                    return;
                } else { // cut old rightwards and don't remove it
                    if (phi->first[0] < R) {
                        processor(run_t{phi->first[0], R}, phi->second);
                        const_cast<T&>(phi->first[0]) = R;
                    }
                    hi = phi;
                }
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] >= L) {
                if (plo->second == color) { // extend new leftwards, removing old
                    L = plo->first[0], lo = plo;
                } else if (plo->first[0] < L) { // cut old leftwards and don't remove it
                    if (plo->first[1] > L) {
                        processor(run_t{L, plo->first[1]}, plo->second);
                        const_cast<T&>(plo->first[1]) = L;
                    }
                } else { // just cut old
                    lo = plo;
                }
            }
        }
        for (auto it = lo; it != hi; ++it) {
            if (it->second != color) {
                processor(it->first, it->second);
            }
        }
        base_t::erase(lo, hi);
        base_t::emplace_hint(hi, intv, color);
    }
    void write(run_t intv, V color) {
        write(intv, color, [](auto, const auto&) {});
    }

    template <typename Fn>
    void cut(run_t intv, Fn&& processor) {
        auto& [L, R] = intv;
        if (L >= R) {
            return;
        }
        auto lo = base_t::lower_bound({L, L});
        auto hi = base_t::lower_bound({R, R});
        if (hi != base_t::begin()) {
            if (auto phi = prev(hi); phi->first[0] < L && phi->first[1] > R) { // splice
                auto [x, y] = phi->first;
                auto color = phi->second;
                processor(intv, color);
                base_t::erase(phi);
                base_t::emplace_hint(hi, run_t{x, L}, color);
                base_t::emplace_hint(hi, run_t{R, y}, color);
                return;
            } else if (phi->first[1] > R) { // cut old rightwards and don't remove it
                if (phi->first[0] < R) {
                    processor(run_t{phi->first[0], R}, phi->second);
                    const_cast<T&>(phi->first[0]) = R;
                }
                hi = phi;
            }
        }
        if (lo != base_t::begin()) {
            if (auto plo = prev(lo); plo->first[1] > L) { // cut old leftwards
                processor(run_t{L, plo->first[1]}, plo->second);
                const_cast<T&>(plo->first[1]) = L;
            }
        }
        for (auto it = lo; it != hi; ++it) {
            processor(it->first, it->second);
        }
        base_t::erase(lo, hi);
    }
    void cut(run_t intv) {
        cut(intv, [](auto, const auto&) {});
    }

    optional<run_t> get_run(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->first;
        }
        return std::nullopt;
    }

    optional<V> get(T x) const {
        auto it = base_t::upper_bound({x, inf});
        if (it != base_t::begin() && prev(it)->first[0] <= x && x < prev(it)->first[1]) {
            return prev(it)->second;
        }
        return std::nullopt;
    }

    V& val(T x) { return prev(base_t::upper_bound({x, inf}))->second; }

    bool contains(T x) const { return get_run(x).has_value(); }

    bool contains(run_t intv) const {
        auto wrap = get_run(intv[0]);
        return wrap.has_value() && wrap->first[1] >= intv[1];
    }

    bool overlaps(run_t intv) const {
        auto lo = base_t::lower_bound({intv[0], intv[0]});
        return !(lo == base_t::end() || lo->first[0] >= intv[1]) ||
               !(lo == base_t::begin() || prev(lo)->first[1] <= intv[0]);
    }

    // Get run including x, or the one closest before x (or end() if none)
    auto before(T x) const {
        auto it = base_t::upper_bound({x, inf});
        return it != base_t::begin() ? prev(it) : base_t::end();
    }

    // Get run strictly before x (or end() if none)
    auto before_strict(T x) const {
        auto it = base_t::upper_bound({x, x});
        if (it != base_t::begin() && prev(it)->first[1] > x)
            --it;
        return it != base_t::begin() ? prev(it) : base_t::end();
    }

    // Get run including x, or the one closest after x (or end() if none)
    auto after(T x) const {
        auto it = base_t::upper_bound({x, inf});
        return it != base_t::begin() && prev(it)->first[1] > x ? prev(it) : it;
    }

    // Get run strictly after x (or end() if none)
    auto after_strict(T x) const {
        return base_t::upper_bound({x, inf}); //
    }
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

struct hld_forest {
    vector<int> subsize, parent, depth, roots;
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
    // With merge=true join heavy path segments [l,m) and [m,r) (for efficiency)
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

template <typename Splay>
struct basic_splay {
    Splay* parent = nullptr;
    Splay* kids[2] = {};

    static int get_size(const Splay* x) { return x ? x->size : 0; }
    static const auto& get_key(const Splay* x) { return x->L; }

  protected:
    basic_splay() = default;
    inline void pushdown() {}
    inline void pushup() {}

    Splay* self() { return static_cast<Splay*>(this); }
    const Splay* self() const { return static_cast<const Splay*>(this); }

  private:
    using TwoSplays = pair<Splay*, Splay*>;
    using ThreeSplays = tuple<Splay*, Splay*, Splay*>;

    bool is_root() const { return !parent; }
    bool is_left() const { return parent && self() == parent->kids[0]; }
    bool is_right() const { return !parent && self() == parent->kids[1]; }

    static void adopt_node(Splay* parent, Splay* kid, int8_t side) {
        if (side >= 0)
            parent->kids[side] = kid;
        if (kid)
            kid->parent = parent;
    }

    static void attach_node(Splay* u, Splay* kid, int8_t side) {
        if (kid) {
            adopt_node(u, kid, side);
            u->pushup();
        }
    }

    static void rotate(Splay* u) {
        Splay *p = u->parent, *g = p->parent;
        int8_t u_side = u == p->kids[1];
        int8_t p_side = g ? p == g->kids[1] : -1;
        adopt_node(p, u->kids[!u_side], u_side);
        adopt_node(g, u, p_side);
        adopt_node(u, p, !u_side);
        p->pushup();
    }

    // Cut the edge from u to u->kids[side] and return the kid
    static Splay* detach_kid(Splay* u, int8_t side) {
        Splay* kid = u->kids[side];
        if (kid) {
            kid->parent = u->kids[side] = nullptr;
            u->pushup();
        }
        return kid;
    }

    // Cut the edge from u to its parent and return the parent
    static Splay* detach_parent(Splay* u) {
        Splay* parent = u->parent;
        if (parent) {
            parent->kids[u == parent->kids[1]] = u->parent = nullptr;
            parent->pushup();
        }
        return parent;
    }

    static Splay* min_node(Splay* u) {
        u->pushdown();
        while (u->kids[0])
            u = u->kids[0], u->pushdown();
        return u;
    }

    static Splay* max_node(Splay* u) {
        u->pushdown();
        while (u->kids[1])
            u = u->kids[1], u->pushdown();
        return u;
    }

    static Splay* findroot(Splay* u) {
        while (u->parent)
            u = u->parent, u->pushdown();
        return u;
    }

    static Splay* splay_unsafe(Splay* u) {
        if (!u->parent) {
            return u;
        }
        while (u->parent && u->parent->parent) {
            u->parent->parent->pushdown(), u->parent->pushdown(), u->pushdown();
            bool zigzig = u->is_right() == u->parent->is_right();
            rotate(zigzig ? u->parent : u), rotate(u);
        }
        if (u->parent) {
            u->parent->pushdown(), u->pushdown(), rotate(u);
        }
        u->pushdown(), u->pushup();
        return u;
    }

  public:
    Splay* clone() const {
        Splay* node = new Splay(*self());
        node = node->parent = node->kids[0] = node->kids[1] = nullptr;
        return node;
    }

    friend Splay* splay(Splay* u) {
        return u ? !u->parent ? u->pushdown(), u : splay_unsafe(u) : nullptr;
    }

    friend void delete_all(Splay* u) {
        if (u) {
            delete_all(u->kids[0]);
            delete_all(u->kids[1]);
            delete u;
        }
    }

    friend Splay* predecessor(Splay*& tree, Splay* index) {
        if (!index) {
            return back(tree);
        } else if (index->kids[0]) {
            return tree = splay(max_node(index->kids[0]));
        } else {
            tree = splay(index);
            return index->kids[0] ? tree = splay(max_node(index->kids[0])) : nullptr;
        }
    }

    friend Splay* successor(Splay*& tree, Splay* index) {
        if (!index) {
            return front(tree);
        } else if (index->kids[1]) {
            return tree = splay(min_node(index->kids[1]));
        } else {
            tree = splay(index);
            return index->kids[1] ? tree = splay(min_node(index->kids[1])) : nullptr;
        }
    }

    friend Splay* insert_before(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[0]) {
                attach_node(index, item, 0);
            } else {
                attach_node(max_node(index->kids[0]), item, 1);
            }
            return tree = splay(item);
        } else {
            return push_back(tree, item);
        }
    }

    friend Splay* insert_after(Splay*& tree, Splay* index, Splay* item) {
        if (!item) {
            return item;
        } else if (index) {
            if (!index->kids[1]) {
                attach_node(index, item, 1);
            } else {
                attach_node(min_node(index->kids[1]), item, 0);
            }
            return tree = splay(item);
        } else {
            return push_front(tree, item);
        }
    }

    friend Splay* back(Splay*& tree) {
        return tree ? tree = splay(max_node(tree)) : nullptr;
    }

    friend Splay* front(Splay*& tree) {
        return tree ? tree = splay(min_node(tree)) : nullptr;
    }

    friend Splay* push_back(Splay*& tree, Splay* item) {
        if (item) {
            return tree = tree ? attach_node(max_node(tree), item, 1), splay(item) : item;
        }
        return item;
    }

    friend Splay* push_front(Splay*& tree, Splay* item) {
        if (item) {
            tree = tree ? attach_node(min_node(tree), item, 0), splay(item) : item;
        }
        return item;
    }

    friend Splay* pop_back(Splay*& tree) {
        if (tree) {
            Splay* item = splay(max_node(tree));
            tree = detach_kid(item, 0);
            return item;
        }
        return nullptr;
    }

    friend Splay* pop_front(Splay*& tree) {
        if (tree) {
            Splay* item = splay(min_node(tree));
            tree = detach_kid(item, 1);
            return item;
        }
        return nullptr;
    }

    friend void delete_back(Splay*& tree) {
        if (tree) {
            Splay* item = pop_back(tree);
            delete item;
        }
    }

    friend void delete_front(Splay*& tree) {
        if (tree) {
            Splay* item = pop_front(tree);
            delete item;
        }
    }

    // Access the range (L...R). If L,R are both null it accesses everything
    friend Splay* access_exclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* S = nullptr;
        if (L && R) {
            splay(R), splay(L);
            if (R->parent != L) {
                R->parent->pushdown();
                R->pushdown();
                rotate(R);
                R->pushup();
            }
            assert(R->parent == L);
            S = R->kids[R->is_left()];
        } else if (L) {
            S = splay(L)->kids[1];
        } else if (R) {
            S = splay(R)->kids[0];
        } else {
            return tree;
        }
        if (S) {
            S->pushdown(), S->pushup();
        }
        tree = L ? L : R;
        return S;
    }

    friend Splay* access_inclusive(Splay*& tree, Splay* L, Splay* R) {
        return access_exclusive(tree, predecessor(tree, L), successor(tree, R));
    }

    friend Splay* access_range(Splay*& tree, Splay* L, Splay* R) {
        return access_exclusive(tree, predecessor(tree, L), R);
    }

    // Delete the range (L...R). If L,R are both null it splices everything
    friend Splay* splice_exclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_exclusive(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* splice_inclusive(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_inclusive(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    friend Splay* splice_range(Splay*& tree, Splay* L, Splay* R) {
        Splay* M = access_range(tree, L, R);
        if (M && M->parent) {
            tree = splay(detach_parent(M));
        } else if (M) {
            tree = nullptr;
        }
        return M;
    }

    // Delete the range (L...R). If L,R are both null it deletes everything
    friend void delete_exclusive(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_exclusive(tree, L, R));
    }

    friend void delete_inclusive(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_inclusive(tree, L, R));
    }

    friend void delete_range(Splay*& tree, Splay* L, Splay* R) {
        delete_all(splice_range(tree, L, R));
    }

    // Splice (remove but not delete) one item from the sequence
    friend Splay* splice_item(Splay*& tree, Splay* item) {
        return splice_inclusive(tree, item, item);
    }

    friend void delete_item(Splay*& tree, Splay* item) { delete splice_item(tree, item); }

    // Split into two sequences: [...A)[A...)
    friend TwoSplays split_before(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {detach_kid(node, 0), node};
        } else {
            return {tree, nullptr};
        }
    }

    // Split into two sequences: [...A](A...)
    friend TwoSplays split_after(Splay*& tree, Splay* node) {
        if (node) {
            splay(node);
            return {node, detach_kid(node, 1)};
        } else {
            return {nullptr, tree};
        }
    }

    // Split into three sequences: [...A)[A...B)[B...)
    friend ThreeSplays split_range(Splay*& tree, Splay* A, Splay* B) {
        auto [mid, c] = split_before(tree, B);
        auto [a, b] = split_before(mid, A);
        return {a, b, c};
    }

    friend Splay* join(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        splay(A), splay(B), assert(A->is_root() && A != B);
        Splay* root = splay(max_node(A));
        attach_node(root, B, 1);
        return root;
    }

    friend Splay* join(Splay* A, Splay* B, Splay* C) { return join(join(A, B), C); }

    friend Splay* join_if_disjoint(Splay* A, Splay* B) {
        if (!A || !B || A == B) {
            return A ? A : B;
        }
        splay(A), splay(B);
        if (A->is_root()) {
            Splay* root = splay(max_node(A));
            attach_node(root, B, 1);
            return root;
        } else {
            return B;
        }
    }

    friend Splay* join_if_disjoint(Splay* A, Splay* B, Splay* C) {
        return join_if_disjoint(join_if_disjoint(A, B), C);
    }

    template <typename... Args>
    [[nodiscard]] static Splay* construct(int N, Args&&... args) {
        if (N == 0) {
            return nullptr;
        } else {
            Splay* node = new Splay(args...);
            attach_node(node, construct(N / 2, args...), 0);
            attach_node(node, construct((N - 1) / 2, args...), 1);
            return node;
        }
    }

    template <typename T>
    [[nodiscard]] static Splay* construct_array(int N, const vector<T>& arr, int s = 0) {
        if (N == 0) {
            return nullptr;
        } else {
            int L = N / 2, R = (N - 1) / 2;
            Splay* node = new Splay(arr[s + L]);
            attach_node(node, construct_array(L, arr, s), 0);
            attach_node(node, construct_array(R, arr, s + 1 + L), 1);
            return node;
        }
    }

    // ***** Order operations

    // Find order of an item (0-indexed)
    friend int order_of_node(Splay*& tree, Splay* item) {
        if (item) {
            tree = splay(item);
            return tree ? get_size(tree->kids[0]) : 0;
        } else {
            return get_size(tree);
        }
    }

    // Find the item with this exact order, or nullptr if order is out of bounds
    friend Splay* find_order(Splay*& tree, int order) {
        if (!tree || order < 0 || order >= get_size(tree)) {
            return nullptr;
        }
        while (true) {
            tree->pushdown();
            int left = get_size(tree->kids[0]);
            if (order < left) {
                tree = tree->kids[0];
            } else if (order > left) {
                order -= left + 1;
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
    }

    // Insert item just before the given order (accepts out of bounds orders)
    friend Splay* insert_order(Splay*& tree, Splay* item, int order) {
        if (!tree) {
            return tree = item;
        } else if (order <= 0) {
            return push_front(tree, item);
        } else if (order >= get_size(tree)) {
            return push_back(tree, item);
        } else {
            return insert_before(tree, find_order(tree, order), item);
        }
    }

    // Access the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend Splay* access_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return access_exclusive(tree, A, B);
        }
    }

    friend Splay* access_order_inclusive(Splay*& tree, int L, int R) {
        return access_order_exclusive(tree, L - 1, R + 1);
    }

    friend Splay* access_order_range(Splay*& tree, int L, int R) {
        return access_order_exclusive(tree, L - 1, R);
    }

    // Splice the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend Splay* splice_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return nullptr;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            return splice_exclusive(tree, A, B);
        }
    }

    friend Splay* splice_order_inclusive(Splay*& tree, int L, int R) {
        return splice_order_exclusive(tree, L - 1, R + 1);
    }

    friend Splay* splice_order_range(Splay*& tree, int L, int R) {
        return splice_order_exclusive(tree, L - 1, R);
    }

    // Delete the nodes s.t. L < order(u) < R. If L<0 and R>=size that's everything
    friend void delete_order_exclusive(Splay*& tree, int L, int R) {
        assert(L <= R);
        if (!tree || R <= 0 || L >= get_size(tree) - 1 || L + 1 >= R) {
            return;
        } else {
            auto A = find_order(tree, L);
            auto B = find_order(tree, R);
            delete_exclusive(tree, A, B);
        }
    }

    friend void delete_order_inclusive(Splay*& tree, int L, int R) {
        delete_order_exclusive(tree, L - 1, R + 1);
    }

    friend void delete_order_range(Splay*& tree, int L, int R) {
        delete_order_exclusive(tree, L - 1, R);
    }

    // Splice (remove but not delete) one item from the sequence
    friend Splay* splice_order(Splay*& tree, int order) {
        auto node = find_order(tree, order);
        if (node) {
            tree = join(detach_kid(tree, 0), detach_kid(tree, 1));
            return node;
        } else {
            return nullptr;
        }
    }

    friend void delete_order(Splay*& tree, int order) {
        delete splice_order(tree, order);
    }

    // Split into two sequences: {order(u)<order} {order<=order(u)}
    friend TwoSplays split_order(Splay*& tree, int order) {
        if (order >= 1) {
            return split_before(tree, find_order(tree, order));
        } else {
            return {nullptr, tree};
        }
    }

    // Split into three sequences: {order(u)<L} {L<=order(u)<R} {R<=order(u)}
    friend ThreeSplays split_order_range(Splay*& tree, int L, int R) {
        auto [mid, c] = split_order(tree, R);
        auto [a, b] = split_order(mid, L);
        return {a, b, c};
    }

    // ***** Key operations

    // Find first item s.t. item->key >= key, or nullptr for end (lower_bound)
    template <typename Key>
    friend Splay* after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(get_key(tree) < key)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find first item s.t. item->key > key, or nullptr for end (upper_bound)
    template <typename Key>
    friend Splay* strict_after(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = tree;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                valid = tree, tree = tree->kids[0];
            } else {
                tree = tree->kids[1];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find last item s.t. item->key <= key, or nullptr for end (reverse lower_bound)
    template <typename Key>
    friend Splay* before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (!(key < get_key(tree))) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find last item s.t. item->key < key, or nullptr for end (reverse upper_bound)
    template <typename Key>
    friend Splay* strict_before(Splay*& tree, const Key& key) {
        Splay *valid = nullptr, *last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (get_key(tree) < key) {
                valid = tree, tree = tree->kids[1];
            } else {
                tree = tree->kids[0];
            }
        }
        tree = splay(last);
        return valid;
    }

    // Find first item s.t. item->key = key
    template <typename Key>
    friend Splay* find_key(Splay*& tree, const Key& key) {
        Splay* last = nullptr;
        while (tree) {
            last = tree, tree->pushdown();
            if (key < get_key(tree)) {
                tree = tree->kids[0];
            } else if (get_key(tree) < key) {
                tree = tree->kids[1];
            } else {
                return splay(tree);
            }
        }
        tree = splay(last);
        return nullptr;
    }

    // Insert item(s) in search position, returning the item splayed
    friend Splay* insert_key(Splay*& tree, Splay* item) {
        if (!item) {
            return tree;
        } else if (!tree) {
            return tree = item;
        } else if (Splay* ahead = after(tree, get_key(item))) {
            return insert_before(tree, ahead, item);
        } else {
            return push_back(tree, item);
        }
    }

    // Access the nodes s.t. L < node->key < R, possibly nullptr if none
    template <typename Key>
    friend Splay* access_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return access_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* access_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return access_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* access_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return access_exclusive(tree, A, B);
    }

    // Splice the range of nodes s.t. L < node->key < R
    template <typename Key>
    friend Splay* splice_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* splice_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    template <typename Key>
    friend Splay* splice_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        return splice_exclusive(tree, A, B);
    }

    // Delete the range of nodes s.t. L < node->key < R
    template <typename Key>
    friend void delete_key_exclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = before(tree, L);
        auto B = after(tree, R);
        delete_exclusive(tree, A, B);
    }

    template <typename Key>
    friend void delete_key_inclusive(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = strict_after(tree, R);
        delete_exclusive(tree, A, B);
    }

    template <typename Key>
    friend void delete_key_range(Splay*& tree, const Key& L, const Key& R) {
        assert(!(R < L));
        auto A = strict_before(tree, L);
        auto B = after(tree, R);
        delete_exclusive(tree, A, B);
    }

    // Splice the first item with exact given key
    template <typename Key>
    friend Splay* splice_key(Splay*& tree, const Key& key) {
        if (auto item = find_key(tree, key)) {
            return splice_item(tree, item);
        } else {
            return nullptr;
        }
    }

    template <typename Key>
    friend void delete_key(Splay*& tree, const Key& key) {
        delete splice_key(tree, key);
    }

    // Split into two sequences: {node<key} {key<=node}
    template <typename Key>
    friend TwoSplays split_key(Splay*& tree, const Key& key) {
        if (auto succ = after(tree, key)) {
            return split_before(tree, succ);
        } else {
            return {tree, nullptr};
        }
    }

    // Split into three sequences: {node<L} {L<=node<R} {R<=node}
    template <typename Key>
    friend ThreeSplays split_key_range(Splay*& tree, const Key& L, const Key& R) {
        auto [mid, c] = split_key(tree, R);
        auto [a, b] = split_key(mid, L);
        return {a, b, c};
    }

    // Meld two splay trees, smaller into larger. O(B log A) if |A| >= |B|
    friend Splay* meld(Splay* A, Splay* B) {
        if (!A || !B) {
            return A ? A : B;
        }
        if (get_size(A) < get_size(B)) {
            swap(A, B);
        }
        visit_inorder(B, [&A](Splay* item) {
            item->kids[0] = item->kids[1] = item->parent = nullptr;
            item->pushup();
            insert_key(A, item);
        });
        return A;
    }

    friend Splay* meld(Splay* A, Splay* B, Splay* C) { return meld(meld(A, B), C); }

    // ***** Debugging

    friend vector<Splay*> get_inorder_vector(Splay* node) {
        vector<Splay*> vec;
        visit_inorder(node, [&vec](Splay* x) { vec.push_back(x); });
        return vec;
    }

    template <typename Fn>
    friend void visit_inorder(Splay* node, Fn&& fn) {
        if (node) {
            node->pushdown();
            auto [a, b] = node->kids;
            visit_inorder(a, fn);
            fn(node);
            visit_inorder(b, fn);
        }
    }

    friend string format_inorder(Splay* node) {
        int id = 0;
        string s;
        visit_inorder(node, [&](Splay* child) {
            s += " [" + to_string(id++) + "] " + child->format() + '\n';
        });
        return s;
    }
};

/**
 * Splay supporting the following operations:
 * Insert range of integers [l,r), none existing (delete first if you need to be sure)
 * Delete range of integers [l,r), some might not exist
 * Query k-th integer
 */
struct RangeSplay : basic_splay<RangeSplay> {
    using V = int64_t;
    V length, L, R;

    explicit RangeSplay(V L, V R) : length(R - L), L(L), R(R) {}

    static V get_length(const RangeSplay* x) { return x ? x->length : 0; }

    void pushdown() {}

    void pushup() { length = R - L + get_length(kids[0]) + get_length(kids[1]); }

    friend RangeSplay* within_range_find(RangeSplay*& tree, V i) {
        RangeSplay* node = tree;
        RangeSplay* after = nullptr;
        while (node) {
            if (i < node->L) {
                after = node;
                node = node->kids[0];
            } else if (node->R <= i) {
                node = node->kids[1];
            } else {
                tree = splay(node);
                return node;
            }
        }
        return after ? tree = splay(after) : nullptr;
    }

    friend void clear_range(RangeSplay*& tree, V l, V r) {
        auto right = within_range_find(tree, r);
        if (right && right->L < r && r < right->R) {
            right = split_node_proper(tree, right, r);
        }
        auto left = within_range_find(tree, l);
        if (left && left->L < l && l < left->R) {
            left = split_node_proper(tree, left, l);
        }
        if (left) {
            delete_range(tree, left, right);
        }
    }

    friend RangeSplay* insert_range(RangeSplay*& tree, V l, V r) {
        return insert_key(tree, new RangeSplay(l, r));
    }

    friend RangeSplay* split_node_proper(RangeSplay*& tree, RangeSplay* x, V M) {
        assert(x->L < M && M < x->R);
        RangeSplay* y = new RangeSplay(M, x->R);
        x->length -= x->R - M, x->R = M;
        return insert_after(tree, x, y);
    }

    friend V range_kth(RangeSplay*& tree, V k) {
        RangeSplay* node = tree;
        assert(0 <= k && k < get_length(tree));
        while (true) {
            if (k < get_length(node->kids[0])) {
                node = node->kids[0];
            }
            k -= get_length(node->kids[0]);
            if (k < get_length(node)) {
                tree = splay(node);
                return node->L + k;
            }
            k -= get_length(node);
            node = node->kids[1];
        }
    }

    friend V range_rank(RangeSplay*& tree, V i) {
        RangeSplay* node = within_range_find(tree, i);
        if (node == nullptr) {
            return get_length(tree);
        } else {
            return get_length(node->kids[0]) + max<V>(i - node->L, 0);
        }
    }

#ifdef LOCAL
    string format() const { return '(' + to_string(L) + ' ' + to_string(R) + ')'; }
#endif
};

auto eval(pair<int, int64_t> pp, int a) { return pp.first * a + pp.second; }

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
    vector<int> deg(N);
    for (int u = 0; u < N; u++) {
        deg[u] = tree[u].size();
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u = 0; u < N; u++) {
        if (deg[u] == 1) {
            pq.push(u);
        }
    }
    vector<int> order, rank(N);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        rank[u] = order.size();
        order.push_back(u);
        for (int v : tree[u]) {
            if (--deg[v] == 1) {
                pq.push(v);
            }
        }
    }

    hld_forest hld(tree, 0);

    RangeSplay* ints = new RangeSplay(0, N);

    merging_interval_processor<int, array<int64_t, 3>> mip;
    for (int u = 0; u < N; u++) {
        mip.write({hld.time[u], hld.time[u] + 1}, {0, rank[u], Q});
    }

    auto get_color = [&](int u) {
        auto [a, b, _] = mip.val(hld.time[u]);
        return a * hld.time[u] + b;
    };
    auto get_rank = [&](int u) {
        auto c = get_color(u);
        return range_rank(ints, c);
    };

    int64_t T = N;
    int u = order.back();

    while (Q--) {
        if (string t; cin >> t, t == "up") {
            int v;
            cin >> v, v--;
            int64_t S = T;
            auto [up, down] = hld.oriented_vertex_segments(u, v);
            for (auto [l, r] : up) {
                mip.write({l, r}, {-1, T + r - 1, Q}, [&](auto intv, auto color) {
                    auto [L, R] = intv;
                    auto [a, b, _] = color;
                    int64_t x = min(a * L + b, a * (R - 1) + b);
                    int64_t y = max(a * L + b, a * (R - 1) + b);
                    clear_range(ints, x, y + 1);
                });
                T += r - l;
            }
            for (auto [l, r] : down) {
                mip.write({l, r}, {+1, T - l, Q}, [&](auto intv, auto color) {
                    auto [L, R] = intv;
                    auto [a, b, _] = color;
                    int64_t x = min(a * L + b, a * (R - 1) + b);
                    int64_t y = max(a * L + b, a * (R - 1) + b);
                    clear_range(ints, x, y + 1);
                });
                T += r - l;
            }
            insert_range(ints, S, T);
            u = v;
        } else if (t == "when") {
            int v;
            cin >> v, v--;
            cout << get_rank(v) + 1 << '\n';
        } else if (t == "compare") {
            int a, b;
            cin >> a >> b, a--, b--;
            cout << (get_rank(a) < get_rank(b) ? a : b) + 1 << '\n';
        } else {
            assert(false);
        }
    }
    return 0;
}