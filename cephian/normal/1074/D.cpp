#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5+5;

vector<int> val;
vector<int> uf;
vector<int> sz;

int id(int u) {
	if(uf[u] == u) return u;
	return uf[u] = id(uf[u]);
}

vector<vector<int>> adj;

void merge(int u, int v) {
	u = id(u), v = id(v);
	if(u == v) return;
	sz[v] += sz[u];
	uf[u] = v;
}

void update(int u, int p, int x) {
	val[u] ^= x;
	for(int v : adj[u]) {
		if(v == p) continue;
		update(v, u, x);
	}
}

int ctr = 0;
unordered_map<int,int> comp;

int replace(int i) {
	if(comp.count(i)) {
		return comp[i];
	}
	adj.push_back(vector<int>());
	val.push_back(0);
	uf.push_back(ctr);
	sz.push_back(1);
	comp[i] = ctr;
	return ctr++;
}

void add(int u, int v, int x) {
	u = replace(u), v = replace(v);
	if(id(u) == id(v)) return;
	if(sz[id(u)] > sz[id(v)]) swap(u, v);
	update(u, -1, x ^ val[u] ^ val[v]);
	adj[u].push_back(v);
	adj[v].push_back(u);
	merge(u, v);
}

int query(int l, int r) {
	l = replace(l), r = replace(r);
	if(id(l) == id(r)) return val[l] ^ val[r];
	return -1;
}

int main() {
	int q;
	scanf("%d",&q);
	int last = 0;
	for(int i = 0; i < q; ++i) {
		int t;
		scanf("%d", &t);
		int lp, rp, xp;
		if(t == 1) {
			scanf("%d%d%d", &lp, &rp, &xp);
			int l = lp ^ last;
			int r = rp ^ last;
			if(l > r) swap(l, r);

			int x = xp ^ last;

			add(l, r+1, x);
		} else {
			scanf("%d%d", &lp, &rp);
			int l = lp ^ last;
			int r = rp ^ last;
			if(l > r) swap(l, r);
			last = query(l, r+1);
			printf("%d\n",last);
			if(last == -1) last = 1;
		}
	}

}