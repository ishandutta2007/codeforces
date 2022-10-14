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

template <typename Flow = int64_t, typename Cost = int64_t, typename FlowSum = Flow,
          typename CostSum = Cost>
struct mcmflow {
    struct Edge {
        int node[2];
        Flow cap, flow = 0;
        Cost cost;
    };
    int V, E = 0;
    vector<vector<int>> res;
    vector<Edge> edge;

    explicit mcmflow(int V) : V(V), res(V), pi(V, 0), heap(V, dist) {}

    void add(int u, int v, Flow capacity, Cost cost) {
        assert(0 <= u && u < V && 0 <= v && v < V && u != v && capacity > 0);
        res[u].push_back(E++), edge.push_back({{u, v}, capacity, 0, cost});
        res[v].push_back(E++), edge.push_back({{v, u}, 0, 0, -cost});
    }

    using heap_t = pairing_int_heap<less_container<vector<CostSum>>>;
    vector<CostSum> dist, pi;
    vector<int> prev;
    heap_t heap;
    static inline constexpr Flow flowinf = numeric_limits<Flow>::max() / 2;
    static inline constexpr FlowSum flowsuminf = numeric_limits<FlowSum>::max() / 2;
    static inline constexpr CostSum costsuminf = numeric_limits<CostSum>::max() / 3;

    // First augmenting path on a DAG in O(V+E) with topological sort
    bool dag_init(int s, int t) {
        dist.assign(V, costsuminf);
        prev.assign(V, -1);
        dist[s] = 0;

        vector<int> deg(V), topo(V);
        int B = 0;

        for (int e = 0; e < E; e += 2) {
            int v = edge[e].node[1];
            deg[v]++;
        }
        for (int u = 0; u < V; u++) {
            if (deg[u] == 0) {
                topo[B++] = u;
            }
        }
        for (int i = 0; i < B; i++) {
            int u = topo[i];
            for (int e : res[u]) {
                if (e % 2 == 0) { // forward edge
                    int v = edge[e].node[1];
                    CostSum w = dist[u] + edge[e].cost;
                    if (edge[e].flow < edge[e].cap && dist[v] > w) {
                        dist[v] = w;
                        prev[v] = e;
                    }
                    if (--deg[v] == 0) {
                        topo[B++] = v;
                    }
                }
            }
        }
        assert(B == V);

        reprice();
        return prev[t] != -1;
    }

    // First augmenting path with SPFA in O(V+E) expected time.
    bool spfa_init(int s, int t) {
        dist.assign(V, costsuminf);
        prev.assign(V, -1);
        dist[s] = 0;

        vector<bool> in_queue(V, false);
        deque<int> Q;
        Q.push_back(s);

        do {
            int u = Q.front();
            Q.pop_front(), in_queue[u] = false;

            for (auto e : res[u]) {
                int v = edge[e].node[1];
                CostSum w = dist[u] + edge[e].cost;
                if (edge[e].flow < edge[e].cap && dist[v] > w) {
                    dist[v] = w;
                    prev[v] = e;
                    if (!in_queue[v]) {
                        if (Q.empty() || dist[v] <= dist[Q.front()]) {
                            Q.push_front(v);
                        } else {
                            Q.push_back(v);
                        }
                        in_queue[v] = true;
                    }
                }
            }
        } while (!Q.empty());

        reprice();
        return prev[t] != -1;
    }

    // First augmenting path with dijkstra (also the regular augmentor) in O(E log V)
    bool dijkstra(int s, int t) {
        dist.assign(V, costsuminf);
        prev.assign(V, -1);
        dist[s] = 0;

        heap.push(s);

        do {
            auto u = heap.pop();
            for (int e : res[u]) {
                int v = edge[e].node[1];
                CostSum w = min(dist[u] + pi[u] - pi[v] + edge[e].cost, costsuminf);
                if (edge[e].flow < edge[e].cap && dist[v] > w) {
                    dist[v] = w;
                    prev[v] = e;
                    heap.push_or_improve(v);
                }
            }
        } while (!heap.empty() && heap.top() != t);

        heap.clear();
        reprice();
        return prev[t] != -1;
    }

    void reprice() {
        for (int u = 0; u < V; u++) {
            pi[u] = min(dist[u] + pi[u], costsuminf);
        }
    }

