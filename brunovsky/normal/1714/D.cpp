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
        string text;
        cin >> text;
        int N = text.size();
        int M;
        cin >> M;
        vector<string> words(M);
        for (int i = 0; i < M; i++) {
            cin >> words[i];
        }
        const int inf = INT_MAX / 2;
        vector<int> dp(300, inf);
        vector<array<int, 2>> prev(300, {-1, -1});
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < M; k++) {
                auto w = words[k];
                int s = w.size();
                if (text.substr(i, s) == w) {
                    for (int j = 1; j <= s; j++) {
                        if (dp[i + j] > dp[i] + 1) {
                            dp[i + j] = dp[i] + 1;
                            prev[i + j] = {i, k};
                        }
                    }
                }
            }
        }
        if (dp[N] == inf) {
            cout << -1 << '\n';
        } else {
            cout << dp[N] << '\n';
            int i = N;
            while (i > 0) {
                cout << prev[i][1] + 1 << ' ' << prev[i][0] + 1 << '\n';
                i = prev[i][0];
            }
        }
    }
    return 0;
}