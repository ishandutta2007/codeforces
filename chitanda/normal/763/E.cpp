#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int maxn = 100100;
int n, k, m, a, b;
int tag[maxn], vis[maxn], tim, c[maxn];
vector<int> g[maxn];

void add(int x){
	for(; x <= n; x += x & -x) ++c[x];
}

int ask(int x){
	int res = 0;
	for(; x; x -= x & -x) res += c[x];
	return res;
}

void dfs(int x){
	vis[x] = ++tim;
	for(auto v : g[x])
		if(!vis[v]) dfs(v);
}

int check(int t){
	if(tag[t]) return 0;
	for(auto v : g[t]){
		if(v < a || v > b) continue;
		if(vis[v] < vis[t]) return 0;
	}
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			dfs(i);
			tag[i] = 1;
			add(i);
		}

	int q; scanf("%d", &q);
	while(q--){
		scanf("%d%d", &a, &b);
		int res = ask(b) - ask(a - 1);
		for(int i = a; i <= min(b, a + 4); ++i) res += check(i);
		for(int i = max(a + 5, b - 4); i <= b; ++i) res += check(i);
		printf("%d\n", res);
	}
	return 0;
}