#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    if (N == 3) {
        cout << "2\n3 2\n3 2" << endl;
        return;
    } else if (N == 4) {
        cout << "4\n4 3\n4 3\n3 2\n3 2" << endl;
        return;
    }
    unordered_set<int> erased;
    vector<array<int, 2>> last_ops;
    erased.insert(N), erased.insert(2);
    int M = N;
    while (M >= 4) {
        int D = int(sqrt(M));
        assert(D * D <= M);
        M = (M + D - 1) / D;
        last_ops.push_back({N, D});
        erased.insert(D);
        if (M == 3 || M == 4) {
            if (D >= 3) {
                last_ops.push_back({D, N});
            }
            last_ops.push_back({N, 2});
            last_ops.push_back({2, N});
        } else {
            last_ops.push_back({D, N});
            erased.insert(D);
        }
    }
    vector<array<int, 2>> ops;
    for (int i = 1; i < N; i++) {
        if (!erased.count(i)) {
            ops.push_back({i, N});
        }
    }
    vector<int> simul(N + 1);
    iota(begin(simul), end(simul), 0);
    int m = ops.size() + last_ops.size();
    assert(m <= N + 5);
    cout << m << endl;
    for (auto [x, y] : ops) {
        cout << x << ' ' << y << endl;
        simul[x] = (simul[x] + simul[y] - 1) / simul[y];
    }
    for (auto [x, y] : last_ops) {
        cout << x << ' ' << y << endl;
        simul[x] = (simul[x] + simul[y] - 1) / simul[y];
    }
    assert(count(begin(simul), end(simul), 1) == N - 1);
    assert(count(begin(simul), end(simul), 2) == 1);
    cout << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}