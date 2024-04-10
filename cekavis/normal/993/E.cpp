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
const double pi = acos(-1);
const int N = 200005;
int n, p, k;
struct cp{
	double x, y;
	inline cp operator +(const cp &rhs)const{ return (cp){x+rhs.x, y+rhs.y};}
	inline cp operator -(const cp &rhs)const{ return (cp){x-rhs.x, y-rhs.y};}
	inline cp operator *(const cp &rhs)const{ return (cp){x*rhs.x-y*rhs.y, x*rhs.y+y*rhs.x};}
	inline cp operator *(const int  &rhs)const{ return (cp){x*rhs, y*rhs};}
} a[1<<19], b[1<<19];
inline void FFT(cp *f, int g){
	for(int i=0, j=0; i<p; ++i){
		if(i>j) swap(f[i], f[j]);
		for(int k=p>>1; (j^=k)<k; k>>=1);
	}
	for(int i=1; i<p; i<<=1){
		cp w0=(cp){cos(pi/i), sin(g*pi/i)};
		for(int j=0; j<p; j+=i<<1){
			cp w=(cp){1, 0};
			for(int k=j; k<j+i; ++k){
				cp t=w*f[k+i];
				f[k+i]=f[k]-t;
				f[k]=f[k]+t;
				w=w*w0;
			}
		}
	}
	if(g==-1) for(int i=0; i<p; ++i) f[i].x/=p;
}
int main() {
	read(n), read(k);
	int cnt=0;
	rep(i, 1, n){
		static int x;
		read(x);
		++a[cnt].x;
		if(x<k) ++cnt;
	}
	++a[cnt].x;
	rep(i, 0, cnt) b[i].x=a[cnt-i].x;
	for(p=1; p<=cnt<<1; p<<=1);
	FFT(a, 1), FFT(b, 1);
	for(int i=0; i<p; ++i) a[i]=a[i]*b[i];
	FFT(a, -1);
	print(((ll)(a[cnt].x+0.5)-n-1)/2);
	for(int i=cnt-1; ~i; --i) print(' '), print((ll)(a[i].x+0.5));
	rep(i, cnt+1, n) print(' '), print('0');
	return flush(), 0;
}