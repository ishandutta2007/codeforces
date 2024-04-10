#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n;
bool vis[N];
vector<int> e[N];
pair<int,int> dfs(int u, int fa=0){
	pair<int,int> ans(-1, u);
	for(int v:e[u]) if(v!=fa && !vis[v]) ans=max(ans, dfs(v, u));
	return ++ans.first, ans;
}
bool solve(int u, int x, int fa=0){
	if(u==x) return 1;
	bool ans=0;
	for(int v:e[u]) if(v!=fa && !vis[v]) ans|=solve(v, x, u);
	vis[u]=ans;
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	int u=1;
	while(1){
		int v=dfs(u).second;
		u=dfs(v).second;
		if(u==v) return printf("! %d\n", u), fflush(stdout), 0;
		printf("? %d %d\n", u, v), fflush(stdout);
		int x;
		scanf("%d", &x);
		solve(u, x), solve(v, x), u=x;
	}
	return 0;
}