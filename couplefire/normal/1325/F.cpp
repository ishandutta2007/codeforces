#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int n, m, siz;
vector<int> adj[MAXN];
int dfn[MAXN], depth[MAXN], fa[MAXN], isCut[MAXN], timer;
vector<int> cut;

void dfs(int v = 0, int p = 0, int d = 0){
    depth[v] = d; fa[v] = p; dfn[v] = ++timer;
    for(auto u : adj[v]){
        if(!dfn[u]) dfs(u, v, d+1);
        else{
            if(depth[v]-depth[u]+1>=siz){
                cout << 2 << endl << depth[v]-depth[u]+1 << endl;
                while(v != u) cout << v+1 << " ", v = fa[v];
                cout << u+1 << endl;
                exit(0);
            }
        }
    }
    isCut[v] = 1;
    for(auto u : adj[v]) isCut[v] &= (isCut[u]^1);
    if(isCut[v]) cut.push_back(v);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    siz = ceil(sqrt(.0+n));
    dfs();
    sort(cut.begin(), cut.end());
    cut.erase(unique(cut.begin(), cut.end()), cut.end());
    cout << 1 << endl;
    for(int i = 0; i<siz; i++) cout << cut[i]+1 << " ";
    cout << endl;
}