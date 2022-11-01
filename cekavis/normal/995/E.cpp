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
const int N = 40005;
int n, u, v, p, optv[102], a[N], b[N], opt[N][102];
inline int Pow(ll x, int y=p-2){
	ll ass=1;
	for(; y; y>>=1, x=x*x%p) if(y&1) ass=ass*x%p;
	return ass;
}
inline bool find(int x){
	int l=1, r=n, ass=0;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<=x) ass=mid, l=mid+1; else r=mid-1;
	}
	return a[ass]==x;
}
int main() {
	read(u), read(v), read(p);
	n=sqrt(p);
	rep(i, 1, n){
		int tmp=u;
		rep(j, 1, 100){
			int x=rand()%3+1;
			if(x==1) tmp=(tmp==p-1?0:tmp+1);
			else if(x==2) tmp=(tmp?tmp-1:p-1);
			else tmp=Pow(tmp);
			opt[i][j]=x;
		}
		b[i]=a[i]=tmp;
	}
	sort(a+1, a+n+1);
	while(1){
		int tmp=v;
		rep(j, 1, 100){
			int x=rand()%3+1;
			optv[j]=x;
			if(x==1) tmp=(tmp?tmp-1:p-1);
			else if(x==2) tmp=(tmp==p-1?0:tmp+1);
			else tmp=Pow(tmp);
			if(find(tmp)){
				rep(k, 1, n) if(b[k]==tmp){
					printf("%d\n", 100+j);
					rep(t, 1, 100) printf("%d ", opt[k][t]);
					for(int t=j; t; --t) printf("%d ", optv[t]);
					return 0;
				}
			}
		}
	}
	return 0;
}