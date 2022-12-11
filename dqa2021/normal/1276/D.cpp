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

const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n;
P w[200010];
vector<int> e[200010];

vector<P> f[200010];  // presum
int g[200010];

inline int getsum(const vector<P> &f,int t){
	int p=lower_bound(all(f),P(t,0))-f.begin();
	return f[p].se;
}

inline int getpos(const vector<P> &f,int t){
	int p=lower_bound(all(f),P(t,0))-f.begin();
	return upd(f[p].se-(p?f[p-1].se:0));
}

void dfs(int x,int fa){
	forall(x,o){
		const int y=w[o].fi^w[o].se^x;
		if (y==fa) continue;
		dfs(y,x);
	}
	g[x]=1;
	forall(x,o){
		const int y=w[o].fi^w[o].se^x;
		if (y==fa) continue;
		g[x]=1LL*g[x]*getsum(f[y],o)%mod;
	}
	static int T[200010]; int W=1;
	per(_,0,e[x].size()-1){
		const int o=e[x][_];
		const int y=w[o].fi^w[o].se^x;
		T[y]=W;
		if (y^fa){
			W=1LL*W*upd(g[y]+upd(f[y].back().se-getpos(f[y],o))-mod)%mod;
		}
	}
	int S=1;
	forall(x,o){
		const int y=w[o].fi^w[o].se^x;
		if (y!=fa){
			W=g[y]; add(W,f[y].back().se);
			iadd(W,getsum(f[y],o));
			f[x].emplace_back(o,1LL*S*W%mod*T[y]%mod);
			S=1LL*S*getsum(f[y],o)%mod;
		}
		else{
			W=1;
			f[x].emplace_back(o,1LL*S*W%mod*T[y]%mod);
		}
	}
	rep(i,1,f[x].size()-1) add(f[x][i].se,f[x][i-1].se);
}

void solve(){
	n=read();
	rep(i,1,n-1){
		int u=read(),v=read();
		w[i]=P(u,v);
		e[u].pb(i),e[v].pb(i);
	}
	dfs(1,0);
	int z=g[1]; add(z,f[1].back().se);
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}