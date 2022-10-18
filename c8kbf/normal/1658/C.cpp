#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;

_ tc, n, a[maxn];

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		if(count(a+1, a+1+n, 1) != 1) {
			puts("NO");
			continue;
		}
		v_ g;
		_ dx = find(a+1, a+1+n, 1)-a;
		for(_ i = dx; i <= n; ++i) g.push_back(a[i]);
		for(_ i = 1; i <= dx-1; ++i) g.push_back(a[i]);
		bool ok = true;
		for(_ i = 1; i < (_)g.size(); ++i) if(g[i] > g[i-1]+1) {
			ok = false;
			break;
		}
		puts(ok ? "YES" : "NO");
	}

	return 0;
}