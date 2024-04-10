#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int> 
using namespace std;
const int N=5e5+5,Inf=1e9;
struct Graph{int u,v,t;}g[N];
struct query{int opt,x;}q[N];
int n,m,qq,p[N];
struct seg{
	pii ma[N<<2];
	pii chkma(pii a,pii b){return a.first>=b.first?a:b;}
	void update(int rt){ma[rt]=chkma(ma[rt<<1],ma[rt<<1|1]);}
	void build(int rt,int l,int r){
		if(l==r){ma[rt]=pii(-1,l);return;}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
		update(rt);
	}
	void change(int rt,int l,int r,int x,int y){
		if(l==r){ma[rt]=pii(y,l);return;}
		int mid=(l+r)>>1;
		(x<=mid)?change(rt<<1,l,mid,x,y):change(rt<<1|1,mid+1,r,x,y);
		update(rt);
	}
	pii ask(int rt,int l,int r,int L,int R){
		if(L<=l&&r<=R)return ma[rt];
		int mid=(l+r)>>1;
		if(R<=mid)return ask(rt<<1,l,mid,L,R);
		if(L>mid)return ask(rt<<1|1,mid+1,r,L,R);
		return chkma(ask(rt<<1,l,mid,L,R),ask(rt<<1|1,mid+1,r,L,R));
	}
}t;
struct Edge{int to,nxt;}e[N];
int tot,fst[N],tote,L[N],R[N],id,dep[N],fa[N][21],bf[N],val[N];
void adde(int u,int v){e[++tote]=(Edge){v,fst[u]};fst[u]=tote;}
void dfs(int u,int f){
	L[u]=++id;dep[u]=dep[f]+1;fa[u][0]=f;
	for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=fst[u];i;i=e[i].nxt)dfs(e[i].to,u);
	R[u]=id; 
}
int find(int u){return bf[u]==u?u:bf[u]=find(bf[u]);}
bool cmp(Graph a,Graph b){return a.t>b.t;}
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
int main(){
	scanf("%d%d%d",&n,&m,&qq);
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=m;i++)g[i].u=read(),g[i].v=read(),g[i].t=Inf;
	for(int i=1;i<=qq;i++){
		q[i].opt=read();q[i].x=read();
		if(q[i].opt==2)g[q[i].x].t=min(g[q[i].x].t,i);
	}
	sort(g+1,g+m+1,cmp);
	tot=n;for(int i=1;i<=n;i++)bf[i]=i;
	for(int i=1,u,v,t,ru,rv;i<=m;i++){
		u=g[i].u;v=g[i].v;t=g[i].t;
		ru=find(u);rv=find(v);
		if(ru!=rv){
			val[++tot]=t;bf[tot]=bf[ru]=bf[rv]=tot;
			adde(tot,ru);adde(tot,rv);
		}
	}
	for(int i=1;i<=tot;i++)if(bf[i]==i)dfs(i,0);
	t.build(1,1,tot);
	for(int i=1;i<=n;i++)t.change(1,1,tot,L[i],p[i]);
	for(int i=1,x;i<=qq;i++)if(q[i].opt==1){
		x=q[i].x;
		for(int k=20;~k;k--)if(fa[x][k]&&val[fa[x][k]]>=i)x=fa[x][k];
		pii tt=t.ask(1,1,tot,L[x],R[x]);
		printf("%d\n",tt.first);
		t.change(1,1,tot,tt.second,0);
	}
	return 0;
}