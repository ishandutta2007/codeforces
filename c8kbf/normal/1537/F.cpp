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

constant maxn = 2E5+8;

_ tc, n, m, a[maxn], b[maxn], x, y, sm, ca, cb, c[maxn];
v_ g[maxn];
bool bp;

void dfs(_ x, _ c);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		sm = ca = cb = 0;
		bp = true;
		scanf("%lld%lld", &n, &m);
		for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &b[i]);
			a[i] -= b[i];
			sm += a[i];
		}
		for(_ i = 1; i <= n; ++i) {
			g[i].clear();
			c[i] = -1;
		}
		for(_ i = m; i--; ) {
			scanf("%lld%lld", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(sm%2) {
			puts("NO");
			continue;
		}
		dfs(1, 1);
//		if(bp) puts("Bipartite!");
		if(!bp || ca == cb) puts("YES");
		else puts("NO");
	}

	return 0;
}

void dfs(_ x, _ c) {
	if(!bp) return;
	::c[x] = c;
	if(c) ca += a[x];
	else cb += a[x];
	for(_ i : g[x]) {
		if(~::c[i]) {
			if(::c[i] != (c^1)) {
				bp = false;
				return;
			}
		} else dfs(i, c^1);
	}
	return;
}