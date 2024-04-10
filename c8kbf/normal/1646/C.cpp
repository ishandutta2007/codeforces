
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

_ n, s, tc;

void dfs(_ x, _ d, _ t, _ r);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		s = 41;
		dfs(n, 0, 1, 1);
		printf("%lld\n", s);
	}

	return 0;
}

void dfs(_ x, _ d, _ t, _ r) {
//	if(t > x) return;
	_ c = d;
	for(_ i = 1; i <= x; i <<= 1) if(x & i) ++c;
//	printf("x = %lld, c = %lld, t = %lld\n", x, c, t);
//	if(d > s) return;
//	if(d == s && x) return;
	s = min(s, c);
	if(t*r > x) return;
//	for(_ i = 1, j = 1; i <= x; ++j, i *= j) dfs(x-i, d+1);
	dfs(x-t*r, d+1, t*r, r+1);
	dfs(x, d, t*r, r+1);
	return;
}