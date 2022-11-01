#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

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

const int N = 1000005, P = 1000000007;
int ans, n, a[N], fa[N], f[N], g[N];
ll sum, s[N];
vector<int> d[N];
inline ll gcd(ll x, ll y){ return y?gcd(y, x%y):x;}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]), sum+=a[i];
	for(int i=2; i<=n; ++i) read(fa[i]);
	for(int i=n; i; --i){
		s[i]+=a[i], s[fa[i]]+=s[i];
		ll x=sum/gcd(sum, s[i]);
		if(x<=n) ++f[x];
	}
	for(int i=n; i; --i) for(int j=i<<1; j<=n; j+=i) f[j]+=f[i], d[j].push_back(i);
	ans=g[1]=1;
	for(int i=2; i<=n; ++i) if(f[i]==i){
		for(int j:d[i]) (g[i]+=g[j])%=P;
		(ans+=g[i])%=P;
	}
	return printf("%d", ans), 0;
}