#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int n; cin >> n;
    string s; cin >> s;
    int dp[n+1][n+1];
    for(int len = 0; len <=n; len++){
        for(int i = 0; i<=n-len; i++){
            if(len == 0){
                dp[len][i] = 0;
                continue;
            }
            if(len == 1){
                dp[len][i] = 1;
                continue;
            }
            char c = s[i+len-1];
            dp[len][i] = dp[len-1][i]+1;
            for(int j = i+len-2; j>=i; j--){
                if(s[j] == c){
                    dp[len][i] = min(dp[len][i], dp[j-i+1][i]+dp[len-j+i-2][j+1]);
                }
            }
        }
    }
    cout << dp[n][0] << endl;
}