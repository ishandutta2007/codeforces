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
const int N = 1020000,mo=1e9+7;
int n,fac[N],ifac[N],m;
int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}
int main() {
	read(n);read(m);int mx=N-1;
	fac[0]=1;rep(i,1,mx)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[mx]=power(fac[mx],mo-2);per(i,mx-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	ll res=0;
	rep(k,1,min(m,n-1))
		res=(res+1LL*C(m-1,k-1)*(k+1)%mo*power(n,(n-2-k+mo-1)%(mo-1))%mo*power(m,n-1-k)%mo*C(n-2,k-1)%mo*fac[k-1]%mo)%mo;
	res=(res%mo+mo)%mo;
	cout<<res;
	return 0;
}