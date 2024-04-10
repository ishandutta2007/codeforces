#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, depth[MAXN];
vector<pair<int, int>>	adj[MAXN];

void dfs(int v, int p = -1, int de = 0){
	depth[v] = de;
	for (auto e:adj[v])
		if (e.F ^ p)
			dfs(e.F, v, de + e.S);
}

int main(){
	scanf("%d", &n);
	long long sm = 0;
	for (int i = 0; i < n - 1; i++){
		int a, b, c;	scanf("%d %d %d", &a, &b, &c), a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
		sm += 2ll * c;
	}
	dfs(0);
	sm -= *max_element(depth, depth + n);
	printf("%lld\n", sm);
	return 0;
}