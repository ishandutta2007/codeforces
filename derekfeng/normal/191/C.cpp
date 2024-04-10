#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,cnt;
struct NODE{
	int to,x,lst;
}g[200004];
int head[100004];
void add_edge(int fr,int to,int x){g[++cnt].to=to,g[cnt].lst=head[fr],g[cnt].x=x,head[fr]=cnt;}
int cmp[100004],par[17][100004],depth[100004],lg[100004],siz[100004],nxt[100004],h[100004],iter[100004],a[100004],ans[100004];
void dfs(int x,int pars,int dep){
	depth[x]=dep,par[0][x]=pars,siz[x]=1;
	int maxx=0;
	for (int i=1;i<=lg[depth[x]];++i)if(par[i-1][x])
		par[i][x]=par[i-1][par[i-1][x]];
	for (int i=head[x];i;i=g[i].lst)if(g[i].to!=pars){
		iter[g[i].to]=g[i].x;
		dfs(g[i].to,x,dep+1),siz[x]+=siz[g[i].to];
		if(maxx<siz[g[i].to])h[x]=g[i].to,maxx=siz[g[i].to];
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v])swap(u,v);
	while (depth[u]<depth[v])v=par[lg[depth[v]-depth[u]]][v];
	if(u==v)return u;
	for(int i=lg[depth[u]];i>=0;--i)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
	return par[0][u];
}
void geth(int x,int pars,int f){
	cmp[x]=++cnt;
	nxt[x]=f;
	if(h[x])geth(h[x],x,f);
	for (int i=head[x];i;i=g[i].lst)if(g[i].to!=pars)
		if(g[i].to!=h[x])geth(g[i].to,x,g[i].to);
}
void add(int x,int f){
	while(1){
		int l=nxt[x];
		a[cmp[l]]+=f,a[cmp[x]+1]-=f;
		if(l==1)break;
		x=par[0][l];
	}
}
int main(){
	read(n);
	for (int i=1;i<n;++i){int u,v;read(u),read(v),add_edge(u,v,i),add_edge(v,u,i);}
	cnt=0;
	for(int i=0;i<17;++i)lg[1<<i]=i;for(int i=3;i<=n;++i)lg[i]=max(lg[i],lg[i-1]); 
	dfs(1,-1,0);
	geth(1,-1,1);
	read(m);
	while(m--){
		int u,v;read(u),read(v);
		int a=lca(u,v);
		add(u,1),add(v,1),add(a,-2);
	}
	for(int i=2;i<=n;i++)a[i]+=a[i-1];
	for(int i=2;i<=n;i++)ans[iter[i]]=a[cmp[i]];
	for(int i=1;i<n;i++)write(ans[i]),putchar(' ');
}