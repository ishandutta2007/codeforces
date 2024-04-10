#include <bits/stdc++.h>
using namespace std;
#define MAXN 55

int n;
vector<int> adj[MAXN];
double dp[MAXN][MAXN], comb[MAXN][MAXN];
double tmp[MAXN];
int siz[MAXN];

void solve(int v, int p){
    dp[v][0] = 1.0; siz[v] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        solve(u, v);
        for(int i = 0; i<siz[v]; i++) tmp[i] = dp[v][i], dp[v][i] = 0;
        for(int i = 0; i<siz[v]; i++){
            for(int j = 0; j<siz[u]; j++){
                for(int k = 1; k<=j+1; k++) dp[v][i+j+1] += tmp[i]*dp[u][j]*comb[i+j+1][i]*comb[siz[v]+siz[u]-1-i-j-1][siz[v]-1-i]/comb[siz[v]+siz[u]-1][siz[v]-1]/(siz[u]);
                for(int k = j+1; k<=siz[u]; k++) dp[v][i+j] += 0.5*tmp[i]*dp[u][k-1]*comb[i+j][i]*comb[siz[v]+siz[u]-1-i-j][siz[v]-1-i]/comb[siz[v]+siz[u]-1][siz[v]-1]/(siz[u]);
            }
        }
        siz[v] += siz[u];
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    comb[0][0] = 1.0;
    for(int i = 1; i<=n; i++){
        comb[i][0] = comb[i][i] = 1.0;
        for(int j = 1; j<i; j++) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
    for(int i = 0; i<n; i++){
        memset(dp, 0, sizeof dp);
        solve(i, -1);
        cout << dp[i][0] << endl;
        // cout << dp[3][0] << endl;
    }
}