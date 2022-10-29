#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=107;
int n, k, a[N];
inline void work() {
	n=read(), k=read();
	for (int i=1 ;i<=n; i++) a[i]=read();
	ll ans=0;
	for (int i=1; i<=k; i++) {
		int mx=0;
		for (int j=i; j<=n; j+=k) ckmax(mx, a[j]);
		ans+=mx;
	}
	printf("%lld\n", ans);
}
int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	for (int T=read(); T; T--) work();
	return 0;
}