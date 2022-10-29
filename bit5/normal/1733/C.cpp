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
const int N=1e5+7;
int n, a[N];
vector<pair<int, int> >ans;
inline void op(int l, int r) {
	ans.push_back({l, r});
	if ((a[l]+a[r])&1) a[r]=a[l];
	else a[l]=a[r];
}
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	if (n==1) {puts("0"); return;}
	ans.clear(), op(1, n);
	for (int i=2; i<n; i++)
		if ((a[1]+a[i])&1) op(1, i);
		else op(i, n);
	printf("%lu\n", ans.size());
	for (auto [x, y]:ans) printf("%d %d\n", x, y);
}
int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	for (int T=read(); T; T--) work();
	return 0;
}