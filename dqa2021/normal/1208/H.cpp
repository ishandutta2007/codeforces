#include<bits/stdc++.h>
#define pb emplace_back
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
#define forall(x,y,e) for (const auto &y: e[x])
const int S=888;  // larger ?

int n,K,q;
vector<int> g[100010];
vector<P> e[100010];
int c[100010];

struct D{
	int o,x,y;
}d[100010];

bool mrk[100010];

int rt[100010];
int dp[100010][2];
vector<int> H[100010];
int mn[100010],mx[100010];
int b[100010];  // red blue

void predfs(int x,int f){
	if (~c[x]) return;
	int L=0;
	forall(x,y,g) if (y^f){
		predfs(y,x);
		L=max(L,int(g[y].size())-1);
	}
	mn[x]=-L,mx[x]=L;
	H[x].resize(L+1<<1);
}

inline int geth(const vector<int> &H,int mn,int mx,int w,const int p=-1e9){
	int z=w;
	per(i,0,H.size()-1){
		z=max(z,min(mn+i,w+H[i]+(int(i<=p)<<1)));
	}
	return z;
}

int dfn[100010];

void dfs0(int x,int f){
	int tot=0,lst=-1,z=-1;
	forall(x,y,g) if (y^f){
		dfs0(y,x);
		if (rt[y]) ++tot,lst=rt[y],z=y;
	}
	auto &H=::H[x]; fill(all(H),0);
	const int &mn=::mn[x],&mx=::mx[x]; int &b=::b[x]; b=0;
	if (mrk[x]||tot>=2){
		dfn[++*dfn]=x;
		rt[x]=x; e[x].clear();
		forall(x,y,g) if (y^f)
			if (rt[y]) e[x].pb(rt[y],y);
		if (~c[x]) return;
		
		forall(x,y,g) if (y^f&&!rt[y]){
			if (~c[y]) b+=c[y]?1:-1;
			else H[dp[y][0]-mn]+=2,b--;
		}
		per(i,0,H.size()-2) H[i]+=H[i+1];
	}
	else{
		if (tot==1){
			rt[x]=lst;
			forall(x,y,g) if (y^f&&!rt[y]){
				if (~c[y]) b+=c[y]?1:-1;
				else H[dp[y][0]-mn]+=2,b--;
			}
			per(i,0,H.size()-2) H[i]+=H[i+1];
			if (z==lst){
				dp[x][0]=geth(H,mn,mx,b-1);
				dp[x][1]=geth(H,mn,mx,b+1);
			}
			else{
				dp[x][0]=geth(H,mn,mx,b-1,dp[z][0]-mn);
				dp[x][1]=geth(H,mn,mx,b-1,dp[z][1]-mn);
			}
		}
		else{
			rt[x]=0;
			if (~c[x]) return;
			forall(x,y,g) if (y^f){
				if (~c[y]) b+=c[y]?1:-1;
				else H[dp[y][0]-mn]+=2,b--;
			}
			per(i,0,H.size()-2) H[i]+=H[i+1];
			dp[x][0]=geth(H,mn,mx,b);
		}
	}
}

int w[100010];

inline void dfs1(int x){  // caution inline
	if (~c[x]) return w[x]=c[x],void();
	int b=::b[x];
	forall(x,o,e){
		int y,z; tie(y,z)=o;
//		dfs1(y);
		if (y^z) b+=K<=dp[z][w[y]]?1:-1;
		else b+=w[y]?1:-1;
	}
	b+=H[x][max(min(K,mx[x]+1),mn[x])-mn[x]];
	w[x]=b>=K;
}

void work(int l,int r){
	memset(mrk+1,0,n); *dfn=0;
	rep(i,l,r){
		const D &w=d[i];
		if (w.o^3) mrk[w.x]=1;
	}
	dfs0(1,0);
	rep(i,l,r){
		const D &w=d[i];
		if (w.o==1){
			rep(j,1,*dfn) dfs1(dfn[j]);
//			dfs1(rt[1]);
			printf("%d\n",::w[w.x]);
		}
		else if (w.o==2) c[w.x]=w.y;
		else K=w.x;
	}
}

void solve(){
	n=read(),K=read();
	rep(i,2,n){
		int u=read(),v=read();
		g[u].pb(v),g[v].pb(u);
	}
	g[1].pb(0);
	rep(i,1,n) c[i]=read();
	predfs(1,0);
	q=read();
	rep(i,1,q){
		D &w=d[i];
		w.o=read();
		w.x=read();
		if (w.o==2) w.y=read();
	}
	for (int i=1,j;i<=q;i=j+1){
		j=min(q,i+S-1);
		work(i,j);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}