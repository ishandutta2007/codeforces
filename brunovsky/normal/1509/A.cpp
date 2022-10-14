#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(begin(A), end(A),
         [&](int a, int b) { return (a & 1) != (b & 1) ? (a & 1) : (a < b); });
    for (int i = 0; i < N; i++)
        cout << (i ? " " : "") << A[i];
    cout << endl;
}

// *****

int main() {
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}