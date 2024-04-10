#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i + 1 < N && K > 0; i++) {
        int sub = min(A[i], K);
        A[i] -= sub, A[N - 1] += sub, K -= sub;
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << (i + 1 == N ? "" : " ");
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