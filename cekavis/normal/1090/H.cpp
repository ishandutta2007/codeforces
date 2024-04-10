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

const int N = 200005, M = 18;
int n, q, f[M][N];
char s[N];
int main() {
	read(n);
	while(isspace(s[0]=read()));
	for(int i=1; i<n; ++i) s[i]=read();
	for(int i=n; --i;) s[i]^=s[i-1];
	for(int i=1; 1<<i<n; ++i){
		for(int j=0; j<1<<i; ++j) f[i][j]=s[j];
		for(int j=1<<i; j<n; ++j) f[i][j]=f[i][j-(1<<i)]+s[j];
	}
	read(q);
	while(q--){
		int l, r, len, now, ans=0;
		read(l), read(r), now=r, len=r-l+1;
		for(int i=1; 1<<i<len; ++i){
			int x=f[i][now]-(now>=len?f[i][now-len]:0);
			ans+=min(x, len/(1<<i)-x), now-=1<<(i-1);
		}
		print((ans+1)/2), print('\n');
	}
	return flush(), 0;
}