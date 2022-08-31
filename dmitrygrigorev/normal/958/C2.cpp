#include <bits/stdc++.h>
using namespace std;
int INF = -5e8;
int dp[20000][50][100], mx[20000][50];
signed main() {
    int n, k, p;
    cin >> n >> k >> p;
    for (int i=0; i < n; i++) for (int j=0; j < k; j++) for (int l=0; l < p; l++) dp[i][j][l] = INF;
    for (int i=0; i < n; i++) for (int j=0; j < k; j++) mx[i][j] = INF;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) v[i] %= p;
    dp[0][0][v[0]] = v[0];
    mx[0][0] = v[0];
    for (int i=1; i < n; i++){
        for (int j=0; j < k; j++){
            for (int l=0; l < p; l++){
                int oost = (l - v[i] + p) % p;
                int prib = l - oost;
                dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][oost]+prib);
                if (l == v[i] && j > 0) dp[i][j][l] = max(dp[i][j][l], mx[i-1][j-1] + v[i]);
                mx[i][j] = max(mx[i][j], dp[i][j][l]);
            }
        }
    }
    cout << mx[n-1][k-1];
    return 0;
}