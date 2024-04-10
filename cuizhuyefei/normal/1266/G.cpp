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
const int N = 2e6+11,mo=998244353;
int n,c[N];
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

int fac[N],ifac[N];
void iniC(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);
	per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
inline int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}
int qry(int n, int i){
	if(i==n-1)return n;
	if(i==n)return 1ll*(n-1)*(n-2)%mo;
	if(i==n+1)return (1ll*(n-2)*(n-3)%mo*n+n-2)%mo;
	int x=i-n-1;
	return 1ll*qry(n-x,i-2*x)*fac[n]%mo*ifac[n-x]%mo;
}
int main() {
	read(n);iniC(2*n);
	rep(i,n-1,2*n-2)c[i]=qry(n,i);//,printf("%d\n",c[i]);
	int res=0;
	rep(i,n-1,2*n-2)res=(res+1ll*n*(i+i-n+1)%mo*c[i])%mo;
	int t=1ll*n*fac[n]%mo;
	cout<<((1ll*t*(t+1)/2-1ll*res*(mo+1)/2)%mo+mo)%mo;
	return 0;
}