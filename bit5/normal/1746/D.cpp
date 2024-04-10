#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use in interactive problems!!! 
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
int n, K, fa[N];
ll s[N], sum[N], f[N], mx[N];
vector<int>G[N];
void dfs(int x, int num) {
	sum[x]=sum[fa[x]]+s[x];
	if (G[x].empty()) {
		f[x]=num*sum[x], mx[x]=sum[x];
		return;
	}
	int sz=G[x].size(), C=(num-1)/sz+1;
	vector<ll>vec; f[x]=0;
	for (int y:G[x]) dfs(y, C), f[x]+=f[y], vec.push_back(mx[y]);
	sort(vec.begin(), vec.end()), C=C*sz-num;
	for (int i=0; i<C; i++) f[x]-=vec[i];
	mx[x]=!C?vec[0]:vec[C];
}
inline void work() {
	n=read(), K=read();
	for (int i=1; i<=n; i++) G[i].clear();
	for (int i=2; i<=n; i++) G[fa[i]=read()].push_back(i);
	for (int i=1; i<=n; i++) s[i]=read();
	dfs(1, K);
	printf("%lld\n", f[1]);
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