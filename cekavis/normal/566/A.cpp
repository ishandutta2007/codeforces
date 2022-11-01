#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 800005, C = 26, M = 100005;
int n, id, root, cnt, Ans, ans[M], ch[N][C];
char s[N];
vector<int> f[N], g[N];
void insertf(int &u, int i){
	if(!u) u=++cnt;
	if(s[i]) insertf(ch[u][s[i]-'a'], i+1);
	else f[u].push_back(id);
}
void insertg(int &u, int i){
	if(!u) u=++cnt;
	if(s[i]) insertg(ch[u][s[i]-'a'], i+1);
	else g[u].push_back(id);
}
void dfs(int u, int dep=0){
	for(int i=0; i<C; ++i) if(ch[u][i]){
		dfs(ch[u][i], dep+1);
		for(int j:f[ch[u][i]]) f[u].push_back(j);
		for(int j:g[ch[u][i]]) g[u].push_back(j);
	}
	// printf("dfs: %d %d\n", u, dep);
	while(f[u].size() && g[u].size())
		ans[f[u].back()]=g[u].back(), f[u].pop_back(), g[u].pop_back(),
		Ans+=dep;
}
int main() {
	scanf("%d", &n);
	for(id=0; id<n; ++id) scanf("%s", s), insertf(root, 0);
	for(id=0; id<n; ++id) scanf("%s", s), insertg(root, 0);
	dfs(root);
	printf("%d\n", Ans);
	for(int i=0; i<n; ++i) printf("%d %d\n", i+1, ans[i]+1);
	return 0;
}