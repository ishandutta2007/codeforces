// https://codeforces.com/contest/498/problem/c
#include <bits/stdc++.h>
using namespace std;
#define MAXN 3300

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

vector<int> factor(int num){
    if(num == 1) return {};
    int temp = num;
    for(int i = 2; i<=sqrt(num); i++){
        if(num%i == 0){
            temp = i;
            break;
        }
    }
    vector<int> ans = factor(num/temp);
    ans.push_back(temp);
    return ans;
}

Dinic<MAXN> flow;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> stuff;
    map<pair<int, int>, int> idx;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        stuff.push_back(factor(a));
    }

    int cur = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<stuff[i].size(); j++){
            idx[{i, j}] = cur++;
        }
    }

    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        if(a % 2 == 1) swap(a, b);
        for(int g = 0; g<stuff[a].size(); g++){
            for(int h = 0; h<stuff[b].size(); h++){
                if(stuff[a][g] != stuff[b][h]) continue;
                flow.ae(idx[{a, g}], idx[{b, h}], 1);
            }
        }
    }
    for(int i = 0; i<n; i+=2){
        for(int j = 0; j<stuff[i].size(); j++) flow.ae(0, idx[{i, j}], 1);
    }

    for(int i = 1; i<n; i+=2){
        for(int j = 0; j<stuff[i].size(); j++) flow.ae(idx[{i, j}], cur, 1);
    }

    cout << flow.maxFlow(cur+1, 0, cur) << endl; 
    
}