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
    sort(begin(A), end(A));

    vector<long long> dp(N, 0);

    for (int n = 2; n <= N; n++) {
        vector<long long> next(N - n + 1);
        for (int i = 0; i <= N - n; i++) {
            next[i] = min(dp[i], dp[i + 1]) + A[i + n - 1] - A[i];
        }
        dp = move(next);
    }

    return dp[0];
}

// *****

int main() {
    cout << solve() << endl;
    return 0;
}