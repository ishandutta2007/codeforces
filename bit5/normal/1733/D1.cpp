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
const int N=3007;
int n, m, x, y, p[N];
char a[N], b[N];
inline void work() {
	n=read(), x=read(), y=read();
	scanf("%s%s", a+1, b+1), m=0;
	for (int i=1; i<=n; i++) if (a[i]^b[i]) p[++m]=i;
	if (m&1) {puts("-1"); return;}
	if (m!=2) printf("%lld\n", (ll)m/2*y);
	else if (p[1]+1!=p[2]) printf("%d\n", y);
	else printf("%d\n", min(y<<1, x));
}
int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	for (int T=read(); T; T--) work();
	return 0;
}