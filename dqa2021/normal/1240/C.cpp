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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const auto &y: e[x])

int n,m;
vector<P> e[500010];
ll dp[500010][2];

void dfs(int x,int f){
	ll *F=dp[x]; ll T=0;
	vector<ll> S;
	forall(x,o){
		int y,w; tie(y,w)=o;
		if (y==f) continue;
		dfs(y,x);
		T+=dp[y][0];
		S.pb(max(0LL,dp[y][1]+w-dp[y][0]));
//		printf("debug %d - %d: w %lld d %lld\n",x,y,dp[y][0],max(0LL,dp[y][1]+w-dp[y][0]));
	}
	sort(all(S),greater<ll>());
//	for (ll w: S) printf("w %lld at %d\n",w,x);
//	printf("w0 %lld\n",T);
	F[0]=F[1]=T;
	rep(i,0,min(m,int(S.size()))-1) F[0]+=S[i];
	rep(i,0,min(m-1,int(S.size()))-1) F[1]+=S[i];
//	printf("test dp %d: %lld %lld\n",x,F[0],F[1]);
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) e[i].clear();
	rep(i,2,n){
		int u=read(),v=read(),w=read();
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	dfs(1,0);
	printf("%lld\n",dp[1][0]);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}