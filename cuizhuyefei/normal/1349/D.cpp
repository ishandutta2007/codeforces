#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 366666, mo = 998244353, inv2 =(mo+1)/2;
const ll MOD=7LL*mo*mo;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int n,m,a[N],f[N],res;Pii dp[N];
Pii operator+(Pii a, Pii b){return mp((a.fi+b.fi)%mo,(a.se+b.se)%mo);}
Pii operator-(Pii a, Pii b){return mp((a.fi-b.fi+mo)%mo,(a.se-b.se+mo)%mo);}
Pii operator*(Pii a, int b){return mp((1ll*a.fi*b)%mo,(1ll*a.se*b)%mo);}
int main() {
	read(n);rep(i,1,n)read(a[i]),m+=a[i];
	dp[m-1]=mp(1,0);
	int x=0;
	per(i,m-1,0){
		Pii tmp=dp[i]-mp(0,1)-(dp[i+1]*power(n-1,mo-2)+dp[i]*(1-power(n-1,mo-2)+mo))*(1ll*(m-i)*power(m,mo-2)%mo);
		if(i)dp[i-1]=tmp*(1ll*m*power(i,mo-2)%mo);
		else x=1ll*(mo-tmp.se)*power(tmp.fi,mo-2)%mo;
	}
	rep(i,0,m-1)f[i]=(1ll*x*dp[i].fi+dp[i].se)%mo;
	res=1ll*f[0]*(1-n+mo)%mo;rep(i,1,n)add(res,f[a[i]]);
	res=1ll*res*power(n,mo-2)%mo;
	cout<<res;
	return 0;
}