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
const int N = 200005, P = 1000000000;
int n, m, f[N], a[N], lazy[N<<2];
struct st{
	int a, b, len;
	inline st(){}
	inline st(int a_, int b_, int len_){ a=a_, b=b_, len=len_;}
	inline st operator *(const st &rhs)const{
		return st((a+(ll)rhs.a*f[len-1]+(ll)rhs.b*f[len])%P, (b+(ll)rhs.a*f[len]+(ll)rhs.b*f[len+1])%P, len+rhs.len);
	}
}s[N<<2];
void build(int l, int r, int t){
	if(l==r) return (void)(s[t].a=s[t].b=a[l], s[t].len=1);
	int mid=l+r>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=s[k]*s[k|1];
}
inline void add(int t, int x){
	(lazy[t]+=x)%=P;
	s[t].a=(s[t].a+(ll)(f[s[t].len+2]-1)*x)%P;
	s[t].b=(s[t].b+(ll)(f[s[t].len+3]-2)*x)%P;
}
void modify(int l, int r, int t, int x, int y){
	if(l==r) return (void)(s[t].a=s[t].b=y);
	int mid=l+r>>1, k=t<<1;
	if(lazy[t]) add(k, lazy[t]), add(k|1, lazy[t]), lazy[t]=0;
	if(x<=mid) modify(l, mid, k, x, y); else modify(mid+1, r, k|1, x, y);
	s[t]=s[k]*s[k|1];
}
st query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return s[t];
	int mid=l+r>>1, k=t<<1;
	if(lazy[t]) add(k, lazy[t]), add(k|1, lazy[t]), lazy[t]=0;
	if(R<=mid) return query(l, mid, k, L, R);
	if(L>mid) return query(mid+1, r, k|1, L, R);
	return query(l, mid, k, L, R)*query(mid+1, r, k|1, L, R);
}
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return add(t, x);
	int mid=l+r>>1, k=t<<1;
	if(lazy[t]) add(k, lazy[t]), add(k|1, lazy[t]), lazy[t]=0;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
	s[t]=s[k]*s[k|1];
}
int main() {
	read(n), read(m);
	f[1]=f[2]=1;
	for(int i=3; i<=n+3; ++i) f[i]=(f[i-1]+f[i-2])%P;
	for(int i=1; i<=n; ++i) read(a[i]);
	build(1, n, 1);
	while(m--){
		static int opt, l, r, x;
		read(opt), read(l), read(r);
		if(opt==1) modify(1, n, 1, l, r);
		else if(opt==2) print(query(1, n, 1, l, r).a), print('\n');
		else read(x), change(1, n, 1, l, r, x);
	}
	return flush(), 0;
}