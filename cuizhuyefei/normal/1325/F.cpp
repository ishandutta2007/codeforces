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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
const int N = 4e5+11;
int n,m,lim,fa[N],dep[N],dp[N];Vi e[N],b;
void dfs(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;
	for(int v:e[u])if(v!=Fa&&!dep[v])dfs(v,u,Dep+1);
	else if(v!=Fa&&dep[v]<dep[u]&&dep[u]-dep[v]+1>=lim){
		Vi a;for(int x=u;;x=fa[x]){a.pb(x);if(x==v)break;}
		puts("2");printf("%d\n",SZ(a));for(int x:a)printf("%d ",x);
		exit(0);
	}
}
void dfs1(int u){
	for(int v:e[u])if(v!=fa[u]&&dep[v]==dep[u]+1)dfs1(v),umin(dp[u],dp[v]);
	if(dp[u]>dep[u]&&SZ(b)<lim)b.pb(u),dp[u]=dep[u]-(lim-1)+1;
}
int main() {
	read(n);read(m);
	rep(i,1,m){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	lim=sqrt(n);if(lim*lim!=n)lim++;
	dfs(1,0,1);rep(i,1,n)dp[i]=n+1;dfs1(1);
	assert(SZ(b)==lim);
	puts("1");for(int x:b)printf("%d ",x);
	return 0;
}