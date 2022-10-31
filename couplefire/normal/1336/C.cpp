#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int main(){
    //freopen("a.in", "r", stdin);
    string s; cin >> s;
    string t; cin >> t;
    long long dp[s.length()][s.length()];
    long long ans = 0;
    for(long long i = 0; i<s.length(); i++){
        if(t.length() <= i || t[i] == s[0]) dp[i][i] = 2;
        else dp[i][i] = 0;
    }
    for(long long len = 1; len < s.length(); len++){
        for(long long i = 0; i+len<s.length(); i++){
            long long j = i+len;
            dp[i][j] = 0;
            if(t.length() <= j || t[j] == s[len]) dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
            if(t.length() <= i || t[i] == s[len]) dp[i][j] = (dp[i][j]+dp[i+1][j])%MOD;
        }
    }
    for(long long len = 0; len<s.length(); len++) if(len >= t.length()-1) ans = (ans+dp[0][len])%MOD;
    cout << ans << endl;
}