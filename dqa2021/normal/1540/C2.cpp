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

const int mod=1e9+7;
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

int n,c[110],b[110];

int dp[110][10010];
int work(int x){
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	rep(i,1,n){
		const auto G=dp[i-1];
		auto F=dp[i];
		const int B=(x*i+b[i]);
		rep(j,0,(i-1)*100){
			const int &V=G[j];
			if (!V) continue;
			const int l=max(0,B-j),r=c[i];
			if (l>r) continue;
			add(F[j+l],V); iadd(F[j+r+1],V);
		}
		rep(j,1,i*100) add(F[j],F[j-1]);
	}
	int z=0;
	rep(j,0,n*100) add(z,dp[n][j]);
	return z;
}

void solve(){
	n=read();
	rep(i,1,n) c[i]=read();
	rep(i,2,n) b[i]=read();
	rep(i,2,n) b[i]+=b[i-1];
	rep(i,2,n) b[i]+=b[i-1];
	int L=1e9,R=1e9;
	rep(i,1,n) R=min(R,(int)floor((100.0*i-b[i])/i));
	rep(i,1,n) L=min(L,(int)floor((-1.0-b[i])/i));
	static int dp[210];
	rep(i,L,R) dp[i-L]=work(i);
	int q=read();
	while (q--){
		int x=read(); x=max(x,L); x=min(x,R+1);
		printf("%d\n",dp[x-L]);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}