#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 205000, mo = 1e9+7;
int n,m,w[N],fac[N],ifac[N];
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0?x:x+mo;}
inline int C(int n, int m) {
	if (m>n||m<0) return 0;
	return 1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo;
}
inline int f(int a, int b) {
	if (a==0) return b==0;
	return C(b-1,a-1);
}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
inline int S(int n, int m) {
	ll res=0;
	rep(i,1,m) res+=1LL*power(i,n)*C(m,i)%mo*((m-i)%2 ? -1 : 1);
	return (res%mo+mo)%mo*ifac[m]%mo;
}
int main() {
	ll ans=0;
	read(n); read(m); rep(i,1,n) read(w[i]),ans+=w[i]; ans%=mo;
	fac[0]=1; rep(i,1,n) fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=inv(fac[n]); per(i,n-1,0) ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	ll res=0; res=S(n,m)+1LL*(n-1)*S(n-1,m)%mo; res%=mo;
	printf("%lld",res*ans%mo);
	return 0;
}