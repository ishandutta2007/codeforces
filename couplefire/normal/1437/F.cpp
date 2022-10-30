#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define MAXN 5005

int n;
int arr[MAXN];
int fac[MAXN];
int invfac[MAXN];
int dp[MAXN][MAXN] = {{0}};
int prefix[MAXN][MAXN] = {{0}};

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inverse(int n){
    int x, y;
    int g = gcd(n,MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    fac[0] = 1;
    for(int i = 1; i<MAXN; i++) fac[i] = 1ll*fac[i-1]*i%MOD;
    for(int i = 0; i<MAXN; i++) invfac[i] = inverse(fac[i]);
    sort(arr+1, arr+1+n);
    dp[0][0] = 1;
    prefix[0][0] = 1;
    for(int i = 1; i<=n; i++){
        dp[i][0] = 1;
        prefix[i][0] = fac[i];
        int m = i-1;
        while(m > 0 && arr[m]*2 > arr[i]) m--;
        for(int j = 1; j<=i; j++){
            prefix[i][j] = prefix[i][j-1];
            dp[i][j] = dp[i-1][j];
            if(m+1-j < 0){
                prefix[i][j] += dp[i][j];
                if(prefix[i][j] >= MOD) prefix[i][j] -= MOD;
                continue;
            }
            dp[i][j] += 1ll*prefix[m][j-1]*invfac[m+1-j]%MOD;
            if(dp[i][j] >= MOD) dp[i][j] -= MOD;
            prefix[i][j] += 1ll*dp[i][j]*fac[i-j]%MOD;
            if(prefix[i][j] >= MOD) prefix[i][j] -= MOD;
        }
    }
    // cout << dp[3][1] << endl;
    cout << dp[n][n] << endl;
}