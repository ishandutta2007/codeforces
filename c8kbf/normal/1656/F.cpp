#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

constant maxn = 2E5+8;

_ tc, n, a[maxn], l, r, md, s, t;

_ check(_ x);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		sort(a+1, a+1+n);
		l = -3E7;
		r = 3E7;
		t = 0;
		s = -9E18;
		for(; l <= r; ) {
			_ md = (l+r)>>1;
			_ ca = check(md), cb = check(md+1);
			s = max(s, ca);
			s = max(s, cb);
			if(ca < cb) {
				l = md+1;
				t |= 1;
			} ef(ca > cb) {
				r = md-1;
				t |= 2;
			} else {
				t = 3;
				break;
			}
		}
		if(t != 3) puts("INF");
		else printf("%lld\n", s);
	}

	return 0;
}

_ check(_ x) {
	_ rv = a[1]*a[n]+x*(a[1]+a[n]);
	for(_ i = 2; i <= n-1; ++i) rv += min(a[1]*a[i]+x*(a[1]+a[i]), a[i]*a[n]+x*(a[i]+a[n]));
	return rv;
}