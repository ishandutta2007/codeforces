// https://codeforces.com/problemset/problem/416/E
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009
#define MAXN 505
vector<pair<int, int>> adj[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n  >> m;
    int dp[n][n];
    int stuff[n][n];
    int ans[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            dp[i][j] = INF;
            stuff[i][j] = 0;
            ans[i][j] = 0;
        }
    }
    for(int i = 0; i<n; i++) dp[i][i] = 0;
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w;
        --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        dp[a][b] = w;
        dp[b][a] = w;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dp[i][j] >= INF) continue;
            for(auto u : adj[i]){
                if(dp[u.first][j]+u.second==dp[i][j]) stuff[i][j]++;
            }
        }
    }

    for(int v = 0; v<n; v++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(dp[i][v]>=INF || dp[j][v] >= INF) continue;
                if(dp[i][v] + dp[j][v] == dp[i][j]) ans[i][j] += stuff[v][i]+stuff[v][j];
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            cout << ans[i][j]/2 << " ";
        }
    }
}