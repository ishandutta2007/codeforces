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
//typedef pair<int,int> P;
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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,m,h[200010],g[200010];
vector<int> e[200010]; int d[200010];
int p[200010],hd,tl;
int sg[200010];

int get(int o){
	static int vis[200010];
	forall(o,v) vis[sg[v]]=o;
	int z=0; while (vis[z]==o) ++z;
	return z;
}

void work(int o){
	//printf("work %d\n",o);
	h[o]^=g[sg[o]]; g[sg[o]]=0;
	forall(o,v){
		if (sg[v]>=sg[o]) continue;
		int w=g[sg[v]];
		h[v]^=w; g[sg[v]]^=w;
	}
	rep(i,1,n) printf("%d ",h[i]);
	puts("");
	
	//rep(i,0,n) printf("%d ",g[i]);
	//puts("");
	//rep(i,1,n) printf("sg %d = %d\n",i,sg[i]);
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) h[i]=read();
	while (m--){
		int u=read(),v=read();
		e[u].pb(v),++d[v];
	}
	rep(i,1,n) if (!d[i]) p[++tl]=i;
	while (hd<tl){
		int u=p[++hd];
		forall(u,v) if (!--d[v]) p[++tl]=v;
	}
	per(i,1,n) sg[p[i]]=get(p[i]),g[sg[p[i]]]^=h[p[i]];
	int q=-1;
	per(i,0,n) if (g[i]) {q=i; break;}
	if (!~q) return puts("LOSE"),void();
	puts("WIN");
	rep(i,1,n) if (sg[i]==q&&(g[sg[i]]^h[i])<h[i]){
		work(i); return;
	}
	assert(0);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}