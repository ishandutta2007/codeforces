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
const int N = 1<<18|3, mo = 998244353, inv2 =(mo+1)/2;
int n,w[N],a[N],b[N];
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
inline void exgcd(int a, int b, int &x, int &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline int inv(int a) {int x,y; exgcd(a,mo,x,y); return x>=0 ? x : x+mo;}
inline void fft(int *a, int n, int tp) {
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
	rep(i,0,n1)a[i]=_a[i];rep(i,n1+1,n-1)a[i]=0;
	rep(i,0,n2)b[i]=_b[i];rep(i,n2+1,n-1)b[i]=0;
	fft(a,n,1);fft(b,n,1);rep(i,0,n-1)a[i]=1LL*a[i]*b[i]%mo;
	int ni=inv(n);fft(a,n,-1);rep(i,0,n-1)c[i]=1LL*a[i]*ni%mo;
}
inline void getinv(int *a, int n, int *_b){
	static int b[N];
	rep(i,0,n)b[i]=0;b[0]=inv(a[0]);
	for(int nn=1;nn<n;nn<<=1){//[0,nn)-->[0,2nn)
		static int c[N],d[N];int sz=4*nn;
		rep(i,0,nn-1)c[i]=b[i];rep(i,nn,sz-1)c[i]=0;
		rep(i,0,2*nn-1)d[i]=a[i];rep(i,2*nn,sz-1)d[i]=0;
		fft(c,sz,1);fft(d,sz,1);
		rep(i,0,sz-1)c[i]=1LL*c[i]*c[i]%mo*d[i]%mo;
		fft(c,sz,-1);int ni=inv(sz);rep(i,0,sz-1)c[i]=1LL*c[i]*ni%mo;
		rep(i,0,2*nn-1)b[i]=((2LL*b[i]-c[i])%mo+mo)%mo;
	}
	rep(i,0,n-1)_b[i]=b[i];
}
inline void qiudao(int *a, int n, int *b){//a[0..n-1]
	rep(i,1,n-1)b[i-1]=1LL*a[i]*i%mo;b[n-1]=0;
}
inline void jifen(int *a, int n, int *b){
	b[0]=0;rep(i,0,n-1)b[i+1]=1LL*a[i]*inv(i+1)%mo;
}
inline void getln(int *a, int n, int *b){
	static int c[N];qiudao(a,n,c);
	static int d[N];getinv(a,n,d);
	static int e[N];mul(c,d,n,n,e);
	jifen(e,n,b);
}
inline void getexp(int *a, int n, int *_b){
	static int b[N];
	rep(i,0,n)b[i]=0;b[0]=1;
	for(int nn=1;nn<n;nn<<=1){//b[0..nn-1]-->b[0..2*nn-1]
		static int c[N];
		rep(i,nn,2*nn-1)b[i]=0;getln(b,nn*2,c);//b[0..nn-1]ln%x^(2nn) 
		rep(i,0,2*nn-1)c[i]=(a[i]-c[i]+mo)%mo;c[0]++;
		mul(b,c,nn,nn*2,b);
	}
	rep(i,0,n)_b[i]=b[i];
}
inline void getsqrt(int *a, int n, int *_b){
	static int b[N];
	assert(a[0]==1);b[0]=1;rep(i,1,n)b[i]=0;
	for(int nn=1;nn<n;nn<<=1){//[0..nn-1]-->[0..2*nn-1]
		static int c[N];
		rep(i,0,nn-1)c[i]=b[i];rep(i,nn,2*nn-1)c[i]=0;
		getinv(c,2*nn,c);mul(c,a,2*nn,2*nn,c);
		rep(i,0,2*nn-1)b[i]=1LL*(b[i]+c[i])*inv2%mo;
	}
	rep(i,0,n)_b[i]=b[i];
}
int main() {
	int n,q;read(q);read(n);
	while(q--){int x;read(x);a[x]++;}
	rep(i,1,n)a[i]=mo-4*a[i];a[0]=1;
	getsqrt(a,n+1,b);b[0]++;getinv(b,n+1,a);
	rep(i,0,n)a[i]=2LL*a[i]%mo;
	rep(i,1,n)printf("%d\n",a[i]);
	return 0;
}