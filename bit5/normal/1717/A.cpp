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

inline void work() {
	ll n=read();
	printf("%lld\n", n+n/2*2+n/3*2);
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}