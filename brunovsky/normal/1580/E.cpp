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

using Argmin = array<int, 2>;
struct Run {
    mutable int L, R = 0;
    mutable Argmin argmin = {}; // minimum, second_min
    bool operator<(const Run& o) const { return make_pair(L, R) < make_pair(o.L, o.R); }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<uint64_t> weight(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> parent(N), order, rank(N);
    vector<uint64_t> dist(N, 1e18);
    pairing_int_heap<less_container<vector<uint64_t>>> heap(N, dist);

    dist[0] = 0;
    heap.push(0);
    do {
        int u = heap.pop();
        rank[u] = order.size();
        order.push_back(u);
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                heap.push_or_improve(v);
            }
        }
    } while (!heap.empty());

    vector<int> rank_next(N);
    for (int l = 0, r = 1; l < N; l = r++) {
        while (r < N && dist[order[l]] == dist[order[r]]) {
            r++;
        }
        for (int i = l; i < r; i++) {
            rank_next[i] = r;
        }
    }

    vector<int> needs(N);
    for (int u = 1; u < N; u++) {
        for (auto [v, w] : adj[u]) {
            assert(dist[v] + w >= dist[u]);
            if (dist[v] + w == dist[u]) {
                needs[u]++;
            }
        }
        needs[u] = needs[u] == 1;
    }

    vector<vector<int>> kids(N);
    vector<int> needy;
    for (int i = 1; i < N; i++) {
        if (int u = order[i]; needs[u]) {
            if (parent[u] != 0) {
                kids[parent[u]].push_back(i);
            } // 0 doesn't care
            needy.push_back(i);
        }
    }

    auto count_needy = [&](int l, int r) {
        auto lit = lower_bound(begin(needy), end(needy), l);
        auto rit = lower_bound(begin(needy), end(needy), r);
        return rit - lit;
    };
    auto count_kids = [&](int p, int l, int r) {
        auto lit = lower_bound(begin(kids[p]), end(kids[p]), l);
        auto rit = lower_bound(begin(kids[p]), end(kids[p]), r);
        return rit - lit;
    };

    using Query = pair<int, uint64_t>;
    vector<Query> queries(Q);
    for (int q = 0; q < Q; q++) {
        int u, x;
        cin >> u >> x, u--;
        queries[q] = {u, x};
        weight[u] += x;
    }

    // argmin[i]: best answer at order i, using nodes [0,rank_head[i])
    vector<Argmin> argmin(N, {0, 0});
    set<Run> runs;

    Argmin current = {0, 0};
    for (int l = 1; l < N; l = rank_next[l]) {
        for (int i = l; i < rank_next[l]; i++) {
            argmin[i] = current;
        }
        for (int i = l; i < rank_next[l]; i++) {
            int u = order[i];
            if (weight[u] <= weight[current[0]]) {
                current = {u, current[0]};
            } else if (weight[u] < weight[current[1]]) {
                current = {current[0], u};
            }
        }
    }

    uint64_t ans = 0;
    vector<uint64_t> saves(Q + 1);
    vector<int> minimum(N), second_min(N), length(N);

    for (int l = 0, r = 1; l < N; l = r++) {
        while (r < N && argmin[l] == argmin[r]) {
            r++;
        }
        runs.insert({l, r, argmin[l]});
    }
    for (int i = 1; i < N; i++) {
        length[argmin[i][0]]++;
    }
    for (int u = 1; u < N; u++) {
        if (needs[u]) {
            if (auto [v, w] = argmin[rank[u]]; parent[u] != v) {
                minimum[v]++, ans += weight[v];
            } else {
                second_min[w]++, ans += weight[w];
            }
        }
    }
    saves[Q] = ans;

    for (int q = Q - 1; q >= 0; q--) {
        auto [u, dx] = queries[q];
        weight[u] -= dx;
        ans -= dx * (minimum[u] + second_min[u]); // These runs don't change

        if (int S = rank_next[rank[u]]; S < N) {
            auto node = std::prev(runs.upper_bound(Run{S + 1, S + 1}));
            Run run = *node;
            if (run.L < S) {
                runs.erase(node);
                runs.insert(Run{run.L, S, run.argmin});
                runs.insert(Run{S, run.R, run.argmin});
            }

            auto start = runs.lower_bound(Run{S + length[u], S + length[u]});
            auto it = start;
            if (start != end(runs)) {
                assert(start->L == S + length[u]);
            }

            while (it != end(runs)) {
                auto [v, w] = it->argmin;

                if (weight[u] <= weight[v]) {
                    // [v,w] -> [u,v], perhaps u=w
                    int len = it->R - it->L;
                    int count = count_needy(it->L, it->R);
                    int vkids = count_kids(v, it->L, it->R);
                    int ukids = count_kids(u, it->L, it->R);

                    // Remove v and w
                    minimum[v] -= count - vkids;
                    second_min[w] -= vkids;
                    ans -= weight[v] * (count - vkids);
                    ans -= weight[w] * vkids;

                    // Add u and v
                    minimum[u] += count - ukids;
                    second_min[v] += ukids;
                    ans += weight[u] * (count - ukids);
                    ans += weight[v] * ukids;

                    // Adjust lead lengths
                    length[v] -= len;
                    length[u] += len;

                    it->argmin = {u, v};
                } else if (weight[u] < weight[w]) {
                    int second = count_kids(v, it->L, it->R);

                    second_min[w] -= second;
                    second_min[u] += second;
                    ans += (weight[u] - weight[w]) * second;

                    it->argmin = {v, u};
                } else if (u != w) { // No more improvements :(
                    break;
                }
                ++it;
            }

            if (start != end(runs) && std::next(start) != end(runs)) {
                auto right = std::next(start);
                while (right != end(runs) && start->argmin == right->argmin) {
                    ++right;
                }
                start->R = right != end(runs) ? right->L : N;
                runs.erase(std::next(start), right);
                if (right != end(runs) && std::next(right) != end(runs)) {
                    auto head = std::next(right);
                    if (right->argmin == head->argmin) {
                        right->R = head->R;
                        runs.erase(head);
                    }
                }
            }
        }

        saves[q] = ans;
    }

    for (int i = 0; i <= Q; i++) {
        cout << saves[i] << '\n';
    }

    return 0;
}

