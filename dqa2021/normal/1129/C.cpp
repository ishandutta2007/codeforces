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

int c[3010];
int n;

int w[3000*1500+10];
int ch[3000*1500+10][2],f[3000*1500+10];
int ctot=1;
int dp[3000*1500+10];

int W;
void work(int x){
	int &V=dp[x]; int msk=0;
	msk|=w[x]<<3; int y=f[x]; add(V,dp[y]);
	msk|=w[y]<<2; y=f[y]; add(V,dp[y]);
	msk|=w[y]<<1; y=f[y]; add(V,dp[y]);
	msk|=w[y]<<0; y=f[y];
	if (y&&msk!=3&&msk!=5&&msk!=14&&msk!=15) add(V,dp[y]);
	add(W,dp[x]);
}

void ins(int x){
	int o=1;
	per(i,1,x){
		int g=c[i];
		if (!ch[o][g]){
			ch[o][g]=++ctot,w[ctot]=g;
			f[ctot]=o;
			work(ctot);
		}
		o=ch[o][g];
	}
}

void solve(){
	n=read(); dp[1]=1;
	rep(i,1,n) c[i]=read();
	rep(i,1,n){
		ins(i);
		printf("%d\n",W);
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}