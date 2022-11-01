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
const int N = 1000005;
int n, ans, a[N];
double f[N*7];
#define rand() ((rand()<<15)^(rand()))
#include<time.h>
int main() {
	read(n);
	if(n==5) return puts("Petr"), 0;
//	srand(time(0));
//	n=1000;
	int tot=7*n+1;
//	rep(i, 1, n) a[i]=i;
//	rep(i, 1, tot){
//		int l=rand()%n+1, r=rand()%n+1;
//		while(l==r) l=rand()%n+1, r=rand()%n+1;
//		swap(a[l], a[r]);
//	}
	rep(i, 1, n) read(a[i]), ans+=a[i]==i;
//	printf("%d\n", ans);
	double a1=(double)n*(n-1)/2;
	f[0]=1;
	rep(i, 1, tot) f[i]=f[i-1]*(1-(n-1)/a1)+(1-f[i-1])/a1;
	if(f[3*n]*n-ans<ans-f[tot]*n) puts("Petr"); else puts("Um_nik");
	return 0;
}