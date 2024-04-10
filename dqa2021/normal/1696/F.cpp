#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n;
bitset<128> mp[110][110];

char s[110];
void read(bitset<128> &mp){
	mp.reset();
	rep(i,1,n) mp[i]=s[i]=='1';
}

vector<P> E;
bool vis[110];
void dfs(int o,int f){
	vis[o]=1;
	rep(i,1,n)
		if (!vis[i]&&mp[i][f][o])
			E.eb(o,i),dfs(i,o);
}

int dis[110][110];
vector<int> g[110];
void dfs2(int o,int f,int r,int d){
	dis[o][r]=d;
	for (int x: g[o]) if (x^f)
		dfs2(x,o,r,d+1);
}

bool check(){
	rep(i,1,n) g[i].clear();
	for (const P &w: E) g[w.fi].pb(w.se),g[w.se].pb(w.fi);
	rep(i,1,n) dfs2(i,0,i,0);
	rep(i,1,n) rep(j,i+1,n) rep(k,1,n)
		if ((dis[i][k]==dis[j][k])^bool(mp[i][j][k])) return 0;
	puts("yes");
	for (const P &w: E) printf("%d %d\n",w.fi,w.se);
	return 1;
}

bool work(int u,int v){
	memset(vis,0,sizeof vis);
	vis[u]=vis[v]=1;
	E.clear();
	E.eb(u,v);
	rep(i,1,n){
		if (vis[i]) continue;
		if (mp[i][v][u]) E.eb(u,i),dfs(i,u);
		else if (mp[i][u][v]) E.eb(v,i),dfs(i,v);
	}
	if (int(E.size())!=n-1) return 0;
	return check();
}

void solve(){
	n=read();
	rep(i,1,n) rep(j,i+1,n) scanf("%s",s+1),read(mp[i][j]),read(mp[j][i]);
	rep(i,2,n) if (work(1,i)) return;
	puts("no");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}