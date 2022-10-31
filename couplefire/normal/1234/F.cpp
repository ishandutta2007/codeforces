#include <bits/stdc++.h>
using namespace std;
int dp[1 << 20];

int main(){
    //freopen("a.in", "r", stdin);
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i<n; i++){
        bool used[20] = {0};
        int mask = 0;
        for(int j = 0; i+j < n; j++){
            if(used[s[i+j]-'a']) break;
            used[s[i+j]-'a'] = true;
            mask |= 1 << (s[i+j]-'a');
            dp[mask] = __builtin_popcount(mask);
        }
    }
    for(int i = 0; i<(1<<20); i++){
        for(int j = 0; j<20; j++){
            if((i >> j) & 1){
                dp[i] = max(dp[i], dp[i^(1 << j)]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<(1 << 20); i++){
        ans = max(ans, dp[i] + dp[~i&((1 << 20)-1)]);
    }
    cout << ans << endl;
}