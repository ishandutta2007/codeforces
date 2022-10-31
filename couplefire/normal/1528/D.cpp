#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int N = 605;
const int INF = 1e9+2*N;

int n, m;
int adj[N][N], ans[N][N];
bool vis[N];

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        fill(adj[i], adj[i]+n, INF);
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a][b] = w;
    }
    for(int i = 0; i<n; i++)
        fill(ans[i], ans[i]+n, INF);
    for(int i = 0; i<n; i++){
        int* dist = ans[i];
        memset(vis, 0, sizeof vis);
        dist[i] = 0;
        for(int j = 0; j<n; j++){
            int v = -1;
            for(int k = 0; k<n; k++)
                if(!vis[k]&&(v==-1||dist[k]<dist[v]))
                    v = k;
            if(dist[v]==INF) break;
            vis[v] = 1;
            int curmin = INF;
            for(int k = n-1; k>=0; k--){
                int u = (k-dist[v])%n;
                if(u<0) u+=n;
                if(adj[v][u] < INF){
                    curmin = min(curmin, n-k+adj[v][u]);
                }
            }
            for(int u = 0; u<n; u++){
                int k = (u-dist[v])%n;
                if(k<0) k+=n;
                if(adj[v][k]) curmin = min(curmin, adj[v][k]-u);
                if(dist[v]+curmin+u<dist[u])
                    dist[u] = dist[v]+curmin+u;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}