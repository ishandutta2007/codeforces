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

template <typename Flow = int64_t, typename FlowSum = Flow>
struct dinitz_flow {
    static inline default_random_engine rng = default_random_engine(random_device{}());
    struct Edge {
        int node[2];
        Flow cap, flow = 0;
    };
    int V, E = 0;
    vector<vector<int>> res;
    vector<Edge> edge;

    explicit dinitz_flow(int V) : V(V), res(V) {}

    int add(int u, int v, Flow capacity) {
        assert(0 <= u && u < V && 0 <= v && v < V && capacity >= 0);
        res[u].push_back(E++), edge.push_back({{u, v}, capacity, 0});
        res[v].push_back(E++), edge.push_back({{v, u}, 0, 0});
        return (E - 2) >> 1;
    }
    int add_node() { return res.emplace_back(), V++; }
    void update_edge(int e, Flow capacity) { edge[2 * e].cap = capacity; }

    void shuffle_edges() {
        for (int u = 0; u < V; u++) {
            shuffle(begin(res[u]), end(res[u]), rng);
        }
    }

    vector<int> level, Q, head_edge, next_edge;
    static constexpr Flow flowinf = numeric_limits<Flow>::max() / 2;

    bool bfs(int s, int t) {
        level.assign(V, -1);
        head_edge.assign(V, -1);
        next_edge.assign(E, -1);
        level[s] = 0;
        Q[0] = s;
        for (int i = 0, S = 1; i < S && level[Q[i]] != level[t]; i++) {
            int u = Q[i];
            for (int e : res[u]) {
                int v = edge[e].node[1];
                if (edge[e].flow < edge[e].cap) {
                    if (level[v] == -1) {
                        level[v] = level[u] + 1;
                        Q[S++] = v;
                    }
                    if (level[u] < level[v]) {
                        next_edge[e] = head_edge[u], head_edge[u] = e;
                    }
                }
            }
        }
        return level[t] != -1;
    }

    auto dfs(int u, int t, Flow mincap) {
        if (u == t) {
            return mincap;
        }
        Flow preflow = 0;
        int& e = head_edge[u];
        while (e != -1 && mincap > 0) {
            int v = edge[e].node[1];
            if (Flow df = dfs(v, t, min(mincap, edge[e].cap - edge[e].flow))) {
                edge[e].flow += df;
                edge[e ^ 1].flow -= df;
                preflow += df;
                mincap -= df;
            }
            if (edge[e].flow == edge[e].cap || mincap > 0) {
                e = next_edge[e];
            }
        }
        return preflow;
    }

    FlowSum maxflow(int s, int t) {
        Q.resize(V);
        FlowSum max_flow = 0;
        while (bfs(s, t)) {
            max_flow += dfs(s, t, flowinf);
        }
        return max_flow;
    }

