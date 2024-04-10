#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig = false, c = read(); !isdigit(c); c = read()) {
		if (c == '-') iosig = true;
		if (c == -1) return;
	}
	for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
	if (iosig) x = -x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x == 0) print('0');
	else {
		if (x < 0) print('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
const int N = 3005, P = 1000000007;
int n, D, num, ans, fac[N], inv[N], fa[N], h[N], e[N], pre[N], f[N][N];
inline int Pow(ll x, int y=P-2){
	ll ass=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ass=ass*x%P;
	return ass;
}
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u){
	rep(i, 0, n) f[u][i]=1;
	travel(i, u){
		dfs(e[i]);
		rep(j, 0, n) f[u][j]=(ll)f[u][j]*f[e[i]][j]%P;
	}
	rep(i, 1, n) f[u][i]=(f[u][i]+f[u][i-1])%P;
}
int main() {
	read(n), read(D), --D;
	fac[0]=1;
	rep(i, 1, n) fac[i]=(ll)fac[i-1]*i%P;
	inv[n]=Pow(fac[n]);
	for(int i=n; i; --i) inv[i-1]=(ll)inv[i]*i%P;
	rep(i, 2, n) read(fa[i]), add(fa[i], i);
	dfs(1);
	if(D<=n) printf("%d", f[1][D]);
	else{
		int p=1;
		rep(i, 0, n) p=(ll)p*(D-i)%P;
		rep(i, 0, n) ans=(ans+((n-i)&1?-1ll:1ll)*p*Pow(D-i)%P*inv[i]%P*inv[n-i]%P*f[1][i])%P;
		printf("%d", (ans+P)%P);
	}
	return 0;
}