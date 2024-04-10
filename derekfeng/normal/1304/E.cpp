#include <bits/stdc++.h>
using namespace std;
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
vector<int>g[100004];
int par[17][100004],depth[100004];
void dfs(int x,int pars,int dep){
	depth[x]=dep,par[0][x]=pars;
	for (int i=0;i<g[x].size();i++)if(g[x][i]!=pars)
		dfs(g[x][i],x,dep+1);
}
int lca(int u,int v){
	if (depth[u]>depth[v]) swap(u,v);
	for (int i=16;i>=0;i--) if ((depth[v]-depth[u])&(1<<i)) v=par[i][v];
	if (u==v) return u;
	for (int i=16;i>=0;i--)
		if (par[i][u]!=par[i][v]) u=par[i][u],v=par[i][v];
	return par[0][u];
}
int len(int u,int v){
	int NUM=lca(u,v);
	return depth[u]-depth[NUM]+depth[v]-depth[NUM];
}
void MAIN(){
	int a,b,x,y,k;cin>>x>>y>>a>>b>>k;
	int L=len(a,b);
	{
		if (L<=k && L%2==k%2){	
			puts("YES");return;
		}
	}
	{
		int Ld=len(a,x)+1+len(b,y);
		if (Ld<=k && Ld%2==k%2){
			puts("YES");return;
		}
	}
	{
		swap(x,y);
		int Ld=len(a,x)+1+len(b,y);
		if (Ld<=k && Ld%2==k%2){
			puts("YES");return;
		}
		swap(x,y);
	}
	puts("NO");
}
int main(){
	std::ios::sync_with_stdio(0);
	cin>>n;
	memset (par,-1,sizeof(par));
	for (int i=1;i<n;i++){
		int x,y;cin>>x>>y,g[x].push_back(y),g[y].push_back(x);  
	}
	dfs(1,-1,0);
	for (int i=1;i<17;i++)
		for (int j=1;j<=n;j++) if (par[i-1][j]!=-1)
			par[i][j]=par[i-1][par[i-1][j]];
	int q;cin>>q; 
	while (q--){
		MAIN();
	}	
}