    void clear_flow() {
        for (int e = 0; e < E; e++) {
            edge[e].flow = 0;
        }
    }
    Flow get_flow(int e) const { return edge[2 * e].flow; }
    bool left_of_mincut(int u) const { return level[u] >= 0; }
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
        assert(0 <= u && u < V && 0 <= v && v < V && u != v);
        res[u].push_back(E++), edge.push_back({{u, v}, capacity, 0, cost});
        res[v].push_back(E++), edge.push_back({{v, u}, 0, 0, -cost});
    }

    void update_edge(int e, Flow capacity) { edge[2 * e].cap = capacity; }

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int R = 7, C = 8, L = 10;
    string pic[R];
    for (int i = 0; i < R; i++) {
        cin >> pic[i];
    }

    vector<string> lab = {"BY", "BW", "BR", "BB", "RY", "RW", "RR", "WY", "WW", "YY"};
    for (int i = 0; i < L; i++) {
        if (lab[i][0] > lab[i][1]) {
            swap(lab[i][0], lab[i][1]);
        }
    }
    array<int, L> pool = {};
    for (int i = 0; i < L; i++) {
        cin >> pool[i];
    }

    auto get_label = [&](string s) {
        if (s[0] > s[1]) {
            swap(s[0], s[1]);
        }
        for (int i = 0; i < L; i++) {
            if (lab[i] == s) {
                return i;
            }
        }
        assert(false);
    };

    array<int, L> count = {};
    int8_t used[R][C] = {};
    set<array<int, L>> can;

    auto advance = [&](int r, int c) {
        while (r < R) {
            while (c < C && used[r][c]) {
                c++;
            }
            if (c == C) {
                r++, c = 0;
            } else {
                break;
            }
        }
        return make_pair(r, c);
    };

    y_combinator([&](auto self, int r, int c) -> void {
        if (r == R) {
            can.insert(count);
            return;
        }
        if (r + 1 < R && !used[r + 1][c]) {
            string s;
            s.push_back(pic[r][c]);
            s.push_back(pic[r + 1][c]);
            int l = get_label(s);
            used[r][c] = used[r + 1][c] = true;
            count[l]++;
            auto [rn, cn] = advance(r, c);
            self(rn, cn);
            count[l]--;
            used[r][c] = used[r + 1][c] = false;
        }
        if (c + 1 < C && !used[r][c + 1]) {
            string s;
            s.push_back(pic[r][c]);
            s.push_back(pic[r][c + 1]);
            int l = get_label(s);
            used[r][c] = used[r][c + 1] = true;
            count[l]++;
            auto [rn, cn] = advance(r, c);
            self(rn, cn);
            count[l]--;
            used[r][c] = used[r][c + 1] = false;
        }
    })(0, 0);

    mcmflow<int> mf(2 * L + 2);
    int s = 2 * L, t = 2 * L + 1;

    for (int i = 0; i < L; i++) {
        mf.add(i + L, t, 1, 0);
    }
    for (int i = 0; i < L; i++) {
        mf.add(s, i, pool[i], 0);
    }
    for (int i = 0; i < L; i++) {
        mf.add(i, i + L, pool[i], -2);
        for (int j = 0; j < L; j++) {
            if (i != j) {
                if (lab[i][0] == lab[j][0] || lab[i][1] == lab[j][0] ||
                    lab[i][0] == lab[j][1] || lab[i][1] == lab[j][1]) {
                    mf.add(i, j + L, pool[i], -1);
                } else {
                    mf.add(i, j + L, pool[i], 0);
                }
            }
        }
    }

    int best_score = -1;
    array<int, L> best_mask = {};

    for (auto mask : can) {
        mf.clear_flow();
        for (int i = 0; i < L; i++) {
            mf.update_edge(i, mask[i]);
        }
        mf.dag_init(s, t);
        auto [flow, cost, paths] = mf.mincost_flow(s, t);
        int score = -cost;
        if (best_score < score) {
            best_score = score;
            best_mask = mask;
        }
    }

    vector<tuple<int, array<int, 2>, array<int, 2>>> pos;

    y_combinator([&](auto self, int r, int c) -> bool {
        if (r == R) {
            return count == best_mask;
        }
        if (r + 1 < R && !used[r + 1][c]) {
            string x;
            x.push_back(pic[r][c]);
            x.push_back(pic[r + 1][c]);
            int l = get_label(x);
            used[r][c] = used[r + 1][c] = true;
            count[l]++;
            pos.push_back({l, {r, c}, {r + 1, c}});
            auto [rn, cn] = advance(r, c);
            if (self(rn, cn)) {
                return true;
            }
            pos.pop_back();
            count[l]--;
            used[r][c] = used[r + 1][c] = false;
        }
        if (c + 1 < C && !used[r][c + 1]) {
            string x;
            x.push_back(pic[r][c]);
            x.push_back(pic[r][c + 1]);
            int l = get_label(x);
            used[r][c] = used[r][c + 1] = true;
            count[l]++;
            pos.push_back({l, {r, c}, {r, c + 1}});
            auto [rn, cn] = advance(r, c);
            if (self(rn, cn)) {
                return true;
            }
            pos.pop_back();
            count[l]--;
            used[r][c] = used[r][c + 1] = false;
        }
        return false;
    })(0, 0);

    mf.clear_flow();
    for (int i = 0; i < L; i++) {
        mf.update_edge(i, best_mask[i]);
    }
    mf.dag_init(s, t);
    mf.mincost_flow(s, t);

    array<array<int, L>, L> uses = {};
    for (int e = 2 * L; e < mf.E / 2; e++) {
        auto [u, v] = mf.edge[2 * e].node;
        assert(0 <= u && u < L && L <= v && v < 2 * L);
        uses[u][v - L] += mf.edge[2 * e].flow;
    }
    for (int i = 0; i < L; i++) {
        debug(uses[i]);
    }

    string ans[2 * R - 1] = {};
    for (int r = 0; r < 2 * R - 1; r++) {
        ans[r].assign(2 * C - 1, '.');
    }

    auto assign = [&](int u, int v, auto x, auto y) {
        auto [rx, cx] = x;
        auto [ry, cy] = y;
        string K;
        K.push_back(pic[rx][cx]);
        K.push_back(pic[ry][cy]);
        int orx = 2 * rx;
        int ocx = 2 * cx;
        int ory = 2 * ry;
        int ocy = 2 * cy;
        assert(uses[u][v] > 0 && pool[u] > 0);
        uses[u][v]--;
        pool[u]--;
        ans[orx][ocx] = lab[u][0];
        ans[ory][ocy] = lab[u][1];
        if (lab[u][0] != K[0] && lab[u][1] != K[1]) {
            swap(ans[orx][ocx], ans[ory][ocy]);
        }
        if (rx == ry) {
            ans[orx][ocx + 1] = '-';
        } else {
            ans[orx + 1][ocx] = '|';
        }
    };

    for (auto [v, x, y] : pos) {
        for (int u = 0; u < L; u++) {
            if (uses[u][v]) {
                assign(u, v, x, y);
                break;
            }
        }
    }

    cout << best_score << '\n';
    for (int r = 0; r < 2 * R - 1; r++) {
        cout << ans[r] << '\n';
    }
    return 0;
}