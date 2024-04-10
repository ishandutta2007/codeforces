#include<cstdio>
#include<algorithm>
#include<ctype.h>
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

const int N = 200005, M = 5;
int n, m, q;
ll a[N];
bool lazy[N<<2];
struct _Map{
	int a[1<<M];
	inline _Map operator +(const _Map &rhs)const{
		_Map ans;
		for(int i=0; i<1<<m; ++i) ans.a[i]=a[rhs.a[i]];
		return ans;
	}
};
struct Map{
	_Map a[2];
	inline Map operator +(const Map &rhs)const{ return (Map){a[0]+rhs.a[0], a[1]+rhs.a[1]};}
	inline void reverse(){ swap(a[0], a[1]);}
}f, s[N<<2];
void build(int l, int r, int t){
	if(l==r){
		s[t]=f;
		if(a[l]) s[t].reverse();
		return;
	}
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=s[k]+s[k|1];
}
void change(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return lazy[t]^=1, s[t].reverse();
	int mid=(l+r)>>1, k=t<<1;
	if(lazy[t]) lazy[k]^=1, lazy[k|1]^=1, s[k].reverse(), s[k|1].reverse(), lazy[t]=0;
	if(L<=mid) change(l, mid, k, L, R);
	if(R>mid) change(mid+1, r, k|1, L, R);
	s[t]=s[k]+s[k|1];
}
_Map query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return s[t].a[0];
	int mid=(l+r)>>1, k=t<<1;
	if(lazy[t]) lazy[k]^=1, lazy[k|1]^=1, s[k].reverse(), s[k|1].reverse(), lazy[t]=0;
	if(R<=mid) return query(l, mid, k, L, R);
	if(L>mid) return query(mid+1, r, k|1, L, R);
	return query(l, mid, k, L, R)+query(mid+1, r, k|1, L, R);
}
int main() {
	read(n), read(m), read(q);
	for(int i=1; i<=n; ++i) read(a[i]), a[i]&=1;
	for(int i=0; i<1<<m; ++i) f.a[0].a[i]=i>>1|(1<<m>>1);
	f.a[1]=f.a[0], f.a[1].a[(1<<m)-1]=(1<<m>>1)-1;
	build(1, n, 1);
	while(q--){
		static int opt, l, r;
		ll d;
		read(opt), read(l), read(r);
		if(opt==1){
			read(d);
			if(d&1) change(1, n, 1, l, r);
		}
		else print(((query(1, n, 1, l, r).a[(1<<m)-1]>>(m-1))^1)+1), print('\n');
	}
	return flush(), 0;
}