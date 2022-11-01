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

const int N = 100005;
int n, m, cnt, a[N], c[N];
bool rev[N<<2];
struct item{
	int mx, mn, lmx, lmn, rmx, rmn, sum;
	inline void init(int x){ mx=mn=lmx=lmn=rmx=rmn=sum=x;}
	inline item operator +(const item &a)const{
		return (item){
			max(max(mx, a.mx), rmx+a.lmx), min(min(mn, a.mn), rmn+a.lmn),
			max(lmx, sum+a.lmx), min(lmn, sum+a.lmn),
			max(rmx+a.sum, a.rmx), min(rmn+a.sum, a.rmn), sum+a.sum
		};
	}
	inline void rev(){
		swap(mx, mn), swap(lmx, lmn), swap(rmx, rmn);
		mx=-mx, mn=-mn, lmx=-lmx, lmn=-lmn, rmx=-rmx, rmn=-rmn, sum=-sum;
	}
} b[N], s[N<<2], f[N<<2];
void build(int l, int r, int t){
	if(l==r) return s[t].init(a[l]);
	rev[t]=0;
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1), s[t]=s[k]+s[k|1];
}
inline void push(int t){ b[cnt]=s[t], c[cnt++]=t, rev[t]^=1, s[t].rev();}
item query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return f[t]=s[t];
	int mid=(l+r)>>1, k=t<<1;
	if(rev[t]) push(k), push(k|1), rev[t]=0;
	if(R<=mid) return f[t]=query(l, mid, k, L, R);
	if(L>mid) return f[t]=query(mid+1, r, k|1, L, R);
	return f[t]=query(l, mid, k, L, R)+query(mid+1, r, k|1, L, R);
}
void changel(int l, int r, int t, int L, int x){
	int p=t;
	while(l<r){
		int mid=(l+r)>>1, k=t<<1;
		if(rev[t]) push(k), push(k|1), rev[t]=0;
		if(L>mid || s[k|1].rmx==x) l=mid+1, t=k|1;
		else r=mid, t=k, x-=s[k|1].sum, push(k|1);
	}
	push(t);
	while((t>>=1)>=p) b[cnt]=s[t], c[cnt++]=t, s[t]=s[t<<1]+s[t<<1|1];
}
void changer(int l, int r, int t, int R, int x){
	int p=t;
	while(l<r){
		int mid=(l+r)>>1, k=t<<1;
		if(rev[t]) push(k), push(k|1), rev[t]=0;
		if(R<=mid || s[k].lmx==x) r=mid, t=k;
		else l=mid+1, t=k|1, x-=s[k].sum, push(k);
	}
	push(t);
	while((t>>=1)>=p) b[cnt]=s[t], c[cnt++]=t, s[t]=s[t<<1]+s[t<<1|1];
}
void change(int l, int r, int t, int L, int R, int x){
	
	if(L<=l && r<=R && s[t].sum==x) return push(t);
	int mid=(l+r)>>1, k=t<<1;
	if(rev[t]) push(k), push(k|1), rev[t]=0;
	if(R<=mid) change(l, mid, k, L, R, x);
	else if(L>mid) change(mid+1, r, k|1, L, R, x);
	else{
		auto g=(L<=l && r<=R?s:f);
		if(g[k].mx==x) change(l, mid, k, L, R, x);
		else if(g[k|1].mx==x) change(mid+1, r, k|1, l, R, x);
		else changel(l, mid, k, L, g[k].rmx), changer(mid+1, r, k|1, R, g[k|1].lmx);
	}
	b[cnt]=s[t], c[cnt++]=t, s[t]=s[k]+s[k|1];
}
void modify(int l, int r, int t, int x, int y){
	if(l==r) return s[t].init(y);
	int mid=(l+r)>>1, k=t<<1;
	if(x<=mid) modify(l, mid, k, x, y); else modify(mid+1, r, k|1, x, y);
	s[t]=s[k]+s[k|1];
}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	build(1, n, 1);
	read(m);
	while(m--){
		int opt, l, r;
		read(opt), read(l), read(r);
		if(!opt) modify(1, n, 1, l, r), a[l]=r;
		else{
			int ans=0, k;
			read(k);
			while(k--){
				item t=query(1, n, 1, l, r);
				if(t.mx>0) ans+=t.mx, change(1, n, 1, l, r, t.mx); else break;
			}
			print(ans), print('\n');
			for(int i=cnt; i--;) rev[c[i]]=0, s[c[i]]=b[i];
			cnt=0;
		}
	}
	return flush(), 0;
}