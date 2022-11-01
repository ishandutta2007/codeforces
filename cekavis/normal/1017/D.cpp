#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
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
int n, m, q, w[55], cnt[1<<12], s[1<<12], a[1<<12][102];
int main() {
	read(n), read(m), read(q);
	for(int i=n-1; ~i; --i) read(w[i]);
	for(int i=1; i<=m; ++i){
		char tmp;
		int a=0;
		while(isspace(tmp=read()));
		a=tmp^'0';
		for(int j=2; j<=n; ++j) a=a*2+read()-'0';
		++cnt[a];
	}
	for(int i=0; i<1<<n; ++i){
		for(int j=0; j<n; ++j) if(i>>j&1) s[i]+=w[j];
		s[i]=min(s[i], 101);
	}
	int tot=(1<<n)-1;
	for(int i=0; i<1<<n; ++i){
		for(int j=0; j<1<<n; ++j) a[i][s[tot^i^j]]+=cnt[j];
		for(int j=1; j<=100; ++j) a[i][j]+=a[i][j-1];
	}
	while(q--){
		char tmp;
		int x=0, y;
		while(isspace(tmp=read()));
		x=tmp^'0';
		for(int i=2; i<=n; ++i) x=x*2+read()-'0';
		read(y);
		print(a[x][y]), print('\n');
	}
	return flush(), 0;
}