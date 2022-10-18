

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef long double _D;
typedef const long long constant;

_ n, m, tc;
_p xa, xb, d;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &xa.first, &xa.second, &xb.first, &xb.second);
		d = mp(1, 1);
		_ s = 0;
		for(; xa.first != xb.first && xa.second != xb.second; ) {
			if(xa.first == 1) d.first = 1;
			ef(xa.first == n) d.first = -1;
			if(xa.second == 1) d.second = 1;
			ef(xa.second == m) d.second = -1;
			xa.first += d.first;
			xa.second += d.second;
//			printf("at %lld %lld\n", xa.first, xa.second);
			++s;
		}
		printf("%lld\n", s);
	}

	return 0;
}