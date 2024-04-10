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
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<long> a(N), b(N);
        for (int i = 1; i < N; i++) {
            cin >> a[i], a[i]++;
        }
        for (int i = 1; i < N; i++) {
            cin >> b[i];
        }
        vector<vector<int>> g(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        long POWER = 1;
        long GAIN = 0;
        int remaining = N - 1;

        vector<long> start(N);
        vector<long> power_here(N);
        vector<int> prev(N);
        vector<bool> vis(N);
        vector<bool> clean(N);
        clean[0] = true;

        auto cmp = [&](int u, int v) {
            return make_tuple(start[u], -power_here[u], u) <
                   make_tuple(start[v], -power_here[v], v);
        };
        binary_int_heap heap(N, cmp);

        while (remaining > 0) {
            for (int i = 0; i < N; i++) {
                if (clean[i]) {
                    start[i] = POWER + GAIN;
                    heap.push(i);
                } else {
                    start[i] = 1e15;
                }
                power_here[i] = POWER + GAIN;
                prev[i] = -1;
                vis[i] = false;
            }

            assert(!heap.empty());

            int cheapest = -1;
            int link = -1;

            do {
                int u = heap.pop();
                vis[u] = true;
                for (int v : g[u]) {
                    if (!vis[v] && !clean[v]) {
                        // minimum power we need to fight v
                        long increment = max<long>(0, a[v] - power_here[u]);
                        long need = start[u] + increment;
                        long cand = increment + power_here[u] + b[v];
                        if (need < start[v] ||
                            (need == start[v] && cand > power_here[v])) {
                            start[v] = need;
                            power_here[v] = cand;
                            heap.push_or_improve(v);
                            prev[v] = u;
                        }
                    }
                }
            } while (!heap.empty());

            // now find cheapest cycle
            for (int v = 0; v < N; v++) {
                if (!clean[v]) {
                    for (int u : g[v]) {
                        if (v != prev[u] && u != prev[v] && start[u] <= start[v]) {
                            if (cheapest == -1 || cmp(v, cheapest)) {
                                cheapest = v;
                                link = u;
                                break;
                            }
                        }
                    }
                }
            }

            int u = cheapest;
            POWER = start[cheapest] - GAIN;
            while (u != -1) {
                if (!clean[u]) {
                    remaining--;
                    clean[u] = true;
                    GAIN += b[u];
                    a[u] = b[u] = 0;
                } else {
                    break;
                }
                u = prev[u];
            }
            u = link;
            while (u != -1) {
                if (!clean[u]) {
                    remaining--;
                    clean[u] = true;
                    GAIN += b[u];
                    a[u] = b[u] = 0;
                } else {
                    break;
                }
                u = prev[u];
            }
        }

        cout << POWER << '\n';
    }
    return 0;
}