#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int INF = 0x3f3f3f3f;

int n, m;
int dist[N][N];
vector<int> adj[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    memset(dist, INF, sizeof dist);
    for(int i = 0; i<m; i++){
        int a, b, t; cin >> a >> b >> t; --a; --b;
        dist[a][b] = 1, dist[b][a] = t?-1:1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for(int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    if(!is_bipartite)
        cout << "NO" << endl, exit(0);
    for(int i = 0; i<n; i++)
        dist[i][i] = 0;
    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    for(int i = 0; i<n; i++)
        if(dist[i][i] < 0)
            cout << "NO" << endl, exit(0);
    cout << "YES" << endl;
    int mxdist = -1, u = -1, v = -1;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(dist[i][j] > mxdist)
                mxdist = dist[i][j], u = i, v = j;
    cout << mxdist << endl;
    for(int i = 0; i<n; i++)
        cout << dist[u][i] << " ";
    cout << endl;
}