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
int n, p;
char s[4444];
int main() {
	read(n), read(p);
	while(isspace(s[1]=read()));
	rep(i, 2, n) s[i]=read();
	rep(i, 1, n-p) if(!isdigit(s[i]) || s[i+p]!=s[i]) goto ok;
	return puts("No"), 0;
	ok:;
	rep(i, 1, n) if(s[i]=='.')
		if(i<=p) s[i]=(s[i+p]=='1'?'0':'1');
		else s[i]=(s[i-p]=='1'?'0':'1');
	puts(s+1);
	return 0;
}