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

const int N = 666666;
int n,m,res,ans[N];
struct A{
	Vi e[N];bool vis[N],fd;int dfn[N],num,sta[N],top,insta[N];
	void add(int u, int v){e[u].pb(v);}
	void dfs1(int u){
		sta[++top]=u;insta[u]=1;dfn[u]=++num;
		for(int v:e[u])if(!dfn[v])dfs1(v);
		else if(insta[v])fd=1;
		top--;insta[u]=0;
	}
	void dfs(int u){
		vis[u]=1;
		for(int v:e[u])if(!vis[v])dfs(v);
	}
	bool findcir(){
		rep(i,1,n)if(!dfn[i])dfs1(i);
		return fd;
	}
}a,b;
int main() {
	read(n);read(m);
	rep(i,1,m){
		int u,v;read(u);read(v);
		a.add(u,v);b.add(v,u);
	}
	if(a.findcir()){puts("-1");return 0;}
	rep(i,1,n)if(!a.vis[i]&&!b.vis[i])ans[i]=1,a.dfs(i),b.dfs(i),res++;
	else a.dfs(i),b.dfs(i);
	printf("%d\n",res);
	rep(i,1,n)putchar(ans[i]?'A':'E');
	return 0;
}