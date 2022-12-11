#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
uint getrand(){
	#ifdef ONLINE_JUDGE
	static uint sd=time(0);
	#else
	static uint sd=251457865U;
	#endif
	return sd^=sd>>13,sd^=sd<<28,sd^=sd>>24,sd^=sd<<7;
}
const int INF=1e9;

int n,m;
vector<int> e[100010];

bool inq[100010],vis[100010];

bool dfs0(int x){
	inq[x]=vis[x]=1;
	for (const int &y: e[x]){
		if (vis[y]&&!inq[y]) return 0;
		if (!vis[y]&&!dfs0(y)) return 0;
	}
	inq[x]=0; return 1;
}

int lk[100010];
bool ok[100010];

inline void check(P &x,const P &y){
	if (y.fi<x.fi) x.se=x.fi,x.fi=y.fi;
	else if (y.fi<x.se) x.se=y.fi;
	if (y.se<x.fi) x.se=x.fi,x.fi=y.se;
	else if (y.se<x.se) x.se=y.se;
}

inline void check(P &x,const int &y){
	if (y<x.fi) x.se=x.fi,x.fi=y;
	else if (y<x.se) x.se=y;
}

int dep[100010];

void dfs1(int x,int d){
	dep[x]=d; vis[x]=1;
	for (const int &y: e[x])
		if (!vis[y]) dfs1(y,d+1);
}

P dfs2(int x){
	vis[x]=1; ok[x]=1,lk[x]=-1;
	P z(INF,INF);
	for (const int &y: e[x]){
		if (vis[y]) check(z,dep[y]);
		else{
			check(z,dfs2(y));
		}
	}
	assert(z.fi<dep[x]);
	if (z.se<dep[x]) ok[x]=0;
	else lk[x]=z.fi;
	return z;
}

int stk[100010],top;
vector<int> S;

void dfs3(int x){
	stk[++top]=x; vis[x]=1;
	if (~lk[x]) ok[x]=ok[stk[lk[x]]];
	if (ok[x]) S.pb(x);
	for (const int &y: e[x])
		if (!vis[y]) dfs3(y);
	--top;
}

void check(int x){
	rep(i,1,n) vis[i]=0;
	dfs1(x,1);
	ok[x]=1,lk[x]=-1;
	rep(i,1,n) vis[i]=0;
	vis[x]=1;
	for (const int &y: e[x]) dfs2(y);
	rep(i,1,n) vis[i]=0;
	S.clear(); top=0; dfs3(x);
	if (S.size()*5<n) puts("-1");
	else{
		sort(all(S));
		for (int x: S) printf("%d ",x);
		puts("");
	}
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) e[i].clear();
	while (m--){
		int u=read(),v=read();
		e[u].pb(v);
	}
	rep(T,1,100){
		int x=getrand()%n+1;
		rep(i,1,n) inq[i]=vis[i]=0;
		if (dfs0(x)==0) continue;
		check(x); return;
	}
	puts("-1");
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}