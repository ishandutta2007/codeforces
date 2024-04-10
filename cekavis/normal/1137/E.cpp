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

const int N = 300005;
int n, m, top, stk[N];
ll K, B, val[N];
int main() {
	read(n), read(m), stk[top=1]=n;
	while(m--){
		static int opt, x, y;
		read(opt), read(x);
		if(opt==1) n+=x, stk[top=1]=n, val[1]=-B;
		else if(opt==2){
			ll now=-(ll)K*n-B;
			while(top>1 && (long double)(val[top]-now)*stk[top-1]>=(long double)(val[top-1]-val[top])*stk[top])
				stk[top-1]+=stk[top], --top;
			stk[++top]=x, n+=x, val[top]=now;
		}
		else B+=x, read(y), K+=y;
		while(top>1 && val[top-1]-val[top]<=stk[top-1]*K)
			stk[top-1]+=stk[top], --top;
		x=n-stk[top]+1;
		print(x), print(' '), print(val[top]+K*(x-1)+B), print('\n');
	}
	return flush(), 0;
}