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
const int N = 102000,mo=1e9+7;const ll MOD=7LL*mo*mo;
Vi e[N];int n,k,S[202][202],f[N][202],fac[202],ans[202],sz[N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
void init(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	S[0][0]=1;rep(i,1,n)rep(j,1,i)S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j)%mo;
}
void dfs(int u, int fa){
	f[u][0]=1;sz[u]=1;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		ll g[202]={0};int v=e[u][i];dfs(v,u);
		per(x,min(sz[v],k),0)if(f[v][x])per(y,min(sz[u],k-x),0)
			g[x+y]+=1LL*f[v][x]*f[u][y],g[x+y]=g[x+y]<MOD?g[x+y]:g[x+y]-MOD;
		rep(j,0,k)f[u][j]=(f[u][j]+g[j])%mo;
		sz[u]+=sz[v];
	}
	rep(i,0,k)ans[i]=(ans[i]+2LL*f[u][i])%mo;ans[0]-=2;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
		rep(j,0,min(k,sz[e[u][i]]))sub(ans[j],f[e[u][i]][j]);
	rep(i,0,k)add(f[u][i],f[u][i]);f[u][0]--;
	per(i,k,0)add(f[u][i],f[u][i-1]);
}
int main() {
	read(n);read(k);
	rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	init(201);
	dfs(1,0);
	int res=0;rep(i,0,k)res=(res+1LL*fac[i]*S[k][i]%mo*ans[i])%mo;
	cout<<res;
	return 0;
}