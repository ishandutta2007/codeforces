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
const int N = 200005, M = 500005;
ll ans;
int n, q, cnt, x, tot, c[N], a[N], prime[N], p[M], f[M];
bool b[N], s[M];
int main() {
	for(int i=2; i<=500000; ++i){
		if(!p[i]) p[i]=i, prime[++cnt]=i, s[i]=1;
		for(int j=1; j<=cnt && i*prime[j]<=500000; ++j){
			p[i*prime[j]]=prime[j], s[i*prime[j]]=s[i]^1;
			if(i%prime[j]==0) break;
		}
	}
	read(n), read(q);
	for(int i=1; i<=n; ++i) read(a[i]);
	while(q--){
		read(x);
		c[tot=1]=1;
		for(int i=a[x]; i!=1;){
			int tmp=p[i];
			i/=tmp;
			while(p[i]==tmp) i/=tmp;
			for(int j=1; j<=tot; ++j) c[tot+j]=c[j]*tmp;
			tot<<=1;
		}
		// printf(">>>"); for(int i=1; i<=tot; ++i) printf("%d ", c[i]); puts("");
		if(b[x]^=1) for(int i=1; i<=tot; ++i) ans+=f[c[i]]++*(s[c[i]]?-1:1);
		else for(int i=1; i<=tot; ++i) ans+=--f[c[i]]*(s[c[i]]?1:-1);
		print(ans), print('\n');
	}
	return flush(), 0;
}