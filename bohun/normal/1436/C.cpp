#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int MOD = 1e9 + 7;

int n, x, pos;

int main() {
	scanf ("%d%d%d", &n, &x, &pos);
	int l = 0, r = n, res = 1, bigger = n - x, smaller = x - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (m == pos) {
			l = m + 1;
			continue;
		}
		if (m < pos) {
			l = m + 1;
			res = 1LL * res * (smaller--) % MOD;
		}
		else {
			r = m;
			res = 1LL * res * (bigger--) % MOD;
		}
	}
	rep(i, 1, bigger + smaller)
		res = 1LL * res * i % MOD;
	printf ("%d\n", res);
	return 0;
}