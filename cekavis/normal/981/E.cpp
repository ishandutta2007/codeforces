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
const int N = 10005, P = 998244353;
int n, q, ass, cnt, g[N];
bool ans[N];
unsigned ll f[N];
pair<int,int> a[N<<1];
inline void chk1(int &x){ x>=P?x-=P:0;}
inline void chk2(int &x){ x<0?x+=P:0;}
int main() {
	read(n), read(q);
	rep(i, 1, q){
		static int l, r, x;
		read(l), read(r), read(x);
		a[++cnt]=make_pair(l, x), a[++cnt]=make_pair(r+1, -x);
	}
	sort(a+1, a+cnt+1);
	int j=1;
	f[0]=g[0]=1;
	rep(i, 1, n){
		while(a[j].first==i){
			if(a[j].second<0){
				int x=-a[j].second;
				rep(i, x, n) f[i]-=f[i-x], chk2(g[i]-=g[i-x]);
			}
			else{
				int x=a[j].second;
				per(i, n, x) f[i]+=f[i-x], chk1(g[i]+=g[i-x]);
			}
			++j;
		}
		rep(i, 1, n) ans[i]|=(f[i]||g[i]);
	}
	rep(i, 1, n) ass+=ans[i];
	printf("%d\n", ass);
	rep(i, 1, n) if(ans[i]) printf("%d ", i);
	return 0;
}