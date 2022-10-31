//https://codeforces.com/problemset/problem/403/D
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[1005][1005] = {0};
long long permu[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(long long i = 0; i<1005; i++) dp[i][0] = 1;
    dp[0][1] = 1;
    for(long long i = 1; i<1005; i++){
        for(long long j = 1; j<1005; j++){
            dp[i][j] = dp[i-1][j];
            long long k = 1;
            while(i-k*j >= 0 && dp[i-k*j][j-1] > 0){
                dp[i][j] += dp[i-k*j][j-1];
                dp[i][j] %= MOD;
                k++;
            }
            if(j == 1) dp[i][j]++;
            dp[i][j] %= MOD;
        }
    }
    permu[0] = 1;
    for(int i = 1; i<1005; i++){
        permu[i] = (i*permu[i-1])%MOD;
    }
    long long n; cin >> n;
    while(n--){
        long long a, b; cin >> a >> b;
        cout << (dp[a-1][b]*permu[b])%MOD << endl;
    }
}