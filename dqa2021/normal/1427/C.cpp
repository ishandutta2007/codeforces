#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef long long ll;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int r,n;
int t[100010],X[100010],Y[100010];
int dp[100010],pre[100010];
void solve(){
	r=read(),n=read();
	t[0]=0,X[0]=Y[0]=1;
	rep(i,1,n){
		t[i]=read(),X[i]=read(),Y[i]=read();
		int &V=dp[i]; V=-1e9;
		int j;
		for (j=i-1;j>=0&&t[i]-t[j]<=r+r-2;j--)
			if (t[i]-t[j]>=abs(X[i]-X[j])+abs(Y[i]-Y[j]))
				V=max(V,dp[j]+1);
		if (j>=0) V=max(V,pre[j]+1);
		pre[i]=max(pre[i-1],dp[i]);
	}
	int res=-1e9;
	rep(i,0,n) res=max(res,dp[i]);
	printf("%d\n",res);
}
int main()
{
	for (int T=1;T--;) solve();
}