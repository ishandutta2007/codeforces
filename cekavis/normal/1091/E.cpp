#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<set>

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

const int N = 500005;
int n, a[N], b[N], c[N];
ll sum, s[N];
inline int check(int x){
	x=x*2+(sum&1);
	memset(b, 0, sizeof b);
	for(int i=1; i<=n; ++i) ++b[a[i]];
	++b[x];
	c[0]=b[0];
	for(int i=1; i<=n; ++i) c[i]=c[i-1]+b[i];
	int k=0;
	ll sum1=0, sum2=0;
	for(int i=n; ~i; --i) while(b[i]--){
		++k, sum1+=i;
		ll s;
		if(k<=i) sum2+=(ll)b[k]*k;
		else sum2-=i;
		if(k<i) s=sum2+(ll)(c[i-1]-c[k]+b[i])*k; else s=sum2;
		if(sum1>(ll)k*(k-1)+s) return (i>x?-1:1);
	}
	return 0;
}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]), sum+=a[i];
	// printf("%d\n", check(0));
	// return 0;
	int l=0, r=(n-(sum&1))/2, ansl=-1, ansr=-1;
	while(l<=r){
		int mid=(l+r)>>1, t=check(mid);
		if(t==-1) l=mid+1; else ansl=mid, r=mid-1;
	}
	l=0, r=(n-(sum&1))/2;
	while(l<=r){
		int mid=(l+r)>>1, t=check(mid);
		if(t==1) r=mid-1; else ansr=mid, l=mid+1;
	}
	if(ansl>ansr) return puts("-1"), 0;
	// printf("ans=[ %d %d ]\n", ansl, ansr);
	for(int i=ansl; i<=ansr; ++i) print(i*2+(sum&1)), print(' ');
	return flush(), 0;
}