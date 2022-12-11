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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
vector<int> e[5010];
int dp[5010];

void solve(){
	n=read(),m=read();
	rep(i,1,m){
		int a=read()-1,b=read()-1;
		e[a].pb(b);
	}
	rep(i,0,n-1){
		int &w=dp[i]; w=1e9;
		if (e[i].empty()){
			w=-1e9; continue;
		}
		for (int x: e[i]) w=min(w,(x-i+n)%n);
		w+=int(e[i].size()-1)*n;
	}
	rep(i,0,n-1){
		int z=0;
		rep(j,0,n-1) z=max(z,dp[j]+(j-i+n)%n);
		printf("%d\n",z);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}