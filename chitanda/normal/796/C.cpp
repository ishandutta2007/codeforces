#include<bits/stdc++.h>
using namespace std;

const int maxn = 300100;
int n;
int a[maxn];
int d1[maxn][2], d2[maxn][2];
vector<int> g[maxn];
int ans;

void update(int a[], const int v){
	if(v > a[0]) a[1] = a[0], a[0] = v;
	else a[1] = max(a[1], v);
}

void dfs(int t, int fa){
	d1[t][0] = d1[t][1] = d2[t][0] = d2[t][1] = -2e9;
	for(auto v : g[t]){
		if(v == fa) continue;
		dfs(v, t);
		update(d1[t], a[v]);
		update(d2[t], max(d1[v][0], d2[v][0]));
	}
}

void dfs2(int t, int fa){
	ans = min(ans, max(a[t], max(d1[t][0] + 1, d2[t][0] + 2)));
	for(auto v : g[t]){
		if(v == fa) continue;
		int fat = d1[t][a[v] == d1[t][0]];
		int fak = d2[t][max(d1[v][0], d2[v][0]) == d2[t][0]];
		update(d1[v], a[t]);
		update(d2[v], max(fat, fak));
		dfs2(v, t);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i < n; ++i){
		static int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	ans = max(a[1], max(d1[1][0] + 1, d2[1][0] + 2));
	dfs2(1, 0);
	printf("%d\n", ans);
	//system("pause");
	return 0;
}