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

const int N = 100005, P = 998244353;
int k, n, ans, lazy[(N>>9)+2], a[N], f[N], h[N], b[N], c[N], g[(N>>9)+2][N];
void change(int x, int y){
	for(int i=0; i<x>>9; ++i){
		if(y==1){
			if(k-lazy[i]>=0 && k-lazy[i]<=n) (ans-=g[i][k-lazy[i]])%=P;
			++lazy[i];
		}
		else{
			--lazy[i];
			if(k-lazy[i]>=0 && k-lazy[i]<=n) (ans+=g[i][k-lazy[i]])%=P;
			--lazy[i];
			if(k-lazy[i]>=0 && k-lazy[i]<=n) (ans+=g[i][k-lazy[i]])%=P;
		}
	}
	int a=x>>9;
	for(int i=a<<9; i<(a+1)<<9 && i<=n; ++i){
		g[a][h[i]]=0;
		if(h[i]+lazy[a]<=k) (ans-=f[i])%=P;
	}
	for(int i=a<<9; i<=x; ++i) h[i]+=y;
	for(int i=a<<9; i<(a+1)<<9 && i<=n; ++i){
		h[i]+=lazy[a];
		(g[a][h[i]]+=f[i])%=P;
		if(h[i]<=k) (ans+=f[i])%=P;
	}
	lazy[a]=0;
}
int main() {
	read(n), read(k);
	for(int i=1; i<=n; ++i) read(a[i]);
	ans=f[0]=g[0][0]=1;
	for(int i=1; i<=n; ++i){
		if(c[a[i]]) change(c[a[i]]-1, 1);
		c[a[i]]=b[a[i]];
		change(i-1, 1);
		if(b[a[i]]) change(b[a[i]]-1, -2);
		b[a[i]]=i;
		f[i]=ans, (ans+=f[i])%=P, (g[i>>9][0]+=f[i])%=P;
		// printf(">> %d\n", f[i]);
	}
	return printf("%d", (f[n]+P)%P), 0;
}