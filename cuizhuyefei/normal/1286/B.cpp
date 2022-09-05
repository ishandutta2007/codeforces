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
const int N = 2666;
int n,fa[N],val[N],sz[N],rt,rk[N];Vi e[N],dp[N];
void dfs(int u){
	sz[u]=1;
	rep(i,0,SZ(e[u])-1)dfs(e[u][i]),sz[u]+=sz[e[u][i]];
	if(val[u]>=sz[u]){puts("NO");exit(0);}
	rep(i,0,SZ(e[u])-1)rep(j,0,SZ(dp[e[u][i]])-1)dp[u].pb(dp[e[u][i]][j]);
	dp[u].insert(dp[u].begin()+val[u],u);
}
int main() {
	read(n);rep(i,1,n)read(fa[i]),read(val[i]);
	rep(i,1,n)if(!fa[i])rt=i;else e[fa[i]].pb(i);
	dfs(rt);rep(i,0,SZ(dp[rt])-1)rk[dp[rt][i]]=i+1;
	puts("YES");
	rep(i,1,n)printf("%d ",rk[i]);
	return 0;
}