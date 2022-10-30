#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n;
bool vis[2], viss[N];
vector<int> e[N];
void dfs(int u, int fa=0, int x=0){
	for(int v:e[u]) if(v!=fa) dfs(v, u, x^1);
	if(e[u].size()==1) vis[x]=1;
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	dfs(1);
	int ans=n-1;
	for(int i=1; i<=n; ++i) if(e[i].size()==1)
		ans-=viss[e[i][0]], viss[e[i][0]]=1;
	printf("%d %d\n", (vis[0] && vis[1]?3:1), ans);
	return 0;
}