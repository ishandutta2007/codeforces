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
const int N = 505050;
int dep[N],fa[N][20],mn[N][20],n,a[N],rt;Vi e[N];ll res;
void dfs(int u, int Fa, int Dep){
	fa[u][0]=Fa;dep[u]=Dep;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa)
		dfs(e[u][i],u,Dep+1);
}
int main() {
	rt=1;read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)if(a[i]<a[rt])rt=i;
	rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	dfs(rt,0,0);
	rep(j,1,19)rep(i,1,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	rep(i,1,n)mn[i][0]=a[i];rep(i,0,19)mn[0][i]=1e9;
	rep(j,1,19)rep(i,1,n)mn[i][j]=min(mn[i][j-1],mn[fa[i][j-1]][j-1]);
	rep(u,1,n)if(u!=rt){
		ll now=1e10;int x=fa[u][0];
		rep(i,0,19)umin(now,1LL*mn[x][i]*(i+1)+a[u]);
		res+=now;
	}
	cout<<res;return 0;
}