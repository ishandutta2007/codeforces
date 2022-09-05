#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2000002, mo = 998244353, inv2 =(mo+1)/2;
const ll MOD=7LL*mo*mo;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int fac[N],ifac[N],n,a[N],res,mrk[N];
void iniC(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);
	per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
inline int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}

int main() {
	iniC(N-1);read(n);rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1);
	rep(p,1,n)if(a[p]<p-1){
		for(int t=0,s=0;t<=p-2;t++){
			while(s+1<=n&&a[s+1]<t)s++;
			res=(res+C(t+n-s-1,n-1))%mo;
		}
		cout<<res;
		return 0;
	}
	ll x=0;rep(i,1,n)x+=a[i]/n,mrk[n-a[i]%n]++;
	
	rep(t,0,n-1){
		x+=1LL*mrk[t];
	//	cerr<<t<<' '<<x-1LL*n*t+n-1<<endl;
		res=(res+C(x-t+n-1,n-1))%mo;
	}
	cout<<res;
	return 0;
}