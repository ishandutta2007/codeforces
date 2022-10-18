#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef double _D;
typedef const long long constant;

constant maxn = 1E5+8;
constant big = 4E18;

_ tc, n, m, f[maxn];
v_ g;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &n, &m);
		g.clear();
		f[0] = f[1] = 1;
		for(_ i = 2; i <= n; ++i) {
			f[i] = f[i-1]<<1;
			f[i] = min(f[i], big);
		}
		for(_ i = 1; i <= n; ++i) {
			_ p = i;
			for(; p+1 <= n && m-f[n-p] >= 1; ++p) m -= f[n-p];
			for(_ j = p; j >= i; --j) g.push_back(j);
			i = p;
		}
		if(m != 1) puts("-1");
		else {
			for(_ i : g) printf("%lld ", i);
			putchar(10);
		}
	}

	return 0;
}