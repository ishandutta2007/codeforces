#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    string s; cin >> s;
    long long dp[26][26] = {0};
    long long cnt[26] = {0};
    for(long long i = 0; i<s.length(); i++){
        for(long long j = 0; j<26; j++){
            dp[j][s[i]-'a'] += cnt[j];
        }
        cnt[s[i]-'a']++;
    }
    long long ans = 0;
    for(long long i = 0; i<26; i++){
        ans = max(ans, cnt[i]);
        for(long long j = 0; j<26; j++) ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
}