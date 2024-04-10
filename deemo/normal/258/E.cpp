#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

const int MAXN = 2e5 + 10;

int n, q, s_t[MAXN], f_t[MAXN], tm, ans[MAXN];
vector<int>	adj[MAXN], que[MAXN];
int root[MAXN], le[40 * MAXN], ri[40 * MAXN], weed[40 * MAXN], sz;

void plant(int v = 0, int p = -1){
	s_t[v] = tm++;
	for (int u:adj[v])
		if (u != p)	plant(u, v);
	f_t[v] = tm;
}

int build(int b, int e){
	int id = sz++;
	weed[id] = e - b;
	if (e - b == 1)	return	id;
	
	int mid = (b + e)/ 2;
	le[id] = build(b, mid);
	ri[id] = build(mid, e);
	return	id;
}

int water(int id, int b, int e, int l, int r){
	if (weed[id] == 0)	return id;
	if (r <= b || e <= l)	return	id;

	int nid = sz++;
	assert(sz <= 40 * MAXN);
	le[nid] = le[id], ri[nid] = ri[id];

	if (l <= b && e <= r){
		weed[nid] = 0;
		return	nid;
	}
	
	int mid = (b + e)/ 2;
	le[nid] = water(le[nid], b, mid, l, r);
	ri[nid] = water(ri[nid], mid, e, l, r);
	weed[nid] = weed[le[nid]] + weed[ri[nid]];
	return	nid;
}	

void dfs(int v, int p = -1, int last_id = 0){
	root[v + 1] = last_id;
	if (que[v].size()){
		root[v + 1] = water(root[v + 1], 0, n, s_t[v], f_t[v]);
		for (int u:que[v])
			root[v + 1] = water(root[v + 1], 0, n, s_t[u], f_t[u]);
	}
	ans[v] = n - weed[root[v + 1]];

	for (int u:adj[v])
		if (u != p)	dfs(u, v, root[v + 1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i = 0; i < q; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		que[a].push_back(b);
		que[b].push_back(a);
	}

	plant();
	root[0] = build(0, n);
	dfs(0);
	for (int i = 0; i < n; i++)
		cout << max(0, ans[i] - 1) << " ";
	cout << "\n";
	return	0;
}