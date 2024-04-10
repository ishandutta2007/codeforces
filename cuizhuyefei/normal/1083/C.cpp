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
const int N = 404000;
int n,p[N],q[N],fa[N];Vi e[N];
namespace LCA{
	int dep[N],s[N],len,a[N][19],pos[N],Log[N];//!!!Log[2n]+1!!!
	void dfs1(int u, int fa, int Dep){
		dep[u]=Dep;s[++len]=u;pos[u]=len;
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
			dfs1(e[u][i],u,Dep+1),s[++len]=u;
	}
	inline void init(){
		dfs1(1,0,0);
		rep(i,1,len)a[i][0]=s[i];
		rep(i,1,len){Log[i]=Log[i-1];if(i==(1<<Log[i]+1))Log[i]++;}
		rep(j,1,18)rep(i,1,len-(1<<j)+1)//WA:len-->n
			a[i][j]=dep[a[i][j-1]]<dep[a[i+(1<<j-1)][j-1]]?a[i][j-1]:a[i+(1<<j-1)][j-1];
	}
	inline int query(int u, int v){
		u=pos[u];v=pos[v];if(u>v)swap(u,v);int k=Log[v-u+1];
		return dep[a[u][k]]<dep[a[v-(1<<k)+1][k]]?a[u][k]:a[v-(1<<k)+1][k];
	}
}
Pii v[N<<2];int dl[N],dr[N],d[N],num;
void dfs(int u, int fa, int D){
	d[u]=D;dl[u]=++num;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
		dfs(e[u][i],u,D+1);
	dr[u]=num;
}
inline int getdis(int u, int v){
	return d[u]+d[v]-2*d[LCA::query(u,v)];
}
inline bool In(int u, int v, int lca, int x){
	if(dl[x]<=dl[u]&&dr[x]>=dl[u]&&dl[lca]<=dl[x]&&dr[lca]>=dl[x])return 1;
	if(dl[x]<=dl[v]&&dr[x]>=dl[v]&&dl[lca]<=dl[x]&&dr[lca]>=dl[x])return 1;
	return 0;
}
inline Pii merge(Pii a, Pii b){
	if(!a.fi||!b.fi)return Pii(0,0);
	Pii x=a;int d=getdis(a.fi,a.se),tmp;
	tmp=getdis(b.fi,b.se);if(tmp>d)d=tmp,x=b;
	tmp=getdis(a.fi,b.fi);if(tmp>d)d=tmp,x=Pii(a.fi,b.fi);
	tmp=getdis(a.fi,b.se);if(tmp>d)d=tmp,x=Pii(a.fi,b.se);
	tmp=getdis(a.se,b.fi);if(tmp>d)d=tmp,x=Pii(a.se,b.fi);
	tmp=getdis(a.se,b.se);if(tmp>d)d=tmp,x=Pii(a.se,b.se);
	int lca=LCA::query(x.fi,x.se);//printf("<%d %d %d>\n",x.fi,x.se,lca);
	if(!In(x.fi,x.se,lca,a.fi)||!In(x.fi,x.se,lca,a.se)||!In(x.fi,x.se,lca,b.fi)||!In(x.fi,x.se,lca,b.se))
		return Pii(0,0);
	return x;
}
inline void upd(int k){
	v[k]=merge(v[k<<1],v[k<<1|1]);
}
inline void build(int k, int l, int r){
	if(l==r){v[k]=Pii(q[l],q[l]);return;}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	upd(k);//printf("%d %d %d:%d %d\n",k,l,r,v[k].fi,v[k].se);
}
inline void modify(int k, int p, int l, int r){
	if(l==r){v[k]=Pii(q[l],q[l]);return;}
	int mid=(l+r)>>1;
	if(p<=mid)modify(k<<1,p,l,mid);else modify(k<<1|1,p,mid+1,r);
	upd(k);
}
Pii qq;bool vis;
inline int query(int k, int l, int r){
//	printf("query %d %d %d\n",k,l,r);
	if(l==r){
		Pii qaq=!vis?v[k]:merge(qq,v[k]);
		if(qaq.fi){qq=qaq;vis=1;return l+1;}return l;
	}
	int mid=(l+r)>>1;Pii qaq=!vis?v[k<<1]:merge(qq,v[k<<1]);//WA:left!!
	if(!qaq.fi)return query(k<<1,l,mid);
	vis=1;qq=qaq;return query(k<<1|1,mid+1,r);
}
int main() {
	read(n);rep(i,1,n)read(p[i]),q[p[i]]=i;
	rep(i,2,n)read(fa[i]),e[i].pb(fa[i]),e[fa[i]].pb(i);
	dfs(1,0,0);LCA::init();
//	printf("%d %d\n",merge(Pii(3,3),Pii(5,5)).fi,merge(Pii(3,3),Pii(5,5)).se);return 0;
	build(1,0,n-1);
	int Q;read(Q);
	while(Q--){
		int op;read(op);
		if(op==1){
			int i,j,x,y;read(i);read(j);x=p[i];y=p[j];
			//x-->j y-->i
			swap(p[i],p[j]);swap(q[x],q[y]);
			modify(1,x,0,n-1);modify(1,y,0,n-1);
		}
		else vis=0,printf("%d\n",query(1,0,n-1));
	}
	return 0;
}