#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define Rep(i,x,y) for(int i=(x);i<(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
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
	for (x = 0; isdigit(c); c = read())
		x = ((x + (x << 2)) << 1) + (c ^ '0');
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
const int N = 1<<22;
int n, m, s, ans, f[N], g[N], a[N], q[N];
int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
int main() {
	read(n), read(m), s=(1<<n)-1;
	memset(f, -1, sizeof f), memset(q, -1, sizeof q);
	Rep(i, 0, m) read(a[i]), g[s^a[i]]=1, f[a[i]]=q[a[i]]=a[i];
	per(i, s, 0) for(int j=1; j<s; j<<=1) if(!(i&j)) g[i]|=g[i^j];
	rep(i, 0, s){
		if(g[i]) for(int j=1; j<s; j<<=1) if((i&j) && ~f[i^j]) f[~f[i]?find(i):i]=find(i^j);
		if(q[i]==-1) for(int j=1; j<s; j<<=1) if((i&j) && ~q[i^j]){ q[i]=q[i^j]; break;}
	}
	Rep(i, 0, m) if(~q[s^a[i]]) f[find(a[i])]=find(q[s^a[i]]);
	rep(i, 0, s) ans+=(~f[i] && i==find(i));
	return printf("%d", ans), 0;
}