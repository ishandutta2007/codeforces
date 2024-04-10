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
const int N = 505;const ll inf=1e16;const short BIG=(1<<14)-1;
int sum,n,lim,sz[N];ll dis[N][N];Vi e[N];
short f[N][N][N],g[N][N],col[N];
void dfs(int u, int fa){
	per(i,SZ(e[u])-1,0)if(e[u][i]!=fa)dfs(e[u][i],u);
	rep(i,1,n){
		if(dis[u][i]>lim)continue;
		f[u][i][1]=1-col[i];sz[u]=1;
		rep(j,0,SZ(e[u])-1)if(e[u][j]!=fa){
			static short dp[N];rep(k,1,sz[u]+sz[e[u][j]])dp[k]=BIG;
			rep(x,1,sz[e[u][j]])rep(y,1,sz[u])
				umin(dp[x+y-1],(short)(f[e[u][j]][i][x]+f[u][i][y]-(1-col[i]))),
				umin(dp[x+y],(short)(g[e[u][j]][x]+f[u][i][y]));
			sz[u]+=sz[e[u][j]];rep(x,1,sz[u])f[u][i][x]=dp[x];
		}
	}
	rep(j,1,n)rep(i,1,min(sum,sz[u]))umin(g[u][i],f[u][j][i]);
	/*rep(j,1,n)rep(i,1,min(sum,sz[u]))if(f[u][j][i]<BIG)
		printf("%d %d %d:%d\n",u,j,i,(int)g[u][i]);
	rep(i,1,min(sum,sz[u]))printf("%d %d:%d\n",u,i,(int)g[u][i]);*/
}
int main() {
	read(n);read(lim);
	rep(i,1,n)read(col[i]),sum+=col[i];
	rep(i,1,n)rep(j,1,n)dis[i][j]=inf;
	rep(i,1,n-1){
		int u,v;ll w;read(u);read(v);read(w);
		umin(dis[u][v],w);umin(dis[v][u],w);
		e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n)dis[i][i]=0;
	rep(k,1,n)rep(i,1,n)rep(j,1,n)umin(dis[i][j],dis[i][k]+dis[k][j]);
	
	rep(i,1,n)rep(j,1,n)rep(k,0,sum)f[i][j][k]=BIG;
	rep(i,1,n)rep(j,1,n)g[i][j]=BIG;
	dfs(1,0);
	int res=g[1][sum]<BIG?g[1][sum]:-1;
	printf("%d\n",res);
	return 0;
}