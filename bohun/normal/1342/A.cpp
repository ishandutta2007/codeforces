#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int a, b, x, y;
		scanf ("%d%d%d%d", &x, &y, &a, &b);
		ll res = 0;
		b = min(b, 2 * a);
		if (x > 0 && y > 0) {
			res += 1LL * b * min(x, y);
			int z = min(x, y);
			x -= z; y -= z;
		}
		if (x < 0 && y < 0) {
			res += 1LL * b * max(x, y) * -1;
			int z = -max(x, y);
			x += z; y += z;
		}
		if (x != 0) res += 1LL * a * abs(x);
		if (y != 0) res += 1LL * a * abs(y);
		printf ("%lld\n", res);
	}
	
	return 0;
}