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

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		ll s = 0, ans = 0;
		while (n--) {
			ll x;
			scanf("%lld", &x);
			if (s > 0) {
				ll y = s * k - x * 100;
				if (y < 0) {
					y = -y;
					ans = max(ans, (y + k - 1) / k);
				}
			}
			s += x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}