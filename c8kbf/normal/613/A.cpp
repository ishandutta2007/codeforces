#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, x, y;
_p a[maxn];
_D mx, mn;

pair<bool, _D> lnDs(_ x);
_D ds(_ x);
int main() {
	
	scanf("%lld%lld%lld", &n, &x, &y);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld", &a[i].first, &a[i].second);
		a[i].first -= x;
		a[i].second -= y;
	}
	mx = mn = ds(1);
	for(_ i = 2; i <= n; ++i) {
		mx = max(mx, ds(i));
		mn = min(mn, ds(i));
	}
	a[++n] = a[1];
	for(_ i = 1; i <= n-1; ++i) if(lnDs(i).first) {
		mn = min(mn, lnDs(i).second);
		fprintf(stderr, "at %lld, mn updated to %.20Lf\n", i, lnDs(i).second);
	}
	printf("%.20Lf\n", acos(-1.L)*(mx-mn));
	
	return 0;
}

_D ds(_ x) {
	return 1.L*a[x].first*a[x].first+a[x].second*a[x].second;
}

pair<bool, _D> lnDs(_ x) {
	if(a[x].first == a[x+1].first) {
		if(min(a[x].second, a[x+1].second) <= 0 && max(a[x].second, a[x+1].second) >= 0) return make_pair(true, 1.L*a[x].first*a[x].first);
		return make_pair(false, -1);
	}
	if(a[x].second == a[x+1].second) {
		if(min(a[x].first, a[x+1].first) <= 0 && max(a[x].first, a[x+1].first) >= 0) return make_pair(true, 1.L*a[x].second*a[x].second);
		return make_pair(false, -1);
	}
	_D sa = 1.L*(a[x].second-a[x+1].second)/(a[x].first-a[x+1].first), sb = -1.L*(a[x].first-a[x+1].first)/(a[x].second-a[x+1].second);
	_D b = a[x].second-sa*a[x].first;
	_D cx = b/(sb-sa);
	_D cy = sb*cx;
	if(cx < min(a[x].first, a[x+1].first) || cx > max(a[x].first, a[x+1].first)) return make_pair(false, -1);
	return make_pair(true, cx*cx+cy*cy);
}