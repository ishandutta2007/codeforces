#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return size[find(i)] == 1; }
    bool root(int i) { return find(i) == i; }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    void join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
        }
    }
};

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> edges(M);
    for (auto& [u, v] : edges) {
        cin >> u >> v, u--, v--;
    }

    vector<disjoint_set> dsu_left(M + 1), dsu_right(M + 1);
    dsu_left[0] = dsu_right[M] = disjoint_set(N);
    for (int i = 1; i <= M; i++) {
        auto [u, v] = edges[i - 1];
        dsu_left[i] = dsu_left[i - 1];
        dsu_left[i].join(u, v);
    }
    for (int i = M - 1; i >= 0; i--) {
        auto [u, v] = edges[i];
        dsu_right[i] = dsu_right[i + 1];
        dsu_right[i].join(u, v);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R, L--;
        disjoint_set dsu = dsu_left[L];
        for (int u = 0; u < N; u++) {
            dsu.join(u, dsu_right[R].find(u));
        }
        cout << dsu.S << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}