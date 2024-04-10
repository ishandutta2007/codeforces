#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int dp[s.size() + 1][2];
    for (int i=0; i <= s.size(); i++) for (int j=0; j <= 2; j++) dp[i][j] = -1e18;
    dp[0][0] = 0;
    for (int i=0; i < s.size(); i++){
        for (int d=0; d < 2; d++){
            int symb = s[s.size() - 1 - i] - '0';
            for (int j=0; j <= 9; j++) for (int p=0; p <= 9; p++){
                int t = (j+p+d)%10;
                int T = j+p+d;
                if (t != symb) continue;
                dp[i+1][(T >= 10)] = max(dp[i+1][(T >= 10)], dp[i][d]+j+p);
            }
        }
    }
    cout << dp[s.size()][0];
}