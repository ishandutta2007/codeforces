#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, u, v, mx, cnt, dep[N], p[N], ans[N];
vector<int> e[N];
void dfs(int u){
	printf("%d ", u);
	if(e[u].empty()) return;
	int mx=n;
	for(int v:e[u]) if(dep[v]>=dep[mx]) mx=v;
	int last=0;
	for(int v:e[u]) if(v!=mx){
		dfs(v);
		while(last--) ans[++cnt]=v;
		last=dep[v]+1;
	}
	while(last--) ans[++cnt]=mx;
	dfs(mx);
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<n; ++i) scanf("%d", p+i), e[p[i]].push_back(i);
	for(int i=n; --i;) dep[p[i]]=max(dep[p[i]], dep[i]+1);
	dfs(0);
	printf("\n%d\n", cnt);
	for(int i=1; i<=cnt; ++i) printf("%d%c", ans[i], " \n"[i==cnt]);
	return 0;
}