#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
vector<int> fact;
int pw(int a, int b){
    if (b==0) return 1;
    if (b==1) return a%MOD;
    if (b%2){
        return (pw(a, b-1) * a) % MOD;
    }
    int rs = pw(a, b/2);
    return (rs*rs) % MOD;
}
int C(int n, int k){
    int x = fact[n] % MOD;
    int y = (fact[k] * fact[n-k]) % MOD;
    return (x * pw(y, MOD-2)) % MOD;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    fact.push_back(1);
    for (int i=0; i < 1000; i++) fact.push_back(((i+1) * fact.back())%MOD);
    int ways[100][2];
    for (int i=0; i < 100; i++){
        int A = 0, B=0;
        for (int j=0; j <= i; j++){
            if (j%2) B += C(i, j);
            else A += C(i, j);
        }
        A %= MOD, B %= MOD;
        ways[i][0] = A, ways[i][1] = B;
    }
    cin >> n >> p;
    vector<int> val(n);
    for (int i=0; i < n; i++) cin >> val[i];
    int dp[51][51][51];
    for (int i=0; i <= 50; i++) for (int j=0; j <= 50; j++) for (int k=0; k <= 50; k++) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for (int i=n-1; i >= 0; i--){
        int dp2[51][51][51];
        for (int e=0; e <= 50; e++) for (int j=0; j <= 50; j++) for (int k=0; k <= 50; k++){
            dp2[e][j][k] = 0;
            if (e+j+k > n-i) continue;
            int rest = n - i - e - j - k;
            if (val[i] == 0 || val[i] == -1){
                if (e > 0){
                    int per = (ways[rest][0] + ways[rest][1]) % MOD;
                    per *= ways[k][0];
                    per %= MOD;
                    per *= (ways[e+j-1][0] + ways[e+j-1][1]);
                    per %= MOD;
                    dp2[e][j][k] += dp[e-1][j][k] * per;
                    dp2[e][j][k] %= MOD;
                }
                if (j > 0){
                    int per = (ways[rest][0] + ways[rest][1]) % MOD;
                    per *= ways[k][1];
                    per %= MOD;
                    per *= (ways[e+j-1][0] + ways[e+j-1][1]);
                    per %= MOD;
                    dp2[e][j][k] += dp[e][j-1][k] * per;
                    dp2[e][j][k] %= MOD;
                }
            }
            if (val[i] == 1 || val[i] == -1){
                if (k > 0){
                    int per = (ways[j][0] + ways[j][1]) % MOD;
                    per *= ways[e][0];
                    per %= MOD;
                    per *= (ways[k+rest-1][0] + ways[k+rest-1][1]);
                    per %= MOD;
                    dp2[e][j][k] += dp[e][j][k-1] * per;
                    dp2[e][j][k] %= MOD;
                }
                if (rest > 0){
                    int per = (ways[j][0] + ways[j][1]) % MOD;
                    per *= ways[e][1];
                    per %= MOD;
                    per *= (ways[k+rest-1][0] + ways[k+rest-1][1]);
                    per %= MOD;
                    dp2[e][j][k] += dp[e][j][k] * per;
                    dp2[e][j][k] %= MOD;
                }
            }
        }
        for (int e=0; e <= 50; e++) for (int j=0; j <= 50; j++) for (int k=0; k <= 50; k++) dp[e][j][k] = dp2[e][j][k];
    }
    int ans = 0;
    for (int i=0; i <= 50; i++) for (int j=0; j <= 50; j++) for (int k=0; k <= 50; k++){
        int nc = i+k;
        if (nc%2 == p) ans+=dp[i][j][k];
    }
    cout << ans%MOD;
}