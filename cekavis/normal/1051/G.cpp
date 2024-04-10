#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>

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

const int N = 200005, M = N*19;
int n, cnt, root[N], f[N<<1], siz[M], lson[M], rson[M];
ll ans, s[M], sumb[M];
void insert(int l, int r, int &t, int x){
	if(!t) t=++cnt;
	if(l==r) return (void)(siz[t]=1, sumb[t]=x);
	int mid=(l+r)>>1;
	if(x<=mid) insert(l, mid, lson[t], x); else insert(mid+1, r, rson[t], x);
	siz[t]=siz[lson[t]]+siz[rson[t]], sumb[t]=sumb[lson[t]]+sumb[rson[t]];
	s[t]=s[lson[t]]+s[rson[t]]+siz[rson[t]]*sumb[lson[t]];
}
void merge(int &x, int y){
	if(!x || !y) return (void)(x|=y);
	merge(lson[x], lson[y]), merge(rson[x], rson[y]);
	siz[x]=siz[lson[x]]+siz[rson[x]], sumb[x]=sumb[lson[x]]+sumb[rson[x]];
	s[x]=s[lson[x]]+s[rson[x]]+siz[rson[x]]*sumb[lson[x]];
}
int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
int main() {
	read(n);
	for(int i=1; i<=200000; ++i) f[i]=i;
	for(int i=1, a, b, t; i<=n; ++i){
		read(a), read(b), ans-=(ll)a*b;
		a=find(a), ans-=a*sumb[root[a]]+s[root[a]], insert(1, n, root[a], b);
		if(siz[root[t=find(a-1)]])
			ans-=t*sumb[root[t]]+s[root[t]], merge(root[t], root[a]), f[a]=t, a=t;
		while(siz[root[t=find(a+siz[root[a]])]])
			ans-=t*sumb[root[t]]+s[root[t]], merge(root[a], root[t]), f[t]=f[t-1]=a;
		f[t-1]=a;
		print(ans+=a*sumb[root[a]]+s[root[a]]), print('\n');
	}
	return flush(), 0;
}