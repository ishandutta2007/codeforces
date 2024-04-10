

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 5E2+8;

_ tc, n, m, a[maxn][maxn];

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &n, &m);
		_ o = 1, e = 2;
		bool ok = true;
		for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= m; ++j) {
			if(i & 1) {
				a[i][j] = o;
				o += 2;
			} else {
				a[i][j] = e;
				e += 2;
			}
			if(a[i][j] > n*m) ok = false;
		}
		if(ok) {
			puts("YES");
			for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= m; ++j) printf("%lld ", a[i][j]);
		} else puts("NO");

	}

	return 0;
}