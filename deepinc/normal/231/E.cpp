#include<bits/stdc++.h>
using namespace std;
const int $=2e5+5;
vector<int>T[$];
#define pb push_back
int tp,st[$],n,m,N,f[19][$],w[$],dep[$],pw[$],bl[$],fir[$],l[$],to[$],ec=1,al[$],t;
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
void dfs(int p,int fe){
	st[++tp]=p; al[p]=++t;
	for(int i=fir[p],y;y=to[i];i=i[l])if(!al[y])dfs(y,i);
		else if(i!=(fe^1)&&al[y]<al[p]){++N;while(st[tp+1]^y)bl[st[tp--]]=N;}
	if(st[tp]==p)tp--;
}
void DFS(int p){
	for(int i=1;i<19;++i)f[i][p]=f[i-1][f[i-1][p]]; w[p]+=p>n;
	for(int y:T[p])if(!w[y])f[0][y]=p,dep[y]=dep[p]+1,w[y]=w[p],DFS(y);
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b); int s=dep[a]-dep[b];
	for(int i=18;~i;--i)if(s>>i&1)a=f[i][a];
	if(a==b)return a;
	for(int i=18;~i;--i)if(f[i][a]!=f[i][b])a=f[i][a],b=f[i][b];
	return f[0][a];
}
int main(){
	scanf("%d%d",&n,&m); N=n;
	for(int i=pw[0]=1;i<=n;++i)pw[i]=pw[i-1]*2ll%1000000007,bl[i]=i;
	for(int i=1,a,b;i<=m;++i)scanf("%d%d",&a,&b),link(a,b),link(b,a);
	dfs(1,0);
	for(int i=1;i<=n;++i)for(int j=fir[i],y;y=to[j];j=l[j])if(bl[i]!=bl[y]&&y>i)T[bl[i]].pb(bl[y]),T[bl[y]].pb(bl[i]);
	w[0]=w[bl[1]]=1; DFS(bl[1]);
	scanf("%d",&m);
	for(int i=1,a,b,c;i<=m;++i)scanf("%d%d",&a,&b),a=bl[a],b=bl[b],c=lca(a,b),printf("%d\n",pw[w[a]+w[b]-w[c]-w[f[0][c]]]);
}