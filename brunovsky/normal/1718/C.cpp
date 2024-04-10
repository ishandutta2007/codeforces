#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<int> primes, lp, nxt;

auto least_prime_sieve(int N) {
    lp.assign(N + 1, 0), nxt.assign(N + 1, 0);
    nxt[1] = 1;

    for (int P = 0, n = 2; n <= N; n++) {
        if (lp[n] == 0) {
            lp[n] = n, primes.push_back(n), P++;
        }
        for (int i = 0; i < P && primes[i] <= lp[n] && n * primes[i] <= N; ++i) {
            lp[n * primes[i]] = primes[i], nxt[n * primes[i]] = n;
        }
    }
}

auto get_primes(int n) {
    vector<pair<int, int>> primes;
    while (n > 1) {
        int p = lp[n], c = 0;
        do {
            c++;
            n = nxt[n];
        } while (n > 1 && lp[n] == p);
        primes.push_back({p, c});
    }
    return primes;
}

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

template <typename Container>
struct greater_container {
    const Container* cont = nullptr;
    greater_container() = default;
    greater_container(const Container& cont) : cont(&cont) {}
    inline bool operator()(int u, int v) const {
        return tie((*cont)[u], u) > tie((*cont)[v], v);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    least_prime_sieve(200'000);
    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int64_t> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        vector<int> divs = {1};
        auto prime_divs = get_primes(N);
        int P = prime_divs.size();
        if (P == 1) {
            int p = prime_divs[0].first;
            divs.push_back(N / p);
        } else {
            for (auto [p, c] : prime_divs) {
                divs.push_back(N / p);
            }
        }
        sort(begin(divs), end(divs));
        divs.erase(unique(begin(divs), end(divs)), end(divs));
        int S = divs.size();
        debug(N, divs);

        using Heap = pairing_int_heap<greater_container<vector<int64_t>>>;
        vector<vector<int64_t>> ans(S);
        vector<Heap> best(S);
        for (int x = 0; x < S; x++) {
            int K = divs[x];
            ans[x].resize(K);
            for (int i = 0; i < N; i++) {
                ans[x][i % K] += K * a[i];
            }
            best[x] = Heap(K, ans[x]);
            best[x].fill();
        }

        auto get = [&]() {
            int64_t top = 0;
            for (int x = 0; x < S; x++) {
                top = max(top, ans[x][best[x].top()]);
            }
            return top;
        };
        auto update = [&](int i, int64_t v) {
            for (int x = 0; x < S; x++) {
                int K = divs[x];
                ans[x][i % K] += K * (v - a[i]);
                best[x].adjust(i % K);
            }
            a[i] = v;
        };

        cout << get() << '\n';

        while (Q--) {
            int p, v;
            cin >> p >> v, p--;
            update(p, v);
            cout << get() << '\n';
        }
    }
    return 0;
}