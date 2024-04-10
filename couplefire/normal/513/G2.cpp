#include <bits/stdc++.h>
using namespace std;
#define MAXN 105

int n, k;
double dp[2*MAXN][MAXN][MAXN];
int arr[MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << setprecision(12);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++) dp[0][i][j] = (arr[i]>arr[j]);
    }
    for(int len = 1; len<=k; len++){
        for(int i = 1; i<=n; i++){
            for(int j = i+1; j<=n; j++){
                for(int a = i+1; a<=j; a++) dp[len][i][j] += dp[len-1][i][a]*min(a-i, n+1-j)*2.0/n/(n+1);
                for(int a = j+1; a<=n; a++) dp[len][i][j] += dp[len-1][i][a]*min(j-i, n+1-a)*2.0/n/(n+1);
                for(int a = i; a<=j-1; a++) dp[len][i][j] += dp[len-1][a][j]*min(j-a, i)*2.0/n/(n+1);
                for(int a = 1; a<=i-1; a++) dp[len][i][j] += dp[len-1][a][j]*min(j-i, a)*2.0/n/(n+1);
                for(int a = 1; a<=i; a++) dp[len][i][j] += (1-dp[len-1][a][a+j-i])*min(a, n+1-j)*2.0/n/(n+1);
                for(int a = j+1; a<=n; a++) dp[len][i][j] += (1-dp[len-1][a-j+i][a])*min(n+1-a, i)*2.0/n/(n+1);
                dp[len][i][j] += dp[len-1][i][j]*(j-i-1)*(j-i)/n/(n+1);
                dp[len][i][j] += dp[len-1][i][j]*(i-1)*(i)/n/(n+1);
                dp[len][i][j] += dp[len-1][i][j]*(n-j)*(n-j+1)/n/(n+1);
            }
        }
    }
    double ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++) ans += dp[k][i][j];
    }
    cout << ans << endl;
}