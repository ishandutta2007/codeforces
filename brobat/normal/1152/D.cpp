#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    ll n;
    cin >> n;
    ll dp[n+1][n+1];
    bool included[n+1][n+1];
    dp[n][n-1] = 1;
    included[n][n-1] = true;
    for(int j=n-2; j>=0; j--) {
        if(included[n][j+1]==true) {
            dp[n][j] = dp[n][j+1];
            dp[n][j] %= MOD;
            included[n][j] = false;
        }
        else {
            dp[n][j] = dp[n][j+1] + 1;
            dp[n][j] %= MOD;
            included[n][j] = true;
        }
    }
    for(int i=n-1; i>=0; i--) {
        // i==j
        if(included[i+1][i]==true) {
            dp[i][i] = dp[i+1][i];
            dp[i][i] %= MOD;
            included[i][i] = false;
        }
        else {
            dp[i][i] = dp[i+1][i] + 1;
            dp[i][i] %= MOD;
            included[i][i] = true;
        }
        for(int j=i-1; j>=0; j--) {
            if(included[i+1][j]&&included[i][j+1]) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
                dp[i][j] %= MOD;
                included[i][j] = false;
            }
            else {
                dp[i][j] = dp[i+1][j] + dp[i][j+1] + 1;
                dp[i][j] %= MOD;
                included[i][j] = true;
            }
        }
    }
    cout << dp[0][0]%MOD;
}
    return 0;
}