#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

// Based on editorial

inline namespace lib {

template <typename Container>
struct less_container {
    const Container* cont = nullptr;
    less_container() = default;
    less_container(const Container& cont) : cont(&cont) {}
    inline bool operator()(int u, int v) const {
        return tie((*cont)[u], u) < tie((*cont)[v], v);
    }
};

template <typename Compare = less<>>
struct pairing_int_heap {
    struct node_t {
        int parent = 0, child = 0, next = 0, prev = 0;
    }; // elements are shifted by 1 to allow 0 to be used as a scratchpad
    vector<node_t> node;
    int root = 0;
    Compare comp;

    explicit pairing_int_heap(int N = 0, const Compare& comp = Compare())
        : node(N + 1), comp(comp) {}

    bool empty() const { return root == 0; }
    bool contains(int u) const { return u++, node[u].parent != 0; }
    int top() const { return root - 1; }

    void push(int u) {
        assert(!contains(u)), u++;
        node[u].parent = -1;
        root = safe_meld(root, u);
    }
    int pop() {
        assert(!empty());
        int u = root;
        root = two_pass_pairing(u);
        node[root].parent = -1;
        node[u] = node_t();
        return u - 1;
    }
    void improve(int u) {
        assert(!empty() && contains(u)), u++;
        if (u != root && do_comp(u, node[u].parent)) {
            take(u), root = meld(root, u);
        }
    }
    void push_or_improve(int u) {
        if (contains(u)) {
            improve(u);
        } else {
            push(u);
        }
    }
    void adjust(int u) {
        erase(u);
        push(u);
    }
    void erase(int u) {
        assert(contains(u)), u++;
        if (u == root) {
            pop();
        } else {
            take(u);
            int v = two_pass_pairing(u);
            root = safe_meld(root, v);
            node[root].parent = -1;
            node[u] = node_t();
        }
    }
    void clear() {
        if (!empty()) {
            clear_rec(root), root = 0;
        }
    }
    void fill() {
        for (int u = 1, N = node.size() - 1; u <= N; u++) {
            if (!contains(u)) {
                push(u);
            }
        }
    }

  private:
    bool do_comp(int u, int v) const { return comp(u - 1, v - 1); }
    int meld(int u, int v) { return do_comp(u, v) ? splice(u, v) : splice(v, u); }
    int safe_meld(int u, int v) {
        if (u == 0 || v == 0 || u == v)
            return u ? u : v;
        return meld(u, v);
    }
    int splice(int u, int v) {
        node[node[u].child].prev = v;
        node[v].next = node[u].child, node[u].child = v;
        return node[v].prev = node[v].parent = u;
    }
    void take(int u) {
        assert(node[u].parent > 0);
        if (node[node[u].parent].child == u) {
            node[node[u].parent].child = node[u].next;
        } else {
            node[node[u].prev].next = node[u].next;
        }
        node[node[u].next].prev = node[u].prev;
    }
    int two_pass_pairing(int n) {
        if (node[n].child == 0)
            return 0;
        int u = node[n].child, v = node[u].next, w;
        while (v && node[v].next) {
            w = node[node[v].next].next;
            u = node[u].next = v = meld(v, node[v].next);
            v = node[v].next = w;
        }
        u = node[n].child, v = node[u].next;
        while (v) {
            w = node[v].next, u = meld(u, v), v = w;
        }
        return u;
    }
    void clear_rec(int u) {
        for (int v = node[u].child, w = node[v].next; v; v = w, w = node[v].next) {
            clear_rec(v);
        }
        node[u] = node_t();
    }
};

template <typename Cost = long, typename CostSum = Cost>
auto dijkstra(int s, const vector<vector<pair<int, Cost>>>& adj) {
    constexpr CostSum inf = numeric_limits<CostSum>::max() / 2;

    int V = adj.size();
    vector<CostSum> dist(V, inf);
    // vector<int> prev(V, -1);
    dist[s] = 0;

    pairing_int_heap heap(V, [&](int u, int v) { return dist[u] < dist[v]; });
    heap.push(s);

    do {
        int u = heap.pop();

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                // prev[v] = u;
                heap.push_or_improve(v);
            }
        }
    } while (!heap.empty());

    // return make_pair(move(dist), move(prev));
    return dist;
}

} // namespace lib

auto solve() {
    int N;
    cin >> N;
    vector<long> A(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> C[i];
    }

    vector<int> index(N);
    iota(begin(index), end(index), 0);
    sort(begin(index), end(index), [&](int u, int v) { return A[u] < A[v]; });

    vector<vector<pair<int, long>>> g(N);
    for (int i = 0; i + 1 < N; i++) {
        int u = index[i], v = index[i + 1];
        int L = i, R = N;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            int w = index[M];
            if (A[w] - A[u] - C[u] <= 0) {
                L = M;
            } else {
                R = M;
            }
        }
        g[v].push_back({u, 0});
        if (L > i) {
            assert(A[index[L]] <= A[u] + C[u]);
            g[u].push_back({index[L], 0});
        }
        if (R < N) {
            assert(A[index[R]] > A[u] + C[u]);
            g[u].push_back({index[R], A[index[R]] - A[u] - C[u]});
        }
    }

    auto dist = dijkstra(index[0], g);
    return dist[index[N - 1]] + accumulate(begin(C), end(C), 0LL);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}