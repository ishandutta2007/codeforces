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
    int N;
    long p;
    cin >> N >> p;
    vector<int> A(N), sorted(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    iota(begin(sorted), end(sorted), 0);
    sort(begin(sorted), end(sorted), [&](int a, int b) { return A[a] < A[b]; });

    disjoint_set dsu(N);
    long ans = 0;

    for (int z = 0; z < N; z++) {
        int n = sorted[z];
        if (A[n] >= p)
            break;
        if (!dsu.unit(n))
            continue;

        for (int i = n + 1; i < N && A[i] % A[n] == 0 && !dsu.same(i, n); i++) {
            dsu.join(n, i), ans += A[n];
        }
        for (int i = n - 1; i >= 0 && A[i] % A[n] == 0 && !dsu.same(i, n); i--) {
            dsu.join(n, i), ans += A[n];
        }
    }

    return ans + (dsu.S - 1) * p;
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