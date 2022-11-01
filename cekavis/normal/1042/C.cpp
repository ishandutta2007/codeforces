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
const int N = 200005;
int n, tot0, tot1, cnt, a[N], b[N];
int main() {
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]), tot0+=!a[i], tot1+=(a[i]<0);
	if(tot0){
		if(tot1&1){
			int x=0;
			a[0]=-2e9;
			for(int i=1; i<=n; ++i) if(a[i]<0 && a[i]>a[x]) x=i;
			for(int i=1; i<=n; ++i) if(!a[i]) printf("1 %d %d\n", i, x);
			if(1+tot0<n) printf("2 %d\n", x);
			int last;
			for(int i=1; i<=n; ++i) if(a[i] && i!=x){
				last=i;
				break;
			}
			for(int i=last+1; i<=n; ++i) if(a[i] && i!=x) printf("1 %d %d\n", last, i), last=i;
			return 0;
		}
		for(int i=1; i<=n; ++i) if(!a[i]) b[++cnt]=i;
		for(int i=1; i<cnt; ++i) printf("1 %d %d\n", b[i], b[i+1]);
		if(tot0<n) printf("2 %d\n", b[cnt]);
		int last;
		for(int i=1; i<=n; ++i) if(a[i]){
			last=i;
			break;
		}
		for(int i=last+1; i<=n; ++i) if(a[i]) printf("1 %d %d\n", last, i), last=i;
		return 0;
	}
	if(tot1&1){
		int x=0;
		a[0]=-2e9;
		for(int i=1; i<=n; ++i) if(a[i]<0 && a[i]>a[x]) x=i;
		printf("2 %d\n", x);
		int last=(x==1?2:1);
		for(int i=last+1; i<=n; ++i) if(i!=x) printf("1 %d %d\n", last, i), last=i;
		return 0;
	}
	for(int i=1; i<n; ++i) printf("1 %d %d\n", i, i+1);
	return 0;
}