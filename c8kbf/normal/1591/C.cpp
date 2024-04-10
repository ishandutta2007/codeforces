
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;

_ tc, n, m, a[maxn];

_ cr(v_ a, v_ b);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &n, &m);
		for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		v_ b, c;
		for(_ i = 1; i <= n; ++i) if(a[i] < 0) b.push_back(-a[i]);
		ef(a[i] > 0) c.push_back(a[i]);
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		printf("%lld\n", min(cr(b, c), cr(c, b)));
	}

	return 0;
}

_ cr(v_ a, v_ b) {
	_ s = 0;
	for(; !a.empty(); ) {
		_ dl = min((_)a.size(), m), mx = -1E11;
		for(_ i = dl; i--; ) {
			mx = max(mx, a.back());
			a.pop_back();
		}
		s += mx<<1;
	}
	if(!b.empty()) {
		_ dl = min((_)b.size(), m);
//		reverse(b.begin(), b.end());
		s += b.back();
		for(_ i = dl; i--; ) b.pop_back();
//		reverse(b.begin(), b.end());
	}
	for(; !b.empty(); ) {
		_ dl = min((_)b.size(), m), mx = -1E11;
		for(_ i = dl; i--; ) {
			mx = max(mx, b.back());
			b.pop_back();
		}
		s += mx<<1;
//		if(!b.empty()) s += mx;
	}
	return s;
}