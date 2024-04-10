#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 200005;
int n, q;
struct item{
	int d, a, b, ab, bc, ans;
	inline item operator+(const item &r){
		item s;
		s.d=d+r.d;
		s.a=max(a, d+r.a);
		s.b=max(b, -2*d+r.b);
		s.ab=max(max(ab, -d+r.ab), a-2*d+r.b);
		s.bc=max(max(bc, -d+r.bc), b+d+r.a);
		s.ans=max(max(ans, r.ans), max(ab+d+r.a, a-d+r.bc));
		return s;
	}
} s[N<<2];
void build(int l, int r, int t){
	if(l==r){
		char c;
		while(isspace(c=read()));
		s[t].d=(c=='('?1:-1);
		return;
	}
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1), s[t]=s[k]+s[k|1];
}
void modify(int l, int r, int t, int x){
	if(l==r) return (void)(s[t].d=-s[t].d);
	int mid=(l+r)>>1, k=t<<1;
	if(x<=mid) modify(l, mid, k, x); else modify(mid+1, r, k|1, x);
	s[t]=s[k]+s[k|1];
}
int main() {
	read(n), read(q), n=n*2-2;
	build(1, n, 1), print(s[1].ans), print('\n');
	while(q--){
		int x=0, y=0;
		read(x), read(y), modify(1, n, 1, x), modify(1, n, 1, y);
		print(s[1].ans), print('\n');
	}
	return flush(), 0;
}