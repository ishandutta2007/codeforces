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

const int N = 100005, MX = 100001;
int n, q, a[N];
bool rev[N<<2];
char f[N], cov[N<<2];
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return (void)(cov[t]=x);
	int mid=(l+r)>>1, k=t<<1;
	if(rev[t]) cov[k]^=1, cov[k|1]^=1, rev[k]^=1, rev[k|1]^=1, rev[t]=0;
	if(cov[t]>1) cov[k]=cov[k|1]=cov[t], cov[t]=0;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
}
void change2(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return (void)(rev[t]^=1, cov[t]^=1);
	int mid=(l+r)>>1, k=t<<1;
	if(rev[t]) cov[k]^=1, cov[k|1]^=1, rev[k]^=1, rev[k|1]^=1, rev[t]=0;
	if(cov[t]>1) cov[k]=cov[k|1]=cov[t], cov[t]=0;
	if(L<=mid) change2(l, mid, k, L, R);
	if(R>mid) change2(mid+1, r, k|1, L, R);
}
void dfs(int l, int r, int t){
	if(l==r) return (void)(f[l]=cov[t]);
	int mid=(l+r)>>1, k=t<<1;
	if(rev[t]) cov[k]^=1, cov[k|1]^=1, rev[k]^=1, rev[k|1]^=1, rev[t]=0;
	if(cov[t]>1) cov[k]=cov[k|1]=cov[t], cov[t]=0;
	dfs(l, mid, k), dfs(mid+1, r, k|1);
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) read(a[i]);
	while(q--){
		char opt;
		int x=0;
		while(isspace(opt=read()));
		read(x);
		if(opt=='>'){
			if(x>=0) change(0, MX, 1, x+1, MX, 3);
			else change(0, MX, 1, -x, MX, 3), change2(0, MX, 1, 0, -x-1);
		}
		else{
			if(x<=0) change(0, MX, 1, -x+1, MX, 2);
			else change(0, MX, 1, x, MX, 2), change2(0, MX, 1, 0, x-1);
		}
	}
	dfs(0, MX, 1);
	for(int i=1; i<=n; ++i)
		if(a[i]>=0) printf("%d ", f[a[i]]&1?-a[i]:a[i]);
		else printf("%d ", f[-a[i]]==1||f[-a[i]]==2?-a[i]:a[i]);
	return 0;
}