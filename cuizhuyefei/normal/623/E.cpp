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
const int N = 1<<16|3, M = 30000;
int mo=1e9+7,inv2=(mo+1)/2;
#define pi acos(-1)
struct E {
	double a,b; //a+bi
	double imag() {return b;}
	double real() {return a;}
	E(double A=0, double B=0) {a=A; b=B;}	
};
E operator + (const E &x, const E &y) {return E(x.a+y.a,x.b+y.b);}
E operator - (const E &x, const E &y) {return E(x.a-y.a,x.b-y.b);}
E operator * (const E &x, const E &y) {return E(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);}
vector<E> w[19];
void sub(int &x,int y){x=x-y>=0?x-y:x-y+mo;}
void initw(int n){
	for(int j=2,d=0;j<=n;j<<=1,d++){
		rep(i,0,(j>>1)-1)w[d].pb(E(cos(2*pi/j*i),sin(2*pi/j*i)));
	}
}
inline void fft(E *a, int n, int tp) {
	for (int i=1,j=0; i<n; i++) {
		for (int k=(n>>1); !((j^=k)&k); k>>=1);
		if (i<j) swap(a[i],a[j]);
	}
	for (int j=2,d=0; j<=n; j<<=1,d++) {
		int m=(j>>1)-1;
		for (register int i=0; i<n; i+=j) rep(k,0,m) {
			E x=a[i+k+(j>>1)]*E(w[d][k].a,w[d][k].b*tp);
			a[i+k+(j>>1)]=a[i+k]-x; a[i+k]=a[i+k]+x;
		}
	}
}
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
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
inline void mul(int *_a, int *_b, int n1, int n2, int *c){
	/*if(n1<=50&&n2<=50){
		copy: _a-->a _b-->b
		rep(i,0,n1-1+n2-1)c[i]=0;
		rep(i,0,n1-1)rep(j,0,n2-1)c[i+j]=(c[i+j]+1LL*a[i]*b[j])%mo;
		return;
	}*/
	static E a0[N],a1[N],b0[N],b1[N],f[N];int n;for(n=1;n<=n1+n2-2;n<<=1);
	rep(i,0,n1-1)a0[i]=_a[i]%M,a1[i]=_a[i]/M;rep(i,n1,n-1)a0[i]=a1[i]=0;//WA!
	rep(i,0,n2-1)b0[i]=_b[i]%M,b1[i]=_b[i]/M;rep(i,n2,n-1)b0[i]=b1[i]=0;
	fft(a0,n,1);fft(a1,n,1);fft(b0,n,1);fft(b1,n,1);
	rep(i,0,n-1)c[i]=0;
	rep(i,0,n-1)f[i]=a0[i]*b0[i];fft(f,n,-1);
	rep(i,0,n-1)c[i]=(c[i]+(ll)(f[i].real()/n+0.5))%mo;
	rep(i,0,n-1)f[i]=a0[i]*b1[i]+a1[i]*b0[i];fft(f,n,-1);
	rep(i,0,n-1)c[i]=(c[i]+(ll)(f[i].real()/n+0.5)%mo*M)%mo;
	rep(i,0,n-1)f[i]=a1[i]*b1[i];fft(f,n,-1);
	rep(i,0,n-1)c[i]=(c[i]+(ll)(f[i].real()/n+0.5)%mo*M%mo*M)%mo;
}
inline void getinv(int *a, int n, int *_b){
	static int b[N];
	rep(i,0,n)b[i]=0;b[0]=inv(a[0]);
	for(int nn=1;nn<n;nn<<=1){//[0,nn)-->[0,2nn)
		static int c[N],d[N];int sz=4*nn;
		rep(i,0,nn-1)c[i]=b[i];rep(i,nn,sz-1)c[i]=0;
		rep(i,0,2*nn-1)d[i]=a[i];rep(i,2*nn,sz-1)d[i]=0;
		mul(c,c,nn,nn,c);mul(c,d,2*nn,2*nn,c);
	//	fft(c,sz,1);fft(d,sz,1);
	//	rep(i,0,sz-1)c[i]=1LL*c[i]*c[i]%mo*d[i]%mo;
	//	fft(c,sz,-1);int ni=inv(sz);rep(i,0,sz-1)c[i]=1LL*c[i]*ni%mo;
		rep(i,0,2*nn-1)b[i]=((2LL*b[i]-c[i])%mo+mo)%mo;
	}
	rep(i,0,n-1)_b[i]=b[i];
}
inline void qiudao(int *a, int n, int *_b){//a[0..n-1]
	static int b[N];
	rep(i,1,n-1)b[i-1]=1LL*a[i]*i%mo;b[n-1]=0;
	memcpy(_b,b,4*(n+2));
}
inline void jifen(int *a, int n, int *_b){
	static int b[N];
	b[0]=0;rep(i,0,n-1)b[i+1]=1LL*a[i]*inv(i+1)%mo;
	memcpy(_b,b,4*(n+2));
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
bool ck(int x){return power(x,(mo-1)/2)==1;}
Pii mul(Pii a, Pii b, int f){
	return Pii((1LL*a.fi*b.fi+1LL*a.se*b.se%mo*f)%mo,(1LL*a.fi*b.se+1LL*a.se*b.fi)%mo);
}
inline int getsqrt(int a){
	if(!ck(a))return -1;
	int t=R()%mo;while(ck((1LL*t*t-a+mo)%mo))t=R()%mo;
	int f=(1LL*t*t-a+mo)%mo;
	Pii res(1,0),now(t,1);int mi=(mo+1)/2;
	while(mi){
		if(mi&1)res=mul(res,now,f);
		now=mul(now,now,f);mi>>=1;
	}
	assert(!res.se);return min(res.fi,mo-res.fi);
}
inline void getsqrt(int *a, int n, int *_b){
	static int b[N];
	b[0]=getsqrt(a[0]);rep(i,1,n)b[i]=0;
	for(int nn=1;nn<n;nn<<=1){//[0..nn-1]-->[0..2*nn-1]
		static int c[N];
		rep(i,0,nn-1)c[i]=b[i];rep(i,nn,2*nn-1)c[i]=0;
		getinv(c,2*nn,c);mul(c,a,2*nn,2*nn,c);
		rep(i,0,2*nn-1)b[i]=1LL*(b[i]+c[i])*inv2%mo;
	}
	rep(i,0,n)_b[i]=b[i];
}
inline void polypower(int *_a, int n, int k, int *_b){//b[0..n-1]
	int c,d=0;while(!_a[d])d++;c=_a[d];int ni=inv(c);
	static int a[N];rep(i,0,n)a[i]=0;
	rep(i,d,n-1)a[i-d]=1LL*_a[i]*ni%mo;
	static int b[N];getln(a,n,b);
	rep(i,0,n-1)b[i]=1LL*b[i]*k%mo;
	getexp(b,n,b);
	rep(i,0,n)_b[i]=0;
	int mi=power(c,k);rep(i,0,n-d*k)_b[i+d*k]=1LL*mi*b[i]%mo;
}
ll n,k;
void merge(int *_a, int *_b, int *c, int t){
	static int a[N],b[N];//int tmp=power(2,t*);
	rep(i,0,k)b[i]=_b[i],a[i]=1LL*_a[i]*power(2,1LL*t*i%(mo-1))%mo;
	mul(a,b,k+1,k+1,c);
}
int main() {
	initw(1<<16);read(n);read(k);
	if(n>k){puts("0");return 0;}
	static int ans[N],a[N],fac[N],ifac[N];
	fac[0]=1;rep(i,1,k)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[k]=power(fac[k],mo-2);per(i,k-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	ans[0]=1;rep(i,1,k)a[i]=ifac[i];
	ll t=1;
	while(n){
		if(n&1)merge(ans,a,ans,t);
		merge(a,a,a,t);n>>=1;t<<=1;
	}
	int res=0;rep(i,0,k)res=(res+1LL*ans[i]*fac[k]%mo*ifac[k-i])%mo;
	cout<<res;
	return 0;
}