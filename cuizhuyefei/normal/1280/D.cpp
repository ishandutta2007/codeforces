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
typedef pair<int,ll> Pil;
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
const int N = 3030;
int n,m,a[N],b[N];Vi e[N];
Pil f[N][N],g[N];int sz[N];
void dfs(int u, int fa){
	sz[u]=1;f[u][0]=Pil(0,a[u]);
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)dfs(e[u][i],u);
	rep(jj,0,SZ(e[u])-1)if(e[u][jj]!=fa){
		int v=e[u][jj];
		rep(i,0,sz[u]+sz[v])g[i]=Pil(-1e9,0);
		rep(i,0,sz[v]-1)rep(j,0,sz[u]-1){
			umax(g[i+j],Pil(f[u][j].fi+f[v][i].fi+(f[v][i].se>0),f[u][j].se));
			umax(g[i+j+1],Pil(f[u][j].fi+f[v][i].fi,f[u][j].se+f[v][i].se));
		}
		sz[u]+=sz[v];rep(i,0,sz[u]-1)f[u][i]=g[i];
	}
}

int main() {
	int T;read(T);while(T--){
		read(n);read(m);rep(i,0,n)e[i].clear();
		rep(i,1,n)read(a[i]);
		rep(i,1,n)read(b[i]),a[i]=b[i]-a[i],b[i]=0;//\sum a[i]>0
		rep(i,1,n-1){
			int u,v;read(u);read(v);
			e[u].pb(v);e[v].pb(u);
		}
		dfs(1,0);
		printf("%d\n",f[1][n-m].fi+(f[1][n-m].se>0));
	}
	return 0;
}