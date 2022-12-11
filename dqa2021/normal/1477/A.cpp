#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
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

int n; ll k;
ll a[200010];
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
void solve(){
	n=read(),k=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	ll g=0;
	rep(i,1,n-1) g=gcd(g,a[i+1]-a[i]);
	puts((a[1]-k)%g==0?"YES":"NO");
}
int main()
{
	for (int T=read();T--;) solve();
}