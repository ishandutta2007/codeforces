#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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

struct lca_schieber_vishkin {
    int N, timer = 0;
    vector<int> preorder, up, I, A, head, depth;

    static int lowest_one_bit(int n) { return n & -n; }
    static int highest_one_bit(int n) { return n ? 1 << (31 - __builtin_clz(n)) : 0; }

    explicit lca_schieber_vishkin(const vector<vector<int>>& tree, int root, int zero = 0)
        : N(tree.size()), preorder(N), up(N), I(N), A(N), head(N), depth(N) {
        init_dfs1(tree, root, zero);
        init_dfs2(tree, root, zero, 0);
    }

    void init_dfs1(const vector<vector<int>>& tree, int u, int p) {
        up[u] = p;
        I[u] = preorder[u] = timer++;
        for (int v : tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                init_dfs1(tree, v, u);
                if (lowest_one_bit(I[u]) < lowest_one_bit(I[v])) {
                    I[u] = I[v];
                }
            }
        }
        head[I[u]] = u;
    }

    void init_dfs2(const vector<vector<int>>& tree, int u, int p, int up) {
        A[u] = up | lowest_one_bit(I[u]);
        for (int v : tree[u]) {
            if (v != p) {
                init_dfs2(tree, v, u, A[u]);
            }
        }
    }

    int parent(int u) const { return up[u]; }

    int enter_into_strip(int u, int hz) const {
        if (lowest_one_bit(I[u]) == hz)
            return u;
        int hw = highest_one_bit(A[u] & (hz - 1));
        return parent(head[(I[u] & -hw) | hw]);
    }

    int lca(int u, int v) const {
        int hb = I[u] == I[v] ? lowest_one_bit(I[u]) : highest_one_bit(I[u] ^ I[v]);
        int hz = lowest_one_bit(A[u] & A[v] & -hb);
        int eu = enter_into_strip(u, hz);
        int ev = enter_into_strip(v, hz);
        return preorder[eu] < preorder[ev] ? eu : ev;
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> boy(N + 1);
    for (int u = 1; u <= N; u++) {
        cin >> boy[u];
    }
    vector<int> fav(N + 1);
    unordered_map<int, int> compress;
    for (int u = 1; u <= N; u++) {
        int large;
        cin >> large;
        fav[u] = compress.emplace(large, compress.size()).first->second;
    }
    debug(N, boy, fav);
    vector<vector<int>> tree(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    lca_schieber_vishkin sv(tree, 1, 0);
    vector<int> tin(N + 1), tout(N + 1);
    int dfs_timer = 0;
    y_combinator([&](auto self, int u, int p) -> void {
        tin[u] = dfs_timer++;
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
            }
        }
        tout[u] = dfs_timer++;
    })(1, 0);
    vector<int> rev_euler(2 * N);
    for (int u = 1; u <= N; u++) {
        rev_euler[tin[u]] = u;
        rev_euler[tout[u]] = u;
    }
    int Q;
    cin >> Q;
    vector<array<int, 2>> queries(Q);
    for (auto& [u, v] : queries) {
        cin >> u >> v;
        if (tin[u] > tin[v]) {
            swap(u, v);
        }
    }
    int BLOCK = sqrt(2 * N);
    int NUM_BLOCKS = (2 * N + BLOCK - 1) / BLOCK;
    auto block = [&](int i) { return i / BLOCK; };
    vector<array<int, 3>> range(Q);
    vector<int> small_queries;
    vector<vector<int>> by_block(NUM_BLOCKS);
    for (int q = 0; q < Q; q++) {
        auto [u, v] = queries[q];
        int c = sv.lca(u, v);
        int l = c == u ? tin[u] : tout[u];
        int r = tin[v];
        range[q][0] = l, range[q][1] = r;
        range[q][2] = c == u ? -1 : tin[c];
        if (block(l) == block(r)) {
            small_queries.push_back(q);
        } else {
            by_block[block(l)].push_back(q);
        }
    }
    int F = compress.size();
    vector<int> freq_boy(F), freq_girl(F), freq_node(N + 1);
    long count_pairs = 0, total_freq = 0;
    auto add = [&](int i) {
        if (i == -1)
            return;
        int u = rev_euler[i];
        int x = fav[u];
        bool is_boy = boy[u];
        int one = 1 == ++freq_node[u];
        count_pairs -= 1LL * freq_boy[x] * freq_girl[x];
        freq_boy[x] += is_boy ? one ? 1 : -1 : 0;
        freq_girl[x] += !is_boy ? one ? 1 : -1 : 0;
        count_pairs += 1LL * freq_boy[x] * freq_girl[x];
        total_freq++;
    };
    auto rem = [&](int i) {
        if (i == -1)
            return;
        int u = rev_euler[i];
        int x = fav[u];
        bool is_boy = boy[u];
        int one = 1 == --freq_node[u];
        count_pairs -= 1LL * freq_boy[x] * freq_girl[x];
        freq_boy[x] += is_boy ? one ? 1 : -1 : 0;
        freq_girl[x] += !is_boy ? one ? 1 : -1 : 0;
        count_pairs += 1LL * freq_boy[x] * freq_girl[x];
        total_freq--;
    };
    vector<long> answer(Q);
    for (int q : small_queries) {
        auto [l, r, e] = range[q];
        for (int i = l; i <= r; i++) {
            add(i);
        }
        add(e);
        answer[q] = count_pairs;
        rem(e);
        for (int i = l; i <= r; i++) {
            rem(i);
        }
    }
    for (int b = 0; b < NUM_BLOCKS; b++) {
        sort(begin(by_block[b]), end(by_block[b]), [&](int x, int y) {
            auto [lx, rx, ex] = range[x];
            auto [ly, ry, ey] = range[y];
            return make_pair(rx, lx) < make_pair(ry, ly);
        });
        int current_l = -1, current_r = -1;
        for (int q : by_block[b]) {
            auto [l, r, e] = range[q];
            if (current_l == -1) {
                for (int i = l; i <= r; i++) {
                    add(i);
                }
                add(e);
                answer[q] = count_pairs;
                rem(e);
            } else {
                for (int i = current_r + 1; i <= r; i++) {
                    add(i);
                }
                for (int i = l; i < current_l; i++) {
                    add(i);
                }
                for (int i = current_l; i < l; i++) {
                    rem(i);
                }
                add(e);
                answer[q] = count_pairs;
                rem(e);
            }
            current_l = l, current_r = r;
        }
        for (int i = current_l; current_l != -1 && i <= current_r; i++) {
            rem(i);
        }
    }
    for (int q = 0; q < Q; q++) {
        cout << answer[q] << '\n';
    }
    return 0;
}