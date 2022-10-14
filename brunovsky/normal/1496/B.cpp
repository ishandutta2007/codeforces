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
    if (K == 0) {
        return N;
    }
    sort(begin(A), end(A));
    int i = 0;
    while (i < N && i == A[i])
        i++;

    if (i == N) {
        return N + K;
    } else {
        int elem = (i + A.back() + 1) / 2;
        bool contains = count(begin(A), end(A), elem) >= 1;
        return N + !contains;
    }
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