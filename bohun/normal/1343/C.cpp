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
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n;
		scanf ("%d", &n);
		ll ans = 0;
		int maxi = -2e9;
		int a, b;
		a = b = 0;
		rep(i, 1, n) {
			int c;
			scanf ("%d", &c);
			if (c > 0) {
				if (a == 1) {
					ans += maxi;
					a = 0;
					maxi = -2e9;
				}
				maxi = max(maxi, c);
				b = 1;
			}
			else {
				if (b == 1) {
					ans += maxi;
					b = 0;
					maxi = -2e9;
				}
				maxi = max(maxi, c);
				a = 1;
			}
		}
		ans += maxi;
		printf ("%lld\n", ans);
	}
	
	return 0;
}