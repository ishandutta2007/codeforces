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
const int N = 100005, P = 1000000007;
int n, m, val[10], tot[10], d[N], len[N];
char tmp[N], s[N], *a[N];
inline ll Pow(ll x, int y){
	ll ass=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ass=ass*x%P;
	return ass;
}
inline pair<int,int> solve(char *s, int len){
	int l=0, v=0;
	for(int i=len-1; ~i; --i) v=(v+val[s[i]^'0']*Pow(10, l))%P, (l+=tot[s[i]^'0'])%=(P-1);
	return make_pair(v, l);
}
int main() {
	while(isdigit(s[m++]=read())); --m;
	read(n);
	rep(i, 1, n){
		while(!isdigit(d[i]=read()));
		d[i]^='0';
		read(), read();
		while(isdigit(tmp[len[i]++]=read()));
		--len[i];
		a[i]=new char[len[i]];
		memcpy(a[i], tmp, len[i]);
	}
	rep(i, 0, 9) tot[i]=1, val[i]=i;
	for(int i=n; i; --i){
		auto tmp=solve(a[i], len[i]);
		tot[d[i]]=tmp.second, val[d[i]]=tmp.first;
	}
	return printf("%d", solve(s, m).first), 0;
}