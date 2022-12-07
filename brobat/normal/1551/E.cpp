#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        --v[i];
    }
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    if(v[0] == 0) {
        dp[0][0] = 1;
    }
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + (v[i] == i ? 1 : 0);
        for(int j = 1; j <= i + 1; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j] + (v[i] == i - j ? 1 : 0));
        }
    }
    for(int j = 0; j <= n; j++) {
        for(int i = 0; i < n; i++) {
            if(dp[i][j] >= k) {
                cout << j << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}