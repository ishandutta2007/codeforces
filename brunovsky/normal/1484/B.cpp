#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    long long m = -1, c = -1;
    if (count(begin(A), end(A), A[0]) == N) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i + 1 < N; i++) {
        if (A[i] <= A[i + 1]) {
            c = A[i + 1] - A[i];
            break;
        }
    }
    if (c == 0) {
        cout << -1 << endl;
        return;
    } else if (c > 0) {
        for (int i = 0; i + 1 < N; i++) {
            if (A[i] <= A[i + 1]) {
                if (A[i + 1] - A[i] != c) {
                    cout << -1 << endl;
                    return;
                }
            } else if (m != -1 && A[i + 1] != A[i] + c - m) {
                cout << -1 << endl;
                return;
            } else {
                m = A[i] + c - A[i + 1];
            }
        }
        if (m > 0) {
            for (int i = 0; i < N; i++) {
                if (A[i] >= m) {
                    cout << -1 << endl;
                    return;
                }
            }
            cout << m << ' ' << c << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        auto D = A[1] - A[0];
        for (int i = 0; i + 1 < N; i++) {
            if (A[i + 1] - A[i] != D) {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
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