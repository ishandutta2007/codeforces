#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int n) { *this = disjoint_set(n); }
    void reset() { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (int r = find(u); u != r) {
            size[u] = size[r];
            next[u] = next[r] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

int64_t bit(int b) { return 1LL << b; }
int64_t bit_down(int64_t v, int b) {
    return v & ~(bit(b) - 1);
}
int64_t bit_up(int64_t v, int b) {
    return bit_down(v, b) + bit(b);
}
int64_t midp(int64_t L, int64_t R) {
    int b = 63 - __builtin_clzll(L ^ (R - 1));
    return L == R - 1 ? L : bit_down(R - 1, b);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, M;
    cin >> n >> M;
    int64_t N = 1LL << n;

    constexpr int BLOCK = 0, ASK = 1;
    vector<array<int64_t, 3>> queries(M);
    for (auto& [type, l, r] : queries) {
        string query;
        cin >> query >> l >> r;
        type = query == "block" ? BLOCK : ASK;
        r += type == BLOCK;
    }
    while (M > 0 && queries[M - 1][0] == BLOCK) {
        M--, queries.pop_back();
    }

    vector<int64_t> endp = {0, N};
    for (auto [type, l, r] : queries) {
        if (type == BLOCK) {
            endp.push_back(l);
            endp.push_back(r);
        }
    }
    sort(begin(endp), end(endp));
    endp.erase(unique(begin(endp), end(endp)), end(endp));
    int E = endp.size();

    vector<int64_t> spots;
    for (int e = 0; e + 1 < E; e++) {
        int64_t l = endp[e], r = endp[e + 1];
        if (midp(l, r) == l) {
            spots.push_back(l);
        } else {
            spots.push_back(l);
            spots.push_back(midp(l, r));
        }
    }
    spots.push_back(N);
    int V = spots.size() - 1;

    auto get_id = [&](int64_t x) {
        return upper_bound(begin(spots), end(spots), x) - begin(spots) - 1;
    };

    vector<vector<int>> graph(V);
    for (int u = 0; u < V; u++) {
        int64_t L = spots[u], R = spots[u + 1];
        for (int b = 0; b < n; b++) {
            int64_t A, B;
            if ((R - 1) >> b & 1) {
                A = max(L, bit_down(R - 1, b) - bit(b));
                B = max(L, bit_down(R - 1, b));
            } else {
                A = max(L, bit_down(R - 1, b));
                B = R;
            }
            if (A >= B) {
                continue;
            }
            int64_t X = max(R, A + bit(b));
            int64_t Y = min(N, B + bit(b));
            int v = get_id(X);
            while (spots[v] < Y) {
                graph[u].push_back(v);
                graph[v].push_back(u);
                v++;
            }
        }
    }

    disjoint_set dsu(V);
    vector<bool> active(V, true);

    for (auto [type, L, R] : queries) {
        if (type == BLOCK) {
            int u = get_id(L);
            while (spots[u] < R) {
                active[u] = false;
                u++;
            }
        }
    }

    for (int u = 0; u < V; u++) {
        if (active[u]) {
            for (int v : graph[u]) {
                if (active[v]) {
                    dsu.join(u, v);
                }
            }
        }
    }

    vector<int> ans(M);

    for (int q = M - 1; q >= 0; q--) {
        auto [type, L, R] = queries[q];
        if (type == BLOCK) {
            int u = get_id(L);
            while (spots[u] < R) {
                for (int v : graph[u]) {
                    if (active[v]) {
                        dsu.join(u, v);
                    }
                }
                active[u] = true;
                u++;
            }
        } else {
            int u = get_id(L);
            int v = get_id(R);
            ans[q] = dsu.same(u, v);
        }
    }

    for (int i = 0; i < M; i++) {
        if (queries[i][0] == ASK) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}

// Each live interval contains at most 2 distinct dsu sets in at most log(n) ranges