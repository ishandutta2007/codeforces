#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    int pos[k];
    fill(pos, pos+k, -1);
    string s; cin >> s;
    long long dp[s.length()+n+1];
    dp[0] = 1ll;
    for(int i = 1; i<=s.length(); i++){
        if(pos[s[i-1]-'a'] == -1) dp[i] = (2*dp[i-1])%MOD;
        else dp[i] = (2*dp[i-1]-dp[pos[s[i-1]-'a']])%MOD;
        pos[s[i-1]-'a'] = i-1;
    }
    // cout << pos[1] << endl;
    for(int i = s.length()+1; i<=s.length()+n; i++){
        int mi = n+s.length()+1, ppos;
        for(int j = 0; j<k; j++){
            if(pos[j] < mi) ppos = j;
            mi = min(pos[j], mi);
        }
        if(mi == -1) dp[i] = (2*dp[i-1])%MOD;
        else dp[i] = (2*dp[i-1]-dp[mi])%MOD;
        pos[ppos] = i-1;
    }
    cout << (dp[n+s.length()]+MOD)%MOD << endl;
}