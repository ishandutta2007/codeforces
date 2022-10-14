#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int until = 0;
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        until = max(until, i + A[N - 1 - i]);
        ans[N - 1 - i] = until > i;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i + 1 < N ? " " : "");
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