#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s; cin >> s;
    n = s.length();
    int sum[n];
    int prefix[n];
    sum[0] = s[0]-'0';
    prefix[0] = sum[0];
    for(int i = 1; i<n; i++){
        sum[i] = (1ll*sum[i-1]*10)%MOD+s[i]-'0';
        if(sum[i] >= MOD) sum[i] -= MOD;
        prefix[i] = prefix[i-1]+sum[i];
        if(prefix[i] >= MOD) prefix[i] -= MOD;
    }
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i<n; i++){
        dp[i] = (1ll*dp[i-1]*10)%MOD;
        dp[i] = (0ll+dp[i]+1ll*i*(i+1)/2*(0ll+s[i]-'0'))%MOD;
        dp[i] += prefix[i-1];
        if(dp[i] >= MOD) dp[i] -= MOD;
    }
    cout << dp[n-1] << endl;
}