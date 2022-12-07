#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int xx[] = {1, -1, 0, 0};
const int yy[] = {0, 0, 1, -1};
int n;
vector<int> g[40];
int x[40], y[40];

void dfs(int t, int f, int fa, int tmp){
	for(int i = 0, j = 0; i < g[t].size(); ++i){
		if (g[t][i] == fa) continue;
		j++;
		x[g[t][i]] = x[t] + tmp * xx[(f + j) % 4];
		y[g[t][i]] = y[t] + tmp * yy[(f + j) % 4];
		dfs(g[t][i], ((f + j) % 4) ^ 1, t, tmp / 2);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i = 1; i <= n; ++i)
		if(g[i].size() > 4){
			printf("NO\n");
			return 0;
		}
	int tmp = 1 << 30;
	for(int i = 0; i < g[1].size(); ++i){
		x[g[1][i]] = xx[i] * tmp, y[g[1][i]] = yy[i] * tmp;
		dfs(g[1][i], i ^ 1, 1, tmp / 2);
	}
	printf("YES\n");
	for(int i = 1; i <= n; ++i) printf("%d %d\n", x[i], y[i]);
	return 0;
}