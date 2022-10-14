#include <bits/stdc++.h>

using namespace std;

#define long int64_t

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

template <typename T, int NDIMS>
struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

  protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    int len;
    T* data;

  public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS - 1] = 1;
        for (int i = NDIMS - 1; i > 0; i--) {
            strides[i - 1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    tensor(const tensor& o)
        : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        for (int i = 0; i < len; i++) {
            data[i] = o.data[i];
        }
    }

    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    tensor(tensor&& o) : tensor() { *this = std::move(o); }
    tensor& operator=(const tensor& o) { return *this = tensor(o); }
    ~tensor() { delete[] data; }

    auto size() const { return shape; }

  protected:
    int flatten_index(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }
    int flatten_index_checked(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](std::array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T& at(std::array<int, NDIMS> idx) const { return data[flatten_index_checked(idx)]; }
};

struct lca_tree {
    int N, B;
    vector<vector<int>> up;
    vector<int> subt;
    vector<int> depth;

    static int need_bits(int n) {
        return 1 + (n > 1 ? 8 * sizeof(n) - __builtin_clz(n - 1) : 0);
    }

    explicit lca_tree(const vector<vector<int>>& tree, int root)
        : N(tree.size()), B(need_bits(N)), up(B, vector<int>(N)), subt(N), depth(N) {
        init_dfs(tree, root, 0);

        for (int b = 1; b < B; b++) {
            for (int i = 1; i < N; i++) {
                int p = up[b - 1][i];
                up[b][i] = (p >= 1) ? up[b - 1][p] : 0;
            }
        }
    }

    void init_dfs(const vector<vector<int>>& tree, int u, int p) {
        up[0][u] = p;
        depth[u] = (p >= 1) ? depth[p] + 1 : 0;
        subt[u] = 1;
        for (int v : tree[u]) {
            if (v != p) {
                init_dfs(tree, v, u);
                subt[u] += subt[v];
            }
        }
    }

    int ancestor(int u, int steps) const {
        for (int b = B - 1; b >= 0; b--) {
            if (steps & (1 << b)) {
                u = up[b][u];
            }
        }
        return u;
    }

    int parent(int u) const { return up[0][u]; }

    int lca(int u, int v) const {
        if (depth[u] < depth[v]) {
            v = ancestor(v, depth[v] - depth[u]);
        } else if (depth[u] > depth[v]) {
            u = ancestor(u, depth[u] - depth[v]);
        }
        for (int k = B - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u], v = up[k][v];
            }
        }
        return u == v ? u : up[0][u];
    }

    int dist(int u, int v) { // # edges on path
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> tree(N + 1);
    vector<array<int, 2>> edges(N - 1);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    lca_tree lca(tree, 1);
    tensor<long, 2> dp({N + 1, N + 1});

    vector<vector<array<int, 2>>> by_len(N);
    for (int u = 1; u <= N; u++) {
        for (int v = u + 1; v <= N; v++) {
            by_len[lca.dist(u, v)].push_back({u, v});
        }
    }

    for (int len = 1; len < N; len++) {
        for (auto [u, v] : by_len[len]) {
            int a = lca.lca(u, v);
            if (a == v) {
                swap(u, v);
            }

            if (a == u) {
                int lo = lca.parent(v);
                int hi = lca.ancestor(v, len - 1);
                // v->lo->...->hi->u

                dp[{u, v}] = max(dp[{u, lo}], dp[{v, hi}]) +
                             lca.subt[v] * (N - lca.subt[hi]);
            } else {
                // v->v1->...<-u1<-u
                int u1 = lca.parent(u);
                int v1 = lca.parent(v);

                dp[{u, v}] = max(dp[{u, v1}], dp[{v, u1}]) + lca.subt[u] * lca.subt[v];
            }

            dp[{v, u}] = dp[{u, v}];
        }
    }

    long S = 0;
    for (int u = 1; u <= N; u++) {
        for (int v = u + 1; v <= N; v++) {
            S = max(S, dp[{u, v}]);
        }
    }
    cout << S << endl;
    return 0;
}