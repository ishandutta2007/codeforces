#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define MOD 1000000007

int dp[MAXN][20*MAXN] = {{0}};
int n;
int arr[MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=n; i++){
        for(int j = -10*MAXN; j<10*MAXN; j++){
            if(arr[i] == j) ++dp[i][j+10*MAXN];
            if(-arr[i] == j) ++dp[i][-j+10*MAXN];
            if(j-arr[i] >= -10*MAXN) dp[i][j+10*MAXN] = (0ll+dp[i][j+10*MAXN]+dp[i-1][j-arr[i]+10*MAXN])%MOD;
            if(j+arr[i] < 10*MAXN) dp[i][j+10*MAXN] = (0ll+dp[i][j+10*MAXN]+dp[i-1][j+arr[i]+10*MAXN])%MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = (0ll+ans+dp[i][10*MAXN])%MOD;
    }
    cout << ans << endl;
}