#pragma G++ optimize("Ofast")
#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 5E2+8;

_ n, m, rx, ry, x, y, cc;
v_ g[maxn], cl;
bool cy, rc;
bitset<maxn> v, c;

inline void dfs(_ x);
int main() {

	scanf("%lld%lld", &n, &m);
	for(; m--; ) {
		scanf("%lld%lld", &x, &y);
		g[x].push_back(y);
	}
	for(_ i = 1; i <= n; ++i) if(!v[i]) {
		dfs(i);
//		if(cy) {
//			if(cc) {
//				puts("NO");
//				exit(0);
//			}
//			++cc;
//		}
		if(cy) break;
	}
	if(!cy) {
		puts("YES");
		exit(0);
	}
	reverse(cl.begin(), cl.end());
//	printf("cl: ");
//	for(_ i : cl) printf("%lld ", i);
//	putchar(10);
	rc = true;
	for(_ i = 1; i < (_)cl.size(); ++i) {
		rx = cl[i-1];
		ry = cl[i];
		v.reset();
//		rx = 2;
//		ry = 3;
//		printf("removed edge {%lld, %lld}\n", rx, ry);
		bool ok = false;
		for(_ j = 1; j <= n; ++j) {
//			printf("starting dfs at %lld\n", j);
			cy = false;
//			v.reset();
			dfs(j);
			ok |= cy;
		}
		if(!ok) {
			puts("YES");
			exit(0);
		}
	}
	puts("NO");

	return 0;
}

inline void dfs(_ x) {
//	printf("dfs at %lld\n", x);
	if(c[x]) {
		if(!rc) cl.push_back(x);
		cy = true;
		return;
	}
	if(v[x]) return;
	v.set(x);
	c.set(x);
	for(_ i : g[x]) if(!(x == rx && i == ry)) {
		dfs(i);
		if(cy) {
			if(!rc) cl.push_back(x);
			break;
		}
	}
	c.reset(x);
	return;
}