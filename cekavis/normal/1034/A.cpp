#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

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
const int N = 300005, M = 15000005;
int n, ans, g, cnt, a[N], p[M], prime[M], f[M];
inline int gcd(int x, int y){ return y?gcd(y, x%y):x;}
inline void work(int x){
	for(int i=x; i!=1;){
		int tmp=p[i];
		if(p[i/=tmp]!=tmp) ++f[tmp];
	}
}
int main() {
	for(int i=2; i<=15000000; ++i){
		if(!p[i]) p[i]=i, prime[++cnt]=i;
		for(int j=1; j<=cnt && i*prime[j]<=15000000; ++j){
			p[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	g=a[1];
	for(int i=2; i<=n; ++i) g=gcd(g, a[i]);
	for(int i=1; i<=n; ++i) work(a[i]/g);
	for(int i=1; i<=15000000; ++i) ans=max(ans, f[i]);
	return printf("%d", !ans?-1:n-ans), 0;
}