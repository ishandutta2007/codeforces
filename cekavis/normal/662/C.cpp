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
const int N = 22, M = 100005, K = 1<<20;
int n, m, a[M];
ll f[K], g[K];
inline void FWT(ll *f, int g, int len=1<<n){
	for(int i=1; i<len; i<<=1)
		for(int j=0; j<len; j+=i<<1)
			for(int k=j; k<j+i; ++k){
				ll x=f[k], y=f[k+i];
				f[k]=x+y, f[k+i]=x-y;
			}
	if(g==-1) for(int i=0; i<len; ++i) f[i]>>=n;
}
int main() {
	read(n), read(m);
	for(int i=0; i<n; ++i){
		char ch;
		while(isspace(ch=read()));
		for(int j=0; j<m; ++j, ch=read()) a[j]=a[j]<<1|(ch^'0');
	}
	for(int i=0; i<m; ++i) ++f[a[i]];
	for(int i=1; i<1<<n; ++i) g[i]=g[i^(i&-i)]+1;
	for(int i=0; i<1<<n; ++i) g[i]=min(g[i], n-g[i]);
	FWT(f, 1), FWT(g, 1);
	for(int i=0; i<1<<n; ++i) f[i]*=g[i];
	FWT(f, -1);
	int ans=1e9;
	for(int i=0; i<1<<n; ++i) ans=min(ans, (int)f[i]);
	return printf("%d", ans), 0;
}