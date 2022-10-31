#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define INF 1000000009

int dp[MAXN][MAXN][MAXN*MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n+1], brr[n+1];
    for(int i = 1; i<=n; i++){
        int a, b; cin >> a >> b;
        arr[i] = a; brr[i] = b;
    }
    int tot = 0;
    for(int i = 1; i<=n; i++) tot += brr[i];
    for(int i = 0; i<MAXN; i++) for(int j = 0; j<MAXN; j++) for(int k = 0; k<MAXN*MAXN; k++) dp[i][j][k] = -INF;
    dp[0][0][0] = 0;
    for(int i = 1; i<=n; i++){
        dp[i][0][0] = 0;
        for(int j = 1; j<=i; j++){
            for(int k = 0; k<=i*100; k++){
                dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-1][max(k-brr[i], 0)]+arr[i]);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        int ans = 0;
        for(int j = 0; j<MAXN*MAXN; j++) ans = max(ans, min(2*dp[n][i][j], j+tot));
        cout << (0.0+ans)/2 << endl;
    }
}