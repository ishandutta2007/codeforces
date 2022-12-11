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

int n,A,B;
char s[5010];
int nxt[5010];
int dp[5010];

void chk(int &x,int y){
	if (y<x) x=y;
}

int lcp[5010][5010];

void solve(){
	scanf("%d%d%d%s",&n,&A,&B,s+1);
	memset(dp,0x3f,sizeof dp); dp[0]=0;
	per(i,1,n) per(j,1,n){
		if (s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
	}
	rep(i,1,n){
		const int &U=dp[i-1];
		chk(dp[i],U+A);
		int t=0;
		rep(j,1,i-1) t=max(t,min(i-j,min(n-i+1,lcp[i][j])));
		chk(dp[i+t-1],U+B);
//		printf("dp %d = %d  t %d\n",i,dp[i],t);
	}
	printf("%d\n",dp[n]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}