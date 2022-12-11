#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()

int n,h[300010],b[300010];
ll dp[300010];
void solve(){
	n=read();
	rep(i,1,n) h[i]=read();
	rep(i,1,n) b[i]=read();
	dp[0]=0;
	static int que[300010];
	static ll w[300010],s[300010];
	s[0]=-1e18;
	int hd=1,tl=0;
	rep(i,1,n){
		ll W=dp[i-1];
		while (hd<=tl&&h[que[tl]]>h[i]) W=max(W,w[tl]),--tl;
		que[++tl]=i; w[tl]=W,s[tl]=max(s[tl-1],w[tl]+b[i]);
		dp[i]=s[tl];
	}
	printf("%lld\n",dp[n]);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}