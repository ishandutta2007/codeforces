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

template <typename Compare = less<>>
struct binary_int_heap {
    vector<int> c, id;
    Compare comp;

    explicit binary_int_heap(int N = 0, const Compare& comp = Compare())
        : c(0, 0), id(N, -1), comp(comp) {}

    bool empty() const { return c.empty(); }
    size_t size() const { return c.size(); }
    bool contains(int u) const { return id[u] != -1; }
    int top() const {
        assert(!empty());
        return c[0];
    }
    void push(int u) {
        assert(!contains(u));
        id[u] = c.size(), c.push_back(u);
        heapify_up(id[u]);
    }
    int pop() {
        assert(!empty());
        int u = c[0];
        c[0] = c.back();
        id[c[0]] = 0, id[u] = -1;
        c.pop_back();
        heapify_down(0);
        return u;
    }
    void improve(int u) { assert(contains(u)), heapify_up(id[u]); }
    void decline(int u) { assert(contains(u)), heapify_down(id[u]); }
    void push_or_improve(int u) { contains(u) ? improve(u) : push(u); }
    void push_or_decline(int u) { contains(u) ? decline(u) : push(u); }
    void clear() {
        for (int u : c)
            id[u] = -1;
        c.clear();
    }
    void fill() {
        for (int u = 0, N = id.size(); u < N; u++) {
            if (!contains(u)) {
                push(u);
            }
        }
    }

  private:
    static int parent(int i) { return (i - 1) >> 1; }
    static int child(int i) { return i << 1 | 1; }
    void exchange(int i, int j) { swap(id[c[i]], id[c[j]]), swap(c[i], c[j]); }
    void heapify_up(int i) {
        while (i > 0 && comp(c[i], c[parent(i)])) { // while c[i] < c[parent(i)]
            exchange(i, parent(i)), i = parent(i);
        }
    }
    void heapify_down(int i) {
        int k, S = c.size();
        while ((k = child(i)) < S) {
            if (k + 1 < S && !comp(c[k], c[k + 1])) // if c[rchild(i)] <= c[lchild(i)]
                k++;
            if (!comp(c[k], c[i])) // break if c[i] <= c[minchild(i)]
                break;
            exchange(i, k), i = k;
        }
    }
};

template <typename Container>
struct less_container {
    const Container* cont = nullptr;
    less_container() = default;
    less_container(const Container& cont) : cont(&cont) {}
    inline bool operator()(int u, int v) const {
        return tie((*cont)[u], u) < tie((*cont)[v], v);
    }
};

auto build_dominator_tree(int root, const vector<vector<int>>& out) {
    int V = out.size();
    assert(V > 0 && root > 0 && root < V);

    vector<vector<int>> in(V);
    vector<int> dom(V), parent(V), semi(V), vertex(V), ancestor(V), label(V);
    iota(begin(label), end(label), 0);
    int timer = 1;

    for (int u = 1; u < V; u++) {
        for (int v : out[u]) {
            in[v].push_back(u);
        }
    }

    auto dfs_index = y_combinator([&](auto self, int u) -> void {
        vertex[timer] = u, semi[u] = timer++;
        for (int v : out[u]) {
            if (semi[v] == 0) {
                parent[v] = u;
                self(v);
            }
        }
    });

    auto compress = y_combinator([&](auto self, int v) -> void {
        if (ancestor[ancestor[v]] != 0) {
            self(ancestor[v]);
            if (semi[label[v]] > semi[label[ancestor[v]]]) {
                label[v] = label[ancestor[v]];
            }
            ancestor[v] = ancestor[ancestor[v]];
        }
    });

    auto eval = [&](int v) -> int {
        if (ancestor[v] == 0) {
            return v;
        } else {
            compress(v);
            return label[v];
        }
    };

    dfs_index(root);

    vector<int> bucket_head(V, 0), bucket_next(V, 0);

    for (int i = V - 1; i >= 2; i--) {
        int w = vertex[i];
        for (int v : in[w]) {
            int u = eval(v);
            semi[w] = min(semi[w], semi[u]);
        }
        // push w onto the front of bucket b
        int b = vertex[semi[w]];
        bucket_next[w] = bucket_head[b], bucket_head[b] = w;
        ancestor[w] = parent[w]; // link
        // visit all nodes in bucket parent[w]
        for (int v = bucket_head[parent[w]]; v != 0; v = bucket_next[v]) {
            int u = eval(v);
            dom[v] = semi[u] < semi[v] ? u : parent[w];
        }
        bucket_head[parent[w]] = 0;
    }

    for (int i = 2; i < V; i++) {
        int w = vertex[i];
        if (dom[w] != vertex[semi[w]]) {
            dom[w] = dom[dom[w]];
        }
    }
    dom[root] = 0;

    // might wish to return semi as well
    return make_pair(dom, parent);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, s;
    cin >> N >> M >> s;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    static constexpr int64_t inf = 1e18;
    vector<int64_t> dist(N + 1, inf);
    binary_int_heap<less_container<vector<int64_t>>> heap(N + 1, dist);
    dist[s] = 0, heap.push(s);

    while (!heap.empty()) {
        int u = heap.pop();
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                heap.push_or_improve(v);
            }
        }
    }

    vector<vector<int>> minor(N + 1);
    for (int u = 1; u <= N; u++) {
        for (auto [v, w] : graph[u]) {
            if (dist[v] == dist[u] + w) {
                minor[u].push_back(v);
            }
        }
    }

    auto [dom, parent] = build_dominator_tree(s, minor);
    vector<vector<int>> tree(N + 1);
    for (int u = 1; u <= N; u++) {
        if (u != s) {
            tree[dom[u]].push_back(u);
        }
    }

    int ans = 0;
    y_combinator([&](auto self, int u) -> int {
        int count = 1;
        for (int v : tree[u]) {
            count += self(v);
        }
        if (u != s) {
            ans = max(ans, count);
        }
        return count;
    })(s);
    cout << ans << '\n';
    return 0;
}