#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n + 1);
        for(int i = 0; i < n; i++) {
            cin >> v[i + 1];
        }
        vector <bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            if(v[i] < i) dp[i] = dp[i - v[i] - 1] | dp[i];
            if(dp[i - 1] && (i + v[i]) <= n) dp[i + v[i]] = true;
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    
    return 0;
}