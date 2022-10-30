#include <bits/stdc++.h>
using namespace std;

int sol(vector<vector<int>> adj, vector<int> col, int c){
    int cnt =  1;
    vector<int> curcol[3];
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> siz(n);
    for(int i = 0; i<n; i++){
        siz[i] = adj[i].size();
        if(adj[i].size() == 1){
            curcol[col[i]].push_back(i);
            visited[i] = 1;
        }
    }
    while((!curcol[0].empty())||(!curcol[1].empty())||(!curcol[2].empty())){
        if(curcol[0].empty() && curcol[c].empty()){
            cnt++; c = 3-c;
            continue;
        }
        int v;
        if(!curcol[0].empty()){
            v = curcol[0].back();
            curcol[0].pop_back();
        }
        else{
            v = curcol[c].back();
            curcol[c].pop_back();
        }
        for(auto u : adj[v]){
            if(visited[u]) continue;
            siz[u]--;
            if(siz[u] < 2){
                curcol[col[u]].push_back(u);
                visited[u] = 1;
            }
        }
        siz[v] = 0;
    }
    return cnt;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> col(n);
    for(int i = 0; i<n; i++) cin >> col[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << min(sol(adj, col, 1), sol(adj, col, 2)) << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}