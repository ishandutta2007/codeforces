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
const int N = 266666;const ll mx=3e11;
int q,ans[N],n,pre[N];vector<Pii>e[N];ll dis[N],thres[N],dep[N];
namespace Tree{
	const int M = 41*102000;
	int sz[N],son[N];int lc[M],rc[M],val[M],tot=1,rt=1;ll dep[N];
	void modify(int &k, ll p, int x, ll l, ll r){
		if(!k)k=++tot;val[k]+=x;if(l==r)return;
		ll mid=(l+r)>>1;
		if(p<=mid)modify(lc[k],p,x,l,mid);else modify(rc[k],p,x,mid+1,r);
	}
	int qry(int k, ll l, ll r, ll L, ll R){
		if(!k||l==L&&r==R)return val[k];
		ll mid=(L+R)>>1;
		if(r<=mid)return qry(lc[k],l,r,L,mid);
		else if(l>mid)return qry(rc[k],l,r,mid+1,R);
		return qry(lc[k],l,mid,L,mid)+qry(rc[k],mid+1,r,mid+1,R);
	}
	void dfsadd(int u, int fa, int xs){
		modify(rt,dep[u],xs,0,mx);
		rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa)dfsadd(e[u][i].fi,u,xs);
	}
	void dfs(int u, int fa, bool keep){
		rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa&&e[u][i].fi!=son[u])
			dfs(e[u][i].fi,u,0);
		if(son[u])dfs(son[u],u,1);
		modify(rt,dep[u],1,0,mx);
		rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa&&e[u][i].fi!=son[u])
			dfsadd(e[u][i].fi,u,1);
		rep(i,1,q){
			umax(ans[i],qry(1,dep[u],dep[u]+thres[i],0,mx));
		}
		if(!keep)dfsadd(u,fa,-1);
	}
	void dfs1(int u, int fa, ll d){
		dep[u]=d;sz[u]=1;
		rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa){
			dfs1(e[u][i].fi,u,d+e[u][i].se),sz[u]+=sz[e[u][i].fi];
			if(sz[son[u]]<sz[e[u][i].fi])son[u]=e[u][i].fi;
		}
	}
	void solve(int u, int fa){
		rep(i,0,tot)lc[i]=rc[i]=val[i]=0;tot=1;rt=1;
		rep(i,1,n)son[i]=sz[i]=0;
		dfs1(u,fa,0);dfs(u,fa,1);
	}
}
int bfs(int s){
	static int q[N];int f=0,r=1;q[f]=s;
	rep(i,1,n)dis[i]=1e18;dis[s]=0;int res=s;
	while(f!=r){
		int u=q[f++];if(dis[u]>dis[res])res=u;
		rep(i,0,SZ(e[u])-1)if(dis[e[u][i].fi]>dis[u]+e[u][i].se)
			dis[e[u][i].fi]=dis[u]+e[u][i].se,q[r++]=e[u][i].fi,pre[e[u][i].fi]=u;
	}
	return res;
}
void dfs1(int u, int fa, ll d){
	dep[u]=d;rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa)
		dfs1(e[u][i].fi,u,d+e[u][i].se);
}
int main() {
	read(n);
	rep(i,1,n-1){
		int u,v,w;read(u);read(v);read(w);
		e[u].pb(Pii(v,w));e[v].pb(Pii(u,w));
	}
	read(q);rep(i,1,q)read(thres[i]);
	int S=bfs(1),T=bfs(S);
	int u=T;while(pre[u]&&(dis[T]-dis[pre[u]])*2<=dis[T])u=pre[u];
	if(dis[u]*2==dis[T]){Tree::solve(u,0);rep(i,1,q)printf("%d\n",ans[i]);return 0;}
	ll A=dis[u],B=dis[T]-dis[pre[u]],t=min(A,B);A-=t;B-=t;
	dfs1(u,pre[u],A);dfs1(pre[u],u,B);
	Tree::solve(u,pre[u]);Tree::solve(pre[u],u);
	static ll s[N];rep(i,1,n)s[i]=dep[i];sort(s+1,s+n+1);
	rep(i,1,q){
	//	cerr<<ans[i]<<' ';
		if(A-B<=thres[i]&&B-A<=thres[i]){
			int res=0;rep(j,1,n)if(s[j]-s[1]<=thres[i])res=j;
			umax(ans[i],res);
		}
		printf("%d\n",ans[i]);
	}
	return 0;
}