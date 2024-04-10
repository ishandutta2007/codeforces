#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E5+8;

_ tc, f[maxn], n, m;
struct ed {
	_ x, y, c;
} a[maxn];

_ find(_ x);
bool ok(_ x);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &n, &m);
		for(_ i = 1; i <= m; ++i) scanf("%lld %lld %lld", &a[i].x, &a[i].y, &a[i].c);
		_ s = (1LL<<30)-1;
		for(_ i = 29; i >= 0; --i) {
			_ cr = 1LL<<i;
			if(ok(s^cr)) s ^= cr;
		}
		printf("%lld\n", s);
	}

	return 0;
}

bool ok(_ x) {
	for(_ i = 1; i <= n; ++i) f[i] = i;
	_ c = n;
	for(_ i = 1; i <= m; ++i) if((x & a[i].c) == a[i].c && find(a[i].x) != find(a[i].y)) {
		--c;
		f[find(a[i].x)] = find(a[i].y);
	}
	return c == 1;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}