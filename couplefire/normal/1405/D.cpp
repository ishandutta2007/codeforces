#include <bits/stdc++.h>
using namespace std;

struct TreeDiameter {
	int N, diaLen; 
    vector<int> par; vector<int> dist; 
	vector<vector<int>> adj; 
    vector<int> dia, center;
    vector<int> depth;
    void init(int n){
        N=n;
        par.resize(n);
        dist.resize(n);
        adj.resize(n);
        depth.resize(n);
    }
	void ae(int a, int b) { adj[a].push_back(b), adj[b].push_back(a); }
	void dfs(int x) {
		for(auto y:adj[x]) if (y != par[x]) {
			par[y] = x; dist[y] = dist[x]+1; 
			dfs(y); }
	}
	void genDist(int x) { par[x] = -1; dist[x] = 0; dfs(x); }
	void solve() {
		dia = {0,0}; 
		genDist(0); for(int i= 0; i<N; i++) if (dist[i]>dist[dia[0]]) dia[0] = i; 
		genDist(dia[0]); for(int i = 0; i<N; i++) if (dist[i]>dist[dia[1]]) dia[1] = i;
		diaLen = dist[dia[1]];
		int cen = dia[1]; for(int i = 0; i<diaLen/2; i++) cen = par[cen];
		center = {cen}; if (diaLen&1) center.push_back(par[cen]);
	}
    void findDepth(int v, int p, int d){
        depth[v] = d;
        for(auto u : adj[v]){
            if(u == p) continue;
            findDepth(u, v, d+1);
        }
    }
};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        --a; --b;
        TreeDiameter tree;
        tree.init(n);
        for(int i = 0; i<n-1; i++){
            int x, y; cin >> x >> y;
            --x; --y;
            tree.ae(x, y);
        }
        tree.solve();
        if((tree.diaLen+1)/2 <= da){
            cout << "Alice" << endl;
            continue;
        }
        tree.findDepth(a, -1, 0);
        if(tree.depth[b] <= da){
            cout << "Alice" << endl;
            continue;
        }
        if(db >= 2*da+1){
            cout << "Bob" << endl;
        }
        else{
            cout << "Alice" << endl;
        }
    }
}