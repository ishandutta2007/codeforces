// https://codeforces.com/problemset/problem/510/E
#include <bits/extc++.h>
using namespace std;
#define MAXN 205

template<int SZ> struct Dinic {
	int N,s,t; // # verts, source, sink
	typedef long long F; // flow type
	struct Edge { int to, rev; F flo, cap; };
	vector<Edge> adj[SZ]; // use asserts, don't be dumb
	void reset() { for(int i = 0; i<N; i++) for(auto e : adj[i]) e.flo = 0; }
	void ae(int u, int v, F cap, F rcap = 0) { 
		assert(min(cap,rcap) >= 0); 
		Edge a{v,(int)adj[v].size(),0ll,cap}, b{u,(int)adj[u].size(),0ll,rcap};
		adj[u].push_back(a), adj[v].push_back(b); } 
	int lev[SZ]; typename vector<Edge>::iterator cur[SZ]; 
	bool bfs() { // level = shortest distance from source
		for(int i = 0; i<N; i++) lev[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); lev[s] = 0; 
		while (q.size()) {
			int u = q.front(); q.pop();
			for(auto e : adj[u]) if (lev[e.to] < 0 && e.flo < e.cap) 
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
		return lev[t] >= 0;
	}
	F dfs(int v, F flo) {
		if (v == t) return flo;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (lev[e.to]!=lev[v]+1||e.flo==e.cap) continue;
			F df = dfs(e.to,min(flo,e.cap-e.flo));
			if (df) { e.flo += df; adj[e.to][e.rev].flo -= df;
				return df; } // saturated >=1 one edge
		}
		return 0;
	}
	F maxFlow(int _N, int _s, int _t) {
		N = _N, s = _s, t = _t; assert(s != t);
		F tot = 0; while (bfs()) while (F df = 
			dfs(s,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

Dinic<MAXN> flow;
vector<bool> isPrime(20005, true);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i<=20004; i++){
        if(isPrime[i] && i*i<=20004){
            for(int j = i*i; j<=20004; j+=i){
                isPrime[j] = false;
            }
        }
    }
    // cout << isPrime[21] << endl;
    for(int i = 0; i<n; i++){
        if(arr[i]%2 == 1) continue;
        for(int j = 0; j<n; j++){
            if(arr[j] %2 == 0) continue;
            if(isPrime[arr[i]+arr[j]]){
                flow.ae(i, j, 1);
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(arr[i]%2==0) flow.ae(n, i, 2);
        else flow.ae(i, n+1, 2);
    }
    if(flow.maxFlow(n+2, n, n+1) != n){
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> to[n];
    bool visited[n];
    for(int i = 0; i<n; i++){
        if(arr[i]%2 == 1) continue;
        for(auto j : flow.adj[i]){
            if(j.flo <= 0) continue;
            to[i].push_back(j.to);
            to[j.to].push_back(i);
            // cout << i << " " << j.to << endl;
        }
    }
    // cout << to[8] << endl;
    vector<vector<int>> ans;
    fill(visited, visited+n, false);
    for(int i = 0; i<n; i++){
        if(visited[i]) continue;
        vector<int> temp;
        int j = i;
        while(!visited[j]){
            temp.push_back(j);
            visited[j] = 1;
            if(!visited[to[j][0]]) j = to[j][0];
            else j = to[j][1];
        }
        ans.push_back(temp);
    }
    cout << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i].size() << " ";
        for(auto j : ans[i]) cout << j+1 << " ";
        cout << endl;
    }
}