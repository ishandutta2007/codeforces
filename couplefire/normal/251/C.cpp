//https://codeforces.com/problemset/problem/251/C
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a, b; int k;
    cin >> a >> b >> k;
    int llcm[17];
    llcm[1] = 1;
    for(int i = 2; i<17; i++) llcm[i] = llcm[i-1]*i/__gcd(llcm[i-1], i);
    if(a - b > llcm[k]){
        int dp1[llcm[k]+5];
        int dp2[llcm[k]+5];
        int aa = a%llcm[k];
        int bb = b%llcm[k];
        dp1[0] = 0;
        for(int i = 1; i<=aa; i++){
            dp1[i] = 1+dp1[i-1];
            for(int j = 2; j<=k; j++){
                dp1[i] = min(dp1[i], dp1[i-i%j]+1);
            }
        }
        dp2[llcm[k]] = 0;
        for(int i = llcm[k]-1; i>=bb; i--){
            dp2[i] = dp2[i+1]+1;
            for(int j = 2; j<=k; j++){
                if(i%j != 0) continue;
                for(int l = 0; l<j; l++) dp2[i] = min(dp2[i], dp2[i+l]+1);
            }
        }
        //cout << dp1[aa] << endl;
        long long between = a/llcm[k]-b/llcm[k]-1;
        int dp[llcm[k]+5];
        dp[0] = 0;
        for(int i = 1; i<=llcm[k]; i++){
            dp[i] = dp[i-1]+1;
            for(int j = 2; j<=k; j++){
                dp[i] = min(dp[i], dp[i-i%j]+1);
            }
        }
        cout << between*dp[llcm[k]]+dp1[aa]+dp2[bb] << endl;
    }
    else{
        //cout << llcm[k] << endl;
        a -= b/llcm[k]*llcm[k];
        b %= llcm[k];
        int dp[2*llcm[k]];
        dp[b] = 0;
        for(int i = b+1; i<=a; i++){
            dp[i] = dp[i-1]+1;
            for(int j = 2; j<=k; j++){
                if(i-i % j < b) continue;
                dp[i] = min(dp[i], dp[i-i%j]+1);
            }
        }
        cout << dp[a] << endl;
    }
    return 0;
}