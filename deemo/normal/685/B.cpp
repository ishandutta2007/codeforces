#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 3e5 + 10;

int n, q, d[MAXN], id[MAXN];
vector<int>	adj[MAXN];
int sz[MAXN], tt, ans[MAXN];
multiset<pair<int, int>>	st[MAXN];

void go(int v, int p = -1){
	pair<int, int>	mx(-1, v);
	sz[v] = 1;
	for (int u:adj[v]){
		go(u, v);
		mx = max(mx, {st[id[u]].size(), u});
		sz[v] += sz[u];
	}
	if (mx.F == -1)
		id[v] = tt++;

	id[v] = id[mx.S];
	st[id[v]].insert({sz[v], v});
	for (int u:adj[v])
		if (u^mx.S){
			for (auto y:st[id[u]])
				st[id[v]].insert(y);
			st[id[u]].clear();
		}

	int mid = sz[v]/2 + (sz[v] & 1);
	ans[v] = st[id[v]].lower_bound({mid, -1})->second;
}

int main(){
	scanf("%d %d", &n, &q);
	for (ll i = 1; i < n; i++){
		int p;	scanf("%d", &p), p--;
		adj[p].push_back(i);
	}
	go(0);
	while (q--){
		int v;	scanf("%d", &v), v--;
		printf("%d\n", ans[v] + 1);
	}
	return 0;
}