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
int n, x, y;
inline void work() {
	n=read(), x=read(), y=read();
	if (x>y) swap(x, y);
	if (x || !y || (n-1)%y!=0) {puts("-1"); return;}
	for (int i=2; i<=n; i+=y)
		for (int j=i; j<i+y; j++) printf("%d ", i);
	puts("");
}
int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	for (int T=read(); T; T--) work();
	return 0;
}