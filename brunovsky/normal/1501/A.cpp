#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> D(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }

    int arrival = 0, departure = 0;
    for (int i = 1; i <= N; i++) {
        arrival = departure + A[i] - B[i - 1] + D[i];
        departure = max(B[i], arrival + (B[i] - A[i] + 1) / 2);
    }
    return arrival;
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