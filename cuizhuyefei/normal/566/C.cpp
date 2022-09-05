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
const int N = 266666;
int n,w[N];int ans1;double ans2=1e100,cur,ans[N];bool gg[N];
int sz[N],T;vector<Pii>e[N];
void getsz(int u,int fa){
	sz[u]=1;rep(i,0,SZ(e[u])-1)if(!gg[e[u][i].fi]&&e[u][i].fi!=fa)
		getsz(e[u][i].fi,u),sz[u]+=sz[e[u][i].fi];
}
void getcen(int u, int fa, Pii &res){
	int mx=T-sz[u];
	rep(i,0,SZ(e[u])-1)if(!gg[e[u][i].fi]&&e[u][i].fi!=fa)
		getcen(e[u][i].fi,u,res),umax(mx,sz[e[u][i].fi]);
//	if(mx==-1)cerr<<T<<' '<<sz[u]<<endl;
	res=min(res,Pii(mx,u));
}
void getans(int u, int fa, ll dis, int bel){
	cur+=w[u]*dis*sqrt(dis);ans[bel]+=w[u]*sqrt(dis);
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa)
		getans(e[u][i].fi,u,dis+e[u][i].se,bel);
}
void solve(int rt){
	getsz(rt,0);T=sz[rt];Pii res(1e9,rt);getcen(rt,0,res);
	assert(res.fi<=T/2);rt=res.se;gg[rt]=1;cur=0;double sum=0;
	cerr<<rt<<' '<<T<<' '<<res.fi<<endl;
	rep(i,0,SZ(e[rt])-1){
		ans[e[rt][i].fi]=0,getans(e[rt][i].fi,rt,e[rt][i].se,e[rt][i].fi),
		sum+=ans[e[rt][i].fi];
	}
	if(cur<ans2)ans2=cur,ans1=rt;
	rep(i,0,SZ(e[rt])-1)if(ans[e[rt][i].fi]*2>sum&&!gg[e[rt][i].fi]){
		solve(e[rt][i].fi);break;
	}
}
int main() {//freopen("1.in","r",stdin);
	read(n);rep(i,1,n)read(w[i]);
	rep(i,1,n-1){
		int u,v,w;read(u);read(v);read(w);
		e[u].pb(Pii(v,w));e[v].pb(Pii(u,w));
	}
	solve(1);printf("%d %.11lf\n",ans1,ans2);
	return 0;
}