// - Let dist[i] be the shortest path length from 1 to i.
// - Build the shortest path tree and build LCA on it. Let lca(u,v) be on the SP tree
// - Fix node u. Let edge e be incident to u and v.
// Label e parent for u if dist[v]+e<=dist[u] (maybe the parent edge)
// Because we built a shortest path tree this is equality
// Ignore all other e they will never be traversed
// - One of the paths up to u will be the tree path
// The other path has to go around, using other edges or new edges
// - If u has multiple parents, say p1 and p2, we take SP to p1 and special path to p2
// if dist[p1]<=dist[p2] else vice-versa. So we're always good then.
// - Now suppose u does not have multiple parents
// For some node v with dist[v]<dist[u] we will add edge v->u
// Now take special path to p and tree path to v + new edge, we're good.
// Actually no but you can work around it by induction
// So we can actually try every vertex v with dist[v]<dist[u] except p.
// That's like two queries on a segtree for each u after we order the nodes around 'p'
// For each node v we can keep track of targets u such that v->u was newly added.
// - Now how to handle updates to this shit?
// - Suppose we increase cost at x
// Then x will keep all of its targets or yield some to other nodes with lower cost.
// Can there be a lot of transfers? Probably yes
// - The edge x->u may be transferred to some node y such that
// cost[x]<=cost[y]<cost[x]+INC & dist[y]<dist[u] & cost[y] is minimum & y!=parent(u)
// Starting to look like we might need 2 cuts on a splay tree and melding what the fuck
// That has to be slow as fuck
// - If there are two nodes z before x such with lower cost, then x has no children
// - Otherwise if there is one node z with lower cost, then x's children are some of
// z's children, we may be able to move some
// - Otherwise fuck
// Hint editorial: Go through updates in reverse
// How the fuck does that help
// Ok so in reverse maybe its some fancy segbeats setmin?
// Because in reverse we 'pull' from several nodes y to x
// While forward we 'push' from x to several y
// Clearly much better in reverse
// When we lower x, we update all z such that dist[z]>dist[x] and cost[z]>cost[x] and
// x is not the parent of z
// That last requirement is fucking annoying how do you get rid of it
// Do you just not give a fuck or what
// Ok you keep second minimum too and do segtree manually with BST