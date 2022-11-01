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
const int N = 100005;
int n, num, h[N], e[N], pre[N], fa[N], ans[N];
bool f[N];
struct vec{
	int x, y, id;
	inline vec operator +(const vec &rhs)const{ return (vec){x+rhs.x, y+rhs.y, id};}
	inline vec operator -(const vec &rhs)const{ return (vec){x-rhs.x, y-rhs.y, id};}
	inline ll module(){ return (ll)x*x+(ll)y*y;}
}a, b, c;
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u){
	f[u]^=f[fa[u]];
	travel(i, u) dfs(e[i]);
}
int main() {
	read(n);
	if(n==1) return puts("1"), 0;
	read(a.x), read(a.y), read(b.x), read(b.y), a.id=1, b.id=2;
	rep(i, 3, n){
		read(c.x), read(c.y), c.id=i;
		if((a+b).module()<=1000000000000ll) fa[b.id]=a.id, a=a+b, b=c;
		else if((a-b).module()<=1000000000000ll) fa[b.id]=a.id, a=a-b, f[b.id]^=1, b=c;
		else if((a+c).module()<=1000000000000ll) fa[i]=a.id, a=a+c;
		else if((a-c).module()<=1000000000000ll) fa[i]=a.id, a=a-c, f[i]^=1;
		else if((b+c).module()<=1000000000000ll) fa[i]=b.id, b=b+c;
		else if((b-c).module()<=1000000000000ll) fa[i]=b.id, b=b-c, f[i]^=1;
	}
	if((a+b).module()>1500000ll*1500000ll) f[b.id]^=1, b.x*=-1, b.y*=-1;
	// if(n==7780) printf("%d %d\n", (a+b).x, (a+b).y);
	rep(i, 1, n) add(fa[i], i);
	dfs(0);
	rep(i, 1, n) print(f[i]?1:-1), print(' ');
	return flush(), 0;
}