#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1005,mo=1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int fac[N],ifac[N];
void iniC(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);
	per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
int n,m,dp[N][15];Vi e[N],E[N];
map<Vi,int>Map;int tot,hsh[N],Fa[N],XS,res;
void gethash(int u, int fa){
	Vi a;Fa[u]=fa;
	for(int v:E[u])if(v!=fa)gethash(v,u),a.pb(hsh[v]);
	sort(ALL(a));
	rep(i,0,SZ(a)-1){
		int j=i;while(j+1<SZ(a)&&a[j+1]==a[i])j++;
		XS=1ll*XS*ifac[j-i+1]%mo;i=j;
	}
	if(!Map.count(a))Map[a]=++tot;
	hsh[u]=Map[a];
}
void dfs(int u, int fa){
	Vi son;for(int v:e[u])if(v!=fa)dfs(v,u),son.pb(v);
	rep(v,1,m)if(SZ(son)>=SZ(E[v])-(Fa[v]>0)){
		static int f[1<<12|3],g[1<<12|3],dot[N];int len=0;
		for(int x:E[v])if(x!=Fa[v])dot[len++]=x;//0..len-1
		memset(f,0,4*(1<<len));f[0]=1;
		for(int x:son){
			memcpy(g,f,4*(1<<len));
			rep(i,0,(1<<len)-1)if(f[i])rep(j,0,len-1)if((~i>>j&1)&&dp[x][dot[j]])
				g[i|1<<j]=(g[i|1<<j]+1ll*f[i]*dp[x][dot[j]])%mo;
			memcpy(f,g,4*(1<<len));
		}
		dp[u][v]=f[(1<<len)-1];
	}
}
int main() {
	iniC(N-1);
	read(n);
	rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	read(m);
	rep(i,1,m-1){int u,v;read(u);read(v);E[u].pb(v);E[v].pb(u);}
	set<int>Set;
	rep(rt,1,m){
		XS=1;gethash(rt,0);
		if(Set.count(hsh[rt]))continue;
		Set.insert(hsh[rt]);
		memset(dp,0,sizeof(dp));
		dfs(1,0);rep(i,1,n)res=(res+1ll*XS*dp[i][rt])%mo;
	//	cerr<<rt<<' '<<XS<<' '<<dp[1][rt]<<endl;
	}
	cout<<res;
	return 0;
}