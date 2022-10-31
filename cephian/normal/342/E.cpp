#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;

struct lca {
	int N;
	vector<int> idx,depth;
	vector<vector<int> > table;
	void dfs(const vvi &T, int u, int v, int d, int &ctr) {
		idx[v] = ctr;
		depth[v] = d, table[0][ctr++] = v;
		for(int i = 0; i < T[v].size(); ++i)
			if(T[v][i] != u)
				dfs(T,v,T[v][i],d+1,ctr), table[0][ctr++] = v;
	}

	static inline int lg(int a) {return 31-__builtin_clz(a);}

	lca(){}
	lca(const vvi &T, int root = 0):N(T.size()),idx(N),depth(N),table(lg(2*N-1)+1,vector<int>(2*N-1)) {
		int ctr = 0;
		dfs(T,-1,root,0,ctr);
		for(int k = 0; k+1 < table.size(); ++k) {
			for(int i = 0; i < table[k].size(); ++i) {
				int j = min(i+(1<<(k)),(int)table[k].size()-1);
				table[k+1][i] = (depth[table[k][i]] < depth[table[k][j]])?table[k][i]:table[k][j];
			}
		}
	}

	inline int query(int u, int v) const {
		u = idx[u], v = idx[v];
		if(v < u) swap(u,v);
		int g = lg(v-u+1);
		u = table[g][u], v = table[g][v+1-(1<<g)];
		return (depth[u] < depth[v])?u:v;
	}

	inline int dist(int u, int v) {
		return depth[u]+depth[v]-2*depth[query(u,v)];
	}
};

vvi T;

int cdt_sz[N]={};
int cdt_parent[N];
vi cdt_children[N];

int cdt_fsz(int u, int v) {
	if(cdt_sz[v] == -1) return 0;
	cdt_sz[v] = 1;
	for(int w : T[v])
		if(w != u)
			cdt_sz[v] += cdt_fsz(v,w);
	return cdt_sz[v];
}
int cdt_build(int v, int n, bool rc = 1) {
	if(rc) cdt_fsz(-1,v);
	int p = -1;
	while(1) {
		int x = -1;
		for(int w : T[v])
			if(x == -1 || cdt_sz[w] > cdt_sz[x])
				x = w;
		if(cdt_sz[x] * 2 <= n) break;
		cdt_sz[v] = n-cdt_sz[x];
		p = v, v = x;
	}
	cdt_sz[v] = cdt_parent[v] = -1;
	for(int w : T[v]) {
		if(cdt_sz[w] == -1) continue;
		int x = cdt_build(w,cdt_sz[w],w == p);
		//found cdt edge (v -> x)
		cdt_children[v].push_back(x);
		cdt_parent[x] = v;
	}
	return v;
}

int shortest[N];
lca L;


void paint(int v) {
	int u = v;
	while(v != -1) {
		shortest[v] = min(shortest[v],L.dist(u,v));
		v = cdt_parent[v];
	}
}

int query(int v) {
	int u = v, a = 1<<28;
	while(v != -1) {
		a = min(a,L.dist(u,v)+shortest[v]);
		v = cdt_parent[v];
	}
	return a;
}

int main() {
	int n,q;
	sc("%d%d",&n,&q);
	T = vvi(n);
	for(int i = 1; i < n; ++i) {
		int u,v;
		sc("%d%d",&u,&v),--u,--v;
		T[u].pb(v),T[v].pb(u);
	}
	L = lca(T);
	cdt_build(0,n);
	fill(shortest,shortest+n,1<<28);
	paint(0);
	while(q--) {
		int t,v;
		sc("%d%d",&t,&v),--v;
		if(t == 1)
			paint(v);
		else
			pr("%d\n",query(v));
	}
}