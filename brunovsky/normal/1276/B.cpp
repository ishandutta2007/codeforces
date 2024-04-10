#include <bits/stdc++.h>

using namespace std;

#define long int64_t

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
    int N, M, a, b;
    cin >> N >> M >> a >> b, a--, b--;
    vector<array<int, 2>> edges(M);
    for (auto& [u, v] : edges) {
        cin >> u >> v, u--, v--;
    }

    disjoint_set noa(N), nob(N);
    for (auto [u, v] : edges) {
        if (u != a && v != a) {
            noa.join(u, v);
        }
        if (u != b && v != b) {
            nob.join(u, v);
        }
    }
    long out_a = N - nob.size[nob.find(a)] - 1;
    long out_b = N - noa.size[noa.find(b)] - 1;
    return out_a * out_b;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}