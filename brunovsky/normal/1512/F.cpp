#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N, C;
    cin >> N >> C;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    long best = LLONG_MAX;
    long day = 0, money = 0;
    for (int i = 0; i < N - 1 && money < C; i++) {
        best = min(best, day + (C - money + A[i] - 1) / A[i]);
        long k = max(long(0), (B[i] - money + A[i] - 1) / A[i]);
        day += 1 + k;
        money += k * A[i] - B[i];
    }
    if (money < C) {
        best = min(best, day + (C - money + A[N - 1] - 1) / A[N - 1]);
    }
    return best;
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