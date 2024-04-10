#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,q,N;
int fa[600004];
int F(int x){
	return x==fa[x]?x:fa[x]=F(fa[x]);
}
int s[2][600004],w[600004],lg[600004],pos[600004];
int p[600004][20],dfn[600004],dep[600004],cnt;
void dfs(int x){
	dfn[x]=++cnt,pos[cnt]=x;
	for(int i=1;i<=lg[dep[x]];i++)
		p[x][i]=p[p[x][i-1]][i-1];
	if(x>n){
		p[s[0][x]][0]=x,dep[s[0][x]]=dep[x]+1;
		dfs(s[0][x]);
		p[s[1][x]][0]=x,dep[s[1][x]]=dep[x]+1;
		dfs(s[1][x]);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	while(dep[u]!=dep[v])v=p[v][lg[dep[v]-dep[u]]];
	if(u==v)return u;
	for(int i=lg[dep[u]];~i;i--)
		if(p[u][i]!=p[v][i])u=p[u][i],v=p[v][i];
	return p[u][0];
}
int ld[1100000],rd[1100000];
int LD[1100000],RD[1100000];
int tg[1100000];
void pushup(int i){
	LD[i]=min(LD[i<<1],LD[i<<1|1]);
	RD[i]=max(RD[i<<1],RD[i<<1|1]);
}
void push(int i,int t){
	if(t==0)LD[i]=N+1,RD[i]=-1;
	else LD[i]=ld[i],RD[i]=rd[i];
	tg[i]=t;
}
void pushdown(int i){
	if(tg[i]!=-1){
		push(i<<1,tg[i]);
		push(i<<1|1,tg[i]);
		tg[i]=-1;
	}
}
void built(int i,int l,int r){
	tg[i]=-1,LD[i]=N+1,RD[i]=-1;
	if(l==r)ld[i]=rd[i]=dfn[l];
	else{
		int md=(l+r)>>1;
		built(i<<1,l,md),built(i<<1|1,md+1,r);
		ld[i]=min(ld[i<<1],ld[i<<1|1]);
		rd[i]=max(rd[i<<1],rd[i<<1|1]);
	}
}
void upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		push(i,x);
		return;
	}
	pushdown(i);
	int md=(l+r)>>1;
	upd(i<<1,l,md,a,b,x),upd(i<<1|1,md+1,r,a,b,x);
	pushup(i);
}
void ask(int x){
	if(LD[1]==N+1){
		puts("-1");
		return;
	}
	int lp=pos[LD[1]],rp=pos[RD[1]];
	int LCA=lca(x,lca(lp,rp));
	if(LCA==x){
		puts("-1");
		return;
	}
	printf("%d\n",w[LCA]);
}
int main(){
	scanf("%d%d",&n,&q),N=n;
	for(int i=2;i<=n+n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n+n;i++)fa[i]=i;
	vector<pair<int,pii> >edg;
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		edg.push_back({w,{u,v}});
	}
	sort(edg.begin(),edg.end());
	for(auto [c,x]:edg){
		int u=x.fi,v=x.se;
		u=F(u),v=F(v);
		++N,w[N]=c,s[0][N]=u,s[1][N]=v;
		fa[u]=fa[v]=N;
	}
	dfs(N);
	built(1,1,n);
	while(q--){
		int op,l,r,x;scanf("%d",&op);
		if(op==1)scanf("%d%d",&l,&r),upd(1,1,n,l,r,1);
		if(op==2)scanf("%d%d",&l,&r),upd(1,1,n,l,r,0);
		if(op==3)scanf("%d",&x),ask(x);
	}
}