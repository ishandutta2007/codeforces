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

int t;
ll x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &x, &y);
		ll ans = 0;
		rep(i, 1, y) {
			ll z = ll(i) * (i + 1) - 1;
			if (z >= x) {
				//~ ans += ll(y - i + 1) * (x / (i + 1));
				for (ll a = i + 1; a <= min(x, y + 1);) {
					ll b = (x / (x / a));
					ans += ll(min(min(x, y + 1), b) - a + 1) * (x / a);
					a = b + 1;
				}
				break;
			}
			ans += z / (i + 1);	
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}