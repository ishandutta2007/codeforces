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

auto build_scc(const vector<vector<int>>& adj, bool reverse_order = true) {
    int V = adj.size(), C = 0; // C = number of scc

    vector<int> cmap(V, -1), index(V), lowlink(V), stack(V);
    int timer = 1, S = 0;

    auto dfs = y_combinator([&](auto self, int u) -> void {
        index[u] = lowlink[u] = timer++;
        stack[S++] = u;

        for (int v : adj[u]) {
            if (index[v] && cmap[v] == -1) { // <-- skip cmap'd nodes
                lowlink[u] = min(lowlink[u], index[v]);
            } else if (!index[v]) {
                self(v);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            }
        }

        // found a strongly connected component
        if (index[u] == lowlink[u]) {
            int c = C++;
            int v;
            do {
                v = stack[--S];
                cmap[v] = c;
            } while (u != v);
        }
    });

    for (int u = 0; u < V; u++) {
        if (!index[u]) {
            dfs(u);
        }
    }
    if (!reverse_order) {
        for (int u = 0; u < V; u++) {
            cmap[u] = C - 1 - cmap[u];
        }
    }

    return make_pair(C, cmap);
}

auto condensate_sccedges(const vector<vector<int>>& adj, const vector<int>& cmap) {
    int V = adj.size();
    vector<array<int, 2>> edges;
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            if (cmap[u] != cmap[v]) {
                edges.push_back({cmap[u], cmap[v]});
            }
        }
    }
    sort(begin(edges), end(edges));
    edges.erase(unique(begin(edges), end(edges)), end(edges));
    return edges;
}

auto condensate_scc(int C, const vector<vector<int>>& adj, const vector<int>& cmap) {
    auto edges = condensate_sccedges(adj, cmap);
    vector<vector<int>> sccout(C), sccin(C);
    for (auto [u, v] : edges) {
        sccout[u].push_back(v);
        sccin[v].push_back(u);
    }
    return make_tuple(edges, sccout, sccin);
}

template <typename T, int NDIMS>
struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

  protected:
    array<int, NDIMS> shape;
    array<int, NDIMS> strides;
    int len;
    T* data;

  public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(array<int, NDIMS> shape_, const T& t = T()) { assign(shape_, t); }

    tensor(const tensor& o)
        : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        copy(o.data, o.data + len, data);
    }
    tensor(tensor&& o) : tensor() { *this = std::move(o); }

    tensor& operator=(const tensor& o) { return *this = tensor(o); }
    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    ~tensor() { delete[] data; }

    void assign(array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS - 1] = 1;
        for (int i = NDIMS - 1; i > 0; i--) {
            strides[i - 1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    const auto& size() const { return shape; }
    int size(int dim) const { return shape[dim]; }

    friend istream& operator>>(istream& in, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            in >> t.data[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            out << ' ' << t.data[i];
        }
        return out;
    }
    bool operator==(const tensor& o) const {
        return shape == o.shape && equal(data, data + len, o.data);
    }
    bool operator!=(const tensor& o) const { return !(*this == o); }

  private:
    template <size_t D>
    int flatten_index(array<int, D> idx) const {
        static_assert(1 <= D && D <= NDIMS);
        int res = 0;
        for (int i = 0; i < int(D); i++) {
            res += idx[i] * strides[i];
        }
        return res;
    }

  public:
    T& operator[](array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
    T* operator[](array<int, NDIMS - 1> idx) const { return data + flatten_index(idx); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, D;
    cin >> N >> M >> D;
    assert(D <= 64);

    vector<vector<int>> out(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        out[u].push_back(v);
    }

    auto [C, cmap] = build_scc(out, true);
    auto [edges, sccout, sccin] = condensate_scc(C, out, cmap);

    vector<int64_t> open(N);
    for (int u = 0; u < N; u++) {
        string s;
        cin >> s;
        for (int i = 0; i < D; i++) {
            if (s[i] == '1') {
                open[u] |= 1LL << i;
            }
        }
    }

    vector<vector<int>> cset(C);
    for (int u = 0; u < N; u++) {
        cset[cmap[u]].push_back(u);
    }

    // we need:
    // - cycle gcd for each component
    // - internal mod for each node, pick an arbitrary root
    // exit offsets from entry mod can be (depth-d+1),(depth-d+1+mod),...
    vector<int> mod(N, D), depth(N, -1), on(N);

    for (int c = 0; c < C; c++) {
        int root = cset[c][0];
        depth[root] = 0;
        y_combinator([&](auto self, int u) -> void {
            on[u] = true;
            for (int v : out[u]) {
                if (cmap[v] == c) {
                    if (depth[v] < 0) {
                        depth[v] = depth[u] + 1;
                        self(v);
                    } else if (on[v]) {
                        mod[c] = gcd(mod[c], 1 + depth[u] - depth[v]);
                    }
                }
            }
            on[u] = false;
        })(root);
    }

    tensor<int, 2> dp({C, D});
    for (int c = 0; c < C; c++) {
        int x = D / mod[c];
        for (int u : cset[c]) {
            int64_t mask = 0;
            for (int d = 0; d < mod[c]; d++) { // residue class
                for (int i = 0; i < x; i++) {
                    int k = d + i * mod[c];
                    if (open[u] >> k & 1) {
                        mask |= 1LL << d;
                        break;
                    }
                }
            }
            open[u] = mask;
        }
        for (int d = 0; d < mod[c]; d++) {
            for (int u : cset[c]) {
                int k = (d + depth[u]) % mod[c];
                dp[{c, d}] += open[u] >> k & 1;
            }
        }
        for (int d = 0; d < mod[c]; d++) {
            for (int i = 1; i < x; i++) {
                int k = d + i * mod[c];
                dp[{c, k}] = dp[{c, d}];
            }
        }
    }

    for (int c = 0; c < C; c++) {
        int x = D / mod[c];
        vector<int> add(mod[c]);
        for (int u : cset[c]) {
            for (int v : out[u]) {
                if (cmap[v] != c) {
                    for (int d = 0; d < mod[c]; d++) { // residue class
                        for (int i = 0; i < x; i++) {
                            int day_at_v = (depth[u] + d + i * mod[c] + 1) % D;
                            int day_at_root = ((day_at_v - depth[v]) % D + D) % D;
                            add[d] = max(add[d], dp[{cmap[v], day_at_root}]);
                        }
                    }
                }
            }
        }
        for (int d = 0; d < mod[c]; d++) {
            for (int i = 0; i < x; i++) {
                int day = d + i * mod[c];
                dp[{c, day}] += add[d];
            }
        }
    }

    cout << dp[{cmap[0], 0}] << '\n';
    return 0;
}