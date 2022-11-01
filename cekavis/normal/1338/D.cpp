#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, ans, d[N], f[N][2];
vector<int> e[N];
void dfs(int u, int fa=0){
	f[u][0]=1, f[u][1]=d[u]-2;
	for(int v:e[u]) if(v!=fa){
		dfs(v, u);
		ans=max(max(max(ans, f[u][0]+f[v][1]), f[u][1]+f[v][0]), f[u][1]+f[v][1]);
		f[u][0]=max(f[u][0], 1+f[v][1]);
		f[u][1]=max(f[u][1], d[u]-2+max(f[v][0], f[v][1]));
	}
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i)
		scanf("%d%d", &x, &y), ++d[x], ++d[y],
		e[x].push_back(y), e[y].push_back(x);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}