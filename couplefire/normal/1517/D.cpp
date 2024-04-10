#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005

int n, m, len;
int dp[MAXN][11];
vector<array<int, 2>> adj[MAXN];

int getid(int i, int j){return i*m+j;}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, 63, sizeof dp);
    cin >> n >> m >> len;
    if(len%2){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) cout << -1 << " ";
            cout << endl;
        }
        return 0;
    }
    len /= 2;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m-1; j++){
            int w; cin >> w;
            adj[getid(i, j)].push_back({getid(i, j+1), w});
            adj[getid(i, j+1)].push_back({getid(i, j), w});
        }
    }
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<m; j++){
            int w; cin >> w;
            adj[getid(i, j)].push_back({getid(i+1, j), w});
            adj[getid(i+1, j)].push_back({getid(i, j), w});
        }
    }
    for(int i = 0; i<n*m; i++) dp[i][0] = 0;
    for(int k = 1; k<=len; k++){
        for(int i = 0; i<n*m; i++){
            for(auto u : adj[i]) dp[i][k] = min(dp[i][k], dp[u[0]][k-1]+u[1]);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << 2*dp[getid(i, j)][len] << " ";
        }
        cout << endl;
    }
}