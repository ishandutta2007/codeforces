#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N, K;
    cin >> N >> K;
    int M = N - K + K / 2;
    cout << M << endl;
    for (int i = K + 1; i <= N; i++) {
        cout << i << ' ';
    }
    for (int i = (K + 1) / 2; i < K; i++) {
        cout << i << ' ';
    }
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