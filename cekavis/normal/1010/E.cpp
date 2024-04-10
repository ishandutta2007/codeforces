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
const int N = 100005, M = 18000000;
int xmax, ymax, zmax, n, m, k, xl=1e9, xr, yl=1e9, yr, zl=1e9, zr, cnt, ans[N], root[N], ax[N], ay[N], az[N], s[M], lson[M], rson[M];
struct point{
	int x, y, z;
	inline bool operator <(const point &rhs)const{ return x<rhs.x;}
} a[N], b[N];
struct item{
	int x, yl, yr, zl, zr, id;
	inline bool operator <(const item &rhs)const{ return x<rhs.x;}
}f[N<<1];
void modify(int l, int r, int &t, int pos){
	// printf("%d %d\n", l, r);
	++s[t?t:t=++cnt];
	if(l!=r){
		int mid=l+r>>1;
		if(pos<=mid) modify(l, mid, lson[t], pos); else modify(mid+1, r, rson[t], pos);
	}
}
int query(int l, int r, int t, int L, int R){
	if(!t || L<=l && r<=R) return s[t];
	int mid=l+r>>1;
	return (L<=mid?query(l, mid, lson[t], L, R):0)+(R>mid?query(mid+1, r, rson[t], L, R):0);
}
inline void insert(int y, int z){ while(y<=ymax) modify(1, zmax, root[y], z), y+=y&-y;}
inline int sum(int y, int zl, int zr){ int ass=0; while(y) ass+=query(1, zmax, root[y], zl, zr), y^=y&-y; return ass;}
int main() {
	read(xmax), read(ymax), read(zmax), read(n), read(m), read(k);
	rep(i, 1, n) read(a[i].x), read(a[i].y), read(a[i].z), xr=max(xr, a[i].x), xl=min(xl, a[i].x), yr=max(yr, a[i].y), yl=min(yl, a[i].y), zr=max(zr, a[i].z), zl=min(zl, a[i].z);
	if(!m){
		puts("CORRECT");
		rep(i, 1, k){
			static int x, y, z;
			read(x), read(y), read(z);
			if(xl<=x && x<=xr && yl<=y && y<=yr && zl<=z && z<=zr) puts("OPEN"); else puts("UNKNOWN");
		}
	}
	else{
		rep(i, 1, m){
			read(b[i].x), read(b[i].y), read(b[i].z);
			if(xl<=b[i].x && b[i].x<=xr && yl<=b[i].y && b[i].y<=yr && zl<=b[i].z && b[i].z<=zr) return puts("INCORRECT"), 0;
		}
		puts("CORRECT");
		sort(b+1, b+m+1);
		int tot=0;
		rep(i, 1, k){
			static int x, y, z;
			read(x), read(y), read(z);
			if(xl<=x && x<=xr && yl<=y && y<=yr && zl<=z && z<=zr) ans[i]=-1;
			else f[++tot]=(item){min(x, xl)-1, min(y, yl), max(y, yr), min(z, zl), max(z, zr), -i}, f[++tot]=(item){max(x, xr), min(y, yl), max(y, yr), min(z, zl), max(z, zr), i};
		}
		sort(f+1, f+tot+1);
		int j=1;
		rep(i, 1, tot){
			while(b[j].x<=f[i].x && j<=m) insert(b[j].y, b[j].z), ++j;
			if(f[i].id<0) ans[-f[i].id]-=sum(f[i].yr, f[i].zl, f[i].zr)-sum(f[i].yl-1, f[i].zl, f[i].zr);
			else ans[f[i].id]+=sum(f[i].yr, f[i].zl, f[i].zr)-sum(f[i].yl-1, f[i].zl, f[i].zr);
		}
		rep(i, 1, k) if(ans[i]==-1) puts("OPEN"); else if(ans[i]) puts("CLOSED"); else puts("UNKNOWN");
	}
	return 0;
}