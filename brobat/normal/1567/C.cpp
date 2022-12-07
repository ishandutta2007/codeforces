#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if(n == 1) {
        cout << s[0] - '0' - 1 << endl;
        return;
    }
    if(n == 2) {
        cout << (s[0] - '0' + 1)*(s[1] - '0' + 1) - 2 << endl;
        return;
    }
    int dp[n][2];
    dp[0][0] = s[n-1] - '0' + 1;
    dp[0][1] = 10 - dp[0][0];
    dp[1][0] = s[n-2] - '0' + 1;
    dp[1][1] = 10 - dp[1][0];
    forn(i, 2, n) {
        int c = s[n-1-i] - '0';
        dp[i][0] = dp[i-2][0]*(c+1) + dp[i-2][1]*(c);
        dp[i][1] = dp[i-2][0]*(10-c-1) + dp[i-2][1]*(10-c);
    }
    cout << dp[n-1][0]*dp[n-2][0] - 2 << endl;
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