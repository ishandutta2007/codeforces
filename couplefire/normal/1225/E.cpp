#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m; cin >> n >> m;
    long long dp[n][m];
    long long dp1[n][m][2]; //0: vert, 1: hori
    long long sumcol[m][n];
    long long sumrow[n][m];
    long long grid[n][m];
    for(long long i = 0; i<n; i++){
        string s; cin >> s;
        for(long long j = 0; j<m; j++){
            if(s[j] == '.'){
                grid[i][j] = 0;
            }
            else{
                grid[i][j] = 1;
            }
        }
    }
    for(long long i = 0; i<m; i++){
        long long prev = 0;
        for(long long j = n-1; j>=0; j--){
            sumcol[i][j] = prev + grid[j][i];
            prev = sumcol[i][j];
        }
    }
    for(long long i = 0; i<n; i++){
        long long prev = 0;
        for(long long j = m-1; j>=0; j--){
            sumrow[i][j] = prev + grid[i][j];
            prev = sumrow[i][j];
        }
    }
    for(long long i = 0; i<m; i++){
        if(i < m-sumrow[0][0]){
            dp[0][i] = 1;
        }
        else{
            dp[0][i] = 0;
        }
        if(i == m-sumrow[0][0]-1){
            dp1[0][i][1] = 1;
        }
        else{
            dp1[0][i][1] = 0;
        }
        if(i < m-sumrow[0][0] && (n == 1 || sumcol[i][1] == n-1)) dp1[0][i][0] = 1;
        else dp1[0][i][0] = 0;
    }
    for(long long i = 0; i<n; i++){
        if(i < n-sumcol[0][0]){
            dp[i][0] = 1;
        }
        else{
            dp[i][0] = 0;
        }
        if(i == n-sumcol[0][0]-1){
            dp1[i][0][0] = 1;
        }
        else{
            dp1[i][0][0] = 0;
        }
        if(i < n-sumcol[0][0] && (m == 1 || sumrow[i][1] == m-1)) dp1[i][0][1] = 1;
        else dp1[i][0][1] = 0;
    }
    for(long long i = 1; i<n; i++){
        for(long long j = 1; j<m; j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp1[i-1][j][0]-dp1[i][j-1][1];
            dp[i][j] %= MOD;
            dp1[i][j][1] = 0;
            long long it1 = lower_bound(sumrow[i], sumrow[i]+m, m-1-j, greater<long long>()) - sumrow[i];
            long long it2 = lower_bound(sumrow[i], sumrow[i]+m, m-1-j-1, greater<long long>()) - sumrow[i];
            for(long long k = max(0ll, it1-1); k<=it2-2; k++) dp1[i][j][1] += dp[i-1][k]-dp1[i-1][k][0];
            dp1[i][j][1] %= MOD;
            dp1[i][j][0] = 0;
            it1 = lower_bound(sumcol[j], sumcol[j]+n, n-1-i, greater<long long>())-sumcol[j];
            it2 = lower_bound(sumcol[j], sumcol[j]+n, n-1-i-1, greater<long long>())-sumcol[j];
            for(long long k = max(0ll, it1-1); k<=it2-2; k++) dp1[i][j][0] += dp[k][j-1]-dp1[k][j-1][1];
            dp1[i][j][0] %= MOD;
        }
    }
    cout << (dp[n-1][m-1]+MOD)%MOD << endl;
    // for(long long i = 0; i<n; i++){
    //     for(long long j = 0; j<m; j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}