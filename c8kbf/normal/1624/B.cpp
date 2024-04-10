#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ tc, x, y, z;
bool ok;

bool ism(_ x, _ y);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld%lld", &x, &y, &z);
		ok = false;
		ok |= ism(x, 2*y-z);
		ok |= !((z+x)&1) && ism(y, (z+x)>>1);
		ok |= ism(z, 2*y-x);
		puts(ok ? "YES" : "NO");
	}

	return 0;
}

bool ism(_ x, _ y) {
	_ c = y/x;
	return c*x == y && c > 0;
}