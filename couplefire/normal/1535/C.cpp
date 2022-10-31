#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s; s = "$"+s;
    int n = s.length();
    vector<int> dp[2]; dp[0].assign(n+1, 0); dp[1].assign(n+1, 0);
    long long ans = 0;
    for(int i = 1; i<=n; i++){
        if(s[i] == '?')
            dp[0][i] = dp[1][i-1]+1,
            dp[1][i] = dp[0][i-1]+1;
        else if(s[i] == '1')
            dp[0][i] = dp[1][i-1]+1;
        else dp[1][i] = dp[0][i-1]+1;
    }
    for(int i = 0; i<n; i++)
        ans += max(dp[0][i], dp[1][i]);
    cout << ans << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}