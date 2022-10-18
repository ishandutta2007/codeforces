

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ tc, xa, xb, ya, yb, k, x, y;

bool cn(_ xa, _ xb, _ ya, _ yb);
int main() {

	scanf("%lld", &tc);
	for(_ i = 1; i <= tc; ++i) {
		scanf("%lld%lld%lld%lld%lld%lld%lld", &xa, &xb, &ya, &yb, &k, &y, &x);
		bool ok = false;
		for(_ j = 0; j <= k; ++j) ok |= cn(xa+j*x, xb+(k-j)*y, ya, yb);
		puts(ok ? "YES" : "NO");
	}

	return 0;
}

bool cn(_ xa, _ xb, _ ya, _ yb) {
	_ na = (xa-1)/yb+1, nb = (ya-1)/xb+1;
	return na >= nb;
}