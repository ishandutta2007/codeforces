#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define INF 1000000009

int n, b;
vector<int> adj[MAXN];
int c[MAXN], d[MAXN];
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];
int sz[MAXN] = {0};

void dfs(int v){
    for(int i = 0; i<=MAXN; i++) dp1[v][i] = dp2[v][i] = b+1;
    sz[v] = 1;
    // dp1[v][0] = 0;
    dp2[v][0] = 0;
    dp1[v][1] = c[v]-d[v];
    dp2[v][1] = c[v];
    for(auto u : adj[v]){
        dfs(u);
        for(int i = sz[v]; i>=0; i--){
            for(int j = sz[u]; j>=0; j--){
                dp2[v][i+j]=min(dp2[v][i+j], dp2[v][i]+dp2[u][j]);
                dp1[v][i+j]=min(dp1[v][i+j], dp1[v][i]+min(dp1[u][j], dp2[u][j]));
            }
        }
        sz[v] += sz[u];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> b;
    cin >> c[0] >> d[0];
    for(int i = 1; i<n; i++){
        cin >> c[i] >> d[i];
        int x; cin >> x; --x;
        adj[x].push_back(i);
    }
    dfs(0);
    int ans = -INF;
    for(int i = 0; i<=n; i++){
        if(dp1[0][i] <= b || dp2[0][i] <= b) ans = i;
    }
    cout << ans << endl;
}