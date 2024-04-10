#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>

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
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 105, P = 1000000007;
int k, cnt, ans, b[N], inv[N], f[10005][N];
ll n, a[N];
int main() {
	scanf("%lld%d", &n, &k);
	inv[1]=1;
	for(int i=2; i<=100; ++i) inv[i]=(ll)(P-P/i)*inv[P%i]%P;
	for(int i=2; (ll)i*i<=n; ++i) if(n%i==0){
		a[++cnt]=i;
		while(n%i==0) n/=i, ++b[cnt];
	}
	if(n>1) a[++cnt]=n, b[cnt]=1;
	ans=1;
	for(int i=1; i<=cnt; ++i){
		memset(f, 0, sizeof f);
		f[0][b[i]]=1;
		for(int j=1; j<=k; ++j) for(int x=0; x<=b[i]; ++x) for(int y=0; y<=x; ++y)
			f[j][y]=(f[j][y]+(ll)f[j-1][x]*inv[x+1])%P;
		int tmp=0;
		for(int j=0, t=1; j<=b[i]; ++j, t=t*a[i]%P)
			tmp=(tmp+(ll)f[k][j]*t)%P;
		ans=(ll)ans*tmp%P;
	}
	return printf("%d", ans), 0;
}