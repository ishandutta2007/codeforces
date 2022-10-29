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
const int N=2e5+7;
int n, a[N], b[N];
bool fl[N];
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=n; i++) b[i]=read(), fl[i]=a[i]==b[i];
	bool ans=1;
	for (int i=1; i<=n; i++) ans&=fl[i] || (a[i]<b[i] && b[i]<=b[i%n+1]+1);
	puts(ans?"Yes":"No");
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}