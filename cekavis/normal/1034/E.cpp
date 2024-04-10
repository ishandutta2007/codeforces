#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ull unsigned long long

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
const int OUT_LEN = 1<<21;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 1<<21, M = 22;
int n, cnt[N];
ull a[N], b[N];
int main() {
	read(n);
	for(int i=1; i<1<<n; ++i) cnt[i]=cnt[i^(i&-i)]+2;
	char x;
	while(isspace(x=read()));
	for(int i=0; i<1<<n; ++i) a[i]=(ull)(x-'0')<<cnt[i], x=read();
	while(isspace(x=read()));
	for(int i=0; i<1<<n; ++i) b[i]=(ull)(x-'0')<<cnt[i], x=read();

	for(int i=0; i<n; ++i) for(int j=0; j<1<<n; ++j) if(j>>i&1)
		a[j]+=a[j^(1<<i)], b[j]+=b[j^(1<<i)];
	for(int i=0; i<1<<n; ++i) a[i]*=b[i];
	for(int i=0; i<n; ++i) for(int j=0; j<1<<n; ++j) if(j>>i&1) a[j]-=a[j^(1<<i)];
	for(int i=0; i<1<<n; ++i) print((char)('0'+(a[i]>>cnt[i]&3)));
	return flush(), 0;
}