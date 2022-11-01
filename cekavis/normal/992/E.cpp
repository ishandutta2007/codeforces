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
const int N = 200005;
int n, q, a[N];
ll s[N], lazy[N<<2], f[N<<2];
inline void build(int l, int r, int t){
	if(l==r) return (void)(f[t]=s[l]);
	int mid=l+r>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	f[t]=f[k|1];
}
inline void change(int l, int r, int t, int pos, int x){
	if(pos<=l) return (void)(lazy[t]+=x, f[t]+=x);
	int mid=l+r>>1, k=t<<1;
	change(mid+1, r, k|1, pos, x);
	if(pos<=mid) change(l, mid, k, pos, x);
	f[t]=lazy[t]+f[k|1];
}
inline pair<ll,int> query(int l, int r, int t, ll x, ll delta){
	if(l==r) return make_pair(f[t]+delta, l);
	int mid=l+r>>1, k=t<<1;
	x-=lazy[t], delta+=lazy[t];
	return x<=f[k]?query(l, mid, k, x, delta):query(mid+1, r, k|1, x, delta);
}
int main() {
	read(n), read(q);
	rep(i, 1, n) read(a[i]), s[i]=s[i-1]+a[i];
	build(1, n, 1);
	while(q--){
		static int pos, x;
		read(pos), read(x), x-=a[pos], a[pos]+=x;
		change(1, n, 1, pos, x);
		// printf("%d\n", query(1, n, 1, 4, 0).first);
		if(!a[1]){
			print(1), print('\n');
			goto ok;
		}
		x=1;
		while(x<=f[1]){
			auto tmp=query(1, n, 1, x, 0);
			if(tmp.first==a[tmp.second]<<1){
				print(tmp.second), print('\n');
				goto ok;
			}
			if(!(x<<=1)) break;
		}
		print(-1), print('\n');
		ok:;
	}
	return flush(), 0;
}