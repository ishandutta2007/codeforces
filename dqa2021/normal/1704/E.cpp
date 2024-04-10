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

//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])


int n,m,a[1010],d[1010];
vector<int> e[1010];

struct C{
	int t,L,w;
};
C operator+(const C &x,const C &y){
	assert(x.t+x.L>=y.t);
	return {x.t,min(mod,x.L+y.L),upd(x.w+y.w-mod)};
}
bool chk(const C &x,const C &y){
	return x.t+x.L>=y.t;
}
vector<C> c[1010];

void work(int o){
	auto S=c[o]; c[o].clear();
	if (a[o]) S.pb((C){0,min(a[o],mod),a[o]%mod});
	sort(all(S),[](const C &x,const C &y){return x.t>y.t;});
	while (S.size()){
		if (S.size()>1&&chk(S.back(),S[S.size()-2]))
			S[S.size()-2]=S.back()+S[S.size()-2];
		else c[o].pb(S.back());
		S.pop_back();
	}
	S=c[o];
	for (auto &x: S) ++x.t;
	forall(o,v){
		c[v].insert(c[v].end(),all(S));
	}
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) a[i]=read(),e[i].clear(),d[i]=0,c[i].clear();
	while (m--){
		int u=read(),v=read();
		++d[v]; e[u].pb(v);
	}
	static int q[1010]; int hd=0,tl=0;
	rep(i,1,n) if (!d[i]) q[++tl]=i;
	while (hd<tl){
		int u=q[++hd];
		for (int v: e[u])
			if (!--d[v]) q[++tl]=v;
	}
	assert(tl==n);
	rep(i,1,n) work(q[i]);
	if (c[q[n]].empty()) return puts("0"),void();
	const auto z=c[q[n]].back();
	printf("%d\n",upd(z.t+z.w-mod));
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}