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

const int N = 266666;
int n,m,fa[N],dep[N],insta[N],gg,gs[N],bian[N],ans[N],f[N];Vi e[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs1(int u, int Fa, int Dep){
	fa[u]=Fa;dep[u]=Dep;insta[u]=1;
	for(int v:e[u])if(!dep[v])dfs1(v,u,Dep+1);else if(!insta[v])gg=1;
	insta[u]=0;
}
void dfs2(int u){
	for(int v:e[u])if(fa[v]==u)dfs2(v),gs[u]+=gs[v];
}
void dfs(int u){
	if(!fa[u])ans[u]=1;
	else if(gs[u]==1)ans[u]=ans[bian[u]];
	for(int v:e[u])if(fa[v]==u)dfs(v);
}
int main() {
	int T;read(T);while(T--){
		int cs=100;
		read(n);read(m);
		rep(i,1,n)e[i].clear(),bian[i]=gs[i]=ans[i]=fa[i]=dep[i]=0;
		rep(i,1,m){
			int u,v;read(u);read(v);e[u].pb(v);
		}
		int rt=1;
		while(cs--){
			rt=R()%n+1;gg=0;
			rep(i,1,n)fa[i]=dep[i]=insta[i]=0;dfs1(rt,0,1);
			if(!gg)break;
		}
		if(cs==-1){puts("-1");continue;}
		rep(i,1,n)f[i]=i;
		rep(u,1,n)for(int v:e[u])if(fa[v]!=u){
			gs[u]++;gs[v]--;
			for(int x=find(u);dep[x]>dep[v];x=find(x))
				bian[x]=v,f[x]=fa[x];
		}
		dfs2(rt);
	//	rep(i,1,n)printf("%d %d %d\n",gs[i],bian[i],dep[i]);
		dfs(rt);
		Vi a;rep(i,1,n)if(ans[i])a.pb(i);
		if(SZ(a)*5<n)puts("-1");
		else{for(int x:a)printf("%d ",x);puts("");}
	}
	return 0;
}