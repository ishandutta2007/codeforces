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
const int N = 5010;
int n, a[N], f[N][N>>1][2];
inline void chkmn(int &x, int y){ x=(x<y?x:y);}
int main() {
	read(n);
	rep(i, 1, n) read(a[i]);
	memset(f, 0x3f3f3f3f, sizeof f);
	f[0][0][0]=0;
	rep(i, 0, n) rep(j, 0, n+1>>1){
		chkmn(f[i+1][j][0], f[i][j][0]);
		chkmn(f[i+1][j+1][1], f[i][j][0]+max(0, a[i]-a[i+1]+1)+max(0, a[i+2]-a[i+1]+1));
		chkmn(f[i+2][j][0], f[i][j][1]);
		chkmn(f[i+2][j+1][1], f[i][j][1]+max(0, min(a[i+1], a[i]-1)-a[i+2]+1)+max(0, a[i+3]-a[i+2]+1));
	}
	rep(i, 1, n+1>>1) printf("%d ", min(min(f[n-1][i][0], f[n-1][i][1]), min(f[n][i][0], f[n][i][1])));
	return 0;
}