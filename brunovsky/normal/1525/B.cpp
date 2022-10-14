#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] != i + 1;
    }
    if (ans == 0) {
        return 0;
    } else if (A[0] == N && A[N - 1] == 1) {
        return 3;
    } else if (A[0] != 1 && A[N - 1] != N) {
        return 2;
    } else {
        return 1;
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