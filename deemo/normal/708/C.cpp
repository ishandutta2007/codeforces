#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define tm lasdjf

const int MAXN = 4e5 + 10;
const int LOG = 40;

int n, sz[MAXN], ans[MAXN];
vector<int>	adj[MAXN];
int weed[4 * MAXN];
int f_t[MAXN], s_t[MAXN], tm, mp[MAXN];
multiset<int>	st;

void build(int v, int p = -1){
	mp[tm] = v;
	s_t[v] = tm++;
	sz[v] = 1;
	for (int u:adj[v])
		if (u^p)
			build(u, v), sz[v] += sz[u];
	f_t[v] = tm;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		if (sz[mp[b]] <= n/2)
			weed[v] = sz[mp[b]];
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

void water(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		weed[v] = val;
		if (weed[v] > n/2)
			weed[v] = 0;
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		water(v<<1, b, mid, pos, val);
	else
		water(v<<1^1, mid, e, pos, val);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return 0;

	int mid = b + e >> 1;
	return max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

void dfs(int v, int p = -1){
	pair<int, int>	mx(-1, -1);
	water(1, 0, n, s_t[v], 0);
	st.insert(sz[v]);
	for (int u:adj[v])
		if (u^p){
			mx = max(mx, {sz[u], u});
			dfs(u, v);
		}
	water(1, 0, n, s_t[v], sz[v]);
	st.erase(st.find(sz[v]));

	if (n - sz[v] <= n/2 && mx.F <= n/2)	ans[v] = 1;
	else{
		bool fl = 0;
		if (mx.F > n/2)
			fl |= mx.F - smoke(1, 0, n, s_t[mx.S], f_t[mx.S]) <= n/2;
		else{
			int z = max(smoke(1, 0, n, 0, s_t[v]), smoke(1, 0, n, f_t[v], n));
			fl |= (n - sz[v]) - z <= n/2;
			auto it = st.upper_bound(sz[v] + n/2);
			if (it != st.begin()){
				it--;
				z = *it - sz[v];
			}
			fl |= (n - sz[v]) - z <= n/2;
		}
		ans[v] = fl;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(0);
	plant(1, 0, n);
	dfs(0);

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}