#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000;

int main(){
    //freopen("a.in", "r", stdin);
    int n; cin >> n;
    int num[2];
    num[0] = n/2;
    num[1] = (n+1)/2;
    int arr[n];
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        if(a == 0){
            arr[i] = 2;
            continue;
        }
        num[a%2]--;
        arr[i] = a%2;
    }
    int dp[n][num[1]+1][2];
    int cur = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == 2) cur++;
        for(int j = 0; j<=num[1]; j++){
            for(int k = 0; k<2; k++){
                if(j > cur){
                    dp[i][j][k] = INF;
                    //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                    continue;
                }
                if(cur - j > num[0]){
                    dp[i][j][k] = INF;
                    //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                    continue;
                }
                if(cur != 0){
                    if(j == 0 && k == 1){
                        dp[i][j][k] = INF;
                        //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                        continue;
                    }
                    if(j == cur && k == 0){
                        dp[i][j][k] = INF;
                        //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                        continue;
                    }
                }
                if(i == 0){
                    dp[i][j][k] = 0;
                    //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                    continue;
                }
                if(arr[i] == 2 && arr[i-1] == 2) dp[i][j][k] = min({dp[i-1][j-k][0]+(k^0), dp[i-1][j-k][1]+(k^1)});
                else if(arr[i] == 2) dp[i][j][k] = min({dp[i-1][j-k][0]+(arr[i-1]^k), dp[i-1][j-k][1]+(arr[i-1]^k)});
                else if(arr[i-1] == 2) dp[i][j][k] = dp[i-1][j][k]+(arr[i]^k);
                else dp[i][j][k] = dp[i-1][j][k]+(arr[i-1]^arr[i]);
                //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }
    int ans = INF;
    for(int i = 0; i<=num[1]; i++){
        ans = min(ans, dp[n-1][i][0]);
        ans = min(ans, dp[n-1][i][1]);
    }
    cout << ans << endl;
}