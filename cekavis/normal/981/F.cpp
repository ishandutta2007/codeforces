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
const int N = 200005;
int n, L, b[N], a[N<<1], lazy[N<<3], s[N<<3];
inline bool check(int mid){
	int l=0;
	rep(i, 1, n) if(b[i]>=mid){
		int x=b[i];
		while(l<=n<<1 && abs(x-a[l])>mid) ++l;
		if(l>n<<1) return 0;
		++l;
	}
	rep(i, 1, n) if(b[i]+mid<L){
		int x=b[i]+L;
		while(l<=n<<1 && abs(x-a[l])>mid) ++l;
		if(l>n<<1) return 0;
		++l;
	}
	return 1;
}
int main() {
	read(n), read(L);
	rep(i, 1, n) read(a[i]), a[i+n]=a[i]+L;
	rep(i, 1, n) read(b[i]);
	sort(a+1, a+n*2+1), sort(b+1, b+n+1);
	int l=0, r=L+1>>1, ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid, r=mid-1; else l=mid+1;
	}
//	printf("%d\n", check(1));
	return printf("%d", ans), 0;
}