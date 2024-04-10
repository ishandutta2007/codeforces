#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, m, par[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];
int sz;
pii seg[MAXN];
int tmn[MAXN];
ll fen[3][MAXN];
vector<int> vec[MAXN];

int q, tl[MAXN], tr[MAXN], sec[MAXN];
ll ans[MAXN];

bool cmp(int u, int v){return tr[u] < tr[v];}

void add(int x, int val, int t){for (x++; x<MAXN; x += x&-x) fen[t][x] += val;}
ll get(int v, int t){
	ll ret = 0;
	for (; v; v-=v&-v)
		ret += fen[t][v];
	return ret;
}

ll get(int l, int r, int t){
	return get(r, t) - get(l, t);
}

int depth[MAXN];

void addCycle(int v, int p){
	int mn = p, mx = p;
	while (v != p){
		mn = min(mn, v);
		mx = max(mx, v);
		v = par[v];
	}
	seg[sz++] = {mn, mx};
	tmn[mn] = min(tmn[mn], mx);
}

void dfs(int v, int p = -1, int de = 0){
	depth[v] = de;
	par[v] = p;
	vis[v] = 1;
	for (int u:adj[v])
		if (u != p){
			if (!vis[u])
				dfs(u, v, de + 1);
			else if (depth[u] < depth[v])
				addCycle(v, u);
		}
}

int main(){
	scanf("%d %d", &n, &m);
	while (m--){
		int a, b; scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(tmn, 63, sizeof(tmn));
	for (int v = 0; v < n; v++)
		if (!vis[v])
			dfs(v);
	for (int i = n-1; ~i; i--)
		if (i+1 < n){
			tmn[i] = min(tmn[i], tmn[i+1]);
			if (tmn[i] < 1e6)
				vec[tmn[i]].push_back(i);
		}

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
		scanf("%d %d", &tl[i], &tr[i]), tl[i]--;
	iota(sec, sec + q, 0);
	sort(sec, sec + q, cmp);

	for (int i = 0; i < n; i++) add(i, 1, 2), add(i, n-i, 1);
	int cur = 0;
	for (int r = 1; r <= n; r++){
		for (int l: vec[r]){
			add(l, -1, 2);
			add(l, -(n-l), 1);
			add(l, tmn[l] - l, 0);
		}

		while (cur < q && tr[sec[cur]] == r){
			int id = sec[cur++];
			ans[id] = get(tl[id], tr[id], 0);
			ans[id] += get(tl[id], tr[id], 1) - get(tl[id], tr[id], 2)*(n-r);
		}
	}

	for (int i = 0; i < q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}