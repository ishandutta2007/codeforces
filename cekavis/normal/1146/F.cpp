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

const int N = 200005, P = 998244353;
int n, f[N], g[N];
vector<int> e[N];
int main() {
	read(n);
	for(int i=2; i<=n; ++i) read(f[i]), e[f[i]].push_back(i);
	for(int u=n; u; --u){
		int s0=1, s1=0, ss=1;
		for(int v:e[u]) ss=(ll)ss*(f[v]+g[v])%P, s1=((ll)s1*f[v]+(ll)s0*g[v])%P, s0=(ll)s0*f[v]%P;
		f[u]=(ss-s1+P)%P, g[u]=(ss-s0+P)%P;
		if(e[u].empty()) g[u]=1;
	}
	return printf("%d", f[1]), 0;
}