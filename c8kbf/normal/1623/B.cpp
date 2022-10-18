

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E3+8;

_ tc, n, x, y;
set<_> g[maxn];

void recur(_ l, _ r);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld%lld", &x, &y);
			g[x].insert(y);
		}
		recur(1, n);
	}

	return 0;
}

void recur(_ l, _ r) {
	g[l].erase(r);
	if(l > r) return;
	for(_ i = l; i <= r; ++i) if((i == l || g[l].count(i-1)) && (i == r || g[i+1].count(r))) {
		printf("%lld %lld %lld\n", l, r, i);
		if(i != l) recur(l, i-1);
		if(i != r) recur(i+1, r);
	}
	return;
}