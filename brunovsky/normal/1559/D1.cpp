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

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (u != find(u)) {
            size[u] = size[find(u)];
            next[u] = next[find(u)] = u;
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M1, M2;
    cin >> N >> M1 >> M2;

    disjoint_set a(N), b(N);
    vector<array<int, 2>> a_edges(M1), b_edges(M2);

    for (auto& [u, v] : a_edges) {
        cin >> u >> v, u--, v--;
        a.join(u, v);
    }
    for (auto& [u, v] : b_edges) {
        cin >> u >> v, u--, v--;
        b.join(u, v);
    }

    vector<array<int, 2>> added;

    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N; v++) {
            if (!a.same(u, v) && !b.same(u, v)) {
                added.push_back({u, v});
                a.join(u, v);
                b.join(u, v);
            }
        }
    }

    int U = added.size();
    cout << U << '\n';
    for (auto [u, v] : added) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }

    return 0;
}