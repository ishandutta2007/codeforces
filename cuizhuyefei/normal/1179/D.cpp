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
const int N = 505000;
int n;Vi e[N];ll res=1e18,dp[N],g[N],sz[N];
ll f(ll x){return x*(x-1)/2;}
bool cmp(int x, int y){return sz[x]<sz[y];}
void dfs(int u, int fa){
	sz[u]=1;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		dfs(e[u][i],u);sz[u]+=sz[e[u][i]];
	}
	umin(dp[u],f(sz[u]));
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		umin(res,dp[e[u][i]]+f(n-sz[e[u][i]]));
		umin(dp[u],dp[e[u][i]]+f(sz[u]-sz[e[u][i]]));
	}
	sort(e[u].begin(),e[u].end(),cmp);
	static int s[N];int len=0;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)s[++len]=e[u][i];
	rep(i,1,len-1)umin(res,dp[s[i]]+dp[s[len]]+f(n-sz[s[i]]-sz[s[len]]));
	rep(i,1,len-1){
		rep(j,1,sz[s[i]])umin(res,g[j]+dp[s[i]]+f(n-j-sz[s[i]]));
		umin(g[sz[s[i]]],dp[s[i]]);
	}
	rep(i,1,len)g[sz[s[i]]]=1e18;
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,0,n)dp[i]=1e18,g[i]=1e18;
	dfs(1,0);
	cout<<1LL*n*(n-1)-res;
	return 0;
}