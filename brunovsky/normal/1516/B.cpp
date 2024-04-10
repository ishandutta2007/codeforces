#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<unsigned> A(N), D(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        D[i + 1] = A[i] ^ D[i];
    }
    if (D[N] == 0) {
        return "YES";
    }
    unsigned which = D[N], blocks = 0;
    for (int i = 0; i < N; i++) {
        if (D[i + 1] == which) {
            blocks++, which ^= D[N];
        }
    }
    return blocks >= 3 ? "YES" : "NO";
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