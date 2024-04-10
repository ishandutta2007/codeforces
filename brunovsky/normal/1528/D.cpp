#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, long>>> g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    constexpr long inf = numeric_limits<long>::max() / 3;
    vector<long> dist;
    binary_int_heap<less_container<vector<long>>> heap(N, dist);

    for (int s = 0; s < N; s++) {
        dist.assign(N, inf);

        for (auto [v, w] : g[s]) {
            if (dist[v] > w) {
                dist[v] = w;
                heap.push_or_improve(v);
            }
        }

        while (!heap.empty()) {
            int u = heap.pop();
            int n = (u + 1) % N;
            if (dist[n] > dist[u] + 1) {
                dist[n] = dist[u] + 1;
                heap.push_or_improve(n);
            }
            for (auto [v, w] : g[u]) {
                v = (v + dist[u]) % N;
                if (dist[v] > w + dist[u]) {
                    dist[v] = w + dist[u];
                    heap.push_or_improve(v);
                }
            }
        }

        dist[s] = 0;
        for (int v = 0; v < N; v++) {
            cout << dist[v] << " \n"[v + 1 == N];
        }
    }

    return 0;
}