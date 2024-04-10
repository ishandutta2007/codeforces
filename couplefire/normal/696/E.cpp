#include<bits/stdc++.h>

using namespace std;

using INT = long long;

#define NN 100010

int min_id[NN], max_id[NN], sz[NN];
int hv[NN], deep[NN], pa[NN], top[NN];
int nn = 0;
vector<int> adj[NN];
int n;

int dfs1(int u, int fa = 0) {
	deep[u] = deep[fa] + 1;
	pa[u] = fa; sz[u] = 1;
	hv[u] = 0;
	for(auto v : adj[u]) if(v != fa) {
		dfs1(v, u);
		sz[u] += sz[v];
		if(hv[u] == 0 || sz[hv[u]] < sz[v]) {
			hv[u] = v;
		}
	}
}

int dfs2(int u, int tp, int fa = 0) {
	min_id[u] = ++nn; top[u] = tp;
	if(hv[u]) dfs2(hv[u], tp, u);
	for(auto v : adj[u]) if(v != fa and v != hv[u]) {
		dfs2(v, v, u);
	}
	max_id[u] = nn;
}

#define inf 0x3f3f3f3f3f3f3f3f
#define ls (u<<1)
#define rs (ls | 1)
#define mid (L + R >> 1)
#define x first
#define y second

using pii = pair<INT, int>;
int c[NN];
vector<int> res[NN];
pii mn[NN*40];
INT val[NN*40], flag[NN*40];

inline int push_up(int u) {
	mn[u] = min(mn[ls], mn[rs]);
}

int build(int u, int L, int R) {
	if(L + 1 == R) {
		mn[u] = pii(inf, 0);
		if(res[L].size()) {
			mn[u] = pii(res[L].back(), res[L].back());
		}
		return 0;
	}
	build(ls, L, mid);
	build(rs, mid, R);
	push_up(u);
}

inline int push_down(int u) {
	if(flag[u] == 0) return 0;
	flag[ls] += flag[u]; flag[rs] += flag[u];
	val[ls] += flag[u]; val[rs] += flag[u];
	if(mn[ls].x != inf) mn[ls].x += flag[u];
	if(mn[rs].x != inf) mn[rs].x += flag[u];
	flag[u] = 0;
}

pii calc(int u, int L, int R, int st, int ed) {
	if(L >= ed || R <= st) return pii(inf, 0);
	if(L >= st and R <= ed) {
		return mn[u];
	}
	push_down(u);
	return min(calc(ls, L, mid, st, ed), calc(rs, mid, R, st, ed));
}

int change(int u, int L, int R, int st, int ed, pii buf) {
	if(L >= ed || R <= st) return 0;
	
	if(L + 1 == R) {
		if(mn[u] != buf) return 0;
		mn[u] = pii(inf, 0);
		if(res[L].size()) res[L].pop_back();
		if(res[L].size()) {
			mn[u] = pii(val[u] + res[L].back(), res[L].back());
			return 0;
		}
	}
	push_down(u);	
	if(calc(ls, L, mid, st, ed) == buf) {
		change(ls, L, mid, st, ed, buf);
		push_up(u);
	}
	else if(calc(rs, mid, R, st, ed) == buf) {
		change(rs, mid, R, st, ed, buf);
		push_up(u);
	}	
}

int update(int u, int L, int R, int st, int ed, int s) {
	if(L >= ed || R <= st) return 0;
	
	if(L >= st and R <= ed) {
		flag[u] += s; val[u] += s;
		if(mn[u].x != inf) mn[u].x += s;
		return 0;
	}
	
	push_down(u);
	update(ls, L, mid, st, ed, s);
	update(rs, mid, R, st, ed, s);
	push_up(u);
}

pii calc_min(int u, int v) {
	pii mn = pii(inf, 0);
	
	int L = u, R = v;
	
	while(top[u] != top[v]) {
		if(deep[top[u]] < deep[top[v]]) swap(u, v);
		pii mm = calc(1, 1, n + 1, min_id[top[u]], min_id[u] + 1);
		if(mn > mm) {
			mn = mm;
			L = min_id[top[u]]; R = min_id[u] + 1;
		}
		u = pa[top[u]];
	}
	
	if(deep[u] < deep[v]) swap(u, v);
	pii mm = calc(1, 1, n + 1, min_id[v], min_id[u] + 1);
	if(mn > mm) {
		L = min_id[v], R = min_id[u] + 1;
		mn = mm;
	}
	if(mn.first != inf) {
		change(1, 1, n + 1, L, R, mn);
	}
	return mn;
}

int main(){
	int m, q;
	cin >> n >> m >> q;
	
	for(int i=1; i<n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs1(1); dfs2(1, 1, 0);
	for(int i=1; i<=m; i++) {
		scanf("%d", c+i);
		res[min_id[c[i]]].push_back(i);
	}
	
	for(int i=1; i<=n; i++) {
		sort(res[i].begin(), res[i].end(), [&] (int u, int v) {
			return u > v;
		});
	}
	
	build(1, 1, n + 1);
	
	while(q--) {
		int st;
		scanf("%d", &st);
		if(st == 1) {
			int u, v, k;
			scanf("%d %d %d", &u, &v, &k);
			vector<int> ans;
			
			while(k--) {
				pii mn = calc_min(u, v);
				if(mn.first == inf) break;
				ans.push_back(mn.y);
			}
			printf("%d ", ans.size());
			for(int v : ans) printf("%d ", v);
			puts("");
		} else {
			int v, k;
			scanf("%d %d", &v, &k);
			update(1, 1, n + 1, min_id[v], max_id[v] + 1, k);
		}
	}
	
	return 0;
}