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
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<ull,ull> Pii;
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
const int N = 666666;const ull mo = 8e18;
ull f[N];int n=1.5e5;
inline int power(int a, int n, int mo) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
ull mul(ull a, ull b, ull mo){
	ull res=0;
	while(b){
		if(b&1)res=(res+a)%mo;a=(a+a)%mo;b>>=1;
	}
	return res;
}
Pii merge(Pii f, Pii g){
	return Pii((mul(f.fi,g.fi,mo)+mul(f.se,g.se,mo))%mo,(mul(f.fi,g.se,mo)+mul(f.se,(g.fi-g.se+mo),mo))%mo);
}
ull qry(ll n){
	if(n<0)return 0;
	Pii res(1,0),a(1,1);
	while(n){
		if(n&1)res=merge(res,a);
		a=merge(a,a);n>>=1;
	}
	return res.fi;
}
int main() {
	f[1]=1;rep(i,2,n)f[i]=(f[i-1]+f[i-2])%mo;
//	assert((f[1]-f[12001])%1000==0);
//	assert((f[1]-f[120001])%10000==0);
//	rep(i,1,1270)printf("%d %lld\n",i,f[i]);
	cerr<<qry(12e9)<<endl;
//	int t=358225649;
	int t=84177449;
	int invt=power(t,4e8-1,1e9);
	int c=125ll*invt%1000000000;
	cerr<<c<<endl;
	ull n=12e9;
	ull a,d;read(a);read(a);read(d);
	cout<<(ull)c*a%1000000000*n+1<<' '<<(ull)c*d%1000000000*n;
	return 0;
}