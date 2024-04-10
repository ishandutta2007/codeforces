#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E5+8;
constant lg = 30+8;

_ n, f[lg][maxn], a[maxn], l[maxn], c, b[maxn], ts, o[maxn];
bitset<maxn> v;
v_ g[maxn];
set<_> st;

int main() {

	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &f[0][i]);
		if(v.test(f[0][i])) ++c;
		v.set(f[0][i]);
	}
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		st.insert(i);
		ts = max(ts, (a[i]-n)/c);
	}
	for(_ i = 1; i <= 30; ++i) for(_ j = 1; j <= n; ++j) f[i][j] = f[i-1][f[i-1][j]];
	for(_ i = 1; i <= n; ++i) {
		_ t = i, r = ts;
		for(_ j = 30; j >= 0; j--) if(r >= (1LL<<j)) {
			r -= 1LL<<j;
			t = f[j][t];
		}
		g[t].push_back(i);
	}
	for(_ i = 1; i <= n; ++i) if(a[i] <= n) {
		o[g[i][0]] = a[i];
		for(_ j = 1; j < (_)g[i].size(); ++j) b[g[i][j]] = a[i];
		st.erase(a[i]);
	}
	for(_ i = 1; i <= n; ++i) {
		if(!o[i]) {
			o[i] = *st.upper_bound(b[i]);
			st.erase(o[i]);
		}
		printf("%lld ", o[i]);
	}
	putchar(10);

	return 0;
}