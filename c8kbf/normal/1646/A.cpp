
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

_ x, y, tc;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", y/x/x);
	}

	return 0;
}