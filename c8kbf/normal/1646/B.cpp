
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

constant maxn = 2E5+8;
_ n, a[maxn], tc;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		sort(a+1, a+1+n);
		bool ok = false;
		_ pa = 1, ca = a[1], pb = n+1, cb = 0;
		for(;;) {
			++pa;
			--pb;
			if(pa >= pb) break;
			ca += a[pa];
			cb += a[pb];
			if(ca < cb) ok = true;
		}
		puts(ok ? "YES" : "NO");
	}

	return 0;
}