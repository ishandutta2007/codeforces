#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>
#include<tuple>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
inline void print(int x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 100005, M = 1<<17, P = 998244353;
int n, k, x, y, z, ans, A[N], B[N], C[N], D[N], f[M], g[M], h[M];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
void FWT(int *f){
	for(int i=1; i<1<<k; i<<=1) for(int j=0; j<1<<k; j+=i<<1) for(int k=j; k<j+i; ++k)
		tie(f[k], f[k+i])=make_pair(f[k]+f[k+i], f[k]-f[k+i]);
}
void IFWT(int *f){
	for(int i=1; i<1<<k; i<<=1) for(int j=0; j<1<<k; j+=i<<1) for(int k=j; k<j+i; ++k)
		tie(f[k], f[k+i])=make_pair((f[k]+f[k+i])%P, (f[k]-f[k+i])%P);
	for(int i=0, I=Pow(1<<k); i<1<<k; ++i) f[i]=(ll)f[i]*I%P;
}
int main() {
	read(n), read(k), read(x), read(y), read(z);
	A[0]=B[0]=C[0]=D[0]=1;
	for(int i=1; i<=n; ++i) A[i]=A[i-1]*((ll)x+y+z)%P, B[i]=B[i-1]*((ll)x+y-z)%P, C[i]=C[i-1]*((ll)x-y+z)%P, D[i]=D[i-1]*((ll)x-y-z)%P;
	for(int i=1, a=0, b=0, c=0; i<=n; ++i){
		read(a), read(b), read(c), ans^=a, b^=a, c^=a;
		++f[b], ++g[c], ++h[b^c];
	}
	FWT(f), FWT(g), FWT(h);
	for(int i=0; i<1<<k; ++i){
		int a=(n+f[i]+g[i]+h[i])/4, b=(n+f[i]-g[i]-h[i])/4, c=(n-f[i]+g[i]-h[i])/4, d=(n-f[i]-g[i]+h[i])/4;
		f[i]=(ll)A[a]*B[b]%P*C[c]%P*D[d]%P;
	}
	IFWT(f);
	for(int i=0; i<1<<k; ++i) print((f[i^ans]+P)%P), print(' ');
	return flush(), 0;
}