

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E5+8;

_ tc, n, a[maxn], b[maxn], l, r, md, s;

bool check(_ x);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		l = 0;
		r = 1E9;
		for(; l <= r; ) {
			md = (l+r)>>1;
			if(check(md)) {
				s = md;
				l = md+1;
			} else r = md-1;
		}
		printf("%lld\n", s);
	}

	return 0;
}

bool check(_ x) {
	for(_ i = 1; i <= n; ++i) b[i] = a[i];
	for(_ i = n; i >= 3; --i) {
		if(b[i] < md) return false;
		_ d = min(b[i]-md, a[i]);
		b[i-1] += d/3;
		b[i-2] += d/3*2;
	}
	return b[1] >= x && b[2] >= x;
}