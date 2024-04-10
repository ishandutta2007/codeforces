#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int dp[N][N], ans[N];

int main() {
    
    int n;
    string s;
    cin >> s;
    n = s.size();
    
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            int r = l + len;
            
            if (len == 1) {
                dp[l][r] = 1;
                continue;
            } else if (len == 2) {
                dp[l][r] = (s[l] == s[r - 1] ? 2 : 0);
                continue;
            }
            
            if (s[l] != s[r - 1] || !dp[l + 1][r - 1]) {
                continue;
            }
            
            dp[l][r] = 1;
            int m = (l + r) / 2;
            
            if (len & 1) {
                if (dp[l][m] && dp[m + 1][r]) {
                    dp[l][r] = dp[l][m] + 1;
                }
            } else {
                if (dp[l][m] && dp[m][r]) {
                    dp[l][r] = dp[l][m] + 1;
                }
            }
        }
    }
    
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            ans[dp[l][l + len]]++;
        }
    }
    
    for (int i = n - 1; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}