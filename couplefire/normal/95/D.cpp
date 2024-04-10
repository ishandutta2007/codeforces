#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define MOD 1000000007

int dp[MAXN][MAXN] = {{0}};
int pow10[MAXN];
int t, k;

int get(string num){
    reverse(num.begin(), num.end());
    int prev = 2*MAXN;
    int mindis = MAXN;
    int ans = 0;
    for(int i = num.length()-1; i>=0; i--){
        int c = num[i]-'0';
        for(int j = 0; j<c; j++){
            if(mindis <= k){
                ans += pow10[i];
                if(ans >= MOD) ans -= MOD;
                continue;
            }
            if((j == 4 || j == 7)&&(prev-i <= k)){
                ans += pow10[i];
                if(ans >= MOD) ans -= MOD;
            }
            else if(j == 4 || j == 7){
                ans += dp[i][1];
                if(ans >= MOD) ans -= MOD;
            }
            else{
                ans += dp[i][min(MAXN-1, prev-i+1)];
                if(ans >= MOD) ans -= MOD;
            }
        }
        if(c == 4 || c == 7){
            mindis = min(mindis, prev-i);
            prev = i;
        }
    }
    if(mindis <= k) ans++;
    return ans;
}

string minusone(string s){
    int ca = 1;
    for(int i = s.length()-1; i>=0; i--){
        if(ca == 0) break;
        if(s[i]-'0'-ca == -1){
            s[i] = '9';
        }
        else{
            s[i] -= ca;
            ca--;
        }
    }
    return s;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> k;
    pow10[0] = 1;
    for(int i = 1; i<MAXN; i++) pow10[i] = (1ll*pow10[i-1]*10)%MOD;
    for(int i = 1; i<MAXN; i++){
        for(int j = 1; j<MAXN; j++){
            dp[i][j] = 1ll*8*dp[i-1][min(j+1, MAXN-1)]%MOD;
            if(j <= k){
                dp[i][j] += (1ll*2*pow10[i-1])%MOD;
                if(dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
            else{
                dp[i][j] += (1ll*2*dp[i-1][1])%MOD;
                if(dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
        }
    }
    while(t--){
        string l, r; cin >> l >> r;
        l = minusone(l);
        // cout << get(r) << endl;
        cout << (get(r)-get(l)+MOD)%MOD << endl;
    }
}