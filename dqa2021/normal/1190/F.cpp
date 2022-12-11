#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;

#define DEBUG
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
typedef __int128 lll;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
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

int n; ll p,m; ll a; int k;
ll phi;

ll qpow(ll x,ll y,const ll p){
	ll z=1;
	for (;y;y>>=1,x=lll(x)*x%p)
		if (y&1) z=lll(z)*x%p;
	return z;
}

namespace P_R{


bool m_r(ll x){
	if (x==1) return 0;
	if (x==2) return 1;
	if (x%2==0) return 0;
	ll s=x-1; int t=0;
	while (s%2==0) s>>=1,++t;
	static int prm[]={2,3,11,61,233};
	rep(e,0,4){
		const int &p=prm[e];
		if (p>=x) break;
		ll c=qpow(p,s,x),d;
		rep(_,1,t){
			d=c; c=lll(c)*c%x;
			if (c==1&&d!=x-1&&d!=1) return 0;
		}
		if (c!=1) return 0;
	}
	return 1;
}

mt19937 rnd(20210703);
uniform_int_distribution<ll> dist(0,1LL<<60);

ll p_r(const ll x){
	ll s=dist(rnd)%x,t=s,c=dist(rnd)%(x-1)+1;
	for (int g=1;;g<<=1,s=t){
		ll z=1;
		rep(i,1,g){
			t=(lll(t)*t+c)%x;
			z=lll(z)*(t<s?s-t:t-s)%x;
			if (i%127==0||i==g){
				z=gcd(z,x);
				if (z>1) return z;
			}
		}
	}
}


vector<ll> D;
void __div(ll x){
	if (x==1) return;
	if (m_r(x)) return D.pb(x),void();
	ll d; do d=p_r(x); while (d==x);
	while (x%d==0) x/=d;
	__div(x); __div(d);
}
void div(ll x){
	D.clear();
	__div(x);
	sort(all(D));
	D.erase(unique(all(D)),D.end());
}

}
using P_R::D;


ll getord(ll x){
	phi=m/a*(a-1);
	P_R::div(phi);
//	debug("phi %lld\n",phi);
	static int q=D.size();
	static ll d[128]; static int c[128];
	ll y(phi);
	rep(i,0,q-1){
		d[i]=D[i];
		while (y%d[i]==0) y/=d[i],++c[i];
	}
	vector<ll> G;
	static function<void(int,ll)> dfs=[&](int x,ll w){
		if (x==q) return G.pb(w);
		rep(i,0,c[x]) {if (i) w*=d[x]; dfs(x+1,w);}
	};
	dfs(0,1);
	sort(all(G));
//	rep(i,0,D.size()-1) debug("  d %lld c %d\n",d[i],c[i]);
//	for (ll g: G) debug("  g %lld\n",g);
	for (ll g: G) if (qpow(x,g,m)==1) return g;
	assert(0); return -1;
}

ll check_ord(ll x,ll ord){
	return qpow(x,ord,m)!=1;
}

int ord2(ll x){
	int t=0; ll y=x;
	while (y!=1) y=lll(y)*y%m,++t;
	return t;
}
int _ord2(ll x,int o){
	int t=0; ll y=x;
	while (t<=o&&y!=1) y=lll(y)*y%m,++t;
	return t;
}
int ox; ll pw[128];
bool check2(ll y){
//	debug("check2 %lld %lld\n",x,y);
	int oy=_ord2(y,ox);
//	debug("  ox %d oy %d\n",ox,oy);
//	debug("  x' %lld y' %lld\n",x%(1LL<<k-ox+1),y%(1LL<<k-oy+1));
	if (oy>ox) return 1;
	return pw[oy]!=(y&(-1+(1LL<<k-oy+1)));
}

void print(const vector<ll> &S){
	for (ll x: S) printf("%lld ",x);
	puts("");
}

void solve(){
	n=read(),m=read(),p=read();
	P_R::div(m); a=D[0];
	for (ll o(m);o^1;o/=a,++k);
	debug("a %lld k %d\n",a,k);
	if (gcd(p,m)>1){
		vector<ll> S;
		for (int i=2;i<m&&int(S.size())<n;++i)
			if (i%a)
				S.pb(i);
		if (int(S.size())<n) puts("-1");
		else print(S);
		return;
	}
	if (a&1){
		if (m<=1e7){
			static bool vis[10000010];
			for (int o(1);!vis[o];vis[o]=1,o=1LL*o*p%m);
			vector<ll> S;
			for (int i=0;i<m&&int(S.size())<n;++i)
				if (!vis[i]&&i%a) S.pb(i);
			if (int(S.size())<n) puts("-1");
			else print(S);
			return;
		}
		vector<ll> S;
		ll ord=getord(p);
		if (ord==phi);
		else{
			for (int i=1;i<m&&int(S.size())<n;++i)
				if (i%a&&check_ord(i,ord)) S.pb(i);
		}
		if (int(S.size())<n) puts("-1");
		else print(S);
		return;
	}
	if (p==1){
		vector<ll> S;
		for (int i=3;i<m&&int(S.size())<n;i+=2) S.pb(i);
		if (int(S.size())<n) puts("-1");
		else print(S);
		return;
	}
	if (p==m-1){
		vector<ll> S;
		for (int i=3;i<m-1&&int(S.size())<n;i+=2) S.pb(i);
		if (int(S.size())<n) puts("-1");
		else print(S);
		return;
	}
	ox=ord2(p);
	rep(oy,0,ox) pw[oy]=qpow(p%(1LL<<k-ox+1),1LL<<ox-oy,m)%(1LL<<k-oy+1);
	vector<ll> S={m-1};
	for (int i=3;i<m-1&&int(S.size())<n;i+=2)
		if (check2(i)) S.pb(i);
	if (int(S.size())<n) puts("-1");
	else print(S);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}