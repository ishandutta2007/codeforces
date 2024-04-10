
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

constant maxn = 5E5+8;

_ tc, n, a[maxn], c, s;
bool v[maxn];

void dfs(_ x);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		s = 0;
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) v[i] = false;
		bool ok = false;
		for(_ i = 1; i <= n; ++i) {
			 scanf("%lld", &a[i]);
			 if(v[a[i]]) ok = true;
			 v[a[i]] = true;
		}
		if(ok) {
			puts("YES");
			continue;
		}
		for(_ i = 1; i <= n; ++i) v[i] = false;
		for(_ i = 1; i <= n; ++i) if(!v[i]) {
			c = 0;
			dfs(i);
			s += c-1;
		}
		puts(s & 1 ? "NO" : "YES");
	}

	return 0;
}

void dfs(_ x) {
	if(v[x]) return;
	++c;
	v[x] = true;
	dfs(a[x]);
	return;
}