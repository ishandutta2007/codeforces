#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 1.5e5 + 10;
const int kT = 100;
const int kMod = 998244353;

int n, q;
vector<int> g[kN];
int que[kN];

void add(int &a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
	if(a < 0) a += kMod;
}
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		n >>= 1, a = 1LL * a * a % kMod;
	}
	return res;
}
int Inv(int a) {return pw(a, kMod - 2);}

int bit[kN];
void update(int x, int d) {
	for(int i = x; i <= n; i += i & -i) add(bit[i], d);
}
int query(int x) {
	int res = 0;
	for(int i = x; i; i -= i & -i) add(res, bit[i]);
	return res;
}

int in[kN], out[kN], dfs_clock;
int sz[kN], mxson[kN], p[kN];
int top[kN];
void dfs1(int u, int fa = 0) {
	sz[u] = 1, p[u] = fa;
	for(int v : g[u]) if(v != fa) {
		dfs1(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[mxson[u]]) mxson[u] = v;
	}
}
void dfs2(int u, int fa = 0, int tp = 1) {
	in[u] = ++dfs_clock;
	top[u] = tp;
	if(mxson[u]) dfs2(mxson[u], u, tp);
	for(int v : g[u]) 
		if(v != fa && v != mxson[u]) dfs2(v, u, v);
	out[u] = dfs_clock;
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs1(1); dfs2(1);
	//for(int i = 1; i <= n; i++) printf("mxson[%d] = %d\n", i, mxson[i]);
	//for(int i = 1; i <= n; i++) printf("top[%d] = %d\n", i, top[i]);
	int invn = Inv(n);
	while(q--) {
		int op, u;
		scanf("%d%d", &op, &u);
		if(op == 1) {
			int d; scanf("%d", &d);
			update(in[u], d), update(in[u] + 1, kMod - d);
			int x = 1LL * sz[u] * Inv(n) % kMod * d % kMod;	
			update(1, x), update(n + 1, kMod - x);
			update(in[u], kMod - x), update(out[u] + 1, x);

			int v = mxson[u];
			if(v) {
				int x = 1LL * (n - sz[v]) * invn % kMod * d % kMod;
				update(in[v], x), update(out[v] + 1, kMod - x);
			}
			add(que[u], d);
		}
		else {
			int ans = query(in[u]);
			int cur = top[u];
			while(p[cur]) {
				add(ans, 1LL * (n - sz[cur]) * invn % kMod * que[p[cur]] % kMod);	
				cur = top[p[cur]];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}