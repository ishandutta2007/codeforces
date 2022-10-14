#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct bipartite_disjoint_set_rollback {
    static constexpr int DEAD = -1;
    int N, S, B = 0;
    vector<int> nxt, col;
    vector<array<int, 3>> hist;

    explicit bipartite_disjoint_set_rollback(int N = 0)
        : N(N), S(N), nxt(N, -1), col(N) {}

    void assign(int n) { *this = bipartite_disjoint_set_rollback(n); }
    void reset() { *this = bipartite_disjoint_set_rollback(N); }
    bool unit(int i) { return size(i) == 1; }
    bool same(int i, int j) { return find(i) == find(j); }
    bool isroot(int i) { return find(i) == i; }
    bool bipartite() const { return B == 0; }
    bool bipartite(int i) { return color(i) != DEAD; }
    int size(int i) { return -nxt[find(i)]; }
    int time() const { return hist.size(); }

    void rollback(int t) {
        int i = time();
        while (i > t) {
            if (hist[i - 1][1] == N) {
                auto [x, a, b] = hist[--i];
                col[x] = b;
                hist.pop_back();
                B--;
            } else {
                auto [x, a, b] = hist[--i];
                auto [y, c, d] = hist[--i];
                nxt[x] = a, col[x] = b;
                nxt[y] = c, col[y] = d;
                hist.pop_back(), hist.pop_back();
                S++;
            }
        }
        hist.resize(t);
    }

    int color(int i) {
        int c = col[i];
        while (nxt[i] >= 0) {
            i = nxt[i], update(c, col[i]);
        }
        return c;
    }

    int find(int i) {
        while (nxt[i] >= 0) {
            i = nxt[i];
        }
        return i;
    }

    bool join(int i, int j) {
        assert(i != j); // ambiguous handling
        int a = find(i);
        int b = find(j);
        int ci = color(i);
        int cj = color(j);
        if (a == b && ci == cj) {
            hist.push_back({a, N, col[a]});
            col[a] = DEAD, B++;
        } else if (a != b) {
            if (nxt[a] > nxt[b]) {
                swap(a, b);
            }
            hist.push_back({a, nxt[a], col[a]});
            hist.push_back({b, nxt[b], col[b]});
            nxt[a] += nxt[b];
            nxt[b] = a, S--;
            col[b] ^= ci != DEAD && cj != DEAD && ci == cj;
        }
        return a != b;
    }

  private:
    void update(int& a, int b) { a = a != DEAD && b != DEAD ? a ^ b : DEAD; }
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

template <typename E, typename Insert, typename Rollback>
struct undo_stack_to_queue {
    Insert inserter;
    Rollback rollbacker;
    vector<pair<int, E>> stack; // A=1, B=0
    int A = 0, S = 0;

    explicit undo_stack_to_queue(const Insert& insert, const Rollback& rollback)
        : inserter(insert), rollbacker(rollback) {}

    void push(E elem) { stack.emplace_back(0, elem), S++, inserter(elem); }

    void pop() {
        if (stack.empty()) {
            return;
        } else if (stack.back().first == 1) {
            stack.pop_back(), A--, S--, rollbacker();
        } else if (A == 0) {
            for (int i = 0; i < S; i++) {
                rollbacker();
            }
            reverse(begin(stack), end(stack));
            for (int i = 0; i < S; i++) {
                stack[i].first = 1, A++;
                inserter(stack[i].second);
            }
            stack.pop_back(), A--, S--, rollbacker();
        } else {
            int D = 0; // Bs - As
            vector<pair<int, E>> popped[2] = {};
            do {
                int t = stack.back().first;
                popped[t].push_back(stack.back()), stack.pop_back();
                rollbacker();
                A -= t, D += t ? -1 : +1;
            } while (stack.size() && A > 0 && D > 0);
            while (popped[0].size()) {
                stack.push_back(popped[0].back()), popped[0].pop_back();
                inserter(stack.back().second);
            }
            while (popped[1].size()) {
                stack.push_back(popped[1].back()), popped[1].pop_back(), A++;
                inserter(stack.back().second);
            }
            stack.pop_back(), A--, S--, rollbacker();
        }
    }
};

template <typename E, typename Insert, typename Rollback>
auto make_undo_stack_to_queue(Insert&& insert, Rollback&& rollback) {
    return undo_stack_to_queue<E, Insert, Rollback>(insert, rollback);
}

void solve_queue() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<array<int, 2>> graph(M);
    for (auto& [u, v] : graph) {
        cin >> u >> v, u--, v--;
    }
    bipartite_disjoint_set_rollback dsu(N);
    vector<int> times;
    auto insert = [&](int e) {
        auto [u, v] = graph[e];
        times.push_back(dsu.time());
        dsu.join(u, v);
    };
    auto rollback = [&]() {
        dsu.rollback(times.back());
        times.pop_back();
    };
    auto undo = make_undo_stack_to_queue<int>(insert, rollback);
    for (int e = 0; e < M; e++) {
        undo.push(e);
    }
    if (dsu.bipartite()) {
        while (Q--) {
            cout << "NO\n";
        }
        return;
    }
    vector<int> right(M);
    int L = 0, R = 0;
    while (L < M) {
        while (R < M && !dsu.bipartite()) {
            undo.pop(), R++;
        }
        assert(L < R);
        right[L] = R - dsu.bipartite();
        undo.push(L++);
    }
    debug(right);
    while (Q--) {
        int l, r;
        cin >> l >> r, l--;
        cout << (r <= right[l] ? "YES\n" : "NO\n");
    }
}

void solve_dac() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<array<int, 2>> graph(M);
    for (auto& [u, v] : graph) {
        cin >> u >> v, u--, v--;
    }
    bipartite_disjoint_set_rollback dsu(N);
    for (auto [u, v] : graph) {
        dsu.join(u, v);
    }
    if (dsu.bipartite()) {
        while (Q--) {
            cout << "NO\n";
        }
        return;
    }
    dsu.rollback(0);
    vector<int> right(M);
    auto add = [&](int e) {
        auto [u, v] = graph[e];
        dsu.join(u, v);
    };
    // Graph with all edges is not bipartite
    // [l,right[l]): removing these edges the graph is still not bipartite
    // [l,right[l]+1): removing these edges the graph is bipartite. right[l]>=l
    // upon entering, graph contains edges [0,l) and [b,M)
    y_combinator([&](auto self, int l, int r, int a, int b) -> void {
        if (l < r) {
            int m = (l + r) / 2;
            int tlb = dsu.time();
            for (int e = l; e < m; e++) {
                add(e);
            }
            int i = b, tmb = dsu.time();
            while (dsu.bipartite()) {
                add(--i);
            }
            debug(l, r, m, a, b, i);
            right[m] = i;
            // recurse left: [l,m,a,i] and [m,r,i,b]
            dsu.rollback(tmb);
            add(m);
            self(m + 1, r, max(m + 1, i), b);
            dsu.rollback(tlb);
            for (int e = b - 1; e >= i; e--) {
                add(e);
            }
            self(l, m, a, i);
            dsu.rollback(tlb);
        }
    })(0, M, 0, M);
    debug(right);
    while (Q--) {
        int l, r;
        cin >> l >> r, l--;
        cout << (r <= right[l] ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve_dac();
    return 0;
}