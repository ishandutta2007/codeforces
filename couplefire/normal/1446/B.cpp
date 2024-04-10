#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005

int dp[MAXN][MAXN];
string A, B;
int n, m;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> A >> B;
    A = " "+A;
    B = " "+B;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
            dp[i][j] = max(dp[i][j], dp[i][j-1]-1);
            if(A[i] == B[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}