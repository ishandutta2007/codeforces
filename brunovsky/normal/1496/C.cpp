#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0, j = 0; i < N || j < N;) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
            A[i++] = y;
        } else {
            B[j++] = x;
        }
    }
    sort(begin(A), end(A), [](int u, int v) { return abs(u) < abs(v); });
    sort(begin(B), end(B), [](int u, int v) { return abs(u) < abs(v); });
    double d = 0;
    for (int i = 0; i < N; i++) {
        d += sqrt(1LL * A[i] * A[i] + 1LL * B[i] * B[i]);
    }
    return d;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << showpoint << setprecision(12);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}