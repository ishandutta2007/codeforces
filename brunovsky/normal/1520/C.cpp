#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

auto solve() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << "1" << endl;
        return;
    } else if (N == 2) {
        cout << "-1" << endl;
        return;
    }
    for (int r = 0, n = 1; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << (c ? " " : "") << n;
            n += 2;
            if (n > N * N)
                n = 2;
        }
        cout << endl;
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