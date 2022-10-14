#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        map<int, int> latest;
        vector<int> dp(N + 1);
        latest[0] = 0;
        int v = 0;
        for (int i = 0; i < N; i++) {
            v ^= a[i];
            if (latest.count(v)) {
                dp[i + 1] = max(dp[i], dp[latest[v]] + 1);
            } else {
                dp[i + 1] = dp[i];
            }
            latest[v] = i + 1;
        }
        cout << N - dp[N] << '\n';
    }
    return 0;
}