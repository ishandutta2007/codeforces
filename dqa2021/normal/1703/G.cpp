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
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,k;
ll dp[2][35];
ll a[100010];

void solve(){
	n=read(),k=read();
	rep(i,1,n) a[i]=read();
	bool c=0;
	memset(dp[c],-0x3f,sizeof dp[c]);
	dp[c][0]=0;
	ll z=0;
	rep(i,1,n){
		c^=1;
		memset(dp[c],-0x3f,sizeof dp[c]);
		rep(j,0,32){
			dp[c][j]=max(dp[c][j],dp[c^1][j]-k+(a[i]>>j));
			dp[c][j+1]=max(dp[c][j+1],dp[c^1][j]+(a[i]>>j+1));
		}
		rep(j,0,32) z=max(z,dp[c][j]);
	}
	printf("%lld\n",z);
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}