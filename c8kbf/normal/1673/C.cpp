#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

constant maxn = 4E4+8;
constant big = 4E4;
constant mod = 1E9+7;

_ tc, n, dp[maxn];
v_ g;

int main() {

	for(_ i = 1; i <= big; ++i) {
		str a = to_string(i), b;
		b = a;
		reverse(b.begin(), b.end());
		if(b == a) g.push_back(i);
	}
	dp[0] = 1;
	for(_ i : g) for(_ j = i; j <= big; ++j) dp[j] = (dp[j]+dp[j-i])%mod;
	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}