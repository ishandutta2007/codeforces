#include<bits/stdc++.h>
using namespace std;
int dp[50][50][50][50];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    char matrix[n][n];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) cin >> matrix[i][j];
    for (int dx=0; dx <= n-1; dx++){
    	for (int dy=0; dy <= n-1; dy++){
    		for (int i=0; i + dx <= n-1; i++) for (int j=0; j+dy <= n-1; j++){
    			if (dx==0 && dy==0){
    				dp[i][j][i][j] = (matrix[i][j] != '.');
    			}
    			else{
    				dp[i][j][i+dx][j+dy] = max(dx+1, dy+1);
    				for (int t=1; t + 1 <= dx+1; t++) dp[i][j][i+dx][j+dy] = min(dp[i][j][i+dx][j+dy], dp[i][j][i+t-1][j+dy] + dp[i+t][j][i+dx][j+dy]);
    				for (int t=1; t + 1 <= dy+1; t++){
    					dp[i][j][i+dx][j+dy] = min(dp[i][j][i+dx][j+dy], dp[i][j][i+dx][j+t-1] + dp[i][j+t][i+dx][j+dy]);
    				}

    			}
    		}
    	}
    }
    cout << dp[0][0][n-1][n-1];
}