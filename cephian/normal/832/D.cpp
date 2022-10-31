#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

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
		assert(u < N && v < N);
		u = idx[u], v = idx[v];
		if(v < u) swap(u,v);
		int g = lg(v-u+1);
		u = table[g][u], v = table[g][v+1-(1<<g)];
		return (depth[u] < depth[v])?u:v;
	}

	//unweighted distance between u and v
	inline int dist(int u, int v) {
		return depth[u]+depth[v]-2*depth[query(u,v)];
	}
};

vvi T;
lca L;

int lca_root(int u, int v, int r) {
	int l = L.query(u,v);
	if(L.depth[l] > L.depth[L.query(l,r)]) return l;
	int ru = L.query(r,u);
	int rv = L.query(r,v);
	if(L.depth[ru] > L.depth[rv]) return ru;
	return rv;
}

int fixed(int a, int b, int c) {
	int l = lca_root(a,b,c);
	return L.dist(l,c)+1;
}

int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	T = vvi(n);
	for(int i = 1; i < n; ++i) {
		int p;
		scanf("%d",&p),--p;
		T[i].pb(p), T[p].pb(i);
	}
	L = lca(T);
	while(q--) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c),--a,--b,--c;
		printf("%d\n",max(fixed(a,b,c),max(fixed(a,c,b),fixed(c,b,a))));
	}
}