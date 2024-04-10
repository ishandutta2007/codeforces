#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int arr[n+1][n+1]; // The length of common sequence in s[i...] and s[j...]
    forn(i, 1, n+1) {
        if(s[i-1]==s[n-1]) arr[i][n] = 1;
        else arr[i][n] = 0;
    }
    for(int i = n-2; i>=1; i--) {
        for(int j = i + 1; j<n; j++) {
            if(s[i-1]==s[j-1]) arr[i][j] = 1 + arr[i+1][j+1];
            else arr[i][j] = 0;
        }
    }
    // forn(i, 1, n) {forn(j, i+1, n+1) cout << arr[i][j] << " "; cout << endl;}
    int dp[n+1];
    forn(i, 0, n+1) dp[i] = 0;
    dp[n] = 1;
    for(int i = n-1; i>=1; i--) {
        int t = 0;
        for(int j = i + 1; j <= n; j++) {
            // Compare positions s[i - 1 + arr[i][j]] and s[j - 1 + arr[i][j]]
            int x = arr[i][j];
            if(j - 1 + x >= n) continue;
            bool y = s[i - 1 + x] > s[j - 1 + x];
            if(!y) t = max(t, dp[j] - x);
        }
        dp[i] = n - i + 1 + t;
    }
    // forn(i, 1, n+1) cerr << dp[i] << " ";
    sort(dp, dp + n + 1);
    cout << dp[n] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}