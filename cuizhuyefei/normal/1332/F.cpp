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
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 366666,mo=998244353;
int n,f[N][2][2],res;Vi e[N];
void dfs(int u, int fa){
	for(int v:e[u])if(v!=fa)dfs(v,u);
	f[u][1][1]=f[u][1][0]=f[u][0][1]=1;
	for(int v:e[u])if(v!=fa){
		f[u][1][1]=1ll*f[u][1][1]*(1ll*f[v][0][0]+f[v][0][1]+f[v][1][0])%mo;
		f[u][1][0]=1ll*f[u][1][0]*(1ll*f[v][0][0]+f[v][1][0]+f[v][0][1]+f[v][1][1])%mo;
		f[u][0][1]=1ll*f[u][0][1]*(f[v][0][0]+f[v][0][1])%mo;
	}
	f[u][0][0]=f[u][1][0];
	f[u][0][1]=(f[u][1][1]-f[u][0][1]+mo)%mo;
//	printf("%d:%d %d %d %d\n",u,f[u][0][0],f[u][0][1],f[u][1][0],f[u][1][1]);
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	dfs(1,0);res=(f[1][0][0]+f[1][0][1]-1)%mo;res=(res+mo)%mo;cout<<res;
	return 0;
}