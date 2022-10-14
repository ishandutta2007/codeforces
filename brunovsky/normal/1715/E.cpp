#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

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
        for (int u = 0, N = node.size() - 1; u < N; u++) {
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

template <typename V, typename Dn, typename Cn>
auto solve_1d1d_concave(int N, V zero, Dn&& dn, Cn&& costfn) {
    vector<V> E(N), D(N);
    E[0] = zero;
    D[0] = dn(E[0], 0);

    vector<array<int, 2>> stk;

    auto cost = [&](int j, int i) { return D[j] + costfn(j, i); };

    auto improv = [&](int j, int i, int t) {
        int l = i - 1, r = t;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            cost(j, m) >= cost(i - 1, m) ? l = m : r = m;
        }
        return l;
    };

    for (int i = 1, S = -1; i < N; i++) {
        while (S >= 0) {
            auto [j, t] = stk[S];
            if (cost(i - 1, t) <= cost(j, t)) {
                stk.pop_back(), S--;
            } else {
                break;
            }
        }

        if (int t = S < 0 ? N - 1 : improv(stk[S][0], i, stk[S][1]); t >= i) {
            stk.push_back({i - 1, t}), S++;
        }

        E[i] = cost(stk[S][0], i);
        D[i] = dn(E[i], i);

        if (S >= 0 && stk[S][1] == i) {
            stk.pop_back(), S--;
        }
    }

    return E;
}

template <typename T>
struct cht_line {
    T m, b;
    mutable T end; // largest x for which this line is in the hull
    bool operator<(const cht_line<T>& other) const { return m < other.m; }
    bool operator<(T x) const { return end < x; }
};

template <typename T>
struct dynamic_cht : multiset<cht_line<T>, less<>> {
    using Line = cht_line<T>;
    using base_t = multiset<cht_line<T>, less<>>;
    static inline const T pinf = numeric_limits<T>::max();
    static inline const T ninf = numeric_limits<T>::lowest();
    static inline const T eps = 20 * numeric_limits<T>::epsilon();
    static inline T zerodiv(T a, T b) {
        if constexpr (is_integral<T>::value) {
            return (a < 0) != (b < 0) ? a / b - !!(a % b) : a / b;
        } else {
            return a / b;
        }
    }
    bool intersect(typename base_t::iterator x, typename base_t::iterator y) {
        if (y == base_t::end()) {
            x->end = pinf;
            return false;
        }
        if (abs(x->m - y->m) <= eps) {
            x->end = x->b > y->b ? pinf : ninf;
        } else {
            x->end = zerodiv(y->b - x->b, x->m - y->m);
        }
        return x->end >= y->end;
    }
    void add(T m, T b) {
        auto z = base_t::insert(cht_line<T>{m, b, 0});
        auto y = z++;
        auto x = y;
        while (intersect(y, z)) {
            z = base_t::erase(z);
        }
        if (x != base_t::begin() && intersect(--x, y)) {
            intersect(x, y = base_t::erase(y));
        }
        while ((y = x) != base_t::begin() && (--x)->end >= y->end) {
            intersect(x, base_t::erase(y));
        }
    }
    cht_line<T> argmax(T x) const {
        assert(!base_t::empty());
        return *base_t::lower_bound(x);
    }
    T max(T x) const {
        auto line = argmax(x);
        return line.m * x + line.b;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> out(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        out[u].emplace_back(v, w);
        out[v].emplace_back(u, w);
    }
    constexpr int64_t inf = 1e16;
    vector<int64_t> dist(N, inf);
    dist[0] = 0;
    pairing_int_heap<less_container<vector<int64_t>>> heap(N, dist);
    heap.push(0);
    while (!heap.empty()) {
        int u = heap.pop();
        for (auto [v, w] : out[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                heap.push_or_improve(v);
            }
        }
    }
    vector<int> order(N);
    iota(begin(order), end(order), 0);
    while (K--) {
        sort(begin(order), end(order), [&](int i, int j) { return dist[i] < dist[j]; });
        dynamic_cht<int64_t> cht;
        for (int u : order) {
            cht.add(2 * u, -dist[u] - 1LL * u * u);
            dist[u] = min<int64_t>(dist[u], 1LL * u * u - cht.max(u));
        }
        heap.fill();
        while (!heap.empty()) {
            int u = heap.pop();
            for (auto [v, w] : out[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    heap.push_or_improve(v);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dist[i] << " \n"[i + 1 == N];
    }
    return 0;
}

//