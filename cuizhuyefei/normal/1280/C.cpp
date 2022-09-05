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
const int N = 1266666;
int n,sz[N];vector<Pii>e[N];ll x,y;
void dfs(int u ,int fa){
	sz[u]=1;
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa){
		dfs(e[u][i].fi,u);sz[u]+=sz[e[u][i].fi];
		if(sz[e[u][i].fi]&1)x+=e[u][i].se;
		y+=1ll*e[u][i].se*min(sz[e[u][i].fi],n-sz[e[u][i].fi]);
	}
}
int main() {
	int T;read(T);while(T--){
		read(n);n*=2;rep(i,0,n)e[i].clear();
		rep(i,1,n-1){
			int u,v,w;read(u);read(v);read(w);
			e[u].pb(Pii(v,w));e[v].pb(Pii(u,w));
		}
		x=0,y=0;dfs(1,0);
		printf("%lld %lld\n",x,y);
	}
	return 0;
}