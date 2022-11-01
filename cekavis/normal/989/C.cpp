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
pair<int, char> a[10];
char ans[55][55];
int main() {
	puts("50 50");
	rep(i, 1, 4) read(a[i].first), a[i].second='A'+i-1;
	sort(a+1, a+5);
	int tmp=0;
	for(int i=50; i>1; i-=2) for(int j=1; j<50; j+=2) if(a[1].first>1) --a[1].first, ans[i][j]=a[1].second;
	else{
		tmp=i;
		goto aaa;
	}
	aaa:;
	per(i, 50, tmp-1) rep(j, 1, 50) if(!ans[i][j]) ans[i][j]=a[4].second;
	--a[4].first;
	tmp=2;
	for(int i=1; i<50; i+=2) for(int j=1; j<50; j+=2){
		while(tmp<=4 && !a[tmp].first) ++tmp;
		if(tmp>4) goto ok;
		--a[tmp].first, ans[i][j]=a[tmp].second;
	}
	ok:;
	rep(i, 1, 50){
		rep(j, 1, 50) putchar(ans[i][j]?ans[i][j]:a[1].second);
		putchar('\n');
	}
	return 0;
}