// yay! https://www.codechef.com/viewsolution/10766398

#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
 
typedef unsigned Val;
vector<vector<pair<int, Val> > > g;
vector<Val> cyclebasis;
bool vis[100000];
Val treeval[100000];
 
void dfs(int i, Val x) {
	vis[i] = true;
	treeval[i] = x;
	for(auto e : g[i]) {
		int j = e.first;
		if(!vis[j]) {
			dfs(j, x ^ e.second);
		} else {
			Val p = treeval[i] ^ treeval[j] ^ e.second;
			if(p != 0) cyclebasis.push_back(p);
		}
	}
}
 
vector<Val> gaussianEliminationMod2(vector<Val> v, int B) {
	int n = v.size();
	vector<Val> t(B, 0);
	int used = 0;
	for(int j = B - 1; j >= 0; j --) {
		int i = used;
		while(i < n && (~v[i] >> j & 1)) i ++;
		if(i < n) {
			Val x = v[i];
			swap(v[i], v[used ++]);
			t[j] = x;
			for(i = used; i < n; i ++)
				if(v[i] >> j & 1)
					v[i] ^= x;
		}
	}
	return t;
}
 
struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
 
int main() {
 
	const int B = 30;
	int N, M, Q = 1;
	scanf("%d%d", &N, &M);
	g.assign(N, vector<pair<int, Val> >());
	UnionFind uf; uf.init(N);
	rep(i, M) {
		int f, t; Val p;
		scanf("%d%d%u", &f, &t, &p), -- f, -- t;
		g[f].emplace_back(t, p);
		g[t].emplace_back(f, p);
		uf.unionSet(f, t);
	}
	struct Query {
		int a, b;
		int i;
	};
	vector<vector<Query>> queries(N);
	rep(ii, Q) {
		int a, b; a = 1, b = N;
		//scanf("%d%d", &a, &b), 
		-- a, -- b;
		if(uf.findSet(a, b))
			queries[uf.root(a)].push_back(Query{a, b, ii});
	}
	memset(vis, 0, sizeof(vis));
	vector<int> ans(Q, -1);
	rep(i, N) if(uf.root(i) == i) {
		cyclebasis.clear();
		dfs(i, 0);
		vector<Val> basis = gaussianEliminationMod2(cyclebasis, B);
		for(auto q : queries[i]) {
			Val p = treeval[q.a] ^ treeval[q.b];
			for(int j = B - 1; j >= 0; j --) {
				if(p >> j & 1)
					p ^= basis[j];
			}
			ans[q.i] = p;
		}
	}
	rep(i, Q) {
		if(ans[i] == -1)
			puts("XIT");
		else
			printf("%d\n", ans[i]);
	}
	return 0;
}