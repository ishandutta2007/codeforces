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
const int N = 366666;
int n,m;Vi e[N];ll res;bool gg[N];
int val[N],lc[N],rc[N],lzy[N],dis[N],rt[N],tot;vector<Pii>mrk[N];
inline void pushlzy(int k, int x){
	if(k)val[k]+=x,lzy[k]+=x;
}
inline void pushdown(int k){
	if(lzy[k])pushlzy(lc[k],lzy[k]),pushlzy(rc[k],lzy[k]),lzy[k]=0;
}
int merge(int x, int y){
	if(!x||!y)return x+y;
	if(val[x]<val[y])swap(x,y);
	pushdown(y);rc[y]=merge(x,rc[y]);
	if(dis[lc[y]]<dis[rc[y]])swap(lc[y],rc[y]);
	dis[y]=dis[rc[y]]+1;return y;
}
void dfs(int u, int fa){
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfs(e[u][i],u),rt[u]=merge(rt[u],rt[e[u][i]]);
	rep(i,0,SZ(mrk[u])-1)if(mrk[u][i].se>0){
		val[mrk[u][i].se]=mrk[u][i].fi;rt[u]=merge(rt[u],mrk[u][i].se);
	}
	rep(i,0,SZ(mrk[u])-1)if(mrk[u][i].se<0)gg[-mrk[u][i].se]=1;
	while(rt[u]&&gg[rt[u]])rt[u]=merge(lc[rt[u]],rc[rt[u]]);
	if(fa&&!rt[u]){puts("-1");exit(0);}
//	cerr<<u<<' '<<rt[u]<<' '<<
	res+=val[rt[u]];pushlzy(rt[u],-val[rt[u]]);
}
int main() {
	read(n);read(m);
	rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	rep(i,1,m){int u,v,x;read(u);read(v);read(x);mrk[u].pb(Pii(x,i));mrk[v].pb(Pii(x,-i));}
	dfs(1,0);cout<<res;
	return 0;
}