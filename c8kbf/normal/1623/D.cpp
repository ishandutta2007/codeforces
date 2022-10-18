
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

constant maxn = 4E5+8;
constant mod = 1E9+7;

_ tc, n, m, p;
_p x, y, d;
bool v[maxn];
v_ g;

_ pw(_ x, _ p);
_ cv(_ x, _ y, _p d);
_ cvd(_p x);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		memset(v, false, sizeof v);
		g.clear();
		scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &x.first, &x.second, &y.first, &y.second, &p);
		p = (1-p*pw(100, mod-2)%mod+mod)%mod;
		d = mp(1, 1);
		_ c = 0;
		for(;;) {
			if(x.first == 1 && d.first == -1) d.first = 1;
			ef(x.first == n && d.first == 1) d.first = -1;
			if(x.second == 1 && d.second == -1) d.second = 1;
			ef(x.second == m && d.second == 1) d.second = -1;
			if(x.first == y.first || x.second == y.second) {
				g.push_back(c);
				c = 0;
				if(v[cv(x.first, x.second, d)]) break;
				v[cv(x.first, x.second, d)] = true;
			}
			++c;
			x.first += d.first;
			x.second += d.second;
		}
//		printf("g.size = %lld\n", (_)g.size());
//		for(_ i = 0; i < (_)g.size(); ++i) printf("g[%lld] = %lld\n", i, g[i]);
		_p s = mp(0, 1);
		for(_ i = (_)g.size()-1; i >= 1; --i) {
			s.first = (s.first+g[i])%mod;
			s.first = s.first*p%mod;
			s.second = s.second*p%mod;
		}
		_ o = s.first*pw((1-s.second+mod)%mod, mod-2)%mod;
		o = (o+g[0])%mod;
		printf("%lld\n", o);
	}

	return 0;
}

_ cvd(_p x) {
	if(x == (_p)mp(1, 1)) return 0;
	ef(x == (_p)mp(1, -1)) return 1;
	ef(x == (_p)mp(-1, 1)) return 2;
	return 3;
}

_ cv(_ x, _ y, _p d) {
	return ((x-1)*m+y)<<2|cvd(d);
}

_ pw(_ x, _ p) {
	if(!p) return 1;
	_ c = pw(x, p>>1);
	c = c*c%mod;
	if(p & 1) c = c*x%mod;
	return c;
}