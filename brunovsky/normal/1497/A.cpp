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
    vector<bool> seen(*max_element(begin(A), end(A)) + 1, false);
    vector<int> prefix, suffix;
    for (int i = 0; i < N; i++) {
        if (seen[A[i]]) {
            suffix.push_back(A[i]);
        } else {
            seen[A[i]] = true;
            prefix.push_back(A[i]);
        }
    }
    sort(begin(prefix), end(prefix));
    for (int n : prefix) {
        cout << n << ' ';
    }
    for (int n : suffix) {
        cout << n << ' ';
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