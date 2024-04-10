#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = (int)1E9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, q;
    cin >> n >> k >> q;
    int dp[n][k + 1];
    for(int i = 0; i < n; i++) {
        dp[i][k] = 1;
    }
    vector <int> f(n, 0);
    for(int j = k - 1; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else if(i == n - 1) {
                dp[i][j] = dp[i - 1][j + 1];
            }
            else {
                dp[i][j] = (dp[i + 1][j + 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            f[i] = (f[i] + dp[i][j] * dp[i][k - j]) % MOD;
        }
    }
    vector <int> a(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans = (ans + (a[i] * f[i])) % MOD;
    }
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        int sub = (a[x] * f[x]) % MOD;
        ans = (ans + MOD - sub) % MOD;
        a[x] = y;
        ans = (ans + (a[x] * f[x])) % MOD;
        cout << ans << '\n';
    }
    
    return 0;
}