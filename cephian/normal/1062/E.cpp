#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

struct lca {
	void init(int n) { T.resize(N = n); }
	lca(){}
	lca(int n){init(n);}
	int N,ctr=0;
	vector<int> idx,depth;
	vector<vector<int>> table,T;
	static inline int lg(int a) {return 31-__builtin_clz(a);}
	void dfs(int u, int v, int d) {
		idx[v] = ctr;
		depth[v] = d, table[0][ctr++] = v;
		for(int i = 0; i < (int)T[v].size(); ++i)
			if(T[v][i] != u)
				dfs(v,T[v][i],d+1), table[0][ctr++] = v;
	}

	void add_edge(int u, int v) {
		T[u].push_back(v);
		T[v].push_back(u);
	}

	//call build after edges are added
	void build(int root = 0) {
		idx.resize(N), depth.resize(N), table.assign(lg(2*N-1)+1,vector<int>(2*N-1));
		dfs(-1,root,0);
		for(int k = 0; k+1 < (int)table.size(); ++k) {
			for(int i = 0; i < (int)table[k].size(); ++i) {
				int j = min(i+(1<<k),(int)table[k].size()-1);
				table[k+1][i] = (depth[table[k][i]] < depth[table[k][j]])?table[k][i]:table[k][j];
			}
		}
	}

	//lca(u,v)
	inline int query(int u, int v) const {
		u = idx[u], v = idx[v];
		if(v < u) swap(u,v);
		int g = lg(v-u+1);
		u = table[g][u], v = table[g][v+1-(1<<g)];
		return (depth[u] < depth[v])?u:v;
	}

	//unweighted distance between u and v
	inline int dist(int u, int v) {
		return depth[u] + depth[v] - 2*depth[query(u,v)];
	}
};

// O(n log n) space, O(1) index query RMQ
struct rmq_ind {
	vector<vector<int> > t;
	int *A;
	rmq_ind(){}
	rmq_ind(int* a, int n):t(32-__builtin_clz(n),vector<int>(n)) {
		A = a;
		for(int i = 0; i < n; ++i)
			t[0][i] = i;
		for(int k = 1, p = 1; k < (int)t.size(); ++k, p<<=1)
			for(int i = 0; i < n; ++i)
				t[k][i] = (i+p<n && a[t[k-1][i+p]] < a[t[k-1][i]])?t[k-1][i+p]:t[k-1][i];
	}
	//inclusive min query
	inline int query(int l, int r) const {
		int p = 31-__builtin_clz(r-l+1), i = t[p][l], j = t[p][r+1-(1<<p)];
		return (A[i]<A[j])?i:j;
	}
};


// O(n log n) space, O(1) index query RMQ
struct rMq_ind {
	vector<vector<int> > t;
	int *A;
	rMq_ind(){}
	rMq_ind(int* a, int n):t(32-__builtin_clz(n),vector<int>(n)) {
		A = a;
		for(int i = 0; i < n; ++i)
			t[0][i] = i;
		for(int k = 1, p = 1; k < (int)t.size(); ++k, p<<=1)
			for(int i = 0; i < n; ++i)
				t[k][i] = (i+p<n && a[t[k-1][i+p]] > a[t[k-1][i]])?t[k-1][i+p]:t[k-1][i];
	}
	//inclusive max query
	inline int query(int l, int r) const {
		int p = 31-__builtin_clz(r-l+1), i = t[p][l], j = t[p][r+1-(1<<p)];
		return (A[i]>A[j])?i:j;
	}
};

const int N = 1e5+5;

int t[4*N];
int l[4*N], r[4*N];
int depth[N];
vector<int> T[N];
int label[N];
lca L;
rMq_ind mx;
rmq_ind mn;

int combine(int u, int v) {
	if(u == 0) return v;
	if(v == 0) return u;
	return L.query(u-1, v-1) + 1;
}

void build(int v, int i, int j) {
	l[v] = i, r[v] = j;
	if(i == j) {
		t[v] = i;
	} else {
		build(v*2, i, (i+j)/2);
		build(v*2+1, (i+j)/2+1, j);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

int query(int v, int i, int j) {
	if(j < i || l[v] > j || r[v] < i) return 0;
	if(i <= l[v] && r[v] <= j) return t[v];
	return combine(query(v*2, i, j), query(v*2+1, i, j));
}

int ctr = 0;
void dfs(int v, int d = 0) {
	depth[v] = d;
	label[v] = ctr++;
	for(int u : T[v])
		dfs(u, d+1);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, q;
	cin >> n >> q;
	L.init(n);
	for(int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		L.add_edge(p-1, i-1);
		T[p].push_back(i);
	}
	dfs(1);
	L.build(0);
	build(1,1,n);

	mx = rMq_ind(label, n+1);
	mn = rmq_ind(label, n+1);

	for(int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		int fst_node = mn.query(l, r);
		int lst_node = mx.query(l, r);

		int rem_fst = combine(query(1, l, fst_node-1), query(1, fst_node+1, r));
		int rem_lst = combine(query(1, l, lst_node-1), query(1, lst_node+1, r));

		if(depth[rem_fst] > depth[rem_lst]) cout << fst_node << " " << depth[rem_fst] << "\n";
		else cout << lst_node << " " << depth[rem_lst] << "\n";
	}
}