#include <bits/stdc++.h>
using namespace std;

const int N = 400005;

int n, m;
vector<int> adj[N], adj_rev[N];
vector<vector<int>> grid;
int roots[N], in[N];
bool used[N];
vector<int> order, comp, bruh;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs1(int v) {
    used[v] = true;
    for (auto u : adj[v])
        if (!used[u]) dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    comp.push_back(v);
    for (auto u : adj_rev[v])
        if (!used[u]) dfs2(u);
}

int hsh(int i, int j){return i*m+j;}

bool valid(int i, int j){return 0 <= i && i < n && 0 <= j && j < m;}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<m; j++)
            grid[i][j] = (s[j]=='#');
    }
    for(int j = 0; j<m; j++){
        int pi = -1;
        for(int i = 0; i<n; i++){
            if(grid[i][j]) pi = i;
            if(!valid(pi, j)) continue;
            for(int k = 0; k<4; k++){
                int a = i+dx[k], b = j+dy[k];
                if(valid(a, b) && grid[a][b])
                    adj[hsh(pi, j)].push_back(hsh(a, b)),
                    adj_rev[hsh(a, b)].push_back(hsh(pi, j));
            }
        }
    }
    for(int i = 0; i<n*m; i++)
        if(!used[i]) dfs1(i);
    memset(used, 0, sizeof used);
    reverse(order.begin(), order.end());
    for(auto v : order){
        if(!used[v]){
            dfs2(v);
            int root = comp.front();
            for(auto u : comp) roots[u] = root;
            bruh.push_back(root);
            comp.clear();
        }
    }
    for(int v = 0; v<n*m; v++){
        for(auto u : adj[v]){
            int rv = roots[v], ru = roots[u];
            if(rv != ru) in[ru]++;
        }
    }
    int ans = 0;
    for(auto v : bruh){
        int i = v/m, j = v%m;
        if(!in[v] && grid[i][j]) ans++;
    }
    cout << ans << endl;
}