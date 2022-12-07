#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    int bans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        bans += (n - 2) * a[i] * a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
        bans += (n - 2) * b[i] * b[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(100 * n + 1));
    int MAXN = 100 * n + 1;
    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < MAXN; j++) {
            if(dp[i][j]) {
                if(j + a[i] < MAXN) dp[i + 1][j + a[i]] = true;
                if(j + b[i] < MAXN) dp[i + 1][j + b[i]] = true;
            }
        }
    }
    int ans = 1E18;
    for(int i = 0; i < MAXN; i++) {
        if(dp[n][i]) {
            ans = min(ans, i * i + (sum - i) * (sum - i));
        }
    }
    cout << ans + bans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}