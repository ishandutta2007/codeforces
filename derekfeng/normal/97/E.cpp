#include<bits/stdc++.h>
using namespace std;
int f[100004],a[100004],P[100004],rt[100004];
int n,m,Q,dep[100004],par[17][100004];
vector<int>g[100004];
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
void dfs(int x,int depth){
	for(int i=1;i<17;i++)if(par[i-1][x]>0)par[i][x]=par[i-1][par[i-1][x]];
	dep[x]=depth;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(!dep[to]){
			par[0][to]=x,dfs(to,depth+1);
			if(F(x)==F(to))a[x]|=a[to];
		}else if(dep[to]+1<dep[x]){
			if((dep[x]-dep[to])%2==0)a[x]=1;
			for(int j=F(x);dep[j]>dep[to]+1;j=F(j))f[j]=par[0][j];
		}
	}
}
void dfs1(int x,int R){
	P[x]+=a[x],rt[x]=R; 
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(dep[to]==dep[x]+1){
			if(F(to)==F(x))a[to]|=a[x];
			P[to]=P[x],dfs1(to,R);
		}
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	for(int i=16;i>=0;i--)if((1<<i)&(dep[v]-dep[u]))v=par[i][v];
	if(u==v)return u;
	for(int i=16;i>=0;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
	return par[0][u];
}
bool ok(int a,int b){
	if(abs(dep[a]-dep[b])%2==1)return 1;
	int L=lca(a,b);
	if(P[a]+P[b]-2*P[L]>0)return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!dep[i])dfs(i,1),dfs1(i,i);
	scanf("%d",&Q);
	while(Q--){
		int a,b;scanf("%d%d",&a,&b);
		if(rt[a]==rt[b]&&ok(a,b))puts("Yes");
		else puts("No");
	}
}