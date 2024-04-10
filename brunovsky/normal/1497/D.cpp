#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    vector<int> tag(N + 1), score(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> tag[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    vector<long long> dp(N + 1, 0);

    for (int u = 1; u <= N; u++) {
        for (int v = u - 1; v >= 1; v--) {
            if (tag[u] != tag[v]) {
                auto dp_u = max(dp[u], abs(score[v] - score[u]) + dp[v]);
                auto dp_v = max(dp[v], abs(score[u] - score[v]) + dp[u]);
                dp[u] = dp_u, dp[v] = dp_v;
            }
        }
    }

    return *max_element(begin(dp), end(dp));
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