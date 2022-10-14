#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

struct Hasher {
    template <typename Container>
    size_t operator()(const Container& vec) const noexcept {
        using std::hash;
        hash<typename Container::value_type> hasher;
        size_t seed = distance(begin(vec), end(vec));
        for (const auto& n : vec) {
            seed ^= hasher(n) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
    template <typename U, typename V>
    size_t operator()(const pair<U, V>& p) const noexcept {
        using std::hash;
        size_t a = hash<U>{}(p.first), b = hash<V>{}(p.second);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <typename U>
    size_t operator()(const array<U, 2>& p) const noexcept {
        using std::hash;
        hash<U> hasher;
        size_t a = hasher(p[0]), b = hasher(p[1]);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <int i, typename Tuple>
    size_t tuple_compute(const Tuple& tuple) const noexcept {
        if constexpr (i == std::tuple_size_v<Tuple>) {
            return std::tuple_size_v<Tuple>;
        } else {
            using std::hash;
            hash<std::tuple_element_t<i, Tuple>> hasher;
            size_t seed = tuple_compute<i + 1, Tuple>(tuple);
            size_t h = hasher(std::get<i>(tuple));
            return seed ^ (h + 0x9e3779b9 + (seed << 6) + (seed >> 2));
        }
    }
    template <typename... Ts>
    size_t operator()(const tuple<Ts...>& t) const noexcept {
        return tuple_compute<0, tuple<Ts...>>(t);
    }
};

namespace std {

template <typename T, size_t N>
struct hash<array<T, N>> : Hasher {};
template <typename T>
struct hash<vector<T>> : Hasher {};
template <typename U, typename V>
struct hash<pair<U, V>> : Hasher {};
template <typename... Ts>
struct hash<tuple<Ts...>> : Hasher {};

} // namespace std

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) { next[u] = next[find(u)] = u; }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

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
        assign(shape_, t);
    }

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

    void assign(std::array<int, NDIMS> shape_, const T& t = T()) {
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

    friend istream& operator>>(istream& in, tensor& t) {
        for (int i = 0; i < t.len; i++) {
            in >> t.data[i];
        }
        return in;
    }
    bool operator==(const tensor& o) const {
        return shape == o.shape && equal(data, data + len, o.data);
    }
    bool operator!=(const tensor& o) const { return !(*this == o); }

  private:
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

auto build_scc(const vector<vector<int>>& out) {
    int V = out.size(), C = 0; // C = number of scc

    vector<vector<int>> cset;
    vector<int> cmap(V, -1);
    vector<int> index(V);
    vector<int> lowlink(V);
    int timer = 1;

    stack<int> S;

    auto dfs = y_combinator([&](auto self, int u) -> void {
        index[u] = lowlink[u] = timer++;
        S.push(u);

        for (int v : out[u]) {
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
            cset.push_back({});
            int v;
            do {
                v = S.top(), S.pop();
                cmap[v] = c, cset[c].push_back(v);
            } while (u != v);
        }
    });

    for (int u = 0; u < V; u++) {
        if (!index[u]) {
            dfs(u);
        }
    }

    return make_tuple(C, cset, cmap);
}

auto condensate_scc(const vector<vector<int>>& adj, const vector<int>& cmap) {
    int V = adj.size(), C = 0;
    unordered_set<array<int, 2>> edges;
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            if (cmap[u] != cmap[v]) {
                edges.insert({cmap[u], cmap[v]});
            }
        }
        C = max(C, cmap[u] + 1);
    }

    vector<vector<int>> sccout(C), sccin(C);
    for (auto [u, v] : edges) {
        sccout[u].push_back(v);
        sccin[v].push_back(u);
    }
    return make_pair(sccout, sccin);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    vector<vector<int>> id(N, vector<int>(M, -1));
    vector<array<int, 2>> where;
    int V = 0;

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (board[i][j] == '#') {
                where.push_back({i, j});
                id[i][j] = V++;
            }
        }
    }

    vector<int> closest_below(M, -1);
    vector<vector<int>> out(V);

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '#') {
                int above = id[i][j];
                for (int c : {j - 1, j, j + 1}) {
                    if (0 <= c && c < M && closest_below[c] >= 0) {
                        int below = id[closest_below[c]][c];
                        out[above].push_back(below);
                        if (closest_below[c] == i + 1 && c == j) {
                            out[below].push_back(above);
                        }
                    }
                }
            }
        }
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '#') {
                closest_below[j] = i;
            }
        }
        for (int j = 0; j + 1 < M; j++) {
            if (board[i][j] == '#' && board[i][j + 1] == '#') {
                int u = id[i][j];
                int v = id[i][j + 1];
                out[u].push_back(v);
                out[v].push_back(u);
            }
        }
    }

    auto [C, cset, cmap] = build_scc(out);
    auto [sccout, sccin] = condensate_scc(out, cmap);

    vector<int> heads;
    for (int c = 0; c < C; c++) {
        if (sccin[c].empty()) {
            heads.push_back(c);
        }
    }
    int H = heads.size();
    sort(begin(heads), end(heads), [&](int u, int v) { return cset[u][0] < cset[v][0]; });

    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }

    vector<bool> eventually(C);
    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i >= 0 && a[j] > 0; i--) {
            if (board[i][j] == '#') {
                int c = cmap[id[i][j]];
                eventually[c] = true;
                a[j]--;
            }
        }
        assert(a[j] == 0);
    }

    vector<bool> is_necessary = eventually;
    for (int c = C - 1; c >= 0; c--) {
        if (eventually[c]) {
            for (int d : sccout[c]) {
                is_necessary[d] = false;
                eventually[d] = true;
            }
        }
    }

    vector<int> need;
    for (int c = 0; c < C; c++) {
        if (is_necessary[c]) {
            need.push_back(c);
        }
    }
    int K = need.size();
    if (K == 0) {
        cout << 0 << '\n';
        return 0;
    }

    sort(begin(need), end(need), [&](int u, int v) { return cset[u][0] < cset[v][0]; });

    vector<int> dpL(C, K + 1), dpR(C, -1);
    for (int i = 0; i < K; i++) {
        dpL[need[i]] = i;
        dpR[need[i]] = i + 1;
    }

    for (int c = 0; c < C; c++) {
        if (dpR[c] != -1) {
            for (int d : sccin[c]) {
                dpL[d] = min(dpL[d], dpL[c]);
                dpR[d] = max(dpR[d], dpR[c]);
            }
        }
    }

    // we only need to try the heads
    sort(begin(heads), end(heads), [&](int u, int v) {
        return make_tuple(dpL[u], -dpR[u], u) < make_tuple(dpL[v], -dpR[v], v);
    });

    // we pick heads[0] always now
    int ans = 1;
    set<pair<int, int>, greater<>> candidates;
    int R = dpR[heads[0]], h = 1;
    while (R < K) {
        while (h < H && dpL[heads[h]] <= R) {
            int r = dpR[heads[h]];
            candidates.insert({r, h});
            h++;
        }
        assert(!candidates.empty());
        int candidate = candidates.begin()->second;
        candidates.erase(candidates.begin());
        int r = dpR[heads[candidate]];
        assert(r > R);
        R = r;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}