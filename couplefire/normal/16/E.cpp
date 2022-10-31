#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    cout << setprecision(8);
    int n; cin >> n;
    double grid[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    double dp[(1<<n)];
    fill(dp, dp+(1<<n), 0);
    dp[(1<<n)-1] = 1;
    for(int i = (1<<n)-1; i>0; i--){
        if(i == (i&(-i))) continue;
        int num = __builtin_popcount(i);
        for(int a = 0; a<n; a++){
            for(int b = a+1; b<n; b++){
                if(!(i&(1<<a) && i&(1<<b))) continue;
                dp[i^(1<<a)] += dp[i]*grid[b][a]*2/(num*(num-1));
                dp[i^(1<<b)] += dp[i]*grid[a][b]*2/(num*(num-1));
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout << dp[1<<i] << " ";
    }
    cout << endl;
}