    auto path(int v) const {
        vector<int> path;
        while (prev[v] != -1) {
            path.push_back(prev[v]);
            v = edge[prev[v]].node[0];
        }
        return path;
    }

    // Augment until we get F flow, C cost, P augmenting paths, or hit minimum cut.
    auto mincost_flow(int s, int t, FlowSum F, CostSum C, int P) {
        assert(F > 0 && C > 0 && P > 0);
        FlowSum sflow = 0;
        CostSum scost = 0;
        int paths = 0;

        if (prev[t] == -1) {
            return make_tuple(sflow, scost, paths);
        }
        do {
            auto augmenting_path = path(t);
            Flow df = min(F - sflow, FlowSum(flowinf));
            CostSum dc = 0;
            for (int e : augmenting_path) {
                df = min(df, edge[e].cap - edge[e].flow);
                dc += edge[e].cost;
            }
            if (dc > 0 && df > (C - scost) / dc) {
                df = (C - scost) / dc;
                if (df == 0) {
                    break; // can't augment without busting C
                }
            }
            sflow += df;
            scost += df * dc;
            paths++;
            for (int e : augmenting_path) {
                edge[e].flow += df;
                edge[e ^ 1].flow -= df;
            }
        } while (sflow < F && scost < C && paths < P && dijkstra(s, t));

        return make_tuple(sflow, scost, paths);
    }

    auto mincost_flow(int s, int t) {
        return mincost_flow(s, t, flowsuminf, costsuminf, INT_MAX);
    }
    // bound the number of augmenting paths
    auto mincost_flow_bounded_paths(int s, int t, int P) {
        return mincost_flow(s, t, flowsuminf, costsuminf, P);
    }
    // bound the flow from s to t
    auto mincost_flow_bounded_flow(int s, int t, FlowSum F) {
        return mincost_flow(s, t, F, costsuminf, INT_MAX);
    }
    // bound the flow cost from s to t
    auto mincost_flow_bounded_cost(int s, int t, CostSum C) {
        return mincost_flow(s, t, flowsuminf, C, INT_MAX);
    }
    // reset the flow network; you must call *_init() again
    void clear_flow() {
        for (int e = 0; e < E; e++) {
            edge[e].flow = 0;
        }
        pi.assign(V, 0);
    }

    Flow get_flow(int e) const { return edge[2 * e].flow; }
    bool left_of_mincut(int u) const { return dist[u] < costsuminf; }
};

auto gen() {
    cout << 20 << ' ' << 200 << '\n';
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 1000000);
    for (int i = 0; i < (1 << 20); i++) {
        cout << dist(rng) << " \n"[i + 1 == (1 << 20)];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(1 << N);
    for (int i = 0; i < (1 << N); i++) {
        cin >> A[i];
    }

    unsigned S = min<int>(N << (N - 1), 2 * N * K);
    auto compare = [&](auto x, auto y) { return A[x[0]] + A[x[1]] > A[y[0]] + A[y[1]]; };
    priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(compare)> heap(compare);

    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) & 1) {
            for (int b = 0; b < N; b++) {
                int j = i ^ (1 << b);
                heap.push({i, j});
                if (heap.size() > S) {
                    heap.pop();
                }
            }
        }
    }

    vector<array<int, 2>> pairs;
    while (!heap.empty()) {
        pairs.push_back(heap.top()), heap.pop();
    }

    vector<int> id(1 << N, -1), nums;
    for (auto [a, b] : pairs) {
        for (int i : {a, b}) {
            if (id[i] == -1) {
                id[i] = nums.size();
                nums.push_back(i);
            }
        }
    }

    S = nums.size();
    int s = S, t = S + 1;
    mcmflow<int, int> mcm(S + 2);
    for (auto [a, b] : pairs) {
        mcm.add(id[a], id[b], 1, 0);
    }
    for (int i : nums) {
        if (__builtin_popcount(i) & 1) {
            mcm.add(s, id[i], 1, -A[i]);
        } else {
            mcm.add(id[i], t, 1, -A[i]);
        }
    }

    mcm.dag_init(s, t);
    auto [flow, cost, paths] = mcm.mincost_flow_bounded_paths(s, t, K);
    cout << -cost << '\n';
    return 0;
}