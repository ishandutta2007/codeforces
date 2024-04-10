

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ tc, n, m, k, x;

int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld%lld%lld", &n, &m, &k);
		for(; n--; ) {
			scanf("%lld", &x);
			m += x;
		}
		puts((m^k)&1 ? "Bob" : "Alice");
	}

	return 0;
}