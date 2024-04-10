#include <bits/stdc++.h>

using namespace std;

// *****

template <typename T>
string to_string(const vector<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}

auto solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    if (K > (N - 1) / 2) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        A[i] = N - i;
    }
    for (int i = 0; i < K; i++) {
        A[2 * i + 1] = N - i;
    }
    for (int i = 0; i < K + 1; i++) {
        A[2 * i] = N - K - i;
    }
    cout << to_string(A) << endl;
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