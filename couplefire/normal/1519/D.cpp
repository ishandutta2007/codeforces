#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 5005

int n;
int dp[MAXN][MAXN], arr[MAXN], brr[MAXN], psum[MAXN];

int getsum(int i, int j){
    if(i == 0) return psum[j];
    return psum[j]-psum[i-1];
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++) cin >> brr[i];
    for(int i = 0; i<n; i++) dp[i][i] = arr[i]*brr[i];
    for(int i = 0; i<n-1; i++) dp[i][i+1] = arr[i+1]*brr[i]+arr[i]*brr[i+1];
    for(int len = 2; len<n; len++){
        for(int i = 0, j = len; j<n; i++, j++){
            dp[i][j] = arr[j]*brr[i]+arr[i]*brr[j]+dp[i+1][j-1];
        }
    }
    psum[0] = arr[0]*brr[0];
    for(int i = 1; i<n; i++) psum[i] = psum[i-1]+arr[i]*brr[i];
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++) ans = max(ans, dp[i][j]+getsum(0, n-1)-getsum(i, j));
    }
    cout << ans << endl;
}