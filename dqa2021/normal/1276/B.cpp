#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

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
#define forall(x,y,e) for (const int &y: e[x])

int n,m,A,B;
vector<int> e[200010],g[400010];

int dfn[200010],low[200010],idtot;
int stk[200010];

void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x;
	forall(x,y,e)
		if (!dfn[y]){
			int t=*stk;
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if (low[y]>=dfn[x]){
				++idtot;
				g[x].pb(idtot),g[idtot].pb(x);
				while (t^*stk){
					int u=stk[*stk]; --*stk;
					g[idtot].pb(u),g[u].pb(idtot);
				}
			}
		}
		else low[x]=min(low[x],dfn[y]);
}

int tot[400010];

void dfs(int x,int f){
	tot[x]=x<=n;
	forall(x,y,g) if (y^f){
		dfs(y,x);
		tot[x]+=tot[y];
	}
}

void solve(){  // init
	n=read(),m=read(),A=read(),B=read();
	rep(i,1,n) e[i].clear();
	rep(i,1,n<<1) g[i].clear();
	while (m--){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	memset(dfn,0,n+1<<2);
	idtot=n;
	*stk=0;
	tarjan(1);
	dfs(A,0); int z=tot[B]-1;
	dfs(B,0);
	printf("%lld\n",1LL*z*(tot[A]-1));
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}