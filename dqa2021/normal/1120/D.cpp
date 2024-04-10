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
typedef pair<ll,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n;
int c[200010];
vector<int> e[200010];

ll f[200010],g[200010];

vector<P> S[200010];

void dfs(int x,int fa){
	if (fa&&e[x].size()==1){
		f[x]=c[x]; g[x]=0;
//		printf("test %d: f %lld g %lld\n",x,f[x],g[x]);
		return;
	}
	vector<P> &S=::S[x]; ll w=0;
	forall(x,y) if (y^fa){
		dfs(y,x);
		w+=f[y];
		S.emplace_back(g[y]-f[y],y);
	}
	sort(all(S));
	f[x]=w;
	f[x]=min(f[x],w+S[0].fi+c[x]);
	g[x]=w+S[0].fi;
//	if (S.size()>1) g[x]=min(g[x],w+S[0].fi+S[1].fi+c[x]);
//	printf("test %d: f %lld g %lld\n",x,f[x],g[x]);
//	printf("  ");
//	for (auto w: S) printf("%lld,%d  ",w.fi,w.se);
//	puts("");
}

vector<int> T;

bool s[200010],t[200010];

void dfs2(int x,int fa){
	if (fa&&e[x].size()==1){
		if (s[x]) T.pb(x);
		return;
	}
	const auto &S=::S[x];
	ll w=0;
	forall(x,y) if (y^fa) w+=f[y];
	if (s[x]){
		if (f[x]==w){
			forall(x,y) if (y^fa) s[y]=1;
		}
		if (S.size()&&f[x]==w+S[0].fi+c[x]){
			T.pb(x); const ll mn=S[0].fi;
			forall(x,y) if (y^fa){
				const ll h=g[y]-f[y];
				if (h>mn||h==mn&&S.size()>1&&S[1].fi==mn) s[y]=1;
				if (h==mn) t[y]=1;
			}
		}
	}
	if (t[x]){
		if (g[x]==w+S[0].fi){
			const ll mn=S[0].fi;
			forall(x,y) if (y^fa){
				const ll h=g[y]-f[y];
				if (h>mn||h==mn&&S.size()>1&&S[1].fi==mn) s[y]=1;
				if (h==mn) t[y]=1;
			}
		}
//		if (S.size()>1&&g[x]==w+S[0].fi+S[1].fi+c[x]){
//			T.pb(x);
//			const ll smn=S[1].fi;
//			forall(x,y) if (y^fa){
//				const ll h=g[y]-f[y];
//				if (h>smn||h==smn&&S.size()>2&&S[2].fi==smn) s[y]=1;
//				if (h<=smn) t[y]=1;
//			}
//		}
	}
	
	forall(x,y) if (y^fa) dfs2(y,x);
}

void solve(){
	n=read();
	rep(i,1,n) c[i]=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1,0);
	printf("%lld\n",f[1]);
	s[1]=1; dfs2(1,0);
	rep(i,1,n) if (!c[i]) T.pb(i);
	sort(all(T)); T.erase(unique(all(T)),T.end());
	printf("%d\n",int(T.size()));
	for (int x: T) printf("%d ",x);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}