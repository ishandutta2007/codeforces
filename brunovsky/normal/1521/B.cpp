#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

auto solve() {
    int N;
    cin >> N;
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int n = min_element(begin(A), end(A)) - begin(A);
    vector<array<long, 4>> changes;
    for (int i = n + 1; i < N; i++) {
        long g = gcd(A[i - 1], A[i]);
        if (g != 1) {
            A[i] = A[i - 1] + 1;
            changes.push_back({n, i, A[n], A[i]});
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        long g = gcd(A[i], A[i + 1]);
        if (g != 1) {
            A[i] = A[i + 1] + 1;
            changes.push_back({n, i, A[n], A[i]});
        }
    }
    int k = changes.size();
    cout << k << endl;
    for (auto [i, j, x, y] : changes) {
        cout << i + 1 << ' ' << j + 1 << ' ' << x << ' ' << y << endl;
    }
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