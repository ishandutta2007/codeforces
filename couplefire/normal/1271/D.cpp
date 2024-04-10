#include <iostream>
#include <algorithm>
 
using namespace std;
 
int A[5000];
int B[5000];
int C[5000];
int D[5000];
int dp[5001][5001];
 
int main() {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i] >> C[i];
        D[i] = i;
    }
 
    int u, v;
    while(m--) {
        cin >> u >> v;
        v -= 1;
        D[v] = max(D[v], u - 1);
    }
 
    dp[0][k] = 1;
 
    for(int i = 0; i < n; ++i) {
        for(int j = A[i]; j < 5001; ++j)
            if(dp[i][j])
                dp[i + 1][j + B[i]] = max(dp[i + 1][j + B[i]], dp[i][j]);
 
        for(int j = 0; j <= i; ++j)
            if(D[j] == i)
                for(int l = 1; l < 5001; ++l)
                    if(dp[i + 1][l])
                        dp[i + 1][l - 1] = max(dp[i + 1][l - 1], dp[i + 1][l] + C[j]);
    }
 
    int mx = 0;
    for(int i = 0; i < 5001; ++i)
        mx = max(mx, dp[n][i]);
 
    cout << mx - 1;
    
    return 0;
}