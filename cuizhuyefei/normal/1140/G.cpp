#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 306000;
int n,fa[N][19],dep[N];ll w[N];
struct ed{
	int v;ll w1,w2;
};vector<ed>e[N];
void dfs1(int u, int fa){
	rep(i,0,SZ(e[u])-1)if(e[u][i].v!=fa)
		dfs1(e[u][i].v,u),umin(w[u],w[e[u][i].v]+e[u][i].w1+e[u][i].w2);
}
void dfs2(int u, int fa){
	rep(i,0,SZ(e[u])-1)if(e[u][i].v!=fa)
		umin(w[e[u][i].v],w[u]+e[u][i].w1+e[u][i].w2),dfs2(e[u][i].v,u);
}
struct node{
	ll a[2][2];
}v[N][19];
inline node merge(node x,node y){
	node z;
	rep(i,0,1)rep(j,0,1)z.a[i][j]=min(x.a[i][0]+y.a[0][j],x.a[i][1]+y.a[1][j]);
	return z;
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);int del=dep[u]-dep[v];
	rep(i,0,18)if(del>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,18,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs(int u, int Fa, int Dep){
	fa[u][0]=Fa;dep[u]=Dep;
	rep(i,0,SZ(e[u])-1)if(e[u][i].v!=Fa){
		ll x=e[u][i].w1,y=w[u],z=e[u][i].w2,W=w[e[u][i].v];
		node tmp;ll all=x+y+z+W;
		tmp.a[0][0]=min(x,all-x);
		tmp.a[0][1]=min(x+y,all-x-y);
		tmp.a[1][0]=min(x+W,all-x-W);
		tmp.a[1][1]=min(z,all-z);
		v[e[u][i].v][0]=tmp;dfs(e[u][i].v,u,Dep+1);
	}
}
int main() {
	read(n);rep(i,1,n)read(w[i]);
	rep(i,1,n-1){
		int u,v;ll x,y;read(u);read(v);read(x);read(y);
		e[u].pb((ed){v,x,y});e[v].pb((ed){u,x,y});
	}
	dfs1(1,0);dfs2(1,0);
//	rep(i,1,n)printf("%d:%lld\n",i,w[i]);
	int q;read(q);dfs(1,0,0);
	rep(j,1,18)rep(i,1,n)if(dep[i]>=(1<<j)){
		fa[i][j]=fa[fa[i][j-1]][j-1];
		v[i][j]=merge(v[i][j-1],v[fa[i][j-1]][j-1]);
	}
	while(q--){
		int u,V;read(u);read(V);
		int t1=u%2==0,t2=V%2==0;u=(u+1)/2;V=(V+1)/2;int lca=LCA(u,V);
	//	printf("qaq %d %d %d\n",u,V,lca);
		ll res=1e18;node x,y;memset(x.a,0,sizeof(x.a));x.a[0][1]=x.a[1][0]=w[u];
		int del=dep[u]-dep[lca];
		rep(i,0,18)if(del>>i&1)x=merge(x,v[u][i]),u=fa[u][i];
		memset(y.a,0,sizeof(y.a));y.a[0][1]=y.a[1][0]=w[V];
		del=dep[V]-dep[lca];
		rep(i,0,18)if(del>>i&1)y=merge(y,v[V][i]),V=fa[V][i];
		res=min(x.a[t1][0]+y.a[t2][0],x.a[t1][1]+y.a[t2][1]);
		printf("%lld\n",res);
	}
	return 0;
}