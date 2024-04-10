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

const int N = 1000005;
int n, m, sum, a[N], b[N];
int main() {
	read(n), read(m);
	for(int i=1; i<=m; ++i) read(a[i]), b[i]=(b[i-1]+a[i])%n, sum+=a[i];
	sort(b+1, b+m), b[m]=n;
	for(int i=m; i>1; --i) b[i]-=b[i-1];
	print((sum-1)/n+1), print('\n');
	for(int i=1; i<=m; ++i) print(b[i]), print(' ');
	print('\n');
	int j=1;
	for(int i=1; i<=m; ++i){
		while(a[i]>0){
			a[i]-=b[j], print(i);
			if(j==m) print('\n'), j=1; else print(' '), ++j;
		}
	}
	if(j>1) while(j<=m) print(m), print(' '), ++j;
	return flush(), 0;
}