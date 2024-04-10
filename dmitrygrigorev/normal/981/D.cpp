#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int sums[n][n];
    for (int i=0; i < n; i++){
        for (int j=i; j < n; j++){
            int s = 0;
            for (int p=i; p <= j; p++) s += v[p];
            sums[i][j] = s;
        }
    }
    int must = 0;
    for (int b=55; b >= 0; b--){
        bool dp[n+1][k+1];
        for (int i=0; i <= n; i++) for (int j=0; j <= k; j++) dp[i][j] = false;
        dp[0][0] = true;
        int var = must + (1LL << b);
        for (int i=1; i <= n; i++){
            for (int j=1; j <= k; j++){
                for (int old=0; old < i; old++){
                    if (!dp[old][j-1]) continue;
                    int ss = sums[old][i-1];
                    if ((ss & var) != var) continue;
                    dp[i][j] = true;
                }
            }
        }
        if (dp[n][k]) must = var;
    }
    cout << must;
}