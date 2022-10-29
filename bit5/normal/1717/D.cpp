#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e5+7, mod=1e9+7;
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, a=(ll)a*a%mod)
		if (b&1) res=(ll)res*a%mod;
	return res;
}
int n;
ll K;
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	n=read(), K=read();
	if (K>=n) printf("%d\n", qpow(2, n)), exit(0);
	int c=1; ll ans=0;
	for (int i=0; i<=K; i++) {
		if (i) c=(ll)c*(n-i+1)%mod*qpow(i, mod-2)%mod;
		ans+=c;
	}
	printf("%lld\n", ans%mod);
	return 0;
}