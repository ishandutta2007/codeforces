#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7, mod=998244353;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, a[N];
inline void work() {
	n=read(); int sum=0;
	for (int i=1; i<=n; i++) a[i]=read(), sum+=a[i]!=0;
	if (sum&1) {puts("-1"); return;}
	vector<pair<int, int> >ans;
	auto op=[&](int l, int r) {ans.push_back({l, r});};
	int l=1; while (l<=n && !a[l]) l++;
	if (l>1) op(1, l-1);
	for (int r=l; l<=n; l=r+1) {
		r=l+1;
		while (r<=n && !a[r]) r++;
		int p=r;
		while (r<n && !a[r+1]) r++;
		if (a[l]==a[p]) {
			if (l%2==p%2) op(l, l), op(l+1, r);
			else op(l, r);
		} else op(l, p-1), op(p, r);
	}
	printf("%lu\n", ans.size());
	for (auto &[x, y]:ans) printf("%d %d\n", x, y);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}