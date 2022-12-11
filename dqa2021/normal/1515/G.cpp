#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
#define gcd __gcd

int n,m;

struct E{
	int t,n,v;
}e[200010];
int cnt,last[200010];
inline void addedge(int x,int y,int v){
	e[++cnt]=(E){y,last[x],v},last[x]=cnt;
}

int dfn[200010],low[200010];
ll dis[200010],g[200010];
bool vis[200010];
int stk[200010];
int id[200010];

void tarjan(int x,ll d){
	dis[x]=d;
	dfn[x]=low[x]=++*dfn;
	vis[x]=1,stk[++*stk]=x;
	for (int i=last[x],v;i;i=e[i].n)
		if (!dfn[v=e[i].t]){
			tarjan(v,d+e[i].v);
			low[x]=min(low[x],low[v]);
		}
		else if (vis[v]){
			low[x]=min(low[x],dfn[v]);
//			g[x]=gcd(g[x],dis[x]+e[i].v-dis[v]);
		}
	if (low[x]^dfn[x]) return;
	do{
		const int &u=stk[*stk];
//		g[x]=gcd(g[x],g[u]);
		vis[u]=0; id[u]=x;
	}while (stk[(*stk)--]^x);
}

void dfs(int x){
	vis[x]=1;
	for (int i=last[x],v;i;i=e[i].n){
		v=e[i].t;
		if (!vis[v]) dfs(v);
		if (id[x]==id[v]) g[id[x]]=gcd(g[id[x]],dis[x]+e[i].v-dis[v]);
	}
}

void solve(){
	n=read(),m=read();
	while (m--){
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	rep(i,1,n) if (!dfn[i]) tarjan(i,0);
	rep(i,1,n) if (!vis[i]) dfs(i);
	int Q=read();
	while (Q--){
		int x=read();
		ll s=read(),t=read();
//		s=(t-s)%t;
		s=gcd(s,t);
		puts(s%gcd(g[id[x]],t)?"NO":"YES");
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}