#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 500100;
int n, m;
vector<int> po[maxn], g[maxn];
int col[maxn], s[maxn], tmax = 1;

void dfs(int t, int fa){
	vector<int> qn;
	for(auto v : po[t])
		if(col[v]) qn.pb(col[v]);
	sort(all(qn));
	int i = 0, j = 1;
	for(auto v : po[t])
		if(!col[v]){
			while(i < qn.size() && qn[i] < j) ++i;
			while(i < qn.size() && qn[i] == j) ++i, ++j;
			col[v] = j; ++j;
			tmax = max(tmax, col[v]);
		}
	for(auto v : g[t]){
		if(v == fa) continue;
		dfs(v, t);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", s + i);
		for(int j = 1; j <= s[i]; ++j){
			static int x;
			scanf("%d", &x);
			po[i].pb(x);
			//g[x].pb(i);
		}
	}
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	printf("%d\n", tmax);
	for(int i = 1; i <= m; ++i){
		if(!col[i]) col[i] = 1;
		printf("%d ", col[i]);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}