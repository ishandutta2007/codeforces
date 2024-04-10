#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

struct edge {
	int u, v;
	ll cap, flow;
	edge() {}
	edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct dinic {
	int V;
	vector<edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;

	dinic(int V): V(V), E(0), g(V), d(V), pt(V) {}

	void add_edge(int u, int v, ll cap) {
		if (u == v) return;
		g[u].emplace_back(E.size());
		E.emplace_back(edge(u, v, cap));
		g[v].emplace_back(E.size());
		E.emplace_back(edge(v, u, 0));
	}

	bool bfs(int S, int T) {
		fill(d.begin(),d.end(),V+1);
		int qf=0,qb=1;
		d[S] = 0;
		pt[0] = S;
		while(qf!=qb) {
			int u = pt[qf++];
			if(u == T) break;
			for(int k: g[u]) {
				edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					pt[qb++] = e.v;
				}
			}
		}
		return d[T] != V + 1;
	}

	ll dfs(int u, int T, ll flow = -1) {
		if(u == T || !flow) return flow;
		for(int &i = pt[u]; i < g[u].size(); ++i) {
			edge &e = E[g[u][i]];
			edge &oe = E[g[u][i]^1];
			if(d[e.v] == d[e.u] + 1) {
				ll amt = e.cap - e.flow;
				if(flow != -1 && amt > flow) amt = flow;
				if(ll pushed = dfs(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	ll flow(int S, int T) {
		ll tot = 0;
		while(bfs(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while(ll flow = dfs(S, T))
				tot += flow;
		}
		return tot;
	}
};

vi A,B,C,D;

const int N = 1e5;
bool ip[N];

vvi G;
bool seen[300]={};
vvi ans;

void dfs(int u, vi& V) {
	seen[u] = true;
	if(u <= A.size()) V.push_back(C[u-1]);
	else V.push_back(D[u-1-A.size()]);
	for(int v : G[u]) {
		if(seen[v]) continue;
		dfs(v,V);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(ip,ip+N,1);
	for(int i = 2; i < N; ++i) {
		if(ip[i]) {
			for(ll j = 1LL*i*i; j < N; j+=i)
				ip[j] = false;
		}
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(a&1) {
			B.pb(a);
			D.pb(i+1);
		}
		else {
			A.pb(a);
			C.pb(i+1);
		}
	}
	dinic D(2 + A.size() + B.size());
	for(int i = 1; i <= A.size(); ++i) {
		D.add_edge(0,i,2);
	}
	for(int i = 1; i <= B.size(); ++i) {
		D.add_edge(A.size()+i,A.size()+B.size()+1,2);
	}
	for(int i = 0; i < A.size(); ++i) {
		for(int j = 0; j < B.size(); ++j) {
			if(ip[A[i]+B[j]])
				D.add_edge(1+i,A.size()+1+j,1);
		}
	}
	ll f = D.flow(0,A.size()+B.size()+1);
	if(A.size() != B.size() || f != A.size()*2) {
		cout << "Impossible\n";
		return 0;
	}
	G = vvi(D.V);
	for(edge &e: D.E) {
		if(e.flow == 1) {
			G[e.v].pb(e.u);
			G[e.u].pb(e.v);
		}
	}
	for(int i = 1; i <= A.size() + B.size(); ++i) {
		if(seen[i]) continue;
		vi tmp;
		dfs(i,tmp);
		ans.pb(tmp);
	}
	cout << ans.size() << "\n";
	for(vi &v : ans) {
		cout << v.size() << "";
		for(int a : v)
			cout << " " << a;
		cout << "\n";
	}
	return 0;
}