#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define MOD 1000000007
#define INVERSE 500000004

int dp[MAXN][2]; //  0 up, 1 down
int tdp[MAXN][2];
int arr[MAXN];
int numdepth[MAXN];
int n;

void copy(){
    for(int i = 1; i<=n; i++) tdp[i][0] = dp[i][0], tdp[i][1] = dp[i][1];
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++) cin >> arr[i+1];
    arr[n] = 0;
    numdepth[1] = 1;
    for(int i = 2; i<=n; i++) numdepth[i] = (1ll*numdepth[i-1]*arr[i-1])%MOD;
    for(int i = 1; i<=n; i++){
        dp[i][0] = dp[i][1] = 1;
        if(i == 1) dp[i][0] = 0;
        if(i == n) dp[i][1] = 0;
    }
    int ss = 0; for(int i = 1; i<=n; i++) ss = (ss+numdepth[i])%MOD;
    cout << ss-1 << " ";
    for(int k = 2; k<=2*n-2; k++){
        copy();
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(i == 1) dp[i][0] = 0;
            else{
                dp[i][0] = (0ll+tdp[i-1][0]+1ll*tdp[i-1][1]*(arr[i-1]-1)%MOD)%MOD;
            }
            if(i == n) dp[i][1] = 0;
            else{
                dp[i][1] = (1ll*tdp[i+1][1]*arr[i+1])%MOD;
            }
            ans = (ans+(1ll*numdepth[i]*dp[i][0]%MOD+1ll*numdepth[i+1]*dp[i][1]%MOD)%MOD)%MOD;
        }
        // cout << dp[1][1] << endl;
        cout << ((1ll*ans*INVERSE%MOD)+MOD)%MOD << " ";
    }
    cout << endl;
}