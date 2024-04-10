#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; long long k; cin >> n >> k;
    string s; cin >> s;

    vector<vector<long long>> dp(n + 1, vector<long long>(30, 0));
    for (int i = n - 1; i >= 0; --i) {
        int now = s[i] - 'a';

        vector<vector<long long>> ndp = dp;
        ndp[1][now] = 1;
        for (int len = n - 1; len >= 1; --len) {
            ndp[len + 1][now] = 0;
            for (int nxt = 0; nxt < 30; ++nxt) {
                ndp[len + 1][now] += dp[len][nxt];
                if (ndp[len + 1][now] > k) 
                    ndp[len + 1][now] = k;
            }
        }
        dp = ndp;
    }

    dp[0][0] = 1;
    long long ans = 0;
    for (int len = n; len >= 0; --len) {
        for (int now = 0; now < 30; ++now) {
            if (dp[len][now] >= k) {
                ans += k * (n - len);
                cout << ans << endl;
                return 0;
            }
            ans += dp[len][now] * (n - len);
            k -= dp[len][now];
        }    
    }

    cout << -1 << endl;

    return 0;
}