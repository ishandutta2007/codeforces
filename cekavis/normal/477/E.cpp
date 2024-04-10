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

const int N = 400005, inf = 1e9;
int n, q, now, top, f[N], ans[N], len[N], stk[N], mn[N<<2], lmn[N<<2], rmn[N<<2];
vector<pair<int,int>> q1[N], q2[N];
void build(int l, int r, int t){
	if(l==r) return (void)(mn[t]=f[l], lmn[t]=f[l]-l*2, rmn[t]=f[l]+l*2);
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1), mn[t]=min(mn[k], mn[k|1]);
	lmn[t]=min(lmn[k], lmn[k|1]), rmn[t]=min(rmn[k], rmn[k|1]);
}
int getmin(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return mn[t];
	int mid=(l+r)>>1, k=t<<1;
	if(R<=mid) return getmin(l, mid, k, L, R);
	if(L>mid) return getmin(mid+1, r, k|1, L, R);
	return min(getmin(l, mid, k, L, R), getmin(mid+1, r, k|1, L, R));
}
int queryl(int l, int r, int t, int R, int x){
	if(l==r && mn[t]<=x) return now=l, inf;
	if(r<=R && mn[t]>x) return lmn[t];
	int mid=(l+r)>>1, k=t<<1;
	if(R<=mid) return queryl(l, mid, k, R, x);
	int ans=queryl(mid+1, r, k|1, R, x);
	if(!now) ans=min(ans, queryl(l, mid, k, R, x));
	return ans;
}
int queryr(int l, int r, int t, int L, int x){
	if(l==r && mn[t]<=x) return now=l, inf;
	if(L<=l && mn[t]>x) return rmn[t];
	int mid=(l+r)>>1, k=t<<1;
	if(L>mid) return queryr(mid+1, r, k|1, L, x);
	int ans=queryr(l, mid, k, L, x);
	if(!now) ans=min(ans, queryr(mid+1, r, k|1, L, x));
	return ans;
}
inline int calcl(int a, int b, int c){
	int ans=min(min(c, f[a]-c)+1, abs(b-c));
	if(a==1) return ans;
	now=0;
	int x=queryl(1, n, 1, a-1, c);
	if(now) ans=min(ans, (a-now)*2+c-f[now]+(b<c));
	ans=min(ans, x+a*2-c+(b<c));
	return ans;
}
inline int calcr(int a, int b, int c){
	int ans=min(min(c, f[a]-c)+1, abs(b-c));
	if(a==n) return ans;
	now=0;
	int x=queryr(1, n, 1, a+1, c);
	if(now) ans=min(ans, (now-a)*2+c-f[now]+(b<c));
	ans=min(ans, x-a*2-c+(b<c));
	return ans;
}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) read(f[i]);
	build(1, n, 1);
	read(q);
	for(int i=1, a=0, b=0, c=0, d=0; i<=q; ++i){
		read(a), read(b), read(c), read(d), len[i]=abs(c-a);
		if(a<=c){
			int x=getmin(1, n, 1, a, c);
			ans[i]=c-a+calcr(c, min(b, x), d);
			if(d<x) ans[i]=min(min(ans[i], c-a+calcl(a, b, d)), c-a+x-d+1);
			else q1[c].push_back(make_pair(d, i));
		}
		else{
			int x=getmin(1, n, 1, c, a);
			ans[i]=a-c+calcl(c, min(b, x), d);
			if(d<x) ans[i]=min(min(ans[i], a-c+calcr(a, b, d)), a-c+x-d+1);
			else q2[c].push_back(make_pair(d, i));
		}
	}
	for(int i=1; i<=n; ++i){
		while(top && f[i]<=stk[top]) --top;
		stk[++top]=f[i];
		for(auto j:q1[i]){
			int x=lower_bound(stk+1, stk+top+1, j.first)-stk;
			ans[j.second]=min(ans[j.second], len[j.second]+1+min(stk[x]-j.first, j.first-stk[x-1]));
		}
	}
	top=0;
	for(int i=n; i; --i){
		while(top && f[i]<=stk[top]) --top;
		stk[++top]=f[i];
		for(auto j:q2[i]){
			int x=lower_bound(stk+1, stk+top+1, j.first)-stk;
			ans[j.second]=min(ans[j.second], len[j.second]+1+min(stk[x]-j.first, j.first-stk[x-1]));
		}
	}
	for(int i=1; i<=q; ++i) print(ans[i]), print('\n');
	return flush(), 0;
}