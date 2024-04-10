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
const int N = 1<<18|3, mo = 998244353, inv2 =(mo+1)/2;
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

int fac[N],ifac[N];
void iniC(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);
	per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
inline int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}

inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0 ? x : x+mo;}
inline void fft(int *a, int n, int tp) {
	static int w[N];
	for (int i=1,j=0; i<n; i++) {
		for (int k=n>>1; !((j^=k)&k); k>>=1);
		if (i<j) swap(a[i],a[j]);
	}
	for (int j=2; j<=n; j<<=1) {
		w[0]=1; w[1]=power(3,(mo-1)/j); w[1]=tp==1?w[1]:inv(w[1]); int m=(j>>1)-1; //mo-1
		rep(i,2,m) w[i]=1LL*w[i-1]*w[1]%mo;
		for (register int i=0; i<n; i+=j) rep(k,0,m) {
			int x=1LL*a[i+k+(j>>1)]*w[k]%mo;
			a[i+k+(j>>1)]=a[i+k]-x>=0?a[i+k]-x:a[i+k]-x+mo;
			a[i+k]=a[i+k]+x<mo?a[i+k]+x:a[i+k]+x-mo;
		}
	}
}
inline void mul(int *_a, int *_b, int n1, int n2, int *c){
	static int a[N],b[N];int n;for(n=1;n<=n1+n2-2;n<<=1);
	if(n<=128){
		static ll _c[N];rep(i,0,n1-1+n2-1)_c[i]=0;
		rep(i,0,n1-1)rep(j,0,n2-1){
			_c[i+j]+=1LL*_a[i]*_b[j];
			_c[i+j]=_c[i+j]<MOD?_c[i+j]:_c[i+j]-MOD;
		}
		rep(i,0,n1-1+n2-1)c[i]=_c[i]%mo;
		return;
	}
	rep(i,0,n1-1)a[i]=_a[i];rep(i,n1,n-1)a[i]=0;//WA!
	rep(i,0,n2-1)b[i]=_b[i];rep(i,n2,n-1)b[i]=0;
	fft(a,n,1);fft(b,n,1);rep(i,0,n-1)a[i]=1LL*a[i]*b[i]%mo;
	int ni=inv(n);fft(a,n,-1);rep(i,0,n-1)c[i]=1LL*a[i]*ni%mo;
}
int n,f[N];ll m;
void solve(int xs){
	static int a[N],b[N];
	rep(i,0,n)a[i]=1ll*fac[i]*f[i]%mo,b[n-i]=1ll*ifac[i]*((xs>0||(~i&1))?1:mo-1)%mo;
	mul(a,b,n+1,n+1,a);
	rep(i,0,n)f[i]=1ll*a[i+n]*ifac[i]%mo;
}
int main() {
	iniC(N-1);read(n);read(m);rep(i,0,n)read(f[i]);
	solve(1);
	rep(i,0,n)f[i]=1ll*f[i]*power(i+1,-m%(mo-1)+mo-1)%mo;
	solve(-1);
	rep(i,0,n)printf("%d ",f[i]);
	return 0;
}