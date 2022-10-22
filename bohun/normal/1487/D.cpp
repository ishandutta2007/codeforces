#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

vector<ll> v;

int main() {
	for (ll a = 1; a <= 100000; ++a) {
		ll b = (a * a - 1) / 2;
		if (a * a != 2 * b + 1 || b > 1e9) continue;
		ll c = a * a - b;
		if (c > 1e9) continue;
		if (c * c == a * a + b * b && a <= b && b <= c) 
			v.pb(c);
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		printf("%d\n", (int)(upper_bound(all(v), n) - v.begin()));
	}
	return 0;
}