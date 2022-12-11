#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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

int n,a[100010];
int dp[100010],tag;

int f[100010],g[100010];

void add1(int x,int v){
	for (++x;x<=n+1;x+=x&-x) f[x]=min(f[x],v);
}
int ask1(int x){
	int res=1e9;
	for (++x;x;x-=x&-x) res=min(res,f[x]);
	return res;
}
void add2(int x,int v){
	for (++x;x;x-=x&-x) g[x]=min(g[x],v);
}
int ask2(int x){
	int res=1e9;
	for (++x;x<=n+1;x+=x&-x) res=min(res,g[x]);
	return res;
}

void solve(){
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	n=read();
	rep(i,1,n) a[i]=read(),dp[i]=1e8;
	dp[0]=1;
	rep(i,0,n) add1(i,dp[i]),add2(i,dp[i]);
	rep(i,2,n){
		if (a[i]==a[i-1]) continue;
		int x=min(ask1(a[i]-1),ask2(a[i]+1))+tag,y=dp[a[i]]+tag;
		tag++;
		dp[a[i-1]]=min(dp[a[i-1]],min(x+1,y)-tag);
		add1(a[i-1],dp[a[i-1]]),add2(a[i-1],dp[a[i-1]]);
	}
	int ans=ask2(0)+tag;
//	rep(i,0,n) ans=min(ans,dp[i]+tag);
	printf("%d\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}