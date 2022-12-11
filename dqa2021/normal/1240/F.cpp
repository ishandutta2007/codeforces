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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m,k;
int c[1010];

struct E{
	int t,n;
}e[2010];
int cnt=1,last[2010];
inline void addedge(int x,int y){
	e[++cnt]=(E){y,last[x]},last[x]=cnt;
	e[++cnt]=(E){x,last[y]},last[y]=cnt;
}

int N;
int h[2010][1010];

void dfs(int x,int P,int Q){
	swap(h[x][P],h[x][Q]);
	if (!h[x][Q]) return;
	c[h[x][Q]>>1]=Q;
	dfs(e[h[x][Q]].t,Q,P);
}

void work(int x,int y,int o){
	int P=-1,Q=-1;
	rep(i,1,k){
		if (!h[x][i]&&!h[y][i]){
			h[x][i]=o<<1,h[y][i]=o<<1|1;
			c[o]=i; return;
		}
		if (!h[x][i]) P=i;
		if (!h[y][i]) Q=i;
	}
	assert(~P&&~Q);
	h[x][P]=o<<1; c[o]=P;
	h[y][Q]=o<<1|1;
	dfs(y,P,Q);
}

typedef pair<int,int> P;
P g[1010];
int id[210];
int d[210];

void solve(){
	n=read(),m=read(),k=read();
	if (k==1){
		rep(i,1,m) puts("1");
		return;
	}
	rep(i,1,n) read();
	rep(i,1,m){
		int x=read(),y=read()+n;
		++d[x],++d[y];
		if (d[x]%k==1) id[x]=++N;
		if (d[y]%k==1) id[y]=++N;
		addedge(id[x],id[y]);
		g[i]={id[x],id[y]};
	}
	rep(i,1,m) work(g[i].fi,g[i].se,i);
	rep(i,1,m) printf("%d\n",c[i]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}