#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 5e5 + 10;
const int INF = 1e8;
const int C = 22;

int n, ans[MAXN], maxi[1<<C], xx, sz[MAXN], depth[MAXN];
vector<pair<int, int>>	adj[MAXN];

void init(int v, int de = 0){
	depth[v] = de;
	sz[v] = 1;
	for (auto e:adj[v])
		init(e.F, de + 1), sz[v] += sz[e.F];
}

void go(int v, int x, int p){
	ans[p] = max(ans[p], maxi[x^xx] + depth[v] - (depth[p]<<1));
	for (int i = 0; i < C; i++)
		ans[p] = max(ans[p], maxi[x^1<<i^xx] + depth[v] - (depth[p]<<1));
	for (auto e:adj[v])
		go(e.F, x^1<<e.S, p);
}

void add(int v, int x){
	maxi[x^xx] = max(maxi[x^xx], depth[v]);
	for (auto e:adj[v])
		add(e.F, x^1<<e.S);
}

void burn(int v, int x=0){
	maxi[x^xx] = -INF;
	for (auto e:adj[v])
		burn(e.F, x^1<<e.S);
}

void dfs(int v, bool tp = 0){
	pair<int, int>	mx(-1, -1);
	for (auto e:adj[v])
		mx = max(mx, {sz[e.F], e.F});
	int temp = 0;
	for (auto e:adj[v])
		if (e.F^mx.S){
			dfs(e.F);
			ans[v] = max(ans[v], ans[e.F]);
		}
		else temp = 1<<e.S;

	if (~mx.S)
		dfs(mx.S, 1), ans[v] = max(ans[v], ans[mx.S]), xx ^= temp;
	maxi[xx] = max(maxi[xx], depth[v]);
	for (auto e:adj[v])
		if (e.F^mx.S)
			go(e.F, 1<<e.S, v), add(e.F, 1<<e.S);
	for (int i = 0; i < C; i++)
		ans[v] = max(ans[v], maxi[1<<i^xx] - depth[v]);
	ans[v] = max(ans[v], maxi[xx] - depth[v]);
	if (!tp)
		burn(v), xx = 0;
}

int main(){
	fill(maxi, maxi + (1<<C), -INF);
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int p;	scanf("%d", &p), p--;
		char ch;	scanf(" %c", &ch);
		adj[p].push_back({i, ch-'a'});
	}
	init(0);
	dfs(0, 1);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}