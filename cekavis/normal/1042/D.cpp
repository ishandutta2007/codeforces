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
int cnt, n, root, a[N], lson[N*60], rson[N*60], s[N*60];
ll t, ans, p[N];
void insert(ll l, ll r, int &t, ll x){
	++s[t?t:t=++cnt];
	if(l==r) return;
	ll mid=l+r>>1;
	if(x<=mid) insert(l, mid, lson[t], x);
	else insert(mid+1, r, rson[t], x);
}
int query(ll l, ll r, int t, ll x){
	if(x>r) return 0;
	if(x<=l) return s[t];
	ll mid=l+r>>1;
	if(x>mid) return query(mid+1, r, rson[t], x);
	return query(l, mid, lson[t], x)+query(mid+1, r, rson[t], x);
}
int main() {
	read(n), read(t);
	insert(-200000000000000, 200000000000000, root, 0);
	for(int i=1; i<=n; ++i){
		read(a[i]), p[i]=p[i-1]+a[i];
		ans+=query(-200000000000000, 200000000000000, root, p[i]-t+1);
		insert(-200000000000000, 200000000000000, root, p[i]);
	}
	printf("%lld", ans);
	return 0